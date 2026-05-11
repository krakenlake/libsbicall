/*
 * libsbicall - RISC-V SBI wrapper
 *
 * Copyright (C) 2026 krakenlake
 *
 */
#include "libsbicall/sbicall.h"


/* list of all extensions */
const struct sbi_extension sbi_extensions[] = {
	{"LEGACY", SBI_EID_LEGACY},
	{"BASE", SBI_EID_BASE},
	{"TIME", SBI_EID_TIME},
	{"IPI", SBI_EID_IPI},
	{"RFNC", SBI_EID_RFNC},
	{"HSM", SBI_EID_HSM},
	{"SRST", SBI_EID_SRST},
	{"PMU", SBI_EID_PMU},
	{"DBCN", SBI_EID_DBCN},
	{"SUSP", SBI_EID_SUSP},
	{"CPPC", SBI_EID_CPPC},
	{"NACL", SBI_EID_NACL},
	{"STA", SBI_EID_STA},
	{"SSE", SBI_EID_SSE},
	{"FWFT", SBI_EID_FWFT},
	{"DBTR", SBI_EID_DBTR},
	{"MPXY", SBI_EID_MPXY}
};

/* number of extensions */
const int sbi_num_extensions = sizeof(sbi_extensions) / sizeof(struct sbi_extension);


/*
 * LEGACY extensions differ from rest
 */
inline long sbicall_legacy(unsigned long arg0, unsigned long arg1,
							unsigned long arg2, unsigned long arg3,
							unsigned long arg4, unsigned long arg5,
							long fid, long eid) 
{
	register unsigned long a0 __asm__("a0") = arg0;
	register unsigned long a1 __asm__("a1") = arg1;
	register unsigned long a2 __asm__("a2") = arg2;
	register unsigned long a3 __asm__("a3") = arg3;
	register unsigned long a4 __asm__("a4") = arg4;
	register unsigned long a5 __asm__("a5") = arg5;
	register unsigned long a6 __asm__("a6") = fid;
	register unsigned long a7 __asm__("a7") = eid;

	__asm__ __volatile__(
		"ecall"
		: "=r"(a0)
		: "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7)
		: "memory"
	);
	return (long)a0;
}


/*
 * other extensions use this
 */
inline struct sbiret sbicall(unsigned long arg0, unsigned long arg1, 
							unsigned long arg2, unsigned long arg3,
							unsigned long arg4, unsigned long arg5,
							long fid, long eid) 
{
	register unsigned long a0 __asm__("a0") = arg0;
	register unsigned long a1 __asm__("a1") = arg1;
	register unsigned long a2 __asm__("a2") = arg2;
	register unsigned long a3 __asm__("a3") = arg3;
	register unsigned long a4 __asm__("a4") = arg4;
	register unsigned long a5 __asm__("a5") = arg5;
	register unsigned long a6 __asm__("a6") = fid;
	register unsigned long a7 __asm__("a7") = eid;

	__asm__ __volatile__(
		"ecall"
		: "=r"(a0), "=r"(a1)
		: "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7)
		: "memory"
	);
	return (struct sbiret){.error = a0, .value = a1};
}
