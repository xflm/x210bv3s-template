###############################################################################
# Verison: v2.1.0
# Author:  xflm
# Date:    Sat Dec 19 09:11:46 CST 2020
###############################################################################

###############################################################################
ifeq ($(MAKELEVEL),0)
INCLUDEPATH_NORMAL = $(filter-out /%, $(INC_PATH))
INCLUDEPATH_ABS = $(filter /%, $(INC_PATH))
else
INCLUDEPATH_NORMAL = $(filter-out /%, $(INC_PATH) $(G_INC_PATH))
INCLUDEPATH_ABS = $(filter /%, $(INC_PATH) $(G_INC_PATH))
endif
SOURCES_NORMAL = $(filter-out /%, $(SRC_FILE) $(LIB_SRC_FILE))
SOURCES_ABS = $(filter /%, $(SRC_FILE) $(LIB_SRC_FILE))
DISTFILES_ALL = $(OTHER_FILE) $(filter %file.mk, $(MAKEFILE_LIST)) \
$(ASM_FILE) $(LINK_FILE) $(LIB_ASM_FILE)
DISTFILES_NORMAL = $(filter-out /%, $(DISTFILES_ALL))
DISTFILES_ABS = $(filter /%, $(DISTFILES_ALL))
# Create Qtcreator pro file
qt: $(TARGET_INC)
	@$(call LIBRARY_DONE, qt)
	@mkdir -p .qt
# '^' in addprefix cmd is used to avoid difference from windows and linux
# In linux use: $(addprefix \\\\\n    ../, $(INC_FILE)), it can instead of tr cmd
	@echo "DEFINES += "$(BOARD) $(DEFINES)"^" \
          "^HEADERS += $(addprefix \^&../, $(filter-out /%, $(shell cat $(TARGET_INC))))" \
		  "$(addprefix \^&, $(filter /%, $(shell cat $(TARGET_INC))))^" \
          "^INCLUDEPATH += $(addprefix \^&../, $(INCLUDEPATH_NORMAL))" \
		  "$(addprefix \^&, $(INCLUDEPATH_ABS))^" \
          "^SOURCES += $(addprefix \^&../,$(SOURCES_NORMAL))" \
		  "$(addprefix \^&, $(SOURCES_ABS))^" \
          "^DISTFILES += $(addprefix \^&../,$(DISTFILES_NORMAL))" \
		  "$(addprefix \^&, $(DISTFILES_ABS))^" | \
          tr '^' '\n' | tr '&' '\t' > .qt/$(TARGET).pro
ifeq ($(MAKELEVEL),0)
	@$(RM) .qt/all.pro
	@cat .qt/*.pro > .qt/all.pro
endif
