###############################################################################
# Version: v2.1.0
# Author:  xflm
# Date:    Fri Feb 26 17:03:14 CST 2021
###############################################################################

# Define toolchain path
#TOOLCHAIN = arm-linux-gnueabi-
TOOLCHAIN = ~/workspace/buildroot-2021.02.5/output/host/bin/arm-buildroot-linux-gnueabihf-

# Define template path
TEMPLATE = .

# Define target name
TARGET = template

# Define board name: X210BV3S
BOARD = X210BV3S

# Define target type: elf exe lib
TARGET_TYPE = elf
#TARGET_TYPE = exe
#TARGET_TYPE = lib

# Define run type: rom ram
#RUN_TYPE = rom
RUN_TYPE = ram

# Define build type: (null) debug profile release
#BUILD_TYPE =
#BUILD_TYPE = debug
BUILD_TYPE = profile
#BUILD_TYPE = release

# Define link file
LINK_FILE = arch/$(RUN_TYPE).lds

# Append global macro
USERDEFINES =

# Append cpu infomation
USERCPU  = -mcpu=cortex-a8
USERCPU += 

# Append standard library
USERSTDLIB = -lc -lm

# Append GCC flags
USERCFLAGS = 

# Append LD flags
#USERLDFLAGS  = --specs=nano.specs 
#USERLDFLAGS += --specs=nosys.specs
USERLDFLAGS += 

# Use vpath mode, y is enable, default is disable
VPATH_MODE = 

# Use garbage collection mode, y is enable, default is disable
GARBAGE_COLLECTION = y

# Create files, y is create, default is not create
CREATE_DIS = 
CREATE_ASM = y
CREATE_BIN = y
CREATE_HEX = 
CREATE_MAP = y
CREATE_GC  = 

# Define shell cmd, run before and after compile
# like: CMD_BEFORE = echo -n ===; echo ===
CMD_BEFORE = 
CMD_AFTER = 

include $(TEMPLATE)/tools/make/make.mk
