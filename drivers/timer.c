#include "timer_hw.h"
#include "timer_conf.h"
#include "timer.h"
#include <stdint.h>
#include "led.h"
#include "vic.h"

static void TIMER_InterruptInit(void)
{
	VIC_ConfigStruct config;

	GTIMER->INT_CSTAT |= TIMER_INT_CSTAT_T4_EN;

	config.func     = TIMER4_Isr;
	config.port     = VIC0_PORT_TIMER4;
	config.priority = VIC_PRICRITY_0;
	config.state    = VIC_STATE_EN;
	config.type     = VIC_TYPE_IRQ;
	config.vic      = VIC0;
	VIC_Config(&config);
}

void TIMER_Init(void)
{
	uint32_t tmp;

	tmp = GTIMER->CFG0;
	tmp &= ~(TIMER_CFG0_x_MASK<<TIMER_CFG0_PRESCALER01);
	tmp |= (TIMER_CFG0_PRESCALER_VALUE_1_255*1)<<TIMER_CFG0_PRESCALER01;
	tmp &= ~(TIMER_CFG0_x_MASK<<TIMER_CFG0_PRESCALER234);
	tmp |= (TIMER_CFG0_PRESCALER_VALUE_1_255*1)<<TIMER_CFG0_PRESCALER234;
	GTIMER->CFG0 = tmp;
	GTIMER->T1.CNTB = 33000000-1;
	GTIMER->T1.CMPB = 16500000;

	tmp = GTIMER->CFG1;
	tmp &= ~(TIMER_CFG1_Tx_MASK<<TIMER_CFG1_T1);
	tmp |= TIMER_CFG1_Tx_DIVIDER_1<<TIMER_CFG1_T1;
	tmp &= ~(TIMER_CFG1_Tx_MASK<<TIMER_CFG1_T4);
	tmp |= TIMER_CFG1_Tx_DIVIDER_1<<TIMER_CFG1_T4;
	GTIMER->CFG1 = tmp;

	GTIMER->T4CNTB = 165000000-1;
	GTIMER->CON |= TIMER_CON_T1_START            |
	               TIMER_CON_T1_MANUAL_UPDATE_EN |
	               TIMER_CON_T1_OUT_INVERTER_ON  |
	               TIMER_CON_T1_AUTO_RELOAD_ON   |
	               TIMER_CON_T4_START            |
				   TIMER_CON_T4_MANUAL_UPDATE_EN |
				   TIMER_CON_T4_AUTO_RELOAD_ON;
	GTIMER->CON &= TIMER_CON_T1_MANUAL_UPDATE_DIS &
	               TIMER_CON_T4_MANUAL_UPDATE_DIS;

	TIMER_InterruptInit();
}

void TIMER4_Isr(void)
{
	GTIMER->INT_CSTAT |= TIMER_INT_CSTAT_T4_STAT;
}
