/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 * based on:
 * RISC-V Supervisor Binary Interface Specification
 * Version v3.0, 2025-07-16: Ratified
 */
#pragma once

#define SBICALL_XLEN (sizeof(unsigned long)*8)

/*
 * Standard SBI Errors
 */
#define SBI_SUCCESS					0
#define SBI_ERR_FAILED				-1
#define SBI_ERR_NOT_SUPPORTED		-2
#define SBI_ERR_INVALID_PARAM		-3
#define SBI_ERR_DENIED				-4
#define SBI_ERR_INVALID_ADDRESS		-5
#define SBI_ERR_ALREADY_AVAILABLE	-6
#define SBI_ERR_ALREADY_STARTED		-7
#define SBI_ERR_ALREADY_STOPPED		-8
#define SBI_ERR_NO_SHMEM			-9
#define SBI_ERR_INVALID_STATE		-10
#define SBI_ERR_BAD_RANGE			-11
#define SBI_ERR_TIMEOUT				-12
#define SBI_ERR_IO					-13
#define SBI_ERR_DENIED_LOCKED		-14


/*
 * BASE extension
 */
#define SBI_EID_BASE					0x10

/* Functions */
#define SBI_FID_sbi_get_spec_version	0
#define SBI_FID_sbi_get_impl_id			1
#define SBI_FID_sbi_get_impl_version	2
#define SBI_FID_sbi_probe_extension		3
#define SBI_FID_sbi_get_mvendorid		4
#define SBI_FID_sbi_get_marchid			5
#define SBI_FID_sbi_get_mimpid			6


/*
 * LEGACY extensions
 */
#define SBI_EID_LEGACY								0

/* Functions */
#define SBI_FID_legacy_sbi_set_timer				0
#define SBI_FID_legacy_sbi_console_putchar			1
#define SBI_FID_legacy_sbi_console_getchar			2
#define SBI_FID_legacy_sbi_clear_ipi				3
#define SBI_FID_legacy_sbi_send_ipi					4
#define SBI_FID_legacy_sbi_remote_fence_i			5
#define SBI_FID_legacy_sbi_remote_sfence_vma		6
#define SBI_FID_legacy_sbi_remote_sfence_vma_asid	7
#define SBI_FID_legacy_sbi_shutdown					8


/*
 * TIME extension
 */
#define SBI_EID_TIME				0x54494D45

/* Functions */
#define SBI_FID_sbi_set_timer		0


/*
 * IPI (Inter-Processor Interrupts) extension
 */
#define SBI_EID_IPI					0x735049

/* Functions */
#define SBI_FID_sbi_send_ipi		0


/*
 * RFNC (RFENCE) extension
 */
#define SBI_EID_RFNC							0x52464E43

/* Functions */
#define SBI_FID_sbi_remote_fence_i				0
#define SBI_FID_sbi_remote_sfence_vma			1
#define SBI_FID_sbi_remote_sfence_vma_asid		2
#define SBI_FID_sbi_remote_hfence_gvma_vmid		3
#define SBI_FID_sbi_remote_hfence_gvma			4
#define SBI_FID_sbi_remote_hfence_vvma_asid		5
#define SBI_FID_sbi_remote_hfence_vvma			6


/*
 * HSM (Hart State Management) extension
 */
#define SBI_EID_HSM						0x48534D

/* Functions */
#define SBI_FID_sbi_hart_start			0
#define SBI_FID_sbi_hart_stop			1
#define SBI_FID_sbi_hart_get_status		2
#define SBI_FID_sbi_hart_suspend		3

/* HSM Hart States */
#define SBI_HSM_STATE_STARTED			0
#define SBI_HSM_STOPPED					1
#define SBI_HSM_START_PENDING			2
#define SBI_HSM_STOP_PENDING			3
#define SBI_HSM_SUSPENDED				4
#define SBI_HSM_SUSPEND_PENDING			5
#define SBI_HSM_RESUME_PENDING			6

/*
 * SRST (System Reset) extension
 */
#define SBI_EID_SRST					0x53525354

/* Functions */
#define SBI_FID_sbi_system_reset		0

