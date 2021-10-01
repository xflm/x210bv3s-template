###############################################################################
# Version: v2.1.0
# Author:  xflm
# Date:    Fri Feb 26 17:03:14 CST 2021
###############################################################################

# Define toolchain path, default $(G_TOOLCHAIN)
TOOLCHAIN = $(G_TOOLCHAIN)

# Define template path, default $(G_TEMPLATE)
TEMPLATE = $(G_TEMPLATE)

# Define board name, default $(G_BOARD)
BOARD = $(G_BOARD)

# Define build type: $(G_BUILD_TYPE) (null) debug profile release
BUILD_TYPE = $(G_BUILD_TYPE)
#BUILD_TYPE =
#BUILD_TYPE = debug
#BUILD_TYPE = profile
#BUILD_TYPE = release

# Append global macro, default $(G_DEFINES)
USERDEFINES  = $(G_DEFINES)
USERDEFINES +=

# Append cpu infomation, default $(G_CPU)
USERCPU  = $(G_CPU)
USERCPU +=

# Append GCC flags, default $(G_INCFLAGS)
USERCFLAGS  = $(G_INCFLAGS)
USERCFLAGS +=

# Use vpath mode, y is enable, default is disable
VPATH_MODE = y

# Use garbage clollection mode, y is enable, default is disable
GARBAGE_COLLECTION = y

# Define shell cmd, run before and after compile
# like: CMD_BEFORE = echo -n ===; echo ===
CMD_BEFORE =
CMD_AFTER =

TARGET = $(LIB_NAME)
TARGET_TYPE = lib
ifneq ($(VPATH_MODE),)
OBJ_DIR = $(BUILD_DIR)/$(FILE_PWD)/.obj
endif
include $(TEMPLATE)/tools/make/make.mk
