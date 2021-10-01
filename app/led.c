#include "led.h"
#include "pad_hw.h"
#include "pad_conf.h"
#include "timer_hw.h"
#include "timer_conf.h"
#include <stdint.h>

static const uint32_t ledState[] = {
    /* 0 */ 0,
    /* 1 */ (PAD_DAT_Px_MASK<<PAD_DAT_P3),
    /* 2 */ (PAD_DAT_Px_MASK<<PAD_DAT_P4),
    /* 3 */ ((PAD_DAT_Px_MASK<<PAD_DAT_P3)|(PAD_DAT_Px_MASK<<PAD_DAT_P4)),
    /* 4 */ (PAD_DAT_Px_MASK<<PAD_DAT_P5),
    /* 5 */ ((PAD_DAT_Px_MASK<<PAD_DAT_P3)|(PAD_DAT_Px_MASK<<PAD_DAT_P5)),
    /* 6 */ ((PAD_DAT_Px_MASK<<PAD_DAT_P4)|(PAD_DAT_Px_MASK<<PAD_DAT_P5)),
    /* 7 */ ((PAD_DAT_Px_MASK<<PAD_DAT_P3)|(PAD_DAT_Px_MASK<<PAD_DAT_P4)
              |(PAD_DAT_Px_MASK<<PAD_DAT_P5)),
};

static void LED_PadInit(void)
{
#if 0
	uint32_t tmp;

	/**********************_IO-OUT-LED_***********************/
	tmp = GPAD->J0.CON;
	tmp &= ~(PAD_CON_PX_MASK<<PAD_CON_P3 | PAD_CON_PX_MASK<<PAD_CON_P4 |
	         PAD_CON_PX_MASK<<PAD_CON_P5);
	tmp |= PAD_CON_PX_OUTPUT<<PAD_CON_P3 | PAD_CON_PX_OUTPUT<<PAD_CON_P4 |
	                          PAD_CON_PX_OUTPUT<<PAD_CON_P5;
	GPAD->J0.CON = tmp;

	tmp = GPAD->J0.PUD;
	tmp &= ~(PAD_PUD_PX_MASK<<PAD_PUD_P3 | PAD_PUD_PX_MASK<<PAD_PUD_P4 |
	                        PAD_PUD_PX_MASK<<PAD_PUD_P5);
	tmp |= PAD_PUD_PX_DISABLE<<PAD_PUD_P3 | PAD_PUD_PX_DISABLE<<PAD_PUD_P4 |
	                           PAD_PUD_PX_DISABLE<<PAD_PUD_P5;
	GPAD->J0.PUD = tmp;

	tmp = GPAD->J0.DAT;
	tmp &= ~(PAD_DAT_PX_MASK<<PAD_DAT_P3 | PAD_DAT_PX_MASK<<PAD_DAT_P4 |
	         PAD_DAT_PX_MASK<<PAD_DAT_P5);
	tmp |= PAD_DAT_PX_LOW<<PAD_DAT_P3 | PAD_DAT_PX_LOW<<PAD_DAT_P4 |
	                       PAD_DAT_PX_LOW<<PAD_DAT_P5;
	GPAD->J0.DAT = tmp;
	/**********************_IO-OUT-LED_***********************/

	/*********************_TOUT1-LED-PWM_*********************/
	tmp = GPAD->D0.CON;
	tmp &= ~(PAD_CON_PX_MASK<<PAD_CON_P1);
	tmp |= PAD_CON_D0_P1_TOUT1;
	GPAD->D0.CON = tmp;

	tmp = GPAD->D0.PUD;
	tmp &= ~(PAD_PUD_PX_MASK<<PAD_PUD_P1);
	tmp |= PAD_PUD_PX_DISABLE<<PAD_PUD_P1;
	GPAD->D0.PUD = tmp;
	/*********************_TOUT1-LED-PWM_*********************/
#endif
}