/* SRST System Reset Types */
#define SBI_SRST_TYPE_SHUTDOWN			0x00000000
#define SBI_SRST_TYPE_COLD_REBOOT		0x00000001
#define SBI_SRST_TYPE_WARM_REBOOT		0x00000002

/* SRST System Reset Reasons */
#define SBI_SRST_REASON_NONE			0x00000000
#define SBI_SRST_REASON_SYSTEM_FAILURE	0x00000001


/*
 * PMU (Performance Monitoring Unit) extension
 */
#define SBI_EID_PMU						0x504D55

/* Functions */
#define SBI_FID_sbi_pmu_num_counters			0
#define SBI_FID_sbi_pmu_counter_get_info		1
#define SBI_FID_sbi_pmu_counter_config_matching	2
#define SBI_FID_sbi_pmu_counter_start			3
#define SBI_FID_sbi_pmu_counter_stop			4
#define SBI_FID_sbi_pmu_counter_fw_read			5
#define SBI_FID_sbi_pmu_counter_fw_read_hi		6
#define SBI_FID_sbi_pmu_snapshot_set_shmem		7
#define SBI_FID_sbi_pmu_event_get_info			8

/* PMU Event Type */
#define SBI_PMU_EVT_HW_GENERAL		0
#define SBI_PMU_EVT_HW_CACHE		1
#define SBI_PMU_EVT_HW_RAW_V1		2
#define SBI_PMU_EVT_HW_RAW_V2		3
#define SBI_PMU_EVT_FIRMWARE		4

/* PMU Hardware Events */
#define SBI_PMU_HW_NO_EVENT					0
#define SBI_PMU_HW_CPU_CYCLES				1
#define SBI_PMU_HW_INSTRUCTIONS				2
#define SBI_PMU_HW_CACHE_REFERENCES			3
#define SBI_PMU_HW_CACHE_MISSES				4
#define SBI_PMU_HW_BRANCH_INSTRUCTIONS		5
#define SBI_PMU_HW_BRANCH_MISSES			6
#define SBI_PMU_HW_BUS_CYCLES				7
#define SBI_PMU_HW_STALLED_CYCLES_FRONTEND	8
#define SBI_PMU_HW_STALLED_CYCLES_BACKEND	9
#define SBI_PMU_HW_REF_CPU_CYCLES			10

/* PMU Cache Event ID */
#define SBI_PMU_HW_CACHE_L1D	0
#define SBI_PMU_HW_CACHE_L1I	1
#define SBI_PMU_HW_CACHE_LL		2
#define SBI_PMU_HW_CACHE_DTLB	3
#define SBI_PMU_HW_CACHE_ITLB	4
#define SBI_PMU_HW_CACHE_BPU	5
#define SBI_PMU_HW_CACHE_NODE	6

/* PMU Cache Operation ID */
#define SBI_PMU_HW_CACHE_OP_READ		0
#define SBI_PMU_HW_CACHE_OP_WRITE		1
#define SBI_PMU_HW_CACHE_OP_PREFETCH	2

/* PMU Cache Operation Result ID */
#define SBI_PMU_HW_CACHE_RESULT_ACCESS	0
#define SBI_PMU_HW_CACHE_RESULT_MISS	1

/* PMU Cache Operation Result ID */
#define SBI_PMU_FW_MISALIGNED_LOAD				0	
#define SBI_PMU_FW_MISALIGNED_STORE				1
#define SBI_PMU_FW_ACCESS_LOAD					2
#define SBI_PMU_FW_ACCESS_STORE					3
#define SBI_PMU_FW_ILLEGAL_INSN					4
#define SBI_PMU_FW_SET_TIMER					5
#define SBI_PMU_FW_IPI_SENT						6
#define SBI_PMU_FW_IPI_RECEIVED					7
#define SBI_PMU_FW_FENCE_I_SENT					8
#define SBI_PMU_FW_FENCE_I_RECEIVED				9
#define SBI_PMU_FW_SFENCE_VMA_SENT				10
#define SBI_PMU_FW_SFENCE_VMA_RECEIVED			11
#define SBI_PMU_FW_SFENCE_VMA_ASID_SENT			12
#define SBI_PMU_FW_SFENCE_VMA_ASID_RECEIVED		13
#define SBI_PMU_FW_HFENCE_GVMA_SENT				14
#define SBI_PMU_FW_HFENCE_GVMA_RECEIVED			15
#define SBI_PMU_FW_HFENCE_GVMA_VMID_SENT		16
#define SBI_PMU_FW_HFENCE_GVMA_VMID_RECEIVED	17
#define SBI_PMU_FW_HFENCE_VVMA_SENT				18
#define SBI_PMU_FW_HFENCE_VVMA_RECEIVED			19
#define SBI_PMU_FW_HFENCE_VVMA_ASID_SENT		20
#define SBI_PMU_FW_HFENCE_VVMA_ASID_RECEIVED	21
	/* 22-255 reserved */
	/* 256-65534 Implementation specific events */
