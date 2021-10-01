###############################################################################
# Verison: v2.1.0
# Author:  xflm
# Date:    Fri 01 Oct 2021 10:53:44 PM CST
###############################################################################
 
# Define create lib name
LIB_NAME := 
 
# Define asm file
FILE_ASM += 
 
# Define source file
FILE_SRC += $(FILE_PWD)/pad.c
FILE_SRC += $(FILE_PWD)/syscon.c
FILE_SRC += $(FILE_PWD)/timer.c
FILE_SRC += $(FILE_PWD)/uart.c
FILE_SRC += $(FILE_PWD)/vic.c
FILE_SRC += 
 
# Define header path
PATH_INC += $(FILE_PWD)/include
PATH_INC += 
 
# Define library file
FILE_LIB += 
 
# Define other file
FILE_OTHER += 
 
# Define spare file
SPARE_FILE += 
 
# Include lib.mk
include $(TEMPLATE)/tools/make/lib.mk
