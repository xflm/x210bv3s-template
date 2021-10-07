#ifndef _MDEV_H_
#define _MDEV_H_

#include <stdint.h>

typedef volatile unsigned int       _RW;
typedef volatile unsigned int       _OW;
typedef volatile const unsigned int _OR;
typedef const unsigned int          _NU;
typedef uint32_t                    MDevBase_t;
typedef uint32_t                    MDevReg_t;

#ifndef NULL
#define NULL (void*)0
#endif

typedef enum {
	MDEV_STAT_OK            = 0,
	MDEV_STAT_PARA_NULL     = 1,
	MDEV_STAT_PARA_ALIGN    = 2,
	MDEV_STAT_PARA_ILLEGAL  = 3,
	MDEV_STAT_PARA_ZERO     = 4,
	MDEV_STAT_BUSY          = 5,
	MDEV_STAT_TIMEOUT       = 6,
	MDEV_STAT_RUN_ERR       = 7,
	MDEV_STAT_RET_ERR       = 8,
	MDEV_STAT_NO_SUPPORT    = 9,
} MDevStat_e;

typedef enum {
	MDEV_BOOL_FLASE = 0,
	MDEV_BOOL_TRUE  = 1,
} MDevBool_e;

#define ASSERT_PARA_NULL     1
#define ASSERT_PARA_ALIGN    1
#define ASSERT_PARA_ILLEGAL  1
#define ASSERT_PARA_ZERO     1
#define ASSERT_RET_FAIL      1

#define assert_para_null(expr)     if((ASSERT_PARA_NULL) && (expr)) { \
	return MDEV_STAT_PARA_NULL; \
	}
#define assert_para_align(expr)    if((ASSERT_PARA_ALIGN) && (expr)) { \
	return MDEV_STAT_PARA_ALIGN; \
	}
#define assert_para_illegal(expr)  if((ASSERT_PARA_ILLEGAL) && (expr)) { \
	return MDEV_STAT_PARA_ILLEGAL; \
	}
#define assert_para_zero(expr)     if((ASSERT_PARA_ZERO) && (expr)) { \
	return MDEV_STAT_PARA_ZERO; \
	}

#define assert_para_null_ret(expr, ...)     if((ASSERT_PARA_NULL) && (expr)) { \
	return __VA_ARGS__; \
	}
#define assert_para_align_ret(expr, ...)    if((ASSERT_PARA_ALIGN) && (expr)) { \
	return __VA_ARGS__; \
	}
#define assert_para_illegal_ret(expr, ...)  if((ASSERT_PARA_ILLEGAL) && (expr)) { \
	return __VA_ARGS__; \
	}
#define assert_para_zero_ret(expr, ...)     if((ASSERT_PARA_ZERO) && (expr)) { \
	return __VA_ARGS__; \
	}

#define assert_para_null_done(expr, ...)     if((ASSERT_PARA_NULL) && (expr)) { \
	__VA_ARGS__; \
	}
#define assert_para_align_done(expr, ...)    if((ASSERT_PARA_ALIGN) && (expr)) { \
	__VA_ARGS__; \
	}
#define assert_para_illegal_done(expr, ...)  if((ASSERT_PARA_ILLEGAL) && (expr)) { \
	__VA_ARGS__; \
	}
#define assert_para_zero_done(expr, ...)     if((ASSERT_PARA_ZERO) && (expr)) { \
	__VA_ARGS__; \
	}

#define assert_ret_fail(expr)                if(ASSERT_RET_FAIL) { \
	do { \
	MDevStat_e ret; \
	ret = expr; \
	if(ret != MDEV_STAT_OK) { \
	return ret; \
	} \
	} while(0); \
	}

#define MDEV_KEEP_TEXT         __attribute__((used,section(".text.keep.user")))
#define MDEV_NO_INIT           __attribute__((section(".bss.no_init.user")))
#define MDEV_RUN_IN_RAM        __attribute__((section(".run_in_ram")))
#define MDEV_WEAK              __attribute__((weak))
#define MDEV_UNUSED            __attribute__((unused))
#define MDEV_PRINT_ADDR(NAME)  asm("addr_mlds_addr_"NAME":")
/* BUILD_NAME BUILD_DATE BUILD_AUTH defined in make.mk */
#define MDEV_BUILD_NAME        BUILD_NAME
#define MDEV_BUILD_DATE        BUILD_DATE
#define MDEV_BUILD_AUTH        BUILD_AUTH

#define _mDevBitOp(ADDR, OFFSET, MODE) do { \
	if(MODE) { \
	ADDR |= 0x1<<(OFFSET); \
	} else { \
	ADDR &= ~(0x1U<<(OFFSET)); \
	} \
	} while(0)

#define _mDevU32EndianSwap(OUT, IN, COUNT) do { \
	uint32_t count; \
	for(count = 0; count < COUNT; count++) { \
		(OUT)[count] = ((((IN)[count] >> 0)  & 0xFF) << 24) | \
		               ((((IN)[count] >> 8)  & 0xFF) << 16) | \
		               ((((IN)[count] >> 16) & 0xFF) << 8)  | \
		               ((((IN)[count] >> 24) & 0xFF) << 0); \
	} \
	} while(0)

#define _mDevU8ToU16(U8)  (((U8)[0]<<8) | ((U8)[1]))
#define _mDevU16ToU8(U8, U16)  do { \
	(U8)[0] = (U16)>>8; \
	(U8)[1] = (U16)&0xFF; \
	} while(0)
#define _mDevU8ToU32(U8)  (((U8)[0]<<24) | ((U8)[1]<<16) | ((U8)[2]<<8) |((U8)[3]))
#define _mDevU32ToU8(U8, U32)  do { \
	(U8)[0] = ((U32)>>24)&0xFF; \
	(U8)[1] = ((U32)>>16)&0xFF; \
	(U8)[2] = ((U32)>>8)&0xFF; \
	(U8)[3] = (U32)&0xFF; \
	} while(0)

#endif /* _MDEV_H_ */
