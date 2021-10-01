###############################################################################
# Verison: v2.1.0
# Author:  xflm
# Date:    Sat Dec 19 09:11:46 CST 2020
###############################################################################

###############################################################################
# Create tags file
tags: $(TARGET_INC)
ifeq ($(MAKELEVEL),0)
	@ctags $(SRC_FILE) $(ASM_FILE) $(LIB_SRC_FILE) $(LIB_ASM_FILE) $(shell cat $(TARGET_INC))
else
	@ctags -a $(SRC_FILE) $(ASM_FILE) $(LIB_SRC_FILE) $(LIB_ASM_FILE) $(shell cat $(TARGET_INC))
endif
	@$(call LIBRARY_DONE, tags)
