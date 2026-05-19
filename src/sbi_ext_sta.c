/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/*
 * STA extension
 */

sbiret sbi_steal_time_set_shmem(unsigned long shmem_phys_lo,
									unsigned long shmem_phys_hi,
									unsigned long flags)
{
	return sbicall(shmem_phys_lo, shmem_phys_hi, flags, 0, 0, 0,
		SBI_FID_sbi_steal_time_set_shmem, SBI_EID_STA);
}