#define SBI_PMU_FW_PLATFORM						65535

/* PMU Counter Config Match Flags */
#define SBI_PMU_CFG_FLAG_SKIP_MATCH		(1 << 0)
#define SBI_PMU_CFG_FLAG_CLEAR_VALUE	(1 << 1)
#define SBI_PMU_CFG_FLAG_AUTO_START		(1 << 2)
#define SBI_PMU_CFG_FLAG_SET_VUINH		(1 << 3)
#define SBI_PMU_CFG_FLAG_SET_VSINH		(1 << 4)
#define SBI_PMU_CFG_FLAG_SET_UINH		(1 << 5)
#define SBI_PMU_CFG_FLAG_SET_SINH		(1 << 6)
#define SBI_PMU_CFG_FLAG_SET_MINH		(1 << 7)

/* PMU Counter Start Flags */
#define SBI_PMU_START_SET_INIT_VALUE		(1 << 0)
#define SBI_PMU_START_FLAG_INIT_SNAPSHOT	(1 << 1)

/* PMU Counter Stop Flags */
#define SBI_PMU_STOP_FLAG_RESET			(1 << 0)
#define SBI_PMU_STOP_FLAG_TAKE_SNAPSHOT	(1 << 1)


/*
 * DBCN (Debug Console) extension
 */
#define SBI_EID_DBCN							0x4442434E

/* Functions */
#define SBI_FID_sbi_debug_console_write			0
#define SBI_FID_sbi_debug_console_read			1
#define SBI_FID_sbi_debug_console_write_byte	2


/*
 * SUSP (System Suspend) extension
 */
#define SBI_EID_SUSP	0x53555350

/* Functions */
#define SBI_FID_sbi_system_suspend	0

/* SUSP System Sleep Types */
#define SBI_SUSPEND_TO_RAM	0


/*
 * CPPC (Collaborative Processor Performance Control) extension
 */
#define SBI_EID_CPPC	0x43505043

/* Functions */
#define SBI_FID_sbi_cppc_probe		0
#define SBI_FID_sbi_cppc_read		1
#define SBI_FID_sbi_cppc_read_hi	2
#define SBI_FID_sbi_cppc_write		3

/* CPPC Registers */
#define SBI_CPPC_HighestPerformance				0x00000000
#define SBI_CPPC_NominalPerformance				0x00000001
#define SBI_CPPC_LowestNonlinearPerformance		0x00000002
#define SBI_CPPC_LowestPerformance				0x00000003
#define SBI_CPPC_GuaranteedPerformance			0x00000004
#define SBI_CPPC_DesiredPerformance				0x00000005
#define SBI_CPPC_MinimumPerformance				0x00000006
#define SBI_CPPC_MaximumPerformance				0x00000007
#define SBI_CPPC_PerformanceReductionTolerance	0x00000008
#define SBI_CPPC_TimeWindow						0x00000009
#define SBI_CPPC_CounterWraparoundTime			0x0000000a
#define SBI_CPPC_ReferencePerformanceCounter	0x0000000b
#define SBI_CPPC_DeliveredPerformanceCounter	0x0000000c
#define SBI_CPPC_PerformanceLimited				0x0000000d
#define SBI_CPPC_CPPCEnable						0x0000000e
#define SBI_CPPC_AutonomousSelectionEnable		0x0000000f
#define SBI_CPPC_AutonomousActivityWindow		0x00000010
#define SBI_CPPC_EnergyPerformancePreference	0x00000011
#define SBI_CPPC_ReferencePerformance			0x00000012
#define SBI_CPPC_LowestFrequency				0x00000013
#define SBI_CPPC_NominalFrequency				0x00000014
#define SBI_CPPC_TransitionLatency				0x80000000


