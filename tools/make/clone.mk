###############################################################################
# Verison: v2.1.0
# Author:  xflm
# Date:    Fri Feb 26 17:03:14 CST 2021
###############################################################################

###############################################################################
# In source may be use #include "aa/bb.h", so INC_PATH may not include aa/, 
# so do $(dir $(INC_FILE)) here
CLONE_TARGET_DIR = ../$(TARGET)-clone
CLONE_MAKEFILE=$(sort $(filter-out %.d,$(MAKEFILE_LIST)))
CLONE_ALL_FILE = $(SRC_FILE) $(ASM_FILE) $(OTHER_FILE) \
$(filter-out $(BUILD_DIR)/%, $(LIB_FILE)) $(LINK_FILE) \
$(filter-out $(TEMPLATE)/%, $(CLONE_MAKEFILE) $(SPARE_FILE))
CLONE_TEMPLATE = $(filter $(TEMPLATE)/%, $(CLONE_MAKEFILE) $(SPARE_FILE))
CLONE_TARGET_TEMPLATE = $(CLONE_TEMPLATE:$(TEMPLATE)/%=$(CLONE_TARGET_DIR)/%)
CLONE_FILEMK = $(filter %/file.mk, $(CLONE_MAKEFILE))
CLONE_TARGET_FILEMK = $(addprefix $(CLONE_TARGET_DIR)/, $(CLONE_FILEMK))
CLONE_NEW_LIB = $(filter $(BUILD_DIR)/%, $(LIB_FILE))
# Project clone
clone: $(TARGET_INC)
# Check dir exist, if exist then quit
ifeq ($(wildcard $(CLONE_TARGET_DIR)),$(CLONE_TARGET_DIR))
	@$(error "dir $(CLONE_TARGET_DIR) has been exist, do nothing")
endif
ifeq ($(wildcard  $(TARGET_ELF) $(TARGET_LIB)),)
	@$(error "Need make compile first, do nothing")
