# libsbicall - C wrapper library for RISC-V SBI

This C library wraps a thin layer of C code around SBI calls,
so that you can call C functions to communicate with SBI instead
of having to deal with `ecall` and assembly interfacing.

**Note**: SBI, being the **Supervisor** Binary Interface, can only be
called from **Supervisor** mode, so your executable needs to run in
**S-mode** in order for SBI calls to work. User-space executables,
like Linux applications, do never have access to SBI calls
(with or without library), so using libsbicall in any 
user-space programm **will not work**.

## Requirements
- riscv GNU toolchain for building

## Building

- check Makefile, especially the following settings:

`LIBSBICALL_TOOLBIN`

`LIBSBICALL_GCC_INC`

`LIBSBICALL_BUILDROOT`

`LIBSBICALL_RELEASE`

- `make`

Per default, the build process creates `libsbicall.a` in `../build/`.

## Usage
Include `include/libsbicall/sbicall.h` and Link with `libsbicall.a`

## Example Code

```
#include "libsbicall/sbicall.h"

int example(void)
{
	struct sbiret result = sbi_get_spec_version();

	if (!result.error) {
		// do something useful with result.value
	} else {
		// use check result.error for error code
	}

	return result.error;
}
```

### Specification

https://github.com/riscv-non-isa/riscv-sbi-doc