/*
 * NACL (Nested Acceleration) extension
 */
#define SBI_EID_NACL	0x4E41434C

/* Functions */
#define SBI_FID_sbi_nacl_probe_feature	0
#define SBI_FID_sbi_nacl_set_shmem		1
#define SBI_FID_sbi_nacl_sync_csr		2
#define SBI_FID_sbi_nacl_sync_hfence	3
#define SBI_FID_sbi_nacl_sync_sret		4

/* Nested acceleration features */
#define SBI_NACL_FEAT_SYNC_CSR		0x00000000
#define SBI_NACL_FEAT_SYNC_HFENCE	0x00000001
#define SBI_NACL_FEAT_SYNC_SRET		0x00000002
#define SBI_NACL_FEAT_AUTOSWAP_CSR	0x00000003


/*
 * STA (Steal-time Accounting) extension
 */
#define SBI_EID_STA		0x535441

/* Functions */
#define SBI_FID_sbi_steal_time_set_shmem	0


/*
 * SSE (Supervisor Software Events) extension
 */
#define SBI_EID_SSE		0x535345

/* Functions */
#define SBI_FID_sbi_sse_read_attrs		0
#define SBI_FID_sbi_sse_write_attrs		1
#define SBI_FID_sbi_sse_register		2
#define SBI_FID_sbi_sse_unregister		3
#define SBI_FID_sbi_sse_enable			4
#define SBI_FID_sbi_sse_disable			5
#define SBI_FID_sbi_sse_complete		6
#define SBI_FID_sbi_sse_inject			7
#define SBI_FID_sbi_sse_hart_unmask		8
#define SBI_FID_sbi_sse_hart_mask		9

/* SSE Event Attributes */
#define SBI_SSE_STATUS				0x00000000
#define SBI_SSE_PRIORITY			0x00000001
#define SBI_SSE_CONFIG				0x00000002
#define SBI_SSE_PREFERRED_HART		0x00000003
#define SBI_SSE_ENTRY_PC			0x00000004
#define SBI_SSE_ENTRY_ARG			0x00000005
#define SBI_SSE_INTERRUPTED_SEPC	0x00000006
#define SBI_SSE_INTERRUPTED_FLAGS	0x00000007
#define SBI_SSE_INTERRUPTED_A6		0x00000008
#define SBI_SSE_INTERRUPTED_A7		0x00000009

/*
 * FWFT (SBI Firmware Features) extension
 */
#define SBI_EID_FWFT	0x46574654

/* Functions */
#define SBI_FID_sbi_fwft_set	0
#define SBI_FID_sbi_fwft_get	1

/* FWFT Feature Types */
#define SBI_MISALIGNED_EXC_DELEG	0x00000000
#define SBI_LANDING_PAD				0x00000001
#define SBI_SHADOW_STACK			0x00000002
#define SBI_DOUBLE_TRAP				0x00000003
#define SBI_PTE_AD_HW_UPDATING		0x00000004
#define SBI_POINTER_MASKING_PMLEN	0x00000005

/*
 * DBTR (Debug Triggers) extension
 */
#define SBI_EID_DBTR	0x44425452

/* Functions */
#define SBI_FID_sbi_debug_num_triggers			0
#define SBI_FID_sbi_debug_set_shmem				1
#define SBI_FID_sbi_debug_read_triggers			2
#define SBI_FID_sbi_debug_install_triggers		3
#define SBI_FID_sbi_debug_update_triggers		4
#define SBI_FID_sbi_debug_uninstall_triggers	5
#define SBI_FID_sbi_debug_enable_triggers		6
#define SBI_FID_sbi_debug_disable_triggers		7

/*
 * MPXY (Message Proxy) extension
 */
#define SBI_EID_MPXY	0x4D505859

