#include "mtim.h"
#include "mboard.h"
#include "syscon.h"
#include "syscon_hw.h"
#include "tim.h"
#include "vic.h"

volatile uint32_t msCount;

static void mTimClockInit(void)
{
	SYSCON_Struct pSyscon = (SYSCON_Struct)SYSCON_BASE;
	uint32_t tmp1;

	tmp1 = pSyscon->CLK_GATE_IP1;
	tmp1 |= SYSCON_CLK_GATE_IP1_NANDXL;  /* no why */
	pSyscon->CLK_GATE_IP1 = tmp1;

	tmp1 = pSyscon->CLK_GATE_IP3;
	tmp1 |= SYSCON_CLK_GATE_IP3_SYSTIMER;
	pSyscon->CLK_GATE_IP3 = tmp1;

	tmp1 = pSyscon->CLK_GATE_IP2;
	tmp1 |= SYSCON_CLK_GATE_IP2_VIC0;
	tmp1 |= SYSCON_CLK_GATE_IP2_HSMMC0; /* no why */
	pSyscon->CLK_GATE_IP2 = tmp1;
}

static void mTimGpioInit(void)
{
}

static void mTimDeviceInit(void)
{
	TIM_InitStruct timInit;

	timInit.dev = TIM_BASE;
	timInit.tcfg = TIM_TCFG_PRESCALER_FF(0) |
	               TIM_TCFG_DIVIDER_1 |
	               TIM_TCFG_TCLKB_XrtcXTI |
				   /*TIM_TCFG_TCLKB_XXTI_XUSB |*/
	               TIM_TCFG_TICKGEN_SEL_FRACTIONAL |
	               TIM_TCFG_FDIV_SEL_RTC_1MS;
	timInit.tcon = TIM_TCON_TIMER_START |
	               TIM_TCON_INTERRUPT_START |
	               TIM_TCON_INTERVAL_MODE;
	timInit.ticntb = TIM_TICNTB_VALUE(32768, 1000);
	timInit.tfcntb = TIM_TFCNTB_VALUE(32768, 1000);
	timInit.icntb  = TIM_ICNTB_VALUE_7FFFFFFF(1-1);
	timInit.int_cstat = TIM_INT_CSTAT_ENABLE |
	                    TIM_INT_CSTAT_INTCNT_EIE;

	TIM_Init(&timInit);
}

static void mTimIrqHander(void)
{
	TIM_IrqStruct irq = {
		.dev = TIM_BASE,
	};

	msCount++;

	TIM_IrqHandler(&irq);
}

static void mTimInterruptInit(void)
{
	VIC_RegisterStruct vic;

	vic.func     = mTimIrqHander;
	vic.port     = VIC0_PORT_SYS_TIMER;
	vic.priority = VIC_PRICRITY_0;
	vic.state    = VIC_STATE_EN;
	vic.type     = VIC_TYPE_IRQ;
	vic.dev      = VIC0_BASE;

	VIC_Register(&vic);
}

void mTimInit(void)
{
	mTimClockInit();
	mTimGpioInit();
	mTimDeviceInit();
	mTimInterruptInit();
}

void mTimDelayMs(uint16_t ms)
{
	uint32_t tmp1 = msCount;
	uint32_t tmp2 = ms;

	tmp2 += tmp1;

	if(tmp2 < tmp1)
	{
		while(msCount > tmp1);
	}

	while(msCount < tmp2);
}

void mTimDelayS(uint16_t s)
{
	uint32_t tmp1 = msCount;
	uint32_t tmp2 = s * 1000;

	tmp2 += tmp1;

	if(tmp2 < tmp1)
	{
		while(msCount > tmp1);
	}

	while(msCount <= tmp2);
}

void mTimTest(void)
{
	while(1)
	{
		mTimDelayS(1);
		extern void mLedSetShine(int);
		mLedSetShine(0);
	}
}
