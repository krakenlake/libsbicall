/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "config.h"
#include "libsbicall/sbicall.h"


/*
 * BASE extension
 */

struct sbiret sbi_get_spec_version(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_get_spec_version, SBI_EID_BASE);
}

struct sbiret sbi_get_impl_id(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_get_impl_id, SBI_EID_BASE);
}

struct sbiret sbi_get_impl_version(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_get_impl_version, SBI_EID_BASE);
}

struct sbiret sbi_probe_extension(long extension_id)
{
	return sbicall(extension_id, 0, 0, 0, 0, 0,
		SBI_FID_sbi_probe_extension, SBI_EID_BASE);
}

struct sbiret sbi_get_mvendorid(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_get_mvendorid, SBI_EID_BASE);
}

struct sbiret sbi_get_marchid(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_get_marchid, SBI_EID_BASE);
}

struct sbiret sbi_get_mimpid(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_get_mimpid, SBI_EID_BASE);
}
