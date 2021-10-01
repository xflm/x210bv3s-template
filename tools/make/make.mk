###############################################################################
# Verison: v2.1.0
# Author:  xflm
# Date:    Fri Feb 26 17:03:14 CST 2021
###############################################################################

###############################################################################
# Define env
SHELL = /bin/bash

# Print bold format word, if console not support, note it.
PRINT_COLOR_OFF = "\\033[0m"
PRINT_BOLD = "\\033[1m"

# Build dir
BUILD_DIR ?= build

# Obj dir
OBJ_DIR ?= $(BUILD_DIR)/.obj

# Target dir
ifeq ($(FILE_PWD),)
TARGET_DIR := $(BUILD_DIR)
FILE_PWD = .
else
TARGET_DIR := $(BUILD_DIR)/$(FILE_PWD)
endif

###############################################################################
# Define global flags
CFLAGS += -c -MMD
CFLAGS += -W -Wall
CFLAGS += -std=gnu99
CFLAGS += -fno-builtin
# If macro has space, need add -D manually
CFLAGS += -DBUILD_NAME="\"$(TARGET)\""
CFLAGS += -DBUILD_DATE="\"$(shell LANG=en_US.UTF-8 date)\""
CFLAGS += -DBUILD_AUTH="\"$(USER)\""

# Define file.mk path
FILEMK := $(FILE_PWD)/file.mk

###############################################################################
# Define target file name
ifneq ($(TARGET_TYPE),lib)
ifeq ($(TARGET_TYPE),exe)
ifeq ($(OS),Windows_NT)
TARGET_ELF = $(TARGET_DIR)/$(TARGET).exe
else
TARGET_ELF = $(TARGET_DIR)/$(TARGET)
endif
else
TARGET_ELF = $(TARGET_DIR)/$(TARGET).elf
endif
ifeq ($(CREATE_DIS),y)
TARGET_DIS = $(TARGET_DIR)/$(TARGET).dis
endif
ifeq ($(CREATE_ASM),y)
TARGET_ASM = $(TARGET_DIR)/$(TARGET).asm
endif
ifeq ($(CREATE_BIN),y)
TARGET_BIN = $(TARGET_DIR)/$(TARGET).bin
endif
ifeq ($(CREATE_HEX),y)
TARGET_HEX = $(TARGET_DIR)/$(TARGET).hex
endif
ifeq ($(CREATE_MAP),y)
TARGET_MAP = $(TARGET_DIR)/$(TARGET).map
endif
ifeq ($(CREATE_GC),y)
TARGET_GC = $(TARGET_DIR)/$(TARGET).gc
endif
else
# create lib
TARGET_LIB = $(TARGET_DIR)/lib$(TARGET).a
endif

# Create header list file, it must be exited
TARGET_INC = $(OBJ_DIR)/$(TARGET).inc

###############################################################################
ifneq ($(BUILD_TYPE),)
ifeq ($(BUILD_TYPE),debug)
CFLAGS += -O2 -g3
STRIPFLAGS = 
else
ifeq ($(GARBAGE_COLLECTION),y)
CFLAGS += -ffunction-sections -fdata-sections
LDFLAGS += -Wl,--gc-sections
endif
ifeq ($(BUILD_TYPE),profile)
CFLAGS += -O2 -g3
STRIPFLAGS = 
else
CFLAGS += -O2
STRIPFLAGS = --strip-unneeded
endif
endif
endif

INCFLAGS = $(addprefix -I, $(INC_PATH))
DEFINES += $(USERDEFINES)
CPU += $(USERCPU)
STDLIB += $(USERSTDLIB)
DEFINEFLAGS = $(addprefix -D, $(BOARD) $(DEFINES))
CFLAGS  += $(CPU) $(INCFLAGS) $(DEFINEFLAGS)
LDFLAGS += $(CPU)
ifeq ($(TARGET_TYPE),elf)
LDFLAGS += -T$(LINK_FILE)
LDFLAGS += -static -nostartfiles
else
LINK_FILE =
endif

