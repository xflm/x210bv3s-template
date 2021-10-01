#include "pad_hw.h"
#include "pad_conf.h"
#include "pad.h"
#include <stdint.h>


void PAD_Init(void)
{
	uint32_t tmp;

	/**********************_IO-OUT-LED_***********************/
	tmp = GPAD->J0.CON;
	tmp &= ~(PAD_CON_Px_MASK<<PAD_CON_P3 | PAD_CON_Px_MASK<<PAD_CON_P4 |
	         PAD_CON_Px_MASK<<PAD_CON_P5);
	tmp |= PAD_CON_Px_OUTPUT<<PAD_CON_P3 | PAD_CON_Px_OUTPUT<<PAD_CON_P4 |
	                          PAD_CON_Px_OUTPUT<<PAD_CON_P5;
	GPAD->J0.CON = tmp;

	tmp = GPAD->J0.PUD;
	tmp &= ~(PAD_PUD_Px_MASK<<PAD_PUD_P3 | PAD_PUD_Px_MASK<<PAD_PUD_P4 |
	                        PAD_PUD_Px_MASK<<PAD_PUD_P5);
	tmp |= PAD_PUD_Px_DISABLE<<PAD_PUD_P3 | PAD_PUD_Px_DISABLE<<PAD_PUD_P4 |
	                           PAD_PUD_Px_DISABLE<<PAD_PUD_P5;
	GPAD->J0.PUD = tmp;

	tmp = GPAD->J0.DAT;
	tmp &= ~(PAD_DAT_Px_MASK<<PAD_DAT_P3 | PAD_DAT_Px_MASK<<PAD_DAT_P4 |
	         PAD_DAT_Px_MASK<<PAD_DAT_P5);
	tmp |= PAD_DAT_Px_HIGH<<PAD_DAT_P3 | PAD_DAT_Px_HIGH<<PAD_DAT_P4 |
	                       PAD_DAT_Px_HIGH<<PAD_DAT_P5;
	GPAD->J0.DAT = tmp;
	/**********************_IO-OUT-LED_***********************/

	/*********************_TOUT1-LED-PWM_*********************/
	tmp = GPAD->D0.CON;
	tmp &= ~(PAD_CON_Px_MASK<<PAD_CON_P1);
	tmp |= PAD_CON_D0_P1_TOUT1;
	GPAD->D0.CON = tmp;

	tmp = GPAD->D0.PUD;
	tmp &= ~(PAD_PUD_Px_MASK<<PAD_PUD_P1);
	tmp |= PAD_PUD_Px_DISABLE<<PAD_PUD_P1;
	GPAD->D0.PUD = tmp;
	/*********************_TOUT1-LED-PWM_*********************/

	/*************************_UART0_*************************/
	tmp = GPAD->A0.CON;
	tmp &= ~(PAD_CON_Px_MASK<<PAD_CON_P3 | PAD_CON_Px_MASK<<PAD_CON_P4 |
	         PAD_CON_Px_MASK<<PAD_CON_P5);
	tmp |= PAD_CON_A0_P0_UART0_RX | PAD_CON_A0_P1_UART0_TX;
	GPAD->A0.CON = tmp;

	tmp = GPAD->A0.PUD;
	tmp &= ~(PAD_PUD_Px_MASK<<PAD_PUD_P0 | PAD_PUD_Px_MASK<<PAD_PUD_P1);
	tmp |= PAD_PUD_Px_UP<<PAD_PUD_P0 | PAD_PUD_Px_UP<<PAD_PUD_P1;
	GPAD->A0.PUD = tmp;
	/*************************_UART0_*************************/
}
