/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/*
 * DBTR extension
 */

sbiret sbi_debug_num_triggers(unsigned long trig_tdata1)
{
	return sbicall(trig_tdata1, 0, 0, 0, 0, 0,
		SBI_FID_sbi_debug_num_triggers, SBI_EID_DBTR);
}

sbiret sbi_debug_set_shmem(unsigned long shmem_phys_lo,
								unsigned long shmem_phys_hi,
								unsigned long flags)
{
	return sbicall(shmem_phys_lo, shmem_phys_hi, flags, 0, 0, 0,
		SBI_FID_sbi_debug_set_shmem, SBI_EID_DBTR);
}

sbiret sbi_debug_read_triggers(unsigned long trig_idx_base,
								unsigned long trig_count)
{
	return sbicall(trig_idx_base, trig_count, 0, 0, 0, 0,
		SBI_FID_sbi_debug_read_triggers, SBI_EID_DBTR);
}

sbiret sbi_debug_install_triggers(unsigned long trig_count)
{
	return sbicall(trig_count, 0, 0, 0, 0, 0,
		SBI_FID_sbi_debug_install_triggers, SBI_EID_DBTR);
}

sbiret sbi_debug_update_triggers(unsigned long trig_count)
{
	return sbicall(trig_count, 0, 0, 0, 0, 0,
		SBI_FID_sbi_debug_update_triggers, SBI_EID_DBTR);
}

sbiret sbi_debug_uninstall_triggers(unsigned long trig_idx_base,
								unsigned long trig_idx_mask)
{
	return sbicall(trig_idx_base, trig_idx_mask, 0, 0, 0, 0,
		SBI_FID_sbi_debug_uninstall_triggers, SBI_EID_DBTR);
}

sbiret sbi_debug_enable_triggers(unsigned long trig_idx_base,
								unsigned long trig_idx_mask)
{
	return sbicall(trig_idx_base, trig_idx_mask, 0, 0, 0, 0,
		SBI_FID_sbi_debug_enable_triggers, SBI_EID_DBTR);
}

sbiret sbi_debug_disable_triggers(unsigned long trig_idx_base,
								unsigned long trig_idx_mask)
{
	return sbicall(trig_idx_base, trig_idx_mask, 0, 0, 0, 0,
		SBI_FID_sbi_debug_disable_triggers, SBI_EID_DBTR);
}
