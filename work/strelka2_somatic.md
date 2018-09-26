# strelka2 somatic 源码解读
## 1 Process input read alignment
- 1.1 Filter input read alignment flag 512 | 1024(mkdup) | 4(unmapped) | 256(secondary) | 2048(sunpplementary)
- 1.2 Tier Mapped
    Tier1Mapped read mapq > 20 and mate mapped and proper_pair
    Tier2Mapped read mapq > 0 or mate unmapped or (mate mapped not proper_pair)
    clearner read cigar 
    1 Remove zero length alignment segments
    2 Remove pad segments
    3 Condense repeated segments
    4 Reduce adjacent insertion/deletion tags to a single pair
    5 Replace Skip-Del-Skip (NDN) pattern with single SKIP (N) segment

- 1.3 Normalize/left-shift the input read
    1 collapse internal indels
    strelka2 source code implementation Function 1.1 collapseInsert
```c++
Function 1.1 collapse Indel 
/// REF:   ACTGC
/// READ:  ACGC
/// CIGAR: 2M1I2D1M -> 2M1D2M
leftCollapse <- 0;
rightCollapse <- 0;
maxCollapse <- min (insert_len, delete_len)
refRightPos <- ref pos
readRightPos <- read pos
while rightCollapse < maxCollapse
    isRightMatch <- read[refRightPos-rightCollapse] == refseq[refRightPos-rightCollapse]
    if isRightMatch 
        rightCollapse++
    else 
        break;

if rightCollapse > 0
    cagar[currentSegment].type = Match
    cagar[currentSegment].langth += rightCollapse 

refLeftPos <- ref pos - delete_leng
readLeftPos <- read pos - insert_leng
while leftCollapse+rightCollapse < maxCollapse
    isLeftMatch <- read[readLeftPos+leftCollapse] == refseq[refLeftPos+leftCollapse]
    if isLeftMatch
        leftCollapse++
    else 
        break;

if leftCollapse > 0 
    carga[PriorMatch].type = Match
    carga[PriorMatch].length += leftCollapse

ai.priorInsertLength -= leftCollapse+rightCollapse;
ai.priorDeleteLength -= leftCollapse+rightCollapse
frist_insert <- true
first_delete <- true

for index <- indel_start to indel_end
    ps2 <- al.carga[index]
    if (ps2.type == Insert ) 
        ps2.length <- frist_insert == true? ai.priorInsertLength: 0;
        frist_insert <- false
    
    if (ps.type == Delete) 
        ps2.length <- frist_insert == true? ai.priorDeleteLength: 0;
        frist_insert <- false
```
    2 left shift read implement by Function 1.2 leftShiftIndel
```c++
// Ref  ACXXGG       ACTCGG
// READ ACTCGG       ACXXGG
// 2M2I2M -> 1M2I3M  2M2D2M _> 1M2D2M
Function 1.2 leftShiftAlignmentIndels
shift <- 0
refRightPos <- ai.refPos-1
readRightPos <- ai.readPos-1
refLeftPos <- refRightPos-ai.priorDeleteLength
readLeftPos <- readRightPos-ai.priorInsertLength
while shift < ai.priorMatchLength 
    isLeftMatch <- readSeq[readLeftPos+shift] == refSeq[refLeftPos+shfit]
    isRightMatch <- readSeq[readRightPos-shift] == refSeq[refRightPos-shfit]
    if !isRightMatch && isLeftMatch
        break;
    else 
        shift++
al.path[currentSegment].type = MATCH;
al.path[currentSegment].length += shift;
al.path[PriorMatchSegment].lenght -= shift
```
    3 normalizeEdgeIndels handle edge indels
