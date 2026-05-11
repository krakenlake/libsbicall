/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/*
 * SUSP extension
 */

struct sbiret sbi_system_suspend(uint32_t sleep_type,
								unsigned long resume_addr,
								unsigned long opaque)
{
	return sbicall(sleep_type, resume_addr, opaque, 0, 0, 0,
		SBI_FID_sbi_system_suspend, SBI_EID_SUSP);
}