/* Functions */
#define SBI_FID_sbi_mpxy_get_shmem_size					0
#define SBI_FID_sbi_mpxy_set_shmem						1
#define SBI_FID_sbi_mpxy_get_channel_ids				2
#define SBI_FID_sbi_mpxy_read_attributes				3
#define SBI_FID_sbi_mpxy_write_attributes				4
#define SBI_FID_sbi_mpxy_send_message_with_response		5
#define SBI_FID_sbi_mpxy_send_message_without_response	6
#define SBI_FID_sbi_mpxy_get_notification_events		7

/* MPXY Channel Attributes */
#define SBI_MSG_PROT_ID				0x00000000
#define SBI_MSG_PROT_VERSION		0x00000001
#define SBI_MSG_DATA_MAX_LEN		0x00000002
#define SBI_MSG_SEND_TIMEOUT		0x00000003
#define SBI_MSG_COMPLETION_TIMEOUT	0x00000004
#define SBI_CHANNEL_CAPABILITY		0x00000005
#define SBI_SSE_EVENT_ID			0x00000006
#define SBI_MSI_CONTROL				0x00000007
#define SBI_MSI_ADDR_LOW			0x00000008
#define SBI_MSI_ADDR_HIGH			0x00000009
#define SBI_MSI_DATA				0x0000000a
#define SBI_EVENTS_STATE_CONTROL	0x0000000b

/* MPXY Message Protocol IDs */
#define SBI_MSG_PROT_RPMI			0x00000000

/* MPXY Shared Memory Setup Mode */
#define SBI_MPXY_OVERWRITE			0b00
#define SBI_MPXY_OVERWRITE_RETURN	0b01


/*
 * C forward declarations
 */
