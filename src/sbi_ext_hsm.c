/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "config.h"
#include "libsbicall/sbicall.h"


/*
 * HSM extension
 */

struct sbiret sbi_hart_start(unsigned long hartid,
							unsigned long start_addr,
							unsigned long opaque)
{
	return sbicall(hartid, start_addr, opaque, 0, 0, 0, 
		SBI_FID_sbi_hart_start, SBI_EID_HSM);
}

struct sbiret sbi_hart_stop(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_hart_stop, SBI_EID_HSM);
}

struct sbiret sbi_hart_get_status(unsigned long hartid)
{
	return sbicall(hartid, 0, 0, 0, 0, 0,
		SBI_FID_sbi_hart_get_status, SBI_EID_HSM);
}

struct sbiret sbi_hart_suspend(uint32_t suspend_type,
							unsigned long resume_addr,
							unsigned long opaque)
{
	return sbicall((unsigned long)suspend_type, resume_addr, opaque, 0, 0, 0, 
		SBI_FID_sbi_hart_suspend, SBI_EID_HSM);
}
