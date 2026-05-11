/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/*
 * DBCN console extension
 */

struct sbiret sbi_debug_console_write(unsigned long num_bytes,
									unsigned long base_addr_lo,
									unsigned long base_addr_hi)
{
	return sbicall(num_bytes, base_addr_lo, base_addr_hi, 0, 0, 0,
		SBI_FID_sbi_debug_console_write, SBI_EID_DBCN);
}

struct sbiret sbi_debug_console_read(unsigned long num_bytes,
									unsigned long base_addr_lo,
									unsigned long base_addr_hi)
{
	return sbicall(num_bytes, base_addr_lo, base_addr_hi, 0, 0, 0,
		SBI_FID_sbi_debug_console_read, SBI_EID_DBCN);
}

struct sbiret sbi_debug_console_write_byte(uint8_t byte)
{
	return sbicall(byte, 0, 0, 0, 0, 0,
		SBI_FID_sbi_debug_console_write_byte, SBI_EID_DBCN);
}