**Function 1.3** leftEdgeIndelCollapse  
```C++ 
leftEdgeIndelCollapse
if cagar.type == DELETE 
    read_pos += cagar.length
if cagar.type == INSERT
    rightCollapse <- 0
    while rightCollapse < cagar.length
        isRightMatch <- read[readRightPos-rightCollapse] == ref[refRightPos-rightCollapse]
        if (!isRightMatch) reak
        rightCollapse++

rightEdgeIndelCollapse
if cagar.type == INSERT
    leftCollapse <- 0
    while leftCollapse < cagar.length
        isLeftMatch <- read[readLeftPos+leftCollapse] == ref[refLeftPos+leftCollapse]
        if (!isLeftMatch) break
        leftCollapse++
```
- 1.4 Insert Read
add Alignment Indels To PosProcessor
**Function 1.4** addAlignmentIndelsToPosProcessor
read there is swap or simple indel by **process_swap** or **process_simple_indel** implement, have same function **finish_indel_sppr**
If Indel is Novel, then initialize all class data which does not depend on read observations by **initializeAuxInfo**
repeat analysis implement by **set_repeat_info**, to compute *repeatUnit*, *repeatUnitLength*, *refRepeatCount*, *indelRepeatCount*
case 1 : Insert seq <- insert seq => insert_repeat_count  
case 2 : Delete seq <- delete seq => delete_repeat_count  
case 3 : SWAP   first compute insert seq repeat, second compute delete seq repeat => insert_repeat_count and delete_repeat_count 
if insert seq not equal delete seq, then return 
```C++
Function get_seq_repeat_unit
IN : seq 
OUT : repeat_unit, repeat_count
n <- indel_seq.size()
for i <- 1 to n -1
    is_repeat <- true
    if n % i == 0
        for j <- i; j < n; j += i
            if (indel_seq[j,...,j+k] != indel_seq[0,...,k])
                is_repeat <- false
                break;
    if (is_repeat) 
        repeat_unit <- indel_seq[0,...,i]
        repeat_count <- n / i
```
count repeats in contextual sequence: (indel_context_repeat_count)
indel_begin_pos : indelKey.pos
indel_end_pos : indelKey.pos + indelKey.delete_length
```c++
indel_context_repeat_count = 0
for pos=indel_begin_pos-repeat_count; pos >=0; pos -= repeat_count
    if ref[pos,...] == repeat_unit
        indel_context_repeat_count++;
for pos=indel_end_pos+repeat_count; pos < ref_end; pos += repeat_count
    if ref[pos,...] == repeat_unit
        indel_context_repeat_count++;
refRepeatCount = indel_context_repeat_count + delete_repeat_count
indelRepeatCount = indel_context_repeat_count + insert_repeat_count

```
interrupted Homopolymer Length 
Get the length of the longest homopolymer extending from pos when one alternate base is allowed to interrupt the homopolymer sequence. 
The implementation by **getInterruptedHomopolymerLength**, 
indelReportInfo.interruptedHomopolymerLength = max([inde_begin_pos-1, inde_begin_pos, indel_end_pos-1, indel_end_pos].getInterruptedHomopolymerLength)
```C++ 
Function getInterruptedHomopolymerLength 
n1 <- 0
n2 <- 0
prior_base = ref[pos]
for pos = current_pos; pos >= 0 ; --pos
    base <- ref[pos]
    if base == prior_base
        n1++;
    else 
        if prior_base = base
            n2++
        else 
            break;
for pos =  current_pos+1; pos <= ref_end; ++pos
    base <- ref[pos]
    if base == prior_base
        n1++;
    else 
        if prior_base = base
            n2++
        else 
            break; 
n3 = max(n1, n2)

n1 = 0
n2 = 0
prior_base = ref[pos]
for pos = current_pos; pos < ref_end ; ++pos
    base <- ref[pos]
    if base == prior_base
        n1++;
    else 
        prior_base = base // togging on new base once
        if prior_base == base
            n2++
        else 
            break;
for pos =  current_pos+1; pos <= ref_end; ++pos
    base <- ref[pos]
    if base == prior_base
        n1++;
    else 
        prior_base = base // togging on new base once
        if prior_base = base
            n2++
        else 
            break; 
n4 = max(n1, n2)

n = max(n3, n4)
```

**Function 1.5** initializeAuxInfo
compute _errorRates  refToIndelErrorProb, indelToRefErrorProb, candidateRefToIndelErrorProb, candidateIndelToRefErrorProb
by implement **initializeAuxInfo** 
case 1: simple indel, implement by code as fellow
case 2: swap indel refToIndelErrorProb <- errorRates[0][0];
indelToRefErrorProb <- errorRates[0][0]>
```c++
repeatingPatternSize = max (repeatUnitLength, 1)
refPatternRepeatCount = max(refRepeatCount, 1)
indelPatternRepeatCount = max (indelRepeatCount, 1)

//Adjustment refPatternRepeatCount indelPatternRepeatCount
if repeatingPatternSize > 1
    repeatingPatternSize = 1
    refPatternRepeatCount = 1
    indelPatternRepeatCount = 1
else 
    refPatternRepeatCount = max(15, refPatternRepeatCount)
    indelPatternRepeatCount = max(15, indelPatternRepeatCount)

refToIndelErrorProb = errorRates[repeatingPatternSize-1][refPatternRepeatCount-1]
reverseIndelType
indelToRefErrorProb = errorRates[repeatingPatternSize-1][indelPatternRepeatCount-1]
```

Somatic Indel Error Model use Non-adaptive indel error model
$e_i(1,r) = e_d(1,r) = e_l exp(f_r(log(e_h)-log(e_l))), e_l = 5*10^{-5}, e_h = 3*10^{-4}$ 
```C++
el <- log(5*10e-5)
eh <- log(3*10e-4)
C <- 15
S <- 1
for p <- 1 to C 
    highErrorFrac <- min(p-1, C) / C
    lowErrorFrac <- (1.0 - highErrorFrac) * el - highErrorFrac * eh
    errorRate[S-1][p-1] <- exp(logErrorRate)
```


## Realign And Score Read 
- 1 Indel Candidacy
**check_for_candidate_indel_overlap** check candidate indel by implement **isCandidateIndelImpl** 
Given a total locus coverage of N, Indel coverage of $n_i$, and an indel error of $e_l$, we define the probability of some coverage x beging generaterd at the locus due to indel error 