#ifndef __ASSEMBLER__

	/* C99 types like uint64_t are defined here */
	#include <stdint.h>

	/* extensions bookkeeping */
	struct sbi_extension {
		char name[8];
		unsigned int eid;
	};

	extern const struct sbi_extension sbi_extensions[];
	extern const int sbi_num_extensions;

	/* calls return this */
	struct sbiret {
		long error;
		union {
			long value;
			unsigned long uvalue;
		};
	};

	/* ecalls */
	long sbicall_legacy(unsigned long arg0, unsigned long arg1,
					unsigned long arg2, unsigned long arg3,
					unsigned long arg4, unsigned long arg5,
					long fid, long eid);

	struct sbiret sbicall(unsigned long arg0, unsigned long arg1,
					unsigned long arg2, unsigned long arg3,
					unsigned long arg4, unsigned long arg5,
					long fid, long eid);


	/* BASE */
	struct sbiret sbi_get_spec_version(void);
	struct sbiret sbi_get_impl_id(void);
	struct sbiret sbi_get_impl_version(void);
	struct sbiret sbi_probe_extension(long extension_id);
	struct sbiret sbi_get_mvendorid(void);
	struct sbiret sbi_get_marchid(void);
	struct sbiret sbi_get_mimpid(void);

	/* LEGACY */
	long legacy_sbi_set_timer(uint64_t stime_value);
	long legacy_sbi_console_putchar(int c);
	long legacy_sbi_console_getchar(void);
	long legacy_sbi_clear_ipi(void);
	long legacy_sbi_send_ipi(const unsigned long *hart_mask);
	long legacy_sbi_remote_fence_i(const unsigned long *hart_mask);
	long legacy_sbi_remote_sfence_vma(const unsigned long *hart_mask, 
									unsigned long start,
									unsigned long size);
	long legacy_sbi_remote_sfence_vma_asid(const unsigned long *hart_mask,
									unsigned long start,
									unsigned long size,
									unsigned long asid);

	/* TIME */
	struct sbiret sbi_set_timer(uint64_t stime_value);

	/* IPI */
	struct sbiret sbi_send_ipi(unsigned long hart_mask,
							unsigned long hart_mask_base);

	/* RFNC */
	struct sbiret sbi_remote_fence_i(unsigned long hart_mask,
									unsigned long hart_mask_base);
	struct sbiret sbi_remote_sfence_vma(unsigned long hart_mask,
									unsigned long hart_mask_base,
									unsigned long start_addr,
									unsigned long size);
	struct sbiret sbi_remote_sfence_vma_asid(unsigned long hart_mask,
									unsigned long hart_mask_base,
									unsigned long start_addr,
									unsigned long size,
									unsigned long asid);
	struct sbiret sbi_remote_hfence_gvma_vmid(unsigned long hart_mask,
									unsigned long hart_mask_base,
									unsigned long start_addr,
									unsigned long size,
									unsigned long vmid);
	struct sbiret sbi_remote_hfence_gvma(unsigned long hart_mask,
									unsigned long hart_mask_base,
									unsigned long start_addr,
									unsigned long size);
	struct sbiret sbi_remote_hfence_vvma_asid(unsigned long hart_mask,
									unsigned long hart_mask_base,
									unsigned long start_addr,
									unsigned long size,
									unsigned long asid);
	struct sbiret sbi_remote_hfence_vvma(unsigned long hart_mask,
									unsigned long hart_mask_base,
									unsigned long start_addr,
									unsigned long size);

	/* HSM */
	struct sbiret sbi_hart_start(unsigned long hartid,
							unsigned long start_addr,
							unsigned long opaque);	
	struct sbiret sbi_hart_stop(void);
	struct sbiret sbi_hart_get_status(unsigned long hartid);
	struct sbiret sbi_hart_suspend(uint32_t suspend_type,
							unsigned long resume_addr,
							unsigned long opaque);

	/* SRST */
	struct sbiret sbi_system_reset(uint32_t reset_type, uint32_t reset_reason);

	/* PMU */
	struct sbiret sbi_pmu_num_counters(void);
	struct sbiret sbi_pmu_counter_get_info(unsigned long counter_idx);
	struct sbiret sbi_pmu_counter_config_matching(unsigned long counter_idx_base,
									unsigned long counter_idx_mask,
									unsigned long config_flags,
									unsigned long event_idx,
									uint64_t event_data);
	struct sbiret sbi_pmu_counter_start(unsigned long counter_idx_base,
									unsigned long counter_idx_mask,
									unsigned long start_flags,
									uint64_t initial_value);
	struct sbiret sbi_pmu_counter_stop(unsigned long counter_idx_base,
									unsigned long counter_idx_mask,
									unsigned long stop_flags);
	struct sbiret sbi_pmu_counter_fw_read(unsigned long counter_idx);
	struct sbiret sbi_pmu_counter_fw_read_hi(unsigned long counter_idx);
	struct sbiret sbi_pmu_snapshot_set_shmem(unsigned long shmem_phys_lo,
									unsigned long shmem_phys_hi,
									unsigned long flags);
	struct sbiret sbi_pmu_event_get_info(unsigned long shmem_phys_lo,
									unsigned long shmem_phys_hi,
									unsigned long num_entries,
									unsigned long flags);

	/* DBCN */
	struct sbiret sbi_debug_console_write(unsigned long num_bytes,
									unsigned long base_addr_lo, 
									unsigned long base_addr_hi);
	struct sbiret sbi_debug_console_read(unsigned long num_bytes,
									unsigned long base_addr_lo, 
									unsigned long base_addr_hi);
	struct sbiret sbi_debug_console_write_byte(uint8_t byte);

	/* SUSP */
	struct sbiret sbi_system_suspend(uint32_t sleep_type,
									unsigned long resume_addr,
									unsigned long opaque);

	/* CPPC */
	struct sbiret sbi_cppc_probe(uint32_t cppc_reg_id);
	struct sbiret sbi_cppc_read(uint32_t cppc_reg_id);
	struct sbiret sbi_cppc_read_hi(uint32_t cppc_reg_id);
	struct sbiret sbi_cppc_write(uint32_t cppc_reg_id, uint64_t val);

	/* NACL */
	struct sbiret sbi_nacl_probe_feature(uint32_t feature_id);
	struct sbiret sbi_nacl_set_shmem(unsigned long shmem_phys_lo,
									unsigned long shmem_phys_hi,
									unsigned long flags);
	struct sbiret sbi_nacl_sync_csr(unsigned long csr_num);
	struct sbiret sbi_nacl_sync_hfence(unsigned long entry_index);
	struct sbiret sbi_nacl_sync_sret(void);

	/* STA */
	struct sbiret sbi_steal_time_set_shmem(unsigned long shmem_phys_lo,
									unsigned long shmem_phys_hi,
									unsigned long flags);

	/* SSE */
	struct sbiret sbi_sse_read_attrs(uint32_t event_id,
									uint32_t base_attr_id, 
									uint32_t attr_count,
									unsigned long output_phys_lo,
									unsigned long output_phys_hi);
	struct sbiret sbi_sse_write_attrs(uint32_t event_id,
									uint32_t base_attr_id, 
									uint32_t attr_count,
									unsigned long input_phys_lo,
									unsigned long input_phys_hi);
	struct sbiret sbi_sse_register(uint32_t event_id,
									unsigned long handler_entry_pc,
									unsigned long handler_entry_arg);
	struct sbiret sbi_sse_unregister(uint32_t event_id);
	struct sbiret sbi_sse_enable(uint32_t event_id);
	struct sbiret sbi_sse_disable(uint32_t event_id);
	struct sbiret sbi_sse_complete(void);
	struct sbiret sbi_sse_inject(uint32_t event_id, unsigned long hart_id);
	struct sbiret sbi_sse_hart_unmask(void);
	struct sbiret sbi_sse_hart_mask(void);

	/* FWFT */
	struct sbiret sbi_fwft_set(uint32_t feature,
							unsigned long value,
							unsigned long flags);
	struct sbiret sbi_fwft_get(uint32_t feature);

	/* DBTR */
	struct sbiret sbi_debug_num_triggers(unsigned long trig_tdata1);
	struct sbiret sbi_debug_set_shmem(unsigned long shmem_phys_lo,
										unsigned long shmem_phys_hi,
										unsigned long flags);
	struct sbiret sbi_debug_read_triggers(unsigned long trig_idx_base,
										unsigned long trig_count);
	struct sbiret sbi_debug_install_triggers(unsigned long trig_count);
	struct sbiret sbi_debug_update_triggers(unsigned long trig_count);
	struct sbiret sbi_debug_uninstall_triggers(unsigned long trig_idx_base,
										unsigned long trig_idx_mask);
	struct sbiret sbi_debug_enable_triggers(unsigned long trig_idx_base,
										unsigned long trig_idx_mask);
	struct sbiret sbi_debug_disable_triggers(unsigned long trig_idx_base,
										unsigned long trig_idx_mask);

	/* MPXY*/	
	struct sbiret sbi_mpxy_get_shmem_size(void);
	struct sbiret sbi_mpxy_set_shmem(unsigned long shmem_phys_lo,
									unsigned long shmem_phys_hi,
									unsigned long flags);
	struct sbiret sbi_mpxy_get_channel_ids(uint32_t start_index);
	struct sbiret sbi_mpxy_read_attributes(uint32_t channel_id,
									uint32_t base_attribute_id,
									uint32_t attribute_count);
	struct sbiret sbi_mpxy_write_attributes(uint32_t channel_id,
									uint32_t base_attribute_id,
									uint32_t attribute_count);
	struct sbiret sbi_mpxy_send_message_with_response(uint32_t channel_id,
									uint32_t message_id,
									unsigned long message_data_len);
	struct sbiret sbi_mpxy_send_message_without_response(uint32_t channel_id,
									uint32_t message_id,
									unsigned long message_data_len);
	struct sbiret sbi_mpxy_get_notification_events(uint32_t channel_id);


	struct sbi_event_idx_code {
		unsigned long result_id : 1;
		unsigned long op_id : 2;
		unsigned long cache_id : 13;
		unsigned long unused : SBICALL_XLEN-1-2-13;
	};
	
	struct sbi_event_idx {
		unsigned long code : 16;
		unsigned long type : 4;
		unsigned long unused : SBICALL_XLEN-16-4;
	};

	struct counter_info {
		unsigned long CSR : 12;
		unsigned long width: 6;
		unsigned long reserved: SBICALL_XLEN-12-6-1;
		unsigned long type : 1;
	};

#endif /* __ASSEMBLER__ */
