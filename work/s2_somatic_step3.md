### process_pos_snp_somatic

```c++
get_diploid_gt_lhood_cached_simple
lhood[REF] <- 0.0
lhood[HET] <- 0.0
lhood[HOM] <- 0.0
for bc <- bcs
    eprob <- bc.error_prob
    ceprob <- 1.0 - eprob
    lne <- bc.ln_error_prob
    lnce <- bc.ln_comp_error_prob
    cv[0] <- lne + ln(1/3)
    cv[1] <- ln(ceprob + 1/3 * eprob) + ln(1/2)
    cv[2] <- lnce
    if bc.base == ref.base 
        lhood[REF] += cv[2]
        lhood[HET] += cv[1]
        lhood[HOM] += cv[0]
    else 
        lhood[REF] += cv[0]
        lhood[HET] += cv[1]
        lhood[HOM] += cv[2]


get_diploid_het_grid_lhood_cached

for gt = 0; gt<18; ++gt
    lhood[gt] = 0.;

for  het_inde = 0; het_inde < 9; ++het_index
    het_ratio = (het_inde + 1) * 0.05
    chet_ratio <- 1.0 - het_ratio
    
    for i = 0; i < n_call; ++n
        eprob <- be.error_prob
        ceprob <- 1.0 - eprob
        cv[0] <- ln(ceprob * het_ratio + eprob * 1/3 * chet_ratio)
        cv[1] <- ln(ceprob * chet_ratio + eprob * 1/3* het_ratio)
        if bc.base == ref.base
            lhood_high += cv[0]
            lhood_low += cv[1]
        else 
            lhood_high += cv[0]
            lhood_low += cv[1]
// calculate probability of strand-specific noise
get_diploid_strand_grid_lhood_spi
for (unsigned i(0); i<9; ++i)
    het_ratio <- 0.05 * (i+1)
    for bc <- base_calls
        eprob <- be.error_prob
        ceprob <- 1.0 - eprob
        cv[0] <- ln(ceprob * het_ratio + eprob * 1/3 * chet_ratio)
        cv[1] <- ln(ceprob * chet_ratio + eprob * 1/3* het_ratio)
        if bc.base == ref.base
            val_off_strand <- bc.ln_comp_error_prob()
            val_fwd <- bc.is_fwd_strand? cv.val[0] : val_off_strand
            val_rev <- bc.is_fwd_strand? val_off_strand : cv.val[0])
            lhood_fwd += val_fwd;
            lhood_rev += val_rev;
        else 
            val_off_strand <- bc.ln_error_prob()+ln(1/3)
            val_off_strand <- bc.ln_comp_error_prob()
            val_fwd <- bc.is_fwd_strand? cv.val[1] : val_off_strand
            val_rev <- bc.is_fwd_strand? val_off_strand : cv.val[1])
            lhood_fwd += val_fwd;
            lhood_rev += val_rev;

// calculate_result_set_grid
calculate_result_set_grid
_contam_tolerance <- 0.15
_ln_sse_rate <- ln(shared_error_rate)
_ln_csse_rate <-ln(1.0 -  shared_error_rate)
log_post_prob[3][2]
log_error_mod <-  -ln(20)
for ngt = 0; ngt < 3; ++ngt // ngt = ref | het | hom
    for tgt = 0; tgt < 2; ++tgt // non-somatic, 1: somatic
        for tumor_freq_index <- 0...21
            // 0 -> 0.0 : 1 -> 1.0f : 2 -> 0.5 : other
            tumor_freq <- 0.05 * tumor_freq_index
            for normal_freq_index <- 0...21
                if tgt == 0
                    lprior_freq <- (normal_freq_index == ngt)  ?_ln_csse_rate : _ln_sse_rate + log_error_mod
                else 
                    if (normal_freq_index != tumor_freq_index) 
                        if (ngt != 0)
                            lprior_freq = log_error_mod
                        else 
                            if  bool consider_norm_contam <- 0.15*tumor_freq >= 0.05
                                if (normal_freq_index == 0)
                                    lprior_freq = log_error_mod
                                else 
                                    if ((normal_freq_index == ngt) || (normal_freq_index == 3))
                                        lprior_freq = log_error_mod + ln_one_half;

                double lsum = lprior_freq + normal_lhood[normal_freq_index] + tumor_lhood[tumor_freq_index];
                log_sum[index++] = lsum;

        double sum = 0.0;
        for (int i(0); i<index; ++i)
            sum += std::exp(log_sum[i] - max_log_sum);
        double log_genotype_prior = germlineGenotypeLogPrior[ngt] + ((tgt == 0) ? lnmatch : lnmismatch);
        log_post_prob[ngt][tgt] = log_genotype_prior + max_log_sum + std::log(sum);
        if (log_post_prob[ngt][tgt] > max_log_prob)
            max_log_prob = log_post_prob[ngt][tgt]
            rs.max_gt = DDIGT::get_state(ngt, tgt)


 // Calculate posterior probabilities ( P(G)*P(D|G) )
    double sum_prob = 0.0;
    for (unsigned ngt(0); ngt<SOMATIC_DIGT::SIZE; ++ngt)
    {
        for (unsigned tgt(0); tgt<SOMATIC_STATE::SIZE; ++tgt)
        {
            double prob = std::exp(log_post_prob[ngt][tgt] - max_log_prob); // to prevent underflow
            sum_prob += prob;
        }
    }

        double log_sum_prob = std::log(sum_prob);
    double min_not_somfrom_sum(INFINITY);
    double nonsom_prob = 0.0;

    double post_prob[SOMATIC_DIGT::SIZE][SOMATIC_STATE::SIZE];
    for (unsigned ngt(0); ngt<SOMATIC_DIGT::SIZE; ++ngt)
    {
        double som_prob_given_ngt(0);
        for (unsigned tgt(0); tgt<SOMATIC_STATE::SIZE; ++tgt)
        {
            post_prob[ngt][tgt] = std::exp(log_post_prob[ngt][tgt] - max_log_prob - log_sum_prob);
            if (tgt == 0)   // Non-somatic
            {
                nonsom_prob += post_prob[ngt][tgt];
            }
            else    // Somatic
            {
                som_prob_given_ngt += post_prob[ngt][tgt];
            }
        }

        double err_som_and_ngt = 1.0 - som_prob_given_ngt;
        if (err_som_and_ngt < min_not_somfrom_sum)
        {
            min_not_somfrom_sum=err_som_and_ngt;
            rs.from_ntype_qphred=error_prob_to_qphred(err_som_and_ngt);
            rs.ntype=ngt;
        }
    }
    rs.qphred=error_prob_to_qphred(nonsom_prob);
```

