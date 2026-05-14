.PHONY: default release clean

default: this

LIBSBICALL_VERSION = 0.9.2

LIBSBICALL_TARGET ?= qemu-64g
#LIBSBICALL_TARGET ?= vf2

LIBSBICALL_TARGET_XLEN ?= 64

# tools
LIBSBICALL_TOOLBIN	?= /usr/local/bin
LIBSBICALL_CC		?= $(LIBSBICALL_TOOLBIN)/riscv64-unknown-elf-gcc
LIBSBICALL_CPP		?= $(LIBSBICALL_TOOLBIN)/riscv64-unknown-elf-cpp
LIBSBICALL_AR		?= $(LIBSBICALL_TOOLBIN)/riscv64-unknown-elf-ar
LIBSBICALL_RANLIB	?= $(LIBSBICALL_TOOLBIN)/riscv64-unknown-elf-ranlib

# CFLAGS
CFLAGS += -DDEBUG
CFLAGS = -march=rv$(LIBSBICALL_TARGET_XLEN)g
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
LIBSBICALL_BUILDROOT	?= ../build
LIBSBICALL_BUILD		?= $(LIBSBICALL_BUILDROOT)/$(LIBSBICALL_TARGET)/$(LIBSBICALL_NAME)
LIBSBICALL_BUILDCONF	?= $(LIBSBICALL_BUILD)/$(LIBSBICALL_CONFIG)
LIBSBICALL_RELEASE		?= ../release/$(LIBSBICALL_TARGET)
LIBSBICALL_SRC			= $(wildcard ./src/*.c)
LIBSBICALL_OBJ			= $(LIBSBICALL_SRC:./src/%.c=$(LIBSBICALL_BUILD)/%.o)
LIBSBICALL_DEP			= $(LIBSBICALL_OBJ:%.o=%.d)

INCLUDES = -Iinclude

# dependencies
-include $(LIBSBICALL_DEP)


# targets
this: $(LIBSBICALL_BUILD)/$(LIBSBICALL_NAME).a Makefile
	@ls -ln $<

$(LIBSBICALL_BUILD) $(LIBSBICALL_RELEASE):
	mkdir -p $@

$(LIBSBICALL_BUILD)/$(LIBSBICALL_NAME).a: $(LIBSBICALL_BUILD) $(LIBSBICALL_OBJ) Makefile
	$(LIBSBICALL_AR) -r -u -v $@ $(LIBSBICALL_BUILD)/*.o
	$(LIBSBICALL_RANLIB) $@

$(LIBSBICALL_BUILD)/%.o: ./src/%.c Makefile
	$(LIBSBICALL_CC) $(LIBSBICALL_CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(LIBSBICALL_RELEASE)/$(LIBSBICALL_NAME)-$(LIBSBICALL_TARGET).a: $(LIBSBICALL_BUILD)/$(LIBSBICALL_NAME).a
	cp $< $@
	@ls -ln $@

release: Makefile $(LIBSBICALL_RELEASE) $(LIBSBICALL_RELEASE)/$(LIBSBICALL_NAME)-$(LIBSBICALL_TARGET).a

clean:
	rm -fr $(LIBSBICALL_BUILD)
