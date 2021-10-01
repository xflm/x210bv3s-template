###############################################################################
# Verison: v2.1.0
# Author:  xflm
# Date:    Fri Feb 26 17:03:14 CST 2021
###############################################################################

###############################################################################
# Print file list which used for compiling
files: $(TARGET_INC)
	@$(call LIBRARY_DONE, files)
	@echo -e "$(PRINT_BOLD)==================== file list ====================$(PRINT_COLOR_OFF)"
	@echo -e "$(PRINT_BOLD)-------------------- make file --------------------$(PRINT_COLOR_OFF)"
	@echo $(filter %file.mk, $(MAKEFILE_LIST)) | tr ' ' '\n'
ifneq ($(strip $(LINK_FILE)),)
	@echo -e "$(PRINT_BOLD)-------------------- link file --------------------$(PRINT_COLOR_OFF)"
	@echo $(LINK_FILE) | tr ' ' '\n'
endif
	@echo -e "$(PRINT_BOLD)------------------ include file -------------------$(PRINT_COLOR_OFF)"
	@cat $(TARGET_INC)
ifneq ($(strip $(INC_PATH)),)
	@echo -e "$(PRINT_BOLD)------------------ include path -------------------$(PRINT_COLOR_OFF)"
	@echo $(INC_PATH) | tr ' ' '\n'
endif
ifneq ($(strip $(SRC_FILE)),)
	@echo -e "$(PRINT_BOLD)------------------- source file -------------------$(PRINT_COLOR_OFF)"
	@echo $(SRC_FILE) | tr ' ' '\n'
endif
ifneq ($(strip $(SRC_PATH)),)
	@echo -e "$(PRINT_BOLD)------------------- source path -------------------$(PRINT_COLOR_OFF)"
	@echo $(SRC_PATH) | tr ' ' '\n'
endif
ifneq ($(strip $(ASM_FILE)),)
	@echo -e "$(PRINT_BOLD)--------------------- asm file --------------------$(PRINT_COLOR_OFF)"
	@echo $(ASM_FILE) | tr ' ' '\n'
endif
ifneq ($(strip $(ASM_PATH)),)
	@echo -e "$(PRINT_BOLD)--------------------- asm path --------------------$(PRINT_COLOR_OFF)"
	@echo $(ASM_PATH) | tr ' ' '\n'
endif
ifneq ($(strip $(LIB_FILE)),)
	@echo -e "$(PRINT_BOLD)--------------------- lib file --------------------$(PRINT_COLOR_OFF)"
	@echo $(LIB_FILE) | tr ' ' '\n'
endif
ifneq ($(strip $(OTHER_FILE)),)
	@echo -e "$(PRINT_BOLD)-------------------- other file -------------------$(PRINT_COLOR_OFF)"
	@echo $(OTHER_FILE) | tr ' ' '\n'
endif
	@echo -e "$(PRINT_BOLD)-------------------- spare file -------------------$(PRINT_COLOR_OFF)"
	@echo $(SPARE_FILE) | tr ' ' '\n'
	@echo -e "$(PRINT_BOLD)======================= end =======================$(PRINT_COLOR_OFF)"
