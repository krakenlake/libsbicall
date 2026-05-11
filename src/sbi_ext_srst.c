/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/*
 * SRST extension
 */

struct sbiret sbi_system_reset(uint32_t reset_type, 
							uint32_t reset_reason)
{
	return sbicall(reset_type, reset_reason, 0, 0, 0, 0,
		SBI_FID_sbi_system_reset, SBI_EID_SRST);
}

