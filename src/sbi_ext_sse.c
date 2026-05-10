/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "config.h"
#include "libsbicall/sbicall.h"


/*
 * SSE extension
 */

struct sbiret sbi_sse_read_attrs(uint32_t event_id,
								uint32_t base_attr_id, 
								uint32_t attr_count,
								unsigned long output_phys_lo,
								unsigned long output_phys_hi)
{
	return sbicall(event_id, base_attr_id, attr_count, output_phys_lo, output_phys_hi, 0,
		SBI_FID_sbi_sse_read_attrs, SBI_EID_SSE);
}

struct sbiret sbi_sse_write_attrs(uint32_t event_id,
								uint32_t base_attr_id, 
								uint32_t attr_count,
								unsigned long input_phys_lo,
								unsigned long input_phys_hi)
{
	return sbicall(event_id, base_attr_id, attr_count, input_phys_lo, input_phys_hi, 0,
		SBI_FID_sbi_sse_write_attrs, SBI_EID_SSE);
}

struct sbiret sbi_sse_register(uint32_t event_id,
								unsigned long handler_entry_pc,
								unsigned long handler_entry_arg)
{
	return sbicall(event_id, handler_entry_pc, handler_entry_arg, 0, 0, 0,
		SBI_FID_sbi_sse_register, SBI_EID_SSE);
}

struct sbiret sbi_sse_unregister(uint32_t event_id)
{
	return sbicall(event_id, 0, 0, 0, 0, 0,
		SBI_FID_sbi_sse_unregister, SBI_EID_SSE);
}

struct sbiret sbi_sse_enable(uint32_t event_id)
{
	return sbicall(event_id, 0, 0, 0, 0, 0,
		SBI_FID_sbi_sse_enable, SBI_EID_SSE);
}

struct sbiret sbi_sse_disable(uint32_t event_id)
{
	return sbicall(event_id, 0, 0, 0, 0, 0,
		SBI_FID_sbi_sse_disable, SBI_EID_SSE);
}

struct sbiret sbi_sse_complete(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_sse_complete, SBI_EID_SSE);
}

struct sbiret sbi_sse_inject(uint32_t event_id, unsigned long hart_id)
{
	return sbicall(event_id, hart_id, 0, 0, 0, 0,
		SBI_FID_sbi_sse_inject, SBI_EID_SSE);
}

struct sbiret sbi_sse_hart_unmask(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_sse_hart_unmask, SBI_EID_SSE);
}

struct sbiret sbi_sse_hart_mask(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_sse_hart_mask, SBI_EID_SSE);
}