P(Fn != Ft | Gt = nonsom, Gn)  = 0
P(Fn = Ft | Gt = som, Gn) = 0
### process_pos_indel_somatic

```c++
get_indel_digt_lhood
for indeldata <- indelSampleData
    noindel_lnp <- indeldata.ref
    hom_lnp <- indelData.indel
    log_ref_prob <- ln(1/2)
    log_indel_prob <- ln(1/2)
    het_allele_ratio <- 0.5
    ref_path_term <- 1.0 - het_allele_ratio * ref_path_expect
    indel_path_term <- het_allele_ratio * indel_path_expect
    total_path_term <- ref_path_term+indel_path_term
    indel_prob(indel_path_term/total_path_term);
    log_ref_prob=std::log(1.-indel_prob);
    log_indel_prob=std::log(indel_prob)
    het_lnp(getLogSum(noindel_lnp+log_ref_prob,hom_lnp+log_indel_prob));
    lhood[noIndel] <- getLogSum()
    lhood[HOM]
    lhood[Ref]
get_indel_het_grid_lhood
    for i(0); i<DIGT_GRID::HET_RES; ++i)
        het_ratio <- (i + 1) * 0.05
        chet_ratio(1.-het_ratio);

        log_het_ratio(std::log(het_ratio));
        log_chet_ratio(std::log(chet_ratio))

```


### 
```c++
calculate_result_set_grid
```