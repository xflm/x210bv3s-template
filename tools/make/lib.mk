###############################################################################
# Version: v2.1.0
# Author:  xflm
# Date:    Fri Feb 26 17:03:14 CST 2021
###############################################################################

ifeq ($(MAKELEVEL),0)
ifeq ($(LIB_NAME),)
# Compile objects
ASM_FILE += $(FILE_ASM)
SRC_FILE += $(FILE_SRC)
LIB_FILE += $(FILE_LIB)
OTHER_FILE += $(FILE_OTHER)
else  # ifneq ($(LIB_NAME),)
# Tell Makefile add a lib
LIB_FILE += $(BUILD_DIR)/$(FILE_PWD)/lib$(LIB_NAME).a
ifeq ($(wildcard $(FILE_PWD)/makefile),)
# Compile library
ifeq ($(VPATH_MODE),)
FILE_OBJ  = $(foreach n, $(FILE_SRC), $(OBJ_DIR)/$(n).o)
FILE_OBJ += $(foreach n, $(FILE_ASM), $(OBJ_DIR)/$(n).o)
else  # ifneq ($(VPATH_MODE),)
FILE_OBJ  = $(foreach n, $(notdir $(FILE_SRC)), $(OBJ_DIR)/$(n).o)
FILE_OBJ += $(foreach n, $(notdir $(FILE_ASM)), $(OBJ_DIR)/$(n).o)
endif # ifeq ($(VPATH_MODE),)
FILE_DEPEND = $(FILE_OBJ:%.o=%.d)
-include $(FILE_DEPEND)
LIB_DEPEND_FILE += $(FILE_DEPEND)
LIB_ASM_FILE += $(FILE_ASM)
LIB_SRC_FILE += $(FILE_SRC)
LIB_FILE += $(FILE_LIB)

$(BUILD_DIR)/$(FILE_PWD)/lib$(LIB_NAME).a: $(FILE_OBJ)
	@mkdir -p $(@D)
	@$(AR) cr $@ $?
else  # ifneq ($(wildcard $(FILE_PWD)/makefile),)
LIB_DONE += $(FILE_PWD)
endif # ifeq ($(wildcard $(FILE_PWD)/makefile),)
endif # ifeq ($(LIB_NAME),)
INC_PATH += $(PATH_INC)
# Clear temporary variable
FILE_ASM = 
FILE_SRC = 
PATH_INC =
FILE_LIB =
FILE_OTHER =
else  # ifneq ($(MAKELEVEL),0)
# Tell sub Makefile compile a library
ASM_FILE += $(FILE_ASM)
SRC_FILE += $(FILE_SRC)
LIB_FILE += $(FILE_LIB)
OTHER_FILE += $(FILE_OTHER)
endif # ifeq ($(MAKELEVEL),0)
