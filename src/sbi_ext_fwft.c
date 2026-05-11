/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/*
 * FWFT extension
 */

struct sbiret sbi_fwft_set(uint32_t feature,
						unsigned long value,
						unsigned long flags)
{
	return sbicall(feature, value, flags, 0, 0, 0,
		SBI_FID_sbi_fwft_set, SBI_EID_FWFT);
}

struct sbiret sbi_fwft_get(uint32_t feature)
{
	return sbicall(feature, 0, 0, 0, 0, 0,
		SBI_FID_sbi_fwft_get, SBI_EID_FWFT);
}
