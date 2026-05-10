/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "config.h"
#include "libsbicall/sbicall.h"


/*
 * LEGACY extensions
 */

long legacy_sbi_set_timer(uint64_t stime_value)
{
	return sbicall_legacy(stime_value, 0, 0, 0, 0, 0, 
		SBI_FID_legacy_sbi_set_timer, SBI_EID_LEGACY);
}

long legacy_sbi_console_putchar(int c)
{
	return sbicall_legacy(c, 0, 0, 0, 0, 0, 
		SBI_FID_legacy_sbi_console_putchar, SBI_EID_LEGACY);
}

long legacy_sbi_console_getchar(void)
{
	return sbicall_legacy(0, 0, 0, 0, 0, 0, 
		SBI_FID_legacy_sbi_console_getchar, SBI_EID_LEGACY);
}

long legacy_sbi_clear_ipi(void)
{
	return sbicall_legacy(0, 0, 0, 0, 0, 0, 
		SBI_FID_legacy_sbi_clear_ipi, SBI_EID_LEGACY);
}

long legacy_sbi_send_ipi(const unsigned long *hart_mask)
{
	return sbicall_legacy((unsigned long)hart_mask, 0, 0, 0, 0, 0, 
		SBI_FID_legacy_sbi_send_ipi, SBI_EID_LEGACY);
}

long legacy_sbi_remote_fence_i(const unsigned long *hart_mask)
{
	return sbicall_legacy((unsigned long)hart_mask, 0, 0, 0, 0, 0, 
		SBI_FID_legacy_sbi_remote_fence_i, SBI_EID_LEGACY);
}

long legacy_sbi_remote_sfence_vma(const unsigned long *hart_mask,
							unsigned long start,
							unsigned long size)
{
	return sbicall_legacy((unsigned long)hart_mask, start, size, 0, 0, 0, 
		SBI_FID_legacy_sbi_remote_sfence_vma, SBI_EID_LEGACY);
}

long legacy_sbi_remote_sfence_vma_asid(const unsigned long *hart_mask, 
								unsigned long start, 
								unsigned long size, 
								unsigned long asid)
{
	return sbicall_legacy((unsigned long)hart_mask, start, size, asid, 0, 0, 
		SBI_FID_legacy_sbi_remote_sfence_vma_asid, SBI_EID_LEGACY);
}

