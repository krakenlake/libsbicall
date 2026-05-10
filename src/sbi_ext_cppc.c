/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "config.h"
#include "libsbicall/sbicall.h"


/*
 * CPPC extension
 */

struct sbiret sbi_cppc_probe(uint32_t cppc_reg_id)
{
	return sbicall(cppc_reg_id, 0, 0, 0, 0, 0,
		SBI_FID_sbi_cppc_probe, SBI_EID_CPPC);
}

struct sbiret sbi_cppc_read(uint32_t cppc_reg_id)
{
	return sbicall(cppc_reg_id, 0, 0, 0, 0, 0,
		SBI_FID_sbi_cppc_read, SBI_EID_CPPC);
}

struct sbiret sbi_cppc_read_hi(uint32_t cppc_reg_id)
{
	return sbicall(cppc_reg_id, 0, 0, 0, 0, 0,
		SBI_FID_sbi_cppc_read_hi, SBI_EID_CPPC);
}

struct sbiret sbi_cppc_write(uint32_t cppc_reg_id, uint64_t val)
{
	return sbicall(cppc_reg_id, val, 0, 0, 0, 0,
		SBI_FID_sbi_cppc_write, SBI_EID_CPPC);
}
