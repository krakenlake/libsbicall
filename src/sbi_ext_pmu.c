/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/*
 * PMU extension
 */

struct sbiret sbi_pmu_num_counters(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_pmu_num_counters, SBI_EID_PMU);
}

struct sbiret sbi_pmu_counter_get_info(unsigned long counter_idx)
{
	return sbicall(counter_idx, 0, 0, 0, 0, 0,
		SBI_FID_sbi_pmu_counter_get_info, SBI_EID_PMU);
}

struct sbiret sbi_pmu_counter_config_matching(unsigned long counter_idx_base,
										unsigned long counter_idx_mask,
										unsigned long config_flags,
										unsigned long event_idx,
										uint64_t event_data)
{
	return sbicall(counter_idx_base, counter_idx_mask, config_flags, 
		event_idx, event_data, 0,
		SBI_FID_sbi_pmu_counter_config_matching, SBI_EID_PMU);
}

struct sbiret sbi_pmu_counter_start(unsigned long counter_idx_base,
								unsigned long counter_idx_mask,
								unsigned long start_flags,
								uint64_t initial_value)
{
	return sbicall(counter_idx_base, counter_idx_mask, start_flags, 
		initial_value, 0, 0,
		SBI_FID_sbi_pmu_counter_start, SBI_EID_PMU);
}

struct sbiret sbi_pmu_counter_stop(unsigned long counter_idx_base,
							unsigned long counter_idx_mask,
							unsigned long stop_flags)
{
	return sbicall(counter_idx_base, counter_idx_mask, stop_flags, 0, 0, 0,
		SBI_FID_sbi_pmu_counter_stop, SBI_EID_PMU);
}

struct sbiret sbi_pmu_counter_fw_read(unsigned long counter_idx)
{
	return sbicall(counter_idx, 0, 0, 0, 0, 0,
		SBI_FID_sbi_pmu_counter_fw_read, SBI_EID_PMU);
}

struct sbiret sbi_pmu_counter_fw_read_hi(unsigned long counter_idx)
{
	return sbicall(counter_idx, 0, 0, 0, 0, 0,
		SBI_FID_sbi_pmu_counter_fw_read_hi, SBI_EID_PMU);
}

struct sbiret sbi_pmu_snapshot_set_shmem(unsigned long shmem_phys_lo,
									unsigned long shmem_phys_hi,
									unsigned long flags)
{
	return sbicall(shmem_phys_lo, shmem_phys_hi, flags, 0, 0, 0,
		SBI_FID_sbi_pmu_snapshot_set_shmem, SBI_EID_PMU);
}

struct sbiret sbi_pmu_event_get_info(unsigned long shmem_phys_lo,
									unsigned long shmem_phys_hi,
									unsigned long num_entries,
									unsigned long flags)
{
	return sbicall(shmem_phys_lo, shmem_phys_hi, num_entries, flags, 0, 0,
		SBI_FID_sbi_pmu_event_get_info, SBI_EID_PMU);
}
