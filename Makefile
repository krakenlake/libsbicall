.PHONY: default release clean

default: this

LIBSBICALL_VERSION = 0.9.1

LIBSBICALL_TARGET ?= qemu-64g
#LIBSBICALL_TARGET ?= vf2

LIBSBICALL_TARGET_XLEN ?= 64

# tools
LIBSBICALL_TOOLBIN	?= /usr/local/bin
LIBSBICALL_GCC_INC	?= /usr/local/Cellar/riscv-gnu-toolchain/main/riscv64-unknown-elf/include
LIBSBICALL_CC		?= $(LIBSBICALL_TOOLBIN)/riscv64-elf-gcc
LIBSBICALL_CPP		?= $(LIBSBICALL_TOOLBIN)/riscv64-elf-cpp
LIBSBICALL_AR		?= $(LIBSBICALL_TOOLBIN)/riscv64-elf-ar
LIBSBICALL_RANLIB	?= $(LIBSBICALL_TOOLBIN)/riscv64-elf-ranlib

# CFLAGS
CFLAGS = -march=rv$(LIBSBICALL_TARGET_XLEN)g
CFLAGS += -I"$(LIBSBICALL_SRCD)/include"
CFLAGS += -DDEBUG
CFLAGS += -DPLUTONIC_VERSION=\"$(PLUTONIC_VERSION)\"
# warnings
CFLAGS += -Wall -Werror -Wextra -pedantic
# warn if inline function cannot be substituted
CFLAGS += -Winline
# create position-independent code
CFLAGS += -fPIC
# create position-independent executables
CFLAGS += -fPIE
# gcc must not try to replace anything with built-in stuff
CFLAGS += -fno-builtin
# no crt0
CFLAGS += -nostartfiles
# optimisation
CFLAGS += -O2
# add debug symbols
CFLAGS += -g
LIBSBICALL_CFLAGS ?= $(CFLAGS) 

# names
LIBSBICALL_NAME			= $(notdir $(shell pwd))
LIBSBICALL_CONFIG		?= config
LIBSBICALL_BUILDROOT	?= ../build
LIBSBICALL_BUILD		?= $(LIBSBICALL_BUILDROOT)/$(LIBSBICALL_TARGET)/$(LIBSBICALL_NAME)
LIBSBICALL_BUILDCONF	?= $(LIBSBICALL_BUILD)/$(LIBSBICALL_CONFIG)
LIBSBICALL_RELEASE		?= ../release/$(LIBSBICALL_TARGET)
LIBSBICALL_SRC_S		= $(wildcard ./src/*.S)
LIBSBICALL_SRC_C		= $(wildcard ./src/*.c)
LIBSBICALL_SRC			= $(LIBSBICALL_SRC_S) $(LIBSBICALL_SRC_C)
LIBSBICALL_OBJ_S		= $(LIBSBICALL_SRC_S:./src/%.S=$(LIBSBICALL_BUILD)/%.o)
LIBSBICALL_OBJ_C		= $(LIBSBICALL_SRC_C:./src/%.c=$(LIBSBICALL_BUILD)/%.o)
LIBSBICALL_OBJ			= $(LIBSBICALL_OBJ_S) $(LIBSBICALL_OBJ_C)
LIBSBICALL_DEP			= $(LIBSBICALL_OBJ:%.o=%.d)

INCLUDES = -Iinclude -I$(LIBSBICALL_BUILD) -I$(LIBSBICALL_GCC_INC)

# dependencies
-include $(LIBSBICALL_DEP)


# targets
this: $(LIBSBICALL_BUILD)/$(LIBSBICALL_NAME).a Makefile
	@ls -ln $<

$(LIBSBICALL_BUILD) $(LIBSBICALL_RELEASE):
	mkdir -p $@

$(LIBSBICALL_BUILD)/$(LIBSBICALL_NAME).a: $(LIBSBICALL_BUILD) $(LIBSBICALL_OBJ) Makefile $(LIBSBICALL_BUILD)/config.h
	$(LIBSBICALL_AR) -r -u -v $@ $(LIBSBICALL_BUILD)/*.o
	$(LIBSBICALL_RANLIB) $@

$(LIBSBICALL_BUILD)/config.h: $(LIBSBICALL_CONFIG)/config.$(LIBSBICALL_TARGET).h
	cp -p $(LIBSBICALL_CONFIG)/config.$(LIBSBICALL_TARGET).h $@

$(LIBSBICALL_BUILD)/%.o: ./src/%.S Makefile $(LIBSBICALL_BUILD)/config.h
	$(LIBSBICALL_CC) $(LIBSBICALL_CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(LIBSBICALL_BUILD)/%.o: ./src/%.c Makefile $(LIBSBICALL_BUILD)/config.h
	$(LIBSBICALL_CC) $(LIBSBICALL_CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(LIBSBICALL_RELEASE)/$(LIBSBICALL_NAME)-$(LIBSBICALL_TARGET).a: $(LIBSBICALL_BUILD)/$(LIBSBICALL_NAME).a
	cp $< $@
	@ls -ln $@

release: Makefile $(LIBSBICALL_RELEASE) $(LIBSBICALL_RELEASE)/$(LIBSBICALL_NAME)-$(LIBSBICALL_TARGET).a

clean:
	rm -fr $(LIBSBICALL_BUILD)
