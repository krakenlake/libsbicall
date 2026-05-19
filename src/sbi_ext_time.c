/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/*
 * TIME extension
 */

sbiret sbi_set_timer(unsigned long stime_value)
{
	return sbicall(stime_value, 0, 0, 0, 0, 0,
		SBI_FID_sbi_set_timer, SBI_EID_TIME);
}

