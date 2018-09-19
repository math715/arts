# Strelka2 Somatic 算法整理

### filter 
Filter(512) | PRIMARY (2048) | duplicate(1024) | unmapped(4)  | secondary(256) | SUPPLEMENTARY(2048) 
TIER1_MAPPED  mapq >= 20 &&  proper_pair
TIER2_MAPPED  mapq < 20 && (mate_unmapped || not proper_pair)


Function 1.1 apath_cleaner (align_path.hh )
1. Remove zero length alignment segments
2. Remove pad segments
3. Condense repeated segments
4. Reduce adjacent insertion/deletion tags to a single pair
5. Replace Skip-Del-Skip (NDN) pattern with single SKIP (N) segment
```C++
Function 1.1 collapse Indel 
/// find 
/// REF:   ACTGC
/// READ:  ACGC
/// CIGAR: 2M1I2D1M
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


leftShiftAlignmentIndels 
### implement
```c++
Function 1.3 leftShiftAlignmentIndels
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


### addAlignmentIndelsToPosProcessor
process_swap  (2I1D)
process_simple_indel 2I or 3D
```c++
Function 1.4 addAlignmentIndelsToPosProcessor

```

### Indel Error model

默认
r的值是[1,15]
$e_i(1,r) = e_d(1,r) = e_lexp(f_r(log(e_h) - log(e_l)))$
$e_l = 5 * 10^{-5}, e_h = 3 * 10^{-4}, f_r = max(r-1, 15) / 15$

#### 现实细节
ErrorRate[0][15]
```C++
el <- log(5*10e-5)
eh <- log(3*10e-4)
C <- 15
S <- 1
for p <- 1 to C 
    do 
    highErrorFrac <- min(p-1, C) / C
    lowErrorFrac <- (1.0 - highErrorFrac) * el - highErrorFrac * eh
    errorRate[S-1][p-1] <- exp(logErrorRate)
```



```C++
Function 2.1
isCandidateIndelImplTest
for sample_id <- 0 to 1
    tier1ReadSupportCount // tier1 read
    totalReadCount // 覆盖read
    totalReadCount <- max (totalReadCount,tier1ReadSupportCount)
    p <- ErrorRate[][]
    n_success <- tier1ReadSupportCount
    if p / (1 - p) <= 0.01 
        // Poisson(\lambda)
        np <- p * totalReadCount
        tn <- 
    else 

```


