#ifndef _PAD_HW_H_
#define _PAD_HW_H_

#include "soc.h"

typedef struct {
	_RW CON;         /* Offset 0x00 */
	_RW DAT;         /* Offset 0x04 */
	_RW PUD;         /* Offset 0x08 */
	_RW DRV;         /* Offset 0x0C */
	_RW CONPND;      /* Offset 0x10 */
	_RW PUDPDN;      /* Offset 0x14 */
	_NU RESERVE0[2]; /* Reserve 0x08 */
} PAD_Struct;        /* Sizes 32 */

typedef struct {
	PAD_Struct A0;                 /* Offset 0x0000 */
	PAD_Struct A1;                 /* Offset 0x0020 */
	PAD_Struct B;                  /* Offset 0x0040 */
	PAD_Struct C0;                 /* Offset 0x0060 */
	PAD_Struct C1;                 /* Offset 0x0080 */
	PAD_Struct D0;                 /* Offset 0x00A0 */
	PAD_Struct D1;                 /* Offset 0x00C0 */
	PAD_Struct E0;                 /* Offset 0x00E0 */
	PAD_Struct E1;                 /* Offset 0x0100 */
	PAD_Struct F0;                 /* Offset 0x0120 */
	PAD_Struct F1;                 /* Offset 0x0140 */
	PAD_Struct F2;                 /* Offset 0x0160 */
	PAD_Struct F3;                 /* Offset 0x0180 */
	PAD_Struct G0;                 /* Offset 0x01A0 */
	PAD_Struct G1;                 /* Offset 0x01C0 */
	PAD_Struct G2;                 /* Offset 0x01E0 */
	PAD_Struct G3;                 /* Offset 0x0200 */
	_NU RESERVE0[8];               /* Reserve 0x0020 */ /* GPIOI Only used for I2S0 and PCM0. */
	PAD_Struct J0;                 /* Offset 0x0240 */
	PAD_Struct J1;                 /* Offset 0x0260 */
	PAD_Struct J2;                 /* Offset 0x0280 */
	PAD_Struct J3;                 /* Offset 0x02A0 */
	PAD_Struct J4;                 /* Offset 0x02C0 */
	_NU RESERVE1[264];             /* Reserve 0x0420 */ /* MP0 - ETC2. */
    _RW A0_INT_CON;                /* Offset 0x0700 */ 
    _RW A1_INT_CON;                /* Offset 0x0704 */
    _RW B_INT_CON;                 /* Offset 0x0708 */
    _RW C0_INT_CON;                /* Offset 0x070C */
    _RW C1_INT_CON;                /* Offset 0x0710 */
    _RW D0_INT_CON;                /* Offset 0x0714 */
    _RW D1_INT_CON;                /* Offset 0x0718 */
    _RW E0_INT_CON;                /* Offset 0x071C */
    _RW E1_INT_CON;                /* Offset 0x0720 */
    _RW F0_INT_CON;                /* Offset 0x0724 */
    _RW F1_INT_CON;                /* Offset 0x0728 */
    _RW F2_INT_CON;                /* Offset 0x072C */
    _RW F3_INT_CON;                /* Offset 0x0730 */
    _RW G0_INT_CON;                /* Offset 0x0734 */
    _RW G1_INT_CON;                /* Offset 0x0738 */
    _RW G2_INT_CON;                /* Offset 0x073C */
    _RW G3_INT_CON;                /* Offset 0x0740 */
    _RW J0_INT_CON;                /* Offset 0x0744 */
    _RW J1_INT_CON;                /* Offset 0x0748 */
    _RW J2_INT_CON;                /* Offset 0x074C */
    _RW J3_INT_CON;                /* Offset 0x0750 */
    _RW J4_INT_CON;                /* Offset 0x0754 */
    _NU RESERVE2[42];              /* Reserve 0x00A8 */
    _RW A0_INT_FLTCON[2];          /* Offset 0x0800 */ 
    _RW A1_INT_FLTCON[2];          /* Offset 0x0808 */
    _RW B_INT_FLTCON[2];           /* Offset 0x0810 */
    _RW C0_INT_FLTCON[2];          /* Offset 0x0818 */
    _RW C1_INT_FLTCON[2];          /* Offset 0x0820 */
    _RW D0_INT_FLTCON[2];          /* Offset 0x0828 */
    _RW D1_INT_FLTCON[2];          /* Offset 0x0830 */
    _RW E0_INT_FLTCON[2];          /* Offset 0x0838 */
    _RW E1_INT_FLTCON[2];          /* Offset 0x0840 */
    _RW F0_INT_FLTCON[2];          /* Offset 0x0848 */
    _RW F1_INT_FLTCON[2];          /* Offset 0x0850 */
    _RW F2_INT_FLTCON[2];          /* Offset 0x0858 */
    _RW F3_INT_FLTCON[2];          /* Offset 0x0860 */
    _RW G0_INT_FLTCON[2];          /* Offset 0x0868 */
    _RW G1_INT_FLTCON[2];          /* Offset 0x0870 */
    _RW G2_INT_FLTCON[2];          /* Offset 0x0878 */
    _RW G3_INT_FLTCON[2];          /* Offset 0x0880 */
    _RW J0_INT_FLTCON[2];          /* Offset 0x0888 */
    _RW J1_INT_FLTCON[2];          /* Offset 0x0890 */
    _RW J2_INT_FLTCON[2];          /* Offset 0x0898 */
    _RW J3_INT_FLTCON[2];          /* Offset 0x08A0 */
    _RW J4_INT_FLTCON[2];          /* Offset 0x08A8 */
    _NU RESERVE3[20];              /* Reserve 0x0050 */
    _RW A0_INT_MASK;               /* Offset 0x0900 */ 
    _RW A1_INT_MASK;               /* Offset 0x0904 */
    _RW B_INT_MASK;                /* Offset 0x0908 */
    _RW C0_INT_MASK;               /* Offset 0x090C */
    _RW C1_INT_MASK;               /* Offset 0x0910 */
    _RW D0_INT_MASK;               /* Offset 0x0914 */
    _RW D1_INT_MASK;               /* Offset 0x0918 */
    _RW E0_INT_MASK;               /* Offset 0x091C */
    _RW E1_INT_MASK;               /* Offset 0x0920 */
    _RW F0_INT_MASK;               /* Offset 0x0924 */
    _RW F1_INT_MASK;               /* Offset 0x0928 */
    _RW F2_INT_MASK;               /* Offset 0x092C */
    _RW F3_INT_MASK;               /* Offset 0x0930 */
    _RW G0_INT_MASK;               /* Offset 0x0934 */
    _RW G1_INT_MASK;               /* Offset 0x0938 */
    _RW G2_INT_MASK;               /* Offset 0x093C */
    _RW G3_INT_MASK;               /* Offset 0x0940 */
    _RW J0_INT_MASK;               /* Offset 0x0944 */
    _RW J1_INT_MASK;               /* Offset 0x0948 */
    _RW J2_INT_MASK;               /* Offset 0x094C */
    _RW J3_INT_MASK;               /* Offset 0x0950 */
    _RW J4_INT_MASK;               /* Offset 0x0954 */
    _NU RESERVE4[42];              /* Reserve 0x00A8 */
    _RW A0_INT_PEND;               /* Offset 0x0A00 */ 
    _RW A1_INT_PEND;               /* Offset 0x0A04 */
    _RW B_INT_PEND;                /* Offset 0x0A08 */
    _RW C0_INT_PEND;               /* Offset 0x0A0C */
    _RW C1_INT_PEND;               /* Offset 0x0A10 */
    _RW D0_INT_PEND;               /* Offset 0x0A14 */
    _RW D1_INT_PEND;               /* Offset 0x0A18 */
    _RW E0_INT_PEND;               /* Offset 0x0A1C */
    _RW E1_INT_PEND;               /* Offset 0x0A20 */
    _RW F0_INT_PEND;               /* Offset 0x0A24 */
    _RW F1_INT_PEND;               /* Offset 0x0A28 */
    _RW F2_INT_PEND;               /* Offset 0x0A2C */
    _RW F3_INT_PEND;               /* Offset 0x0A30 */
    _RW G0_INT_PEND;               /* Offset 0x0A34 */
    _RW G1_INT_PEND;               /* Offset 0x0A38 */
    _RW G2_INT_PEND;               /* Offset 0x0A3C */
    _RW G3_INT_PEND;               /* Offset 0x0A40 */
    _RW J0_INT_PEND;               /* Offset 0x0A44 */
    _RW J1_INT_PEND;               /* Offset 0x0A48 */
    _RW J2_INT_PEND;               /* Offset 0x0A4C */
    _RW J3_INT_PEND;               /* Offset 0x0A50 */
    _RW J4_INT_PEND;               /* Offset 0x0A54 */
    _NU RESERVE5[42];              /* Reserve 0x00A8 */
    _RW GPIO_INT_GRPPRI;           /* Offset 0x0B00 */
    _RW GPIO_INT_PRIORITY;         /* Offset 0x0B04 */
    _OR GPIO_INT_SERVICE;          /* Offset 0x0B08 */
    _OR GPIO_INT_SERVICE_PEND;     /* Offset 0x0B0C */
    _RW GPIO_INT_GRPFIXPRI;        /* Offset 0x0B10 */
    _RW A0_INT_FIXPRI;             /* Offset 0x0B14 */ 
    _RW A1_INT_FIXPRI;             /* Offset 0x0B18 */
    _RW B_INT_FIXPRI;              /* Offset 0x0B1C */
    _RW C0_INT_FIXPRI;             /* Offset 0x0B20 */
    _RW C1_INT_FIXPRI;             /* Offset 0x0B24 */
    _RW D0_INT_FIXPRI;             /* Offset 0x0B28 */
    _RW D1_INT_FIXPRI;             /* Offset 0x0B2C */
    _RW E0_INT_FIXPRI;             /* Offset 0x0B30 */
    _RW E1_INT_FIXPRI;             /* Offset 0x0B34 */
    _RW F0_INT_FIXPRI;             /* Offset 0x0B38 */
    _RW F1_INT_FIXPRI;             /* Offset 0x0B3C */
    _RW F2_INT_FIXPRI;             /* Offset 0x0B40 */
    _RW F3_INT_FIXPRI;             /* Offset 0x0B44 */
    _RW G0_INT_FIXPRI;             /* Offset 0x0B48 */
    _RW G1_INT_FIXPRI;             /* Offset 0x0B4C */
    _RW G2_INT_FIXPRI;             /* Offset 0x0B50 */
    _RW G3_INT_FIXPRI;             /* Offset 0x0B54 */
    _RW J0_INT_FIXPRI;             /* Offset 0x0B58 */
    _RW J1_INT_FIXPRI;             /* Offset 0x0B5C */
    _RW J2_INT_FIXPRI;             /* Offset 0x0B60 */
    _RW J3_INT_FIXPRI;             /* Offset 0x0B64 */
    _RW J4_INT_FIXPRI;             /* Offset 0x0B68 */
    _NU RESERVE6[37];              /* Reserve 0x94 */
    PAD_Struct H0;                 /* Offset 0x0C00 */
    PAD_Struct H1;                 /* Offset 0x0C20 */
    PAD_Struct H2;                 /* Offset 0x0C40 */
    PAD_Struct H3;                 /* Offset 0x0C60 */
    _NU RESERVE7[96];              /* Reserve 0x180 */
    _RW EXT_INT_CON[4];            /* Offset 0x0E00 */
    _NU RESERVE8[28];              /* Reserve 0x70 */
    _RW EXT_INT_FLTCON[4][2];      /* Offset 0x0E80 */
    _NU RESERVE9[24];              /* Reserve 0x60 */
    _RW EXT_INT_MASK[4];           /* Offset 0x0F00 */
    _NU RESERVE10[12];             /* Reserve 0x30 */
    _RW EXT_INT_PEND[4];           /* Offset 0x0F40 */
    _NU RESERVE11[12];             /* Reserve 0x30 */
    _RW PDNEN;                     /* Offset 0x0F80 */
} GPAD_Struct;

static GPAD_Struct * const GPAD = (GPAD_Struct *)GPIO_BASE_ADDR;

#endif /* _PAD_HW_H_ */
