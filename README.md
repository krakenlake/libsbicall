# libsbicall - C wrapper library for RISC-V SBI

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
#include <stdio.h>
#include "libsbicall/sbicall.h"

int example(void)
{
	struct sbiret result = sbi_get_spec_version();

	if (!result.error) printf("SBI spec version: %lx", result.value);
		else printf("error %lx", result.error);

	return result.error;
}
```

### Specification

https://github.com/riscv-non-isa/riscv-sbi-doc
