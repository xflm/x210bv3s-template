#ifndef _TIM_HW_H_
#define _TIM_HW_H_

#include "soc.h"

typedef struct {
	_RW TCFG;             /* offset 0x0000 */
	_RW TCON;             /* offset 0x0004 */
	_RW TICNTB;           /* offset 0x0008 */
	_OR TICNTO;           /* offset 0x000C */
	_RW TFCNTB;           /* offset 0x0010 */
	_NU RESERVED0[1];     /* reserved 0x0004 */
	_RW ICNTB;            /* offset 0x0018 */
	_OR ICNTO;            /* offset 0x001C */
	_RW INT_CSTAT;        /* offset 0x0020 */
} * const TIM_Struct;     /* size 0x0024 */

#define _TIM_Reset(dev)   ((TIM_Struct)(dev))->TCFG = 0x1<<16

#define _TIM_Stop(dev)    do { \
		TIM_Struct pTim = (TIM_Struct)(dev); \
		pTim->INT_CSTAT &= ~(0x1<<0);\
		pTim->TCON &= ~(0x1<<3); \
		pTim->TCON &= ~(0x1<<0);\
	} while(0)

#endif /* _TIM_HW_H_ */
