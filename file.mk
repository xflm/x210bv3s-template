###############################################################################
# Verison: v2.1.0
# Author:  xflm
# Date:    Wed 06 Oct 2021 12:13:00 AM CST
###############################################################################
 
# Define asm file
ASM_FILE += arch/crt0.S
ASM_FILE += 
 
# Define source file
SRC_FILE += main.c
SRC_FILE += 
 
# Define header path
INC_PATH += 
 
# Define library file
LIB_FILE += 
 
# Define other file
OTHER_FILE += .gitignore
OTHER_FILE += 
 
# Define spare file
SPARE_FILE += 
 
# Include sub file.mk
FILE_PWD = mboard
include $(FILE_PWD)/file.mk
FILE_PWD = drivers
include $(FILE_PWD)/file.mk
 
