###############################################################################
# Verison: v2.1.0
# Author:  xflm
# Date:    Fri 01 Oct 2021 10:53:44 PM CST
###############################################################################
 
# Define asm file
ASM_FILE += arch/crt0.S
ASM_FILE += 
 
# Define source file
SRC_FILE += main.c
SRC_FILE += 
 
# Define header path
INC_PATH += include
INC_PATH += 
 
# Define library file
LIB_FILE += 
 
# Define other file
OTHER_FILE += .gitignore
OTHER_FILE += 
 
# Define spare file
SPARE_FILE += 
 
# Include sub file.mk
FILE_PWD = drivers
include $(FILE_PWD)/file.mk
FILE_PWD = app
include $(FILE_PWD)/file.mk
 
