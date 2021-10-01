#ifndef _VIC_HW_H_
#define _VIC_HW_H_

#include "soc.h"

typedef struct {
	/* Show the state of interrupt after masking by INT_ENABLE and INT_SELECT. */
	_OR IRQ_STATUS;           /* Offset 0x0000 */
	_OR FIQ_STATUS;           /* Offset 0x0004 */
	/* Show the state of FIQ/IRQ interrupt before masking by INT_ENABLE and INT_SELECT. */
	_OR RAW_STATUS;           /* Offset 0x0008 */
	/* 0:IRQ 1:FIQ. */
	_RW INT_SELECT;           /* Offset 0x000C */
	/* R: 0:dis,1:en. W: 0:no effect,1:enable. Must use INT_CLEAR to disable. */
	_RW INT_ENABLE;           /* Offset 0x0010 */
	/* W: 0:no effect,1:disable interrupt in INT_ENABLE. */
	_OW INT_CLEAR;            /* Offset 0x0014 */
	/* R: 0:inactive,1:active. W: 0:no effect,1:generate a interrupt. */
	_RW SOFT_INT;             /* Offset 0x0018 */
	/* W: 0:no effect,1:clear corresponding bits in SOFT_INT. */
	_OW SOFT_INT_CLEAR;       /* Offset 0x001C */
	/* Only privileged mode can access PROTECTION. */
	/* 0:user and privileged both can access VIC. */
	/* 1:only privileged can access VIC. */
	_RW PROTECTION;           /* Offset 0x0020 */
	/* Only [15:0] to use. each bit is applied to each of the 16 interrupt priority levels. */
	_RW PRIORITY_MASK;        /* Offset 0x0024 */
	_RW PRIORITY_DAISY;       /* Offset 0x0028 */
	_NU RESERVED0[53];        /* Reserved 0x00D4*/
	_RW VECT_ADDR[32];        /* Offset 0x0100 */
	_NU RESERVED1[32];        /* Reserved 0x0080*/
	/* [3:0] to use, 16 interrupt priority levels. */
	_RW VEC_PRIORITY[32];     /* Offset 0x0200 */
	_NU RESERVED2[800];       /* Reserved 0x0C80*/
	_RW ADDRESS;              /* Offset 0x0F00 */
	_NU RESERVED3[55];        /* Reserved 0x00DC*/
	_OR PERIPHID[4];          /* Offset 0x0FE0 */
	_OR PCELLID[4];           /* Offset 0x0FF0 */
	_NU RESERVED4[261120];    /* Reserved 0xFF000*/
} VIC_Struct;

typedef struct {
	VIC_Struct V[4];
} GVIC_Struct;

static GVIC_Struct * const GVIC = (GVIC_Struct *)VIC0_BASE_ADDR;

#endif /* _VIC_HW_H_ */