static void LED_PWM_Init(void)
{
#if 0
	uint32_t tmp;

	/*********************_TIMER1-LED-PWM_********************/
	tmp = GTIMER->CFG0;
	tmp &= ~(TIMER_CFG0_x_MASK<<TIMER_CFG0_PRESCALER01);
	tmp |= (TIMER_CFG0_PRESCALER_VALUE_1_255*1)<<TIMER_CFG0_PRESCALER01;
	GTIMER->CFG0 = tmp;
	GTIMER->T1.CNTB = 33000000-1;
	GTIMER->T1.CMPB = 16500000;

	tmp = GTIMER->CFG1;
	tmp &= ~(TIMER_CFG1_Tx_MASK<<TIMER_CFG1_T1);
	tmp |= TIMER_CFG1_Tx_DIVIDER_1<<TIMER_CFG1_T1;
	GTIMER->CFG1 = tmp;

	GTIMER->CON |= TIMER_CON_T1_START            |
	               TIMER_CON_T1_MANUAL_UPDATE_EN |
	               TIMER_CON_T1_OUT_INVERTER_ON  |
	               TIMER_CON_T1_AUTO_RELOAD_ON;
	GTIMER->CON &= TIMER_CON_T1_MANUAL_UPDATE_DIS;
	/*********************_TIMER1-LED-PWM_********************/
#endif
}

static void LED_DriveInit(void)
{

}

void LED_Init(void)
{
	LED_PadInit();
	LED_DriveInit();
	LED_PWM_Init();
}

static void LED_SetState(LED_e led, LED_State_e state)
{
	uint32_t tmp;

	if(led > 0x7)
	{
		return;
	}

	tmp = ledState[led];

	if(state == LED_STATE_ON)
	{
		GPAD->J0.DAT &= ~tmp;
	}
	else
	{
		GPAD->J0.DAT |= tmp;
	}
}

LED_State_e LED_State(LED_e led)
{
	uint32_t tmp;

	if(led > 0x7)
	{
		return LED_STATE_OFF;
	}

	tmp = ledState[led];

	return GPAD->J0.DAT & tmp ? LED_STATE_OFF : LED_STATE_ON;
}

void LED_On(LED_e led)
{
	LED_SetState(led, LED_STATE_ON);
}

void LED_Off(LED_e led)
{
	LED_SetState(led, LED_STATE_OFF);
}

void LED_OnOff(LED_e led)
{
	uint32_t tmp;

	if(led > 0x7)
	{
		return;
	}

	tmp = ledState[led];
	GPAD->J0.DAT ^= tmp;
}

void LED_PWM(uint32_t onMs, uint32_t offMs)
{
	/* If GTIMER->T1.CMPB > GTIMER->T1.CNTB TOUT1 is high, LED_PWM off. */
	if(onMs == 0)
	{
		GTIMER->T1.CMPB = 0x1;
		GTIMER->T1.CNTB = 0x0;
		GTIMER->CON &= TIMER_CON_T1_STOP;
		GTIMER->CON |= TIMER_CON_T1_MANUAL_UPDATE_EN;
		GTIMER->CON &= TIMER_CON_T1_MANUAL_UPDATE_DIS;

		return;
	}

	if(offMs == 0)
	{
		GTIMER->T1.CMPB = 0x0;
		GTIMER->T1.CNTB = 0x1;
		GTIMER->CON &= TIMER_CON_T1_STOP;
		GTIMER->CON |= TIMER_CON_T1_MANUAL_UPDATE_EN;
		GTIMER->CON &= TIMER_CON_T1_MANUAL_UPDATE_DIS;

		return;
	}

	GTIMER->T1.CNTB = 33*(onMs+offMs);
	GTIMER->T1.CMPB = 33*onMs;
	GTIMER->CON |= TIMER_CON_T1_START            |
				   TIMER_CON_T1_MANUAL_UPDATE_EN |
				   TIMER_CON_T1_OUT_INVERTER_ON  |
				   TIMER_CON_T1_AUTO_RELOAD_ON;
	GTIMER->CON &= TIMER_CON_T1_MANUAL_UPDATE_DIS;
}
