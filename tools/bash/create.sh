#!/bin/bash
###############################################################################
# Verison: v2.1.0
# Author:  xflm
# Date:    Fri Feb 26 17:03:14 CST 2021
###############################################################################


FILE_MK_VERSION=v2.1.0
FILE_MK_AUTHER=$USER
FILE_MK_DATE=$(LANG=en_US.UTF-8 date)

# $*: path outsize current dir, like: ../aa or /home/xflm/, each path cann't
# include ' '.
func_help()
{
	echo "Usage: ./tools/make/create.sh [path outsize current dir]"
	echo "like: ./tools/make/create.sh"
	echo "      ./tools/make/create.sh ../../drivers /home/xflm/workspace/mtools"
	echo
	echo "This command is used to construct the project, that is, to generate \
file.mk. It searches for files from the current directory by default, and always \
searches the current directory. The user only needs to create an empty file.mk in \
each directory, where ./file.mk must exist, the create.sh script will record the \
path of file.mk, and then write the searched file name into the corresponding file.mk. \
create.sh will recurse all files with the suffix ".c .h .a .S" in each directory, \
including the external directory and the current directory"
}

ALL_PATH=$(echo $* | tr ' ' '\n')
ERROR_PATH=$(echo "$ALL_PATH" | grep -v "^../\|^/")
if [ -n "$ERROR_PATH" ]; then
	echo "Don't support subdir of current dir: "$ERROR_PATH
	echo
	func_help
	exit 0
fi

# Classify find path by '.' '../' '/', because echo them need different method.
NORMAL_PTAH="."
RELATIVE_PTAH=$(echo "$ALL_PATH" | grep "^../")
ABS_PTAH=$(echo "$ALL_PATH" | grep "^/")

# -regex is more flexible then -name.
# Find result is start './' or '../' or '/'.
# Here only get *.c *.h *.a *.S *.mk files's name.
# If find not appoint path, it default is current dir.
# Find will find files recursion.
[ -z "$NORMAL_PTAH" ] || NORMAL_FILE=$(find $NORMAL_PTAH -type f -regex ".*\.[cSah]\|.*file\.mk" | sed "s|^./||g")
[ -z "$RELATIVE_PTAH" ] || RELATIVE_FILE=$(find $RELATIVE_PTAH -type f -name "*.[cSah]")
[ -z "$ABS_PTAH" ] || ABS_FILE=$(find $ABS_PTAH -type f -name "*.[cSah]")

# Classify files by suffix, among them, H file only need path end with '/',
# '/' assists sed to mate word below. And sort -u will be delete repetition.
NORMAL_C=$(echo "$NORMAL_FILE" | grep "\.c$")
NORMAL_H=$(echo "$NORMAL_FILE" | grep "\.h$" | sed "s|[^/]*\.h$||g" | sort -u)
NORMAL_S=$(echo "$NORMAL_FILE" | grep "\.S$")
NORMAL_A=$(echo "$NORMAL_FILE" | grep "\.a$")

RELATIVE_C=$(echo "$RELATIVE_FILE" | grep "\.c$")
RELATIVE_H=$(echo "$RELATIVE_FILE" | grep "\.h$" | sed "s|[^/]*\.h$||g" | sort -u)
RELATIVE_S=$(echo "$RELATIVE_FILE" | grep "\.S$")
RELATIVE_A=$(echo "$RELATIVE_FILE" | grep "\.a$")

ABS_C=$(echo "$ABS_FILE" | grep "\.c$")
ABS_H=$(echo "$ABS_FILE" | grep "\.h$" | sed "s|[^/]*\.h$||g" | sort -u)
ABS_S=$(echo "$ABS_FILE" | grep "\.S$")
ABS_A=$(echo "$ABS_FILE" | grep "\.a$")

# Get file.mk file name and path end with '/'.
# File name is a array, it is used below.
# Find will be search sub dir first, so MK_PATH will be like: driver/aa/cc/ driver/aa/ driver/.
# It ensures mate C H A S files's path will be propitious.
MK_PATH=$(echo "$NORMAL_FILE" | grep "/file.mk$" | sed "s|file.mk||g" | sort -r)
MK_PATH_ARRAY=($MK_PATH)

