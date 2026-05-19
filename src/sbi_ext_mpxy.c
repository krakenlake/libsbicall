/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/*
 * MPXY extension
 */

sbiret sbi_mpxy_get_shmem_size(void)
{
	return sbicall(0, 0, 0, 0, 0, 0,
		SBI_FID_sbi_mpxy_get_shmem_size, SBI_EID_MPXY);
}

sbiret sbi_mpxy_set_shmem(unsigned long shmem_phys_lo,
							unsigned long shmem_phys_hi,
							unsigned long flags)
{
	return sbicall(shmem_phys_lo, shmem_phys_hi, flags, 0, 0, 0,
		SBI_FID_sbi_mpxy_set_shmem, SBI_EID_MPXY);
}

sbiret sbi_mpxy_get_channel_ids(uint32_t start_index)
{
	return sbicall(start_index, 0, 0, 0, 0, 0,
		SBI_FID_sbi_mpxy_get_channel_ids, SBI_EID_MPXY);
}

sbiret sbi_mpxy_read_attributes(uint32_t channel_id,
							uint32_t base_attribute_id,
							uint32_t attribute_count)
{
	return sbicall(channel_id, base_attribute_id, attribute_count, 0, 0, 0,
		SBI_FID_sbi_mpxy_read_attributes, SBI_EID_MPXY);
}

sbiret sbi_mpxy_write_attributes(uint32_t channel_id,
							uint32_t base_attribute_id,
							uint32_t attribute_count)
{
	return sbicall(channel_id, base_attribute_id, attribute_count, 0, 0, 0,
		SBI_FID_sbi_mpxy_write_attributes, SBI_EID_MPXY);
}

sbiret sbi_mpxy_send_message_with_response(uint32_t channel_id,
							uint32_t message_id,
							unsigned long message_data_len)
{
	return sbicall(channel_id, message_id, message_data_len, 0, 0, 0,
		SBI_FID_sbi_mpxy_send_message_with_response, SBI_EID_MPXY);
}

sbiret sbi_mpxy_send_message_without_response(uint32_t channel_id,
							uint32_t message_id,
							unsigned long message_data_len)
{
	return sbicall(channel_id, message_id, message_data_len, 0, 0, 0,
		SBI_FID_sbi_mpxy_send_message_without_response, SBI_EID_MPXY);
}

sbiret sbi_mpxy_get_notification_events(uint32_t channel_id)
{
	return sbicall(channel_id, 0, 0, 0, 0, 0,
		SBI_FID_sbi_mpxy_get_notification_events, SBI_EID_MPXY);
}
