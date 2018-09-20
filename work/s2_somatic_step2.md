
## Candidate Indel Test
 test whether the indel should be promoted to a candidate

a total locru coverage of N, indel coverage of $n_i$, indel error reate of $e_l$ , define the probability of some coverage x beging generated at the locus due to indel error as  
$ P(x | N, e_l) = C_N^xe_i^x(1-e_l)^{N-x}$  
$ P(X >= n_i | N, e_l )= \sum_{x=n_i}^N P (x |N, e_l)$
$ p_{reject} = 1 x 10^{-9} $
```c++ 
function 2.1 isCandidateIndelImplTestSignalNoise
for sample in [normal, turmor]
    n <- totalReadCount 
    tier1ReadSupportCount
    totalReadCount <- max (totalReadCount ,tier1ReadSupportCount )
    p <- candidateIndelToRefErrorProb
    if p / 1-p <= 0.01
        // Poisson 
        np = p * n
        if (np < max_papprox)
            tn <- tier1ReadSupportCount - 1
            result <- np <- _papprox[tn]
    else 
        getExct
```

Function 2.2 getCandidateAlignments
```c++
// find all indels in the indel_buffer which intersect a range (and meet candidacy/usability requirements)
function  add_indels_in_range

// Get the keys of the indels present in the candidate alignment
function getAlignmentIndels
// Recursively build potential alignment paths and push them into the candidate alignment set
// output -> cal_set
function candidate_alignment_search
//  1) is the current state of the active indel
//  2) is the alternate state of the active indel with the alignment's start position pinned
//  3) is the alternate state of the active indel with the alignment's end position pinned
// limit max_depth 5 

// Find the most likely alignment and most likely alignment for each indel state for every indel in indel_status_map
function scoreCandidateAlignmentsAndIndels
function scoreCandidateAlignments
for cal <- cals 
    lnp <- 0.0
    function scoreCandidateAlignment (cal)
        cigar <- cagars
        case cigar.type == Match:
            for i <- i ... cigar.length
            if is_same
                lnp += ln_comp(qscore)
            else 
                lnp += ln(qsore) + ln(1/3)
        case cigar.type == Insert:
            IndelKey <- getMatchingIndelKey
            for i <- i .. cigar.length
            read_base <- read[read_pos + i]
            ref_base <- ref[ref_pos]
            if read_base == ref_base
                lnp += ln_comp(qscore)
            else 
                lnp += ln(qsore) + ln(1/3)
        case cigar.type == Delete
            IndelKey <- getMatchingIndelKey
        
        if (IndelKey != INDEL::NONE) && not isCandidate
            lnp += log(1e-5)

/// The function will select the alignment with the following properties, in order until a tie is broken:
/// 1. fewest indels
/// 2. fewest non-candidate indels
/// 2. smallest total insertion length
/// 3. smallest total deletion length
if cal.lnp same 

/// Record 'best' re-alignment for the purpose of defining a single realigned read
finishRealignment
```


function score_indels


```C++

```


### PileUp

create_mismatch_filter_map
```c++
// read_mismatch_info
Function create_mismatch_filter_map
    S <- read.length
    F <- 20

Function pile_up_segement 
base_call
``` 




    