# Retain OTHER_FILE and SPARE_FILE in file.mk
OTHER_FILE=$(grep OTHER_FILE file.mk)
[ -z "$OTHER_FILE" ] && OTHER_FILE="OTHER_FILE += "
SPARE_FILE=$(grep SPARE_FILE file.mk)
[ -z "$SPARE_FILE" ] && SPARE_FILE="SPARE_FILE += "

# back up *file.mk.
mkdir -p make_create_bak
RECOVER_SCRIPT="#!/bin/bash^ ^"
for ((i = 0; i < ${#MK_PATH_ARRAY[@]}; i++)); do
	mv ${MK_PATH_ARRAY[$i]}/file.mk make_create_bak/$i.mk
	RECOVER_SCRIPT+="cp make_create_bak/$i.mk ${MK_PATH_ARRAY[$i]}/file.mk^"
done
mv file.mk make_create_bak/$i.mk
RECOVER_SCRIPT+="cp make_create_bak/$i.mk file.mk^"
echo "$RECOVER_SCRIPT" | tr '^' '\n' > make_create_bak/recover.sh
chmod +x make_create_bak/recover.sh

# n is record cycle times
n=0

# Classify C H A S files by */file.mk files's path, and add prefix.
# These not matching file will be write in to ./file.mk.
# NORMAL_C(H S A) will update each cycle, avoid repet matching.
# Here will delete '/' at end of H file path.
# RELATIVE_C_ARRAY need add prefix and add '../'.
for i in $MK_PATH; do
	NORMAL_C_ARRAY[$n]=$(echo -n "$NORMAL_C" | grep "^$i" | sed "s|^$i|FILE_SRC += \$(FILE_PWD)/|g")
	NORMAL_C=$(echo -n "$NORMAL_C" | grep -v "^$i")
	NORMAL_H_ARRAY[$n]=$(echo -n "$NORMAL_H" | grep "^$i" | sed "s|^$i|PATH_INC += \$(FILE_PWD)/|g;s|/$||g")
	NORMAL_H=$(echo -n "$NORMAL_H" | grep -v "^$i")
	NORMAL_S_ARRAY[$n]=$(echo -n "$NORMAL_S" | grep "^$i" | sed "s|^$i|FILE_ASM += \$(FILE_PWD)/|g")
	NORMAL_S=$(echo -n "$NORMAL_S" | grep -v "^$i")
	NORMAL_A_ARRAY[$n]=$(echo -n "$NORMAL_A" | grep "^$i" | sed "s|^$i|FILE_LIB += \$(FILE_PWD)/|g")
	NORMAL_A=$(echo -n "$NORMAL_A" | grep -v "^$i")

	j=$(echo "$i" | sed "s|[^/]*/|../|g")
	RELATIVE_C_ARRAY[$n]=$(echo -n "$RELATIVE_C" | grep "$i" | sed "s|^|FILE_SRC += \$(FILE_PWD)/$j|g")
	RELATIVE_C=$(echo -n "$RELATIVE_C" | grep -v "$i")
	RELATIVE_H_ARRAY[$n]=$(echo -n "$RELATIVE_H" | grep "$i" | sed "s|^|PATH_INC += \$(FILE_PWD)/$j|g;s|/$||g")
	RELATIVE_H=$(echo -n "$RELATIVE_H" | grep -v "$i")
	RELATIVE_S_ARRAY[$n]=$(echo -n "$RELATIVE_S" | grep "$i" | sed "s|^|FILE_ASM += \$(FILE_PWD)/$j|g")
	RELATIVE_S=$(echo -n "$RELATIVE_S" | grep -v "$i")
	RELATIVE_A_ARRAY[$n]=$(echo -n "$RELATIVE_A" | grep "$i" | sed "s|^|FILE_LIB += \$(FILE_PWD)/$j|g")
	RELATIVE_A=$(echo -n "$RELATIVE_A" | grep -v "$i")

	ABS_C_ARRAY[$n]=$(echo -n "$ABS_C" | grep "$i" | sed "s|^|FILE_SRC += |g")
	ABS_C=$(echo -n "$ABS_C" | grep -v "$i")
	ABS_H_ARRAY[$n]=$(echo -n "$ABS_H" | grep "$i" | sed "s|^|PATH_INC += |g;s|/$||g")
	ABS_H=$(echo -n "$ABS_H" | grep -v "$i")
	ABS_S_ARRAY[$n]=$(echo -n "$ABS_S" | grep "$i" | sed "s|^|FILE_ASM += |g")
	ABS_S=$(echo -n "$ABS_S" | grep -v "$i")
	ABS_A_ARRAY[$n]=$(echo -n "$ABS_A" | grep "$i" | sed "s|^|FILE_LIB += |g")
	ABS_A=$(echo -n "$ABS_A" | grep -v "$i")
# Used in create file.mk
	MK_INCLUDE+="FILE_PWD = ${i%/}^include \$(FILE_PWD)/file.mk^"
	((n++))
done

FILE_MK_VERSION_CHECK='###############################################################################
# Verison: '$FILE_MK_VERSION'
# Author:  '$FILE_MK_AUTHER'
# Date:    '$FILE_MK_DATE'
###############################################################################^ ^'

# Create */file.mk.
# '^ ^' will turn to '\n \n' means the second line is not a space line.
for ((i = 0; i < ${#NORMAL_C_ARRAY[@]}; i++)); do
	echo "$FILE_MK_VERSION_CHECK# Define create lib name^\
LIB_NAME := ^ ^\
# Define asm file^\
${NORMAL_S_ARRAY[$i]}^${RELATIVE_S_ARRAY[$i]}^${ABS_S_ARRAY[$i]}^\
FILE_ASM += ^ ^\
# Define source file^\
${NORMAL_C_ARRAY[$i]}^${RELATIVE_C_ARRAY[$i]}^${ABS_C_ARRAY[$i]}^\
FILE_SRC += ^ ^\
# Define header path^\
${NORMAL_H_ARRAY[$i]}^${RELATIVE_H_ARRAY[$i]}^${ABS_H_ARRAY[$i]}^\
PATH_INC += ^ ^\
# Define library file^\
${NORMAL_A_ARRAY[$i]}^${RELATIVE_A_ARRAY[$i]}^${ABS_A_ARRAY[$i]}^\
FILE_LIB += ^ ^\
# Define other file^\
FILE_OTHER += ^ ^\
# Define spare file^\
SPARE_FILE += ^ ^\
# Include lib.mk^\
include $""(TEMPLATE)/tools/make/lib.mk" | tr '^' '\n' | sed "/^$/d"\
> ${MK_PATH_ARRAY[$i]}/file.mk
done

# Create ./file.mk
echo "$FILE_MK_VERSION_CHECK# Define asm file^\
$(echo -en "$NORMAL_S\n$RELATIVE_S\n$ABS_S" | sed "s|^|ASM_FILE += |g")^\
ASM_FILE += ^ ^\
# Define source file^
$(echo -en "$NORMAL_C\n$RELATIVE_C\n$ABS_C" | sed "s|^|SRC_FILE += |g")^\
SRC_FILE += ^ ^\
# Define header path^\
$(echo -en "$NORMAL_H\n$RELATIVE_H\n$ABS_H" | sed "s|^|INC_PATH += |g;s|/$||g")^\
INC_PATH += ^ ^\
# Define library file^\
$(echo -en "$NORMAL_A\n$RELATIVE_A\n$ABS_A" | sed "s|^|LIB_FILE += |g")^\
LIB_FILE += ^ ^\
# Define other file^\
$OTHER_FILE^ ^\
# Define spare file^\
$SPARE_FILE^ ^\
# Include sub file.mk^\
$MK_INCLUDE^ ^" | tr '^' '\n' | sed "/^$/d" | uniq > file.mk

