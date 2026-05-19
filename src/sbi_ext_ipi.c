/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/*
 * IPI extension
 */

sbiret sbi_send_ipi(unsigned long hart_mask, 
						unsigned long hart_mask_base)
{
	return sbicall(hart_mask, hart_mask_base, 0, 0, 0, 0, 
		SBI_FID_sbi_send_ipi, SBI_EID_IPI);
}
