/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "config.h"
#include "libsbicall/sbicall.h"


/*
 * RFNC extension
 */

struct sbiret sbi_remote_fence_i(unsigned long hart_mask,
							unsigned long hart_mask_base)
{
	return sbicall(hart_mask, hart_mask_base, 0, 0, 0, 0,
		SBI_FID_sbi_remote_fence_i, SBI_EID_RFNC);
}

struct sbiret sbi_remote_sfence_vma(unsigned long hart_mask,
							unsigned long hart_mask_base,
							unsigned long start_addr,
							unsigned long size)
{
	return sbicall(hart_mask, hart_mask_base, start_addr, size, 0, 0, 
		SBI_FID_sbi_remote_sfence_vma, SBI_EID_RFNC);
}

struct sbiret sbi_remote_sfence_vma_asid(unsigned long hart_mask,
							unsigned long hart_mask_base,
							unsigned long start_addr,
							unsigned long size,
							unsigned long asid)
{
	return sbicall(hart_mask, hart_mask_base, start_addr, size, asid, 0, 
		SBI_FID_sbi_remote_sfence_vma_asid, SBI_EID_RFNC);
}

struct sbiret sbi_remote_hfence_gvma_vmid(unsigned long hart_mask,
							unsigned long hart_mask_base,
							unsigned long start_addr,
							unsigned long size,
							unsigned long vmid)
{
	return sbicall(hart_mask, hart_mask_base, start_addr, size, vmid, 0, 
		SBI_FID_sbi_remote_hfence_gvma_vmid, SBI_EID_RFNC);
}

struct sbiret sbi_remote_hfence_gvma(unsigned long hart_mask,
							unsigned long hart_mask_base,
							unsigned long start_addr,
							unsigned long size)
{
	return sbicall(hart_mask, hart_mask_base, start_addr, size, 0, 0, 
		SBI_FID_sbi_remote_hfence_gvma, SBI_EID_RFNC);
}

struct sbiret sbi_remote_hfence_vvma_asid(unsigned long hart_mask,
							unsigned long hart_mask_base,
							unsigned long start_addr,
							unsigned long size,
							unsigned long asid)
{
	return sbicall(hart_mask, hart_mask_base, start_addr, size, asid, 0, 
		SBI_FID_sbi_remote_hfence_vvma_asid, SBI_EID_RFNC);
}

struct sbiret sbi_remote_hfence_vvma(unsigned long hart_mask,
							unsigned long hart_mask_base,
							unsigned long start_addr,
							unsigned long size)
{
	return sbicall(hart_mask, hart_mask_base, start_addr, size, 0, 0, 
		SBI_FID_sbi_remote_hfence_vvma, SBI_EID_RFNC);
}