ifneq ($(TARGET_MAP),)
# Create cross reference table and map file
LDFLAGS += -Wl,--cref,-Map=$(TARGET_MAP)
endif
CFLAGS  += $(USERCFLAGS)
LDFLAGS += $(USERLDFLAGS)

###############################################################################
# This is base target
.PHONY: all debug FORCE
# This expend function target
.PHONY: clone create files help qt slim tags
# Avoid create target file
.PHONY: all_before 

###############################################################################
# Default target
all: all_before all_done
	@$(CMD_AFTER)

###############################################################################
# Include file list, it must immediate
ASM_FILE := 
SRC_FILE :=
INC_PATH :=
LIB_FILE :=
OTHER_FILE :=
SPARE_FILE :=
LIB_ASM_FILE :=
LIB_SRC_FILE :=
LIB_DEPEND_FILE :=
VPATH_SRC_FILE :=
VPATH_ASM_FILE :=
LIB_DONE := 

###############################################################################
# Prerequisites
SPARE_FILE += $(TEMPLATE)/tools/bash/create.sh
SPARE_FILE += $(TEMPLATE)/tools/make/makefile

###############################################################################
# Include file.mk
include $(FILEMK)

###############################################################################
# export var
ifeq ($(MAKELEVEL), 0)
export G_TOOLCHAIN = $(TOOLCHAIN)
export G_TEMPLATE = $(TEMPLATE)
export G_BOARD = $(BOARD)
export G_BUILD_TYPE = $(BUILD_TYPE)
export G_INC_PATH = $(INC_PATH)
export G_INCFLAGS = $(INCFLAGS)
export G_DEFINES = $(DEFINES)
export G_CPU = $(CPU)
endif

###############################################################################
# Define toolchain
CC = $(TOOLCHAIN)gcc
AS = $(TOOLCHAIN)as
AR = $(TOOLCHAIN)ar
LD = $(TOOLCHAIN)ld
NM = $(TOOLCHAIN)nm
GDB = $(TOOLCHAIN)gdb
SIZE = $(TOOLCHAIN)size
STRIP = $(TOOLCHAIN)strip
OBJDUMP = $(TOOLCHAIN)objdump
OBJCOPY = $(TOOLCHAIN)objcopy

###############################################################################
# Create object file name
ifeq ($(VPATH_MODE),)
OBJ_FILE  = $(foreach n, $(SRC_FILE), $(OBJ_DIR)/$(n).o)
OBJ_FILE += $(foreach n, $(ASM_FILE), $(OBJ_DIR)/$(n).o)
else
OBJ_FILE  = $(foreach n, $(notdir $(SRC_FILE)), $(OBJ_DIR)/$(n).o)
OBJ_FILE += $(foreach n, $(notdir $(ASM_FILE)), $(OBJ_DIR)/$(n).o)
$(shell mkdir -p $(OBJ_DIR))
endif

# Include *.d file
DEPEND_FILE = $(OBJ_FILE:%.o=%.d)

# GDB init file
GDBINIT = $(wildcard .gdbinit)

# Create source file path
SRC_PATH = $(sort $(dir $(SRC_FILE) $(LIB_SRC_FILE)))
# Create asm file path
ASM_PATH = $(sort $(dir $(ASM_FILE) $(LIB_ASM_FILE)))

###############################################################################
# Compile echo
define compile_echo_cmd
echo -e "$(PRINT_BOLD)->$(PRINT_COLOR_OFF) $<"
endef

###############################################################################
# Library done, each -n let make output nothing when nothing to do.
LIBRARY_DONE = echo -n$(foreach n, $(LIB_DONE), ;$(MAKE) $(1) \
--no-print-directory -f $(n)/makefile FILE_PWD=$(n))

###############################################################################
# If some target depend on FORCE, it will be done anytime
FORCE:

###############################################################################
# Check depend(*.d) files, this must after target all
-include $(DEPEND_FILE)

