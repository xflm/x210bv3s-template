#ifndef _UART_HW_H_
#define _UART_HW_H_

#include "soc.h"

typedef struct {
	_RW LCON;           /* Offset 0x0000 */
	_RW CON;            /* Offset 0x0004 */
	_RW FCON;           /* Offset 0x0008 */
	_RW MCON;           /* Offset 0x000C */
	_OR TRSTATE;        /* Offset 0x0010 */
	_OR ERSTATE;        /* Offset 0x0014 */
	_OR FSTATE;         /* Offset 0x0018 */
	_OR MSTATE;         /* Offset 0x001C */
	_OW TXH;            /* Offset 0x0020 */
	_OR RXH;            /* Offset 0x0024 */
	_RW BRDIV;          /* Offset 0x0028 */
	_RW DIVSLOT;        /* Offset 0x002C */
	_RW INTP;           /* Offset 0x0030 */
	_RW INTSP;          /* Offset 0x0034 */
	_RW INTM;           /* Offset 0x0038 */
	_NU RESERVE0[241];  /* Reserve 0x03C4 */
} * const UART_Struct; /* Sizes 0x400 */


#endif /* _UART_HW_H_ */
