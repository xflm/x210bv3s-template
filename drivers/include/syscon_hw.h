#ifndef _CLK_HW_H_
#define _CLK_HW_H_

#include "soc.h"

typedef struct {
	_RW APP_LOCK;           /* Offset 0x0000 */
	_NU RESERVED0[1];       /* Reserved 0x0004 */
	_RW MPLL_LOCK;          /* Offset 0x0008 */
	_NU RESERVED1[1];       /* Reserved 0x0004 */
	_RW EPLL_LOCK;          /* Offset 0x0010 */
	_NU RESERVED2[3];       /* Reserved 0x0010 */
	_RW VPLL_LOCK;          /* Offset 0x0020 */
	_NU RESERVED3[55];      /* Offset 0x00DC */
	_RW APLL_CON0;          /* Offset 0x0100 */
	_RW APLL_CON1;          /* Offset 0x0104 */
	_RW MPLL_CON;           /* Offset 0x0108 */
	_NU RESERVED4[1];       /* Reserved 0x0004 */
	_RW EPLL_CON0;          /* Offset 0x0110 */
	_RW EPLL_CON1;          /* Offset 0x0114 */
	_NU RESERVED5[2];       /* Reserved 0x0008 */
	_RW VPLL_CON;           /* Offset 0x0120 */
	_NU RESERVED6[55];      /* Reserved 0x00DC */
	_RW CLK_SRC0;           /* Offset 0x0200 */
	_RW CLK_SRC1;           /* Offset 0x0204 */
	_RW CLK_SRC2;           /* Offset 0x0208 */
	_RW CLK_SRC3;           /* Offset 0x020C */
	_RW CLK_SRC4;           /* Offset 0x0210 */
	_RW CLK_SRC5;           /* Offset 0x0214 */
	_RW CLK_SRC6;           /* Offset 0x0218 */
	_NU RESERVED7[25];      /* Reserved 0x0065 */
	_RW CLK_SRC_MASK[2];    /* Offset 0x0280 */
	_NU RESERVED8[30];      /* Reserved 0x0078 */
	_RW CLK_DIV0;           /* Offset 0x0300 */
	_RW CLK_DIV1;           /* Offset 0x0304 */
	_RW CLK_DIV2;           /* Offset 0x0308 */
	_RW CLK_DIV3;           /* Offset 0x030C */
	_RW CLK_DIV4;           /* Offset 0x0310 */
	_RW CLK_DIV5;           /* Offset 0x0314 */
	_RW CLK_DIV6;           /* Offset 0x0318 */
	_RW CLK_DIV7;           /* Offset 0x031C */
	_NU RESERVED9[74];      /* Reserved 0x011C */
	_RW CLK_GATE_SCLK;      /* Offset 0x0444 */
	_NU RESERVED10[6];      /* Reserved 0x0018 */
	_RW CLK_GATE_IP0;       /* Offset 0x0460 */
	_RW CLK_GATE_IP1;       /* Offset 0x0464 */
	_RW CLK_GATE_IP2;       /* Offset 0x0468 */
	_RW CLK_GATE_IP3;       /* Offset 0x046C */
	_RW CLK_GATE_IP4;       /* Offset 0x0470 */
	_NU RESERVED11[3];      /* Offset 0x000C */
	_RW CLK_GATE_BLOCK;     /* Offset 0x0480 */
	_RW CLK_GATE_IP5;       /* Offset 0x0484 */
	_NU RESERVED12[30];     /* Reserved 0x0078 */
	_RW CLK_OUT;            /* Offset 0x0500 */
	_NU RESERVED13[703];    /* Reserved 0x0AFC */
	_OR CLK_DIV_STAT0;      /* Offset 0x1000 */
	_OR CLK_DIV_STAT1;      /* Offset 0x1004 */
	_NU RESERVED14[62];     /* Reserved 0x00F8 */
	_OR CLK_MUX_STAT0;      /* Offset 0x1100 */
	_OR CLK_MUX_STAT1;      /* Offset 0x1104 */
	_NU RESERVED15[958];    /* Reserved 0x0EF8 */
	_RW SWRESET;            /* Offset 0x2000 */
	_NU RESERVED16[1023];   /* Reserved 0x0FFC */
	_RW DCGIDX_MAP0;        /* Offset 0x3000 */
	_RW DCGIDX_MAP1;        /* Offset 0x3004 */
	_RW DCGIDX_MAP2;        /* Offset 0x3008 */
	_NU RESERVED17[5];      /* Reserved 0x0014 */
	_RW DCGPERF_MAP0;       /* Offset 0x3020 */
	_RW DCGPERF_MAP1;       /* Offset 0x3024 */
	_NU RESERVED18[6];      /* Reserved 0x0018 */
	_RW DVCIDX_MAP;         /* Offset 0x3040 */
	_NU RESERVED19[7];      /* Reserved 0x001C */
	_RW FREQ_CPU;           /* Offset 0x3060 */
	_RW FREQ_DPM;           /* Offset 0x3064 */
	_NU RESERVED20[6];     /* Reserved 0x0018 */
	_RW DVSEMCLK_EN;        /* Offset 0x3080 */
	_RW MAXPERF;            /* Offset 0x3084 */
	_NU RESERVED21[30];     /* Reserved 0x0078 */
	_RW APLL_CON0_L8;       /* Offset 0x3100 */
	_RW APLL_CON0_L7;       /* Offset 0x3104 */
	_RW APLL_CON0_L6;       /* Offset 0x3108 */
	_RW APLL_CON0_L5;       /* Offset 0x310C */
	_RW APLL_CON0_L4;       /* Offset 0x3110 */
	_RW APLL_CON0_L3;       /* Offset 0x3114 */
	_RW APLL_CON0_L2;       /* Offset 0x3118 */
	_RW APLL_CON0_L1;       /* Offset 0x311C */
	_NU RESERVED22[56];     /* Reserved 0x00E0 */
	_RW CLK_DIV_IEM_L8;     /* Offset 0x3200 */
	_RW CLK_DIV_IEM_L7;     /* Offset 0x3204 1*/
	_RW CLK_DIV_IEM_L6;     /* Offset 0x3208 */
	_RW CLK_DIV_IEM_L5;     /* Offset 0x320C */
	_RW CLK_DIV_IEM_L4;     /* Offset 0x3210 */
	_RW CLK_DIV_IEM_L3;     /* Offset 0x3214 */
	_RW CLK_DIV_IEM_L2;     /* Offset 0x3218 */
	_RW CLK_DIV_IEM_L1;     /* Offset 0x321C */
	_NU RESERVED23[56];     /* Reserved 0x00E0 */
	_RW APLL_CON1_L8;       /* Offset 0x3300 */
	_RW APLL_CON1_L7;       /* Offset 0x3304 */
	_RW APLL_CON1_L6;       /* Offset 0x3308 */
	_RW APLL_CON1_L5;       /* Offset 0x330C */
	_RW APLL_CON1_L4;       /* Offset 0x3310 */
	_RW APLL_CON1_L3;       /* Offset 0x3314 */
	_RW APLL_CON1_L2;       /* Offset 0x3318 */
	_RW APLL_CON1_L1;       /* Offset 0x331C */
	_NU RESERVED24[2936];   /* Reserved 0x2DE0 */
	_RW GENERAL_CTRL;       /* Offset 0x6100 */
	_NU RESERVED25[961];    /* Reserved 0x0F04 */
	_RW DISPLAY_CONTROL;    /* Offset 0x7008 */
	_RW AUDIO_ENDIAN;       /* Offset 0x700C */
} SYSCON_Struct;

static SYSCON_Struct * const SYSCON = (SYSCON_Struct *)SYSCON_BASE_ADDR;

#endif /* _CLK_HW_H_ */
