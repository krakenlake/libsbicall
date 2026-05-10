/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#pragma once
#include "config.h"

/*
 * integer registers
 */
#if XLEN == 32
	#define LOAD	lw
	#define	STORE	sw
	#define LWU		lw
	#define SWU		sw
#endif
#if XLEN == 64
	#define LOAD	ld
	#define	STORE	sd
	#define LWU		lwu
	#define SWU		swu
#endif
#define XLEN_BYTES			(XLEN/8)
#define NUM_INT_REGISTERS	32

/*
 * float registers
 */
#if FLEN == 32
	#define SAVE_F	fsw
	#define LOAD_F	flw
#endif
#if FLEN == 64
	#define	SAVE_F	fsd
	#define LOAD_F	fld
#endif
#define FLEN_BYTES				(FLEN/8)
#define NUM_FLOAT_REGISTERS		32
