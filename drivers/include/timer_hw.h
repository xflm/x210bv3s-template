#ifndef _TIMER_HW_H_
#define _TIMER_HW_H_

#include "soc.h"

typedef struct {
	_RW CNTB;     /* Offset 0x0000 */
	_RW CMPB;     /* Offset 0x0004 */
	_OR CNTO;     /* Offset 0x0008 */
} TIMER_Struct;   /* Sizes 12 */

typedef struct {
	_RW CFG0;         /* Offset 0x0000 */
	_RW CFG1;         /* Offset 0x0004 */
	_RW CON;          /* Offset 0x0008 */
	TIMER_Struct T0;  /* Offset 0x000C */
	TIMER_Struct T1;  /* Offset 0x0018 */
	TIMER_Struct T2;  /* Offset 0x0024 */
	TIMER_Struct T3;  /* Offset 0x0030 */
	_RW T4CNTB;       /* Offset 0x003C */
	_OR T4CNTO;       /* Offset 0x0040 */
	_RW INT_CSTAT;    /* Offset 0x0044 */
} GTIMER_Struct;

static GTIMER_Struct * const GTIMER = (GTIMER_Struct *)PWM_BASE_ADDR;

#endif /* _TIMER_HW_H_ */