###############################################################################
# Run cmd before compile, this only used by target: all, echo -n let make don't
# print "Nothing to be done for" message.
all_before:
	@ echo -n
	@$(CMD_BEFORE)

###############################################################################
# When defining the "all" target, TARGET_LIB and TARGET_ELF have not been 
# defined yet, so write here
all_done: $(TARGET_LIB) $(TARGET_ELF)

###############################################################################
# Updata GDBINIT file
$(GDBINIT): Makefile
ifeq ($(RUN_TYPE),ram)
	@sed -i "s|^\s*file\b.*|file $(TARGET_ELF)|g; \
      s|^\s*set.*debug_in_rom.*|set $$""debug_in_rom = 0|g; \
      s|^\s*source \..*/tools/gdb/|source $(TEMPLATE)/tools/gdb/|g" .gdbinit
else
	@sed -i "s|^\s*file\b.*|file $(TARGET_ELF)|g; \
      s|^\s*set.*debug_in_rom.*|set $$""debug_in_rom = 1|g; \
      s|^\s*source \..*/tools/gdb/|source $(TEMPLATE)/tools/gdb/|g" .gdbinit
endif

###############################################################################
# Create ELF file
$(TARGET_ELF): $(OBJ_FILE) $(LIB_FILE) $(LINK_FILE) $(GDBINIT)
	@$(CC) -o $(TARGET_ELF) $(LDFLAGS) $(OBJ_FILE) $(LIB_FILE) $(STDLIB)
ifneq ($(TARGET_GC),)
	@$(CC) -o $(TARGET_ELF) $(LDFLAGS) $(OBJ_FILE) $(LIB_FILE) $(STDLIB) \
-Wl,--print-gc-sections 2>&1 | grep $(BUILD_DIR) | sed "s/.*section //g" \
> $(TARGET_GC)
endif
ifneq ($(TARGET_DIS),)
	@$(OBJDUMP) -d $(TARGET_ELF) > $(TARGET_DIS)
endif
ifneq ($(TARGET_ASM),)
	@$(OBJDUMP) -S $(TARGET_ELF) > $(TARGET_ASM)
endif
ifneq ($(TARGET_BIN),)
	@$(OBJCOPY) -O binary $(TARGET_ELF)  $(TARGET_BIN)
endif
ifneq ($(TARGET_HEX),)
	@$(OBJCOPY) -O ihex $(TARGET_ELF)  $(TARGET_HEX)
endif
ifneq ($(STRIPFLAGS),)
	@$(STRIP) $(STRIPFLAGS) $(TARGET_ELF)
