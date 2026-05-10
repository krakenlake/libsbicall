/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "config.h"
#include "libsbicall/sbicall.h"


/*
 * NACL extension
 */

struct sbiret sbi_nacl_probe_feature(uint32_t feature_id)
{
	return sbicall(feature_id, 0, 0, 0, 0, 0,
		SBI_FID_sbi_nacl_probe_feature, SBI_EID_NACL);
}

struct sbiret sbi_nacl_set_shmem(unsigned long shmem_phys_lo,
								unsigned long shmem_phys_hi,
								unsigned long flags)
{
	return sbicall(shmem_phys_lo, shmem_phys_hi, flags, 0, 0, 0,
		SBI_FID_sbi_nacl_set_shmem, SBI_EID_NACL);
}

struct sbiret sbi_nacl_sync_csr(unsigned long csr_num)
{
	return sbicall(csr_num, 0, 0, 0, 0, 0,
		SBI_FID_sbi_nacl_sync_csr, SBI_EID_NACL);
}

struct sbiret sbi_nacl_sync_hfence(unsigned long entry_index)
{
	return sbicall(entry_index, 0, 0, 0, 0, 0,
		SBI_FID_sbi_nacl_sync_hfence, SBI_EID_NACL);
}

struct sbiret sbi_nacl_sync_sret(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_nacl_sync_sret, SBI_EID_NACL);
}