endif
	@$(call LIBRARY_DONE, clone)
	@ALL_FILE=$$(echo "$(CLONE_ALL_FILE)" | tr ' ' '\n' | sed "s|^\./||g;/^$$/d"); \
     ALL_HEADER=$$(cat $(TARGET_INC) | sed "s|^\./||g;/^$$/d"); \
     ALL_NEW_LIB=$$(echo $(CLONE_NEW_LIB) | tr ' ' '\n' | sed "s|^\./||g;/^$$/d"); \
     BUILD_DIR="$(BUILD_DIR)"; \
     CLONE_TARGET_DIR="$(CLONE_TARGET_DIR)"; \
     CLONE_FILEMK="$(CLONE_FILEMK)"; \
     CLONE_TARGET_FILEMK="$(CLONE_TARGET_FILEMK)"; \
     CLONE_TEMPLATE="$(CLONE_TEMPLATE)"; \
     CLONE_TARGET_TEMPLATE="$(CLONE_TARGET_TEMPLATE)"; \
     IS_SUB_MK="$(MAKELEVEL)"; \
     if [ $$IS_SUB_MK -ne 0 ]; then \
     MAKE_PATH="$(TARGET_LIB)"; \
     TARGET="$(TARGET)"; \
     G_TOOLCHAIN="$(G_TOOLCHAIN)"; \
     G_TEMPLATE="$(G_TEMPLATE)"; \
     G_BOARD="$(G_BOARD)"; \
     G_BUILD_TYPE="$(G_BUILD_TYPE)"; \
     G_CPU="$(G_CPU)"; \
     G_DEFINES="$(G_DEFINES)"; \
     MAKE_PATH=$${MAKE_PATH#$$BUILD_DIR/}; \
     MAKE_PATH=$${MAKE_PATH%/lib*}; fi; \
     NORMAL_FILE=$$(echo "$$ALL_FILE" | sed "/\.\./d;/^\//d;/^~/d;/:/d"); \
     NORMAL_HEADER=$$(echo "$$ALL_HEADER" | sed "/\.\./d;/^\//d;/^~/d;/:/d"); \
     TOP_RELATIVE_FILE=$$(echo "$$ALL_FILE" | grep "^\.\."); \
     TOP_RELATIVE_HEADER=$$(echo "$$ALL_HEADER" | grep "^\.\."); \
     RELATIVE_FILE=$$(echo "$$ALL_FILE" | grep "\.\." | grep -v "^\.\."); \
     RELATIVE_HEADER=$$(echo "$$ALL_HEADER" | grep "\.\." | grep -v "^\.\."); \
     LINUX_ABS_FILE=$$(echo "$$ALL_FILE" | grep "^/"); \
     LINUX_ABS_HEADER=$$(echo "$$ALL_HEADER" | grep "^/"); \
     HOME_ABS_FILE=$$(echo "$$ALL_FILE" | grep "^~"); \
     HOME_ABS_HEADER=$$(echo "$$ALL_HEADER" | grep "^~"); \
     WIN_ABS_FILE=$$(echo "$$ALL_FILE" | grep ":"); \
     WIN_ABS_HEADER=$$(echo "$$ALL_HEADER" | grep ":"); \
     NEW_LIB=$$ALL_NEW_LIB; \
     if [ ! -z "$$NORMAL_FILE" ]; then \
     CLONE_NORMAL_FILE=$$(echo "$$NORMAL_FILE" | \
         sed "s|^|$$CLONE_TARGET_DIR/|g"); fi; \
     if [ ! -z "$$NORMAL_HEADER" ]; then \
     CLONE_NORMAL_HEADER=$$(echo "$$NORMAL_HEADER" | \
         sed "s|^|$$CLONE_TARGET_DIR/|g"); fi; \
     CLONE_TOP_RELATIVE_FILE=$$(echo "$$TOP_RELATIVE_FILE" | \
         sed "s|.*\.\./|$$CLONE_TARGET_DIR/|g"); \
     CLONE_TOP_RELATIVE_HEADER=$$(echo "$$TOP_RELATIVE_HEADER" | \
         sed "s|.*\.\./|$$CLONE_TARGET_DIR/|g"); \
     CLONE_NEW_LIB=$$(echo "$$NEW_LIB" | \
         sed "s|$$BUILD_DIR/|$$CLONE_TARGET_DIR/|g"); \
     for i in $$RELATIVE_FILE $$RELATIVE_HEADER; do j=$${i%%/..*}; m=$${j##*/}; \
         CLONE_RELATIVE_FILE+=$$CLONE_TARGET_DIR/$$j/$${i##*/$$m/}" "; done; \
     for i in $$LINUX_ABS_FILE; do j=$$(grep -l $$i $$CLONE_FILEMK); \
         if [ -z "$$j" ]; then m=$${i#/}" "; \
         CLONE_ABS_FILE+=$$CLONE_TARGET_DIR/$$m; MK_ABS_FILE+=$$m; \
         else j=$${j%%/file.mk*}; m=$${j##*/}; m=$${i##*/$$m/}" "; \
         CLONE_ABS_FILE+=$$CLONE_TARGET_DIR/$$j/$$m; \
         MK_ABS_FILE+='$$(FILE_PWD)/'$$m; fi; done;\
     for i in $$WIN_ABS_FILE; do j=$$(grep -l $$i $$CLONE_FILEMK); i=/$${i/:/}; \
         if [ -z "$$j" ]; then m=$${i#/}" "; \
         CLONE_ABS_FILE+=$$CLONE_TARGET_DIR/$$m; MK_ABS_FILE+=$$m; \
         else j=$${j%%/file.mk*}; m=$${j##*/}; m=$${i##*/$$m/}" "; \
         CLONE_ABS_FILE+=$$CLONE_TARGET_DIR/$$j/$$m; \
         MK_ABS_FILE+='$$(FILE_PWD)/'$$m; fi; done;\
     for i in $$HOME_ABS_FILE; do j=$$(grep -l $$i $$CLONE_FILEMK); i=$${i/\~/$$HOME}; \
         if [ -z "$$j" ]; then m=$${i#/}" "; \
         CLONE_ABS_FILE+=$$CLONE_TARGET_DIR/$$m; MK_ABS_FILE+=$$m; \
         else j=$${j%%/file.mk*}; m=$${j##*/}; m=$${i##*/$$m/}" "; \
         CLONE_ABS_FILE+=$$CLONE_TARGET_DIR/$$j/$$m; \
         MK_ABS_FILE+='$$(FILE_PWD)/'$$m; fi; NEW_HOME_ABS_FILE+=$$i" "; done; \
     ALL_HEADER_PATH=$$(echo "$(INC_PATH)" | tr ' ' '\n'); \
     LINUX_HEADER_PATH=$$(echo "$$ALL_HEADER_PATH" | grep "^/" | sort -u); \
     WIN_HEADER_PATH=$$(echo "$$ALL_HEADER_PATH" | grep ":" | sort -u); \
     HOME_HEADER_PATH=$$(echo "$$ALL_HEADER_PATH" | grep "^~"| sort -u); \
     CLONE_LINUX_ABS_HEADER=$$LINUX_ABS_HEADER; \
     for i in $$LINUX_HEADER_PATH; do j=$$(grep -l $$i $$CLONE_FILEMK); \
         if [ -z "$$j" ]; then m=$${i#/}; \
         CLONE_LINUX_ABS_HEADER=$${CLONE_LINUX_ABS_HEADER//"$$i"/"$$CLONE_TARGET_DIR/$$m"};\
         MK_ABS_FILE+=$$m" "; \
         else j=$${j%%/file.mk*}; m=$${j##*/}; m=$${i##*/$$m/}; \
         CLONE_LINUX_ABS_HEADER=$${CLONE_LINUX_ABS_HEADER//"$$i"/"$$CLONE_TARGET_DIR/$$j/$$m"};\
         MK_ABS_FILE+='$$(FILE_PWD)/'$$m" "; fi; done; \
     CLONE_WIN_ABS_HEADER=$$WIN_ABS_HEADER; \
     for i in $$WIN_HEADER_PATH; do j=$$(grep -l $$i $$CLONE_FILEMK); n=/$${i/:/}; \
         if [ -z "$$j" ]; then m=$${n#/}; \
         CLONE_WIN_ABS_HEADER=$${CLONE_WIN_ABS_HEADER//"$$i"/"$$CLONE_TARGET_DIR/$$m"};\
         MK_ABS_FILE+=$$m" "; \
         else j=$${j%%/file.mk*}; m=$${j##*/}; m=$${n##*/$$m/}; \
         CLONE_WIN_ABS_HEADER=$${CLONE_WIN_ABS_HEADER//"$$i"/"$$CLONE_TARGET_DIR/$$j/$$m"};\
         MK_ABS_FILE+='$$(FILE_PWD)/'$$m" "; fi; done; \
     CLONE_HOME_ABS_HEADER=$$HOME_ABS_HEADER; \
     for i in $$HOME_HEADER_PATH; do j=$$(grep -l $$i $$CLONE_FILEMK); n=$${i/\~/$$HOME}; \
         if [ -z "$$j" ]; then m=$${n#/}; \
         CLONE_HOME_ABS_HEADER=$${CLONE_HOME_ABS_HEADER//"$$i"/"$$CLONE_TARGET_DIR/$$m"};\
         MK_ABS_FILE+=$$m" "; \
         else j=$${j%%/file.mk*}; m=$${j##*/}; m=$${n##*/$$m/}; \
         CLONE_HOME_ABS_HEADER=$${CLONE_HOME_ABS_HEADER//"$$i"/"$$CLONE_TARGET_DIR/$$j/$$m"};\
         MK_ABS_FILE+='$$(FILE_PWD)/'$$m" "; fi; NEW_HOME_ABS_HEADER+=$$n" "; done; \
     for i in $$CLONE_NORMAL_FILE $$CLONE_TOP_RELATIVE_FILE $$CLONE_RELATIVE_FILE \
         $$CLONE_ABS_FILE $$CLONE_NORMAL_HEADER $$CLONE_TOP_RELATIVE_HEADER \
         $$CLONE_LINUX_ABS_HEADER $$CLONE_WIN_ABS_HEADER $$CLONE_HOME_ABS_HEADER \
         $$CLONE_TARGET_TEMPLATE; do \
         CLONE_PATH+=$${i%/*}" "; done; \
     mkdir -p $$CLONE_PATH; \
     COPY_FILE=($$NORMAL_FILE $$TOP_RELATIVE_FILE $$RELATIVE_FILE $$RELATIVE_HEADER \
         $$LINUX_ABS_FILE $$WIN_ABS_FILE $$NEW_HOME_ABS_FILE $$NORMAL_HEADER \
         $$TOP_RELATIVE_HEADER $$LINUX_ABS_HEADER $$WIN_ABS_HEADER $$NEW_HOME_ABS_HEADER \
         $$NEW_LIB $$CLONE_TEMPLATE); \
     COPY_TO_FILE=($$CLONE_NORMAL_FILE $$CLONE_TOP_RELATIVE_FILE $$CLONE_RELATIVE_FILE \
         $$CLONE_ABS_FILE $$CLONE_NORMAL_HEADER $$CLONE_TOP_RELATIVE_HEADER \
         $$CLONE_LINUX_ABS_HEADER $$CLONE_WIN_ABS_HEADER $$CLONE_HOME_ABS_HEADER \
         $$CLONE_NEW_LIB $$CLONE_TARGET_TEMPLATE); \
     for ((i = 0; i < $${#COPY_FILE[@]}; i++)); do cp $${COPY_FILE[$$i]} $${COPY_TO_FILE[$$i]}; done; \
     for i in $$CLONE_TARGET_FILEMK; do j=$${i%/file.mk}; m=$${j##*/}; \
         sed -i "s|/\.\..*/$$m/|/|g;s|/\.\..*/$$m\s*||g" $$i; done; \
     ABS_NAME=($$LINUX_ABS_FILE $$WIN_ABS_FILE $$HOME_ABS_FILE \
         $$LINUX_HEADER_PATH $$WIN_HEADER_PATH $$HOME_HEADER_PATH); \
     NEW_NAME=($$MK_ABS_FILE); \
     if [ $$IS_SUB_MK -eq 0 ]; then \
     sed -i "s|\.\./||g" $$CLONE_TARGET_DIR/file.mk; \
     sed -i "s|\.\./||g;s|\.\.\s*|\.|g" $$CLONE_TARGET_DIR/file.mk; \
     sed -i "s|.*TEMPLATE.*=.*|TEMPLATE = .|g" $$CLONE_TARGET_DIR/Makefile; \
     for ((i = 0; i < $${#ABS_NAME[@]}; i++)); do \
         sed -i "s|$${ABS_NAME[$$i]}|$${NEW_NAME[$$i]}|g" $$CLONE_TARGET_FILEMK $$CLONE_TARGET_DIR/file.mk; done; \
     NEW_LIB_MK=($$(echo "$$CLONE_NEW_LIB" | sed "s|/lib.*|/file.mk|g")); \
     NEW_LIB_NAME=($$(echo "$$CLONE_NEW_LIB" | sed "s|.*/||g")); \
     for ((i = 0; i < $${#NEW_LIB_MK[@]}; i++)); do \
         TMP1=$${NEW_LIB_MK[$$i]}; \
         LINE1=$$(grep FILE_SRC -n $$TMP1 | tail -1 | cut -d':' -f1); LINE1=$$(($$LINE1+1)); \
         sed -i "s|LIB_NAME.*|LIB_NAME :=|g;/FILE_SRC.*/d; $$LINE1 iFILE_SRC +=" $$TMP1; \
         TMP2=$${TMP1##$$CLONE_TARGET_DIR/}; TMP2=$${TMP2/file.mk/makefile}; if [ -f $$TMP2 ]; then \
         LINE1=$$(grep FILE_LIB -n $$TMP1 | tail -1 | cut -d':' -f1); LINE1=$$(($$LINE1+1)); \
         sed -i "/FILE_LIB.*+=.*[a-z]/d;$$LINE1""iFILE_LIB += $$""(FILE_PWD)/$${NEW_LIB_NAME[$$i]}" $$TMP1; \
         else LINE1=$$(grep FILE_LIB -n $$TMP1 | head -1 | cut -d':' -f1); \
         sed -i "$$LINE1""iFILE_LIB += $$""(FILE_PWD)/$${NEW_LIB_NAME[$$i]}" $$TMP1; fi; done; \
     else head -6 file.mk > $$CLONE_TARGET_DIR/file.mk; cd $$CLONE_TARGET_DIR;\
     mv $$MAKE_PATH/makefile Makefile; \
     sed -i "/LIB_NAME/c\LIB_NAME :=" $$MAKE_PATH/file.mk; \
     sed -i "s|$$""(G_TOOLCHAIN)|$$G_TOOLCHAIN|g; \
         s|$$""(G_TEMPLATE)|.|g; \
         s/$$""(G_BOARD)/$$G_BOARD/g; \
         s/$$""(G_BUILD_TYPE)/$$G_BUILD_TYPE/g; \
         s/$$""(G_CPU)/$$G_CPU/g; \
         s/$$""(G_INCFLAGS)//g; \
         s/$$""(LIB_NAME)/$$TARGET/g;\
         s/$$""(G_DEFINES)/$$G_DEFINES/g; \
         /OBJ_DIR/d" Makefile; \
     INC_PATH=$$(find . -name "*.h" | sed "s|\./||g;s|/[^/]*h||g" | \
         uniq | sed "s|^|INC_PATH += |g"); cd $$OLDPWD; \
     echo -e "# Define asm file\nASM_FILE +=\n\n# Define source file\nSRC_FILE +=\n\n"\
"# Define header path\n$$INC_PATH\n""INC_PATH +=\n\n# Define library file\nLIB_FILE +=\n\n"\
"# Define library file\nOTHER_FILE +=\n\n# Include sub file.mk\nFILE_PWD = $$MAKE_PATH\n"\
"include $$""(FILE_PWD)/file.mk\n" >> $$CLONE_TARGET_DIR/file.mk; fi;
