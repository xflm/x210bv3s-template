###############################################################################
# Verison: v2.1.0
# Author:  xflm
# Date:    Sat Dec 19 09:11:46 CST 2020
###############################################################################

###############################################################################
SLIM_FILE_MK = $(filter %file.mk, $(MAKEFILE_LIST))

# Remove redundant C files
slim:
ifeq ($(TARGET_ELF),)
	@$(error "This only support for compile elf, do nothing")
endif
ifeq ($(wildcard  $(TARGET_ELF)),)
	@$(error "Need make compile first, do nothing")
endif
ifeq ($(findstring -g3, $(CFLAGS)),)
	@$(error "Need compile with -g3(CFLAGS), do nothing")
endif
ifeq ($(findstring --gc-sections, $(LDFLAGS)),)
	@$(CC) -o $(TARGET_ELF) $(LDFLAGS) $(OBJ_FILE) $(LIB_FILE) \
-Wl,--cref,-Map=$(BUILD_DIR)/slim.map -Wl,--gc-sections
else # ifneq ($(findstring --gc-sections, $(LDFLAGS)),)
ifeq ($(TARGET_MAP),)
	@$(CC) -o $(TARGET_ELF) $(LDFLAGS) $(OBJ_FILE) $(LIB_FILE) \
-Wl,--cref,-Map=$(BUILD_DIR)/slim.map
else
	@cp $(TARGET_MAP) $(BUILD_DIR)/slim.map
endif # ifeq ($(TARGET_MAP),)
endif # ifeq ($(findstring --gc-sections, $(LDFLAGS)),)
	@mkdir -p make_slim_bak;RECOVER_SCRIPT="#!/bin/bash^ ^"; \
j=0; for i in $(SLIM_FILE_MK); do cp $$i make_slim_bak/$$j.mk; \
RECOVER_SCRIPT+="cp make_slim_bak/$$j.mk $$i^"; ((j++)); \
done; echo "$$RECOVER_SCRIPT" | tr '^' '\n' > make_slim_bak/recover.sh; \
chmod +x make_slim_bak/recover.sh
ifeq ($(VPATH_MODE),y)
	@REMOVE_FILES=$$(grep " .debug_info" $(BUILD_DIR)/slim.map | grep "0x0* " | \
grep $(OBJ_DIR) | sed '$$d;s|.*$(OBJ_DIR)/||g;s/\.o$$//g'); \
[ -z "$$REMOVE_FILES" ] || echo "$$REMOVE_FILES"; \
for i in $$REMOVE_FILES; do sed -i "/[= \/]$$i/d" $(filter %file.mk, $(MAKEFILE_LIST)); \
done
else
	@REMOVE_FILES=$$(grep " .debug_info" $(BUILD_DIR)/slim.map | grep "0x0* " | \
grep $(OBJ_DIR) | sed '$$d;s|.*$(OBJ_DIR)/||g;s/\.o$$//g'); \
REMOVE_INTERN_FILES=$$(echo "$$REMOVE_FILES" | grep -v '\.\./\|^/\|^~'); \
[ -z "$$REMOVE_INTERN_FILES" ] || echo "$$REMOVE_INTERN_FILES"; \
REMOVE_EXTERN_FILES=$$(echo "$$REMOVE_FILES" | grep '\.\./\|^/\|^~' | \
sed 's|^[^.]*/\.\.|..|g'); \
[ -z "$$REMOVE_EXTERN_FILES" ] || echo "$$REMOVE_EXTERN_FILES"; \
for i in $$REMOVE_INTERN_FILES; do j=$$i; m=0; while true; do j=$${j%/*}; \
if [ -f $$j/file.mk ]; then i=$${i#$$j/}; [ $$m -eq 1 ] && i=$${i////[/]}; \
sed -i "/[= \/]$$i/d" $$j/file.mk; break; else m=1; fi; done; done; \
for i in $$REMOVE_EXTERN_FILES; do sed -i "s|.*[= \/]$$i.*|==|g;/^==/d" \
$(filter %file.mk, $(MAKEFILE_LIST)); done
endif # ifeq ($(VPATH_MODE),y)