endif
# If PRINT_BOLD has ';', then echo two '"'.
	@echo -e "$(PRINT_BOLD)Complete !!!$(PRINT_COLOR_OFF)"
	@MLDS=$$($(NM) $(TARGET_ELF) 2> /dev/null | grep _mlds_ | tr ' ' '-'); \
    if [[ ! -z "$$MLDS" ]]; then MLDS_ADDR=$$(echo "$$MLDS" | grep addr_mlds_addr_); \
    if [[ ! -z "$$MLDS_ADDR" ]]; then MLDS=$$(echo "$$MLDS" | grep -v addr_mlds_addr_); \
    for i in $$MLDS_ADDR; do echo 0x$${i/-*addr_mlds_addr_/ }; done; fi; \
    MLDS_HEAD="type"; MLDS_USED="used"; MLDS_UNUSED="unused"; j=0; \
    for i in $$MLDS; do if [[ j -eq 0 ]]; then MLDS_HEAD+=","$${i##*_mlds_unused_}; \
    MLDS_UNUSED+=","$$((0x$${i%%-*})); j=1; else j=0; MLDS_USED+=","$$((0x$${i%%-*})); \
    fi; done; MLDS_HEAD+=",file"; MLDS_USED+=",$(RUN_TYPE) $(BUILD_TYPE)"; \
    MLDS_UNUSED+=",$(TARGET_ELF)"; echo $$MLDS_HEAD"^"$$MLDS_USED"^"$$MLDS_UNUSED"^" | \
    tr '^' '\n' | column -s ',' -t; else $(SIZE) $(TARGET_ELF); fi

###############################################################################
# Create LIB file
$(TARGET_LIB): $(OBJ_FILE) $(LIB_FILE)
ifeq ($(LIB_FILE),)
	@$(AR) cr $(TARGET_LIB) $(OBJ_FILE)
else
	@mkdir -p $(TARGET_DIR)/.libobj; LAYER=$$(echo $(TARGET_DIR)/.libobj/ | \
sed "s|[^/]*/|../|g"); cd $(TARGET_DIR)/.libobj; for i in $(LIB_FILE); \
do $(AR) x $$LAYER$$i; done; cd $$OLDPWD
	@$(AR) cr $(TARGET_LIB) $$(find $(TARGET_DIR)/.libobj -type f) $(OBJ_FILE)
endif
ifneq ($(STRIPFLAGS),)
	@$(STRIP) $(STRIPFLAGS) $(TARGET_LIB)
endif
	@echo -e "$(PRINT_BOLD)Complete !!!$(PRINT_COLOR_OFF)"
	@$(SIZE) $(TARGET_LIB)

ifeq ($(VPATH_MODE),)
###############################################################################
# Compile asm file
$(OBJ_DIR)/%.S.o: %.S 
	@$(compile_echo_cmd)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ $<

###############################################################################
# Compile c file
$(OBJ_DIR)/%.c.o: %.c
	@$(compile_echo_cmd)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ $<
else  # ifneq ($(VPATH_MODE),)
vpath %.S $(ASM_PATH)
vpath %.c $(SRC_PATH)

###############################################################################
# Compile asm file
$(OBJ_DIR)/%.S.o: %.S
	@$(compile_echo_cmd)
	@$(CC) $(CFLAGS) -o $@ $<

###############################################################################
# Compile c file
$(OBJ_DIR)/%.c.o: %.c
	@$(compile_echo_cmd)
	@$(CC) $(CFLAGS) -o $@ $<
endif # ifeq ($(VPATH_MODE),)

###############################################################################
# Compile lib file, it should be done anytime
$(BUILD_DIR)/%.a: FORCE
	@mkdir -p $(@D)
	@$(MAKE) --no-print-directory -f $(*D)/makefile FILE_PWD=$(*D)

###############################################################################
# Get *.h file name, and write to TARGET_INC, grep "\.h" at the end may be faster.
# If no *.h file in project, grep "\.h" will be return 1, make will be stop, so do
# echo -n at the end, it will be return 0. If no elf file, means *.d file invalid,
# so find *.h file directly
$(TARGET_INC): FORCE
ifeq ($(wildcard $(TARGET_ELF) $(TARGET_LIB)),)
	@mkdir -p $(OBJ_DIR)
	@echo $(wildcard $(addsuffix /*.h, $(INC_PATH))) | tr ' ' '\n' > $(TARGET_INC)
else
	@cat $(DEPEND_FILE) $(LIB_DEPEND_FILE) | tr ' ' '\n' | sort -u | grep "\.h" > $(TARGET_INC); \
	echo -n
endif

###############################################################################
# Clean all create file
clean:
	@$(RM) -r $(BUILD_DIR)

###############################################################################
# Start debug procedure
debug:
ifneq ($(TARGET_TYPE),lib)
	@$(GDB) -q $(TARGET_ELF)
endif

###############################################################################
# Add auxiliary function
-include $(TEMPLATE)/tools/make/clone.mk
-include $(TEMPLATE)/tools/make/create.mk
-include $(TEMPLATE)/tools/make/files.mk
-include $(TEMPLATE)/tools/make/help.mk
-include $(TEMPLATE)/tools/make/qt.mk
-include $(TEMPLATE)/tools/make/slim.mk
-include $(TEMPLATE)/tools/make/tags.mk
-include $(TEMPLATE)/tools/make/sd.mk
