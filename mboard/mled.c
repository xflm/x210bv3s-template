#include "mled.h"
#include "mboard.h"
#include "syscon.h"
#include "syscon_hw.h"
#include "gpio.h"
#include "gpio_hw.h"

static void mLedClockInit(void)
{
	SYSCON_Struct pSyscon = (SYSCON_Struct)SYSCON_BASE;
	uint32_t tmp1;

	tmp1 = pSyscon->CLK_GATE_IP3;
	tmp1 |= SYSCON_CLK_GATE_IP3_GPIO;
	pSyscon->CLK_GATE_IP3 = tmp1;
}

static void mLedGpioInit(void)
{
	GPIO_Struct pGpio = (GPIO_Struct)GPIO_BASE;
	uint32_t tmp1;

	tmp1 = pGpio->J0.CON;
	tmp1 &= ~GPIO_CON_MASK(GPIO_OFF3_OUT);
	tmp1 &= ~GPIO_CON_MASK(GPIO_OFF4_OUT);
	tmp1 &= ~GPIO_CON_MASK(GPIO_OFF5_OUT);
	tmp1 |= GPIO_CON_FUNC(GPIO_OFF3_OUT);
	tmp1 |= GPIO_CON_FUNC(GPIO_OFF4_OUT);
	tmp1 |= GPIO_CON_FUNC(GPIO_OFF5_OUT);
	pGpio->J0.CON = tmp1;

	tmp1 = pGpio->J0.DAT;
	tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF3_OUT);
	tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF4_OUT);
	tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF5_OUT);
	tmp1 |= GPIO_DAT_HIGH(GPIO_OFF3_OUT);
	tmp1 |= GPIO_DAT_HIGH(GPIO_OFF4_OUT);
	tmp1 |= GPIO_DAT_HIGH(GPIO_OFF5_OUT);
	pGpio->J0.DAT = tmp1;

	tmp1 = pGpio->J0.PUD;
	tmp1 &= ~GPIO_PUD_MASK(GPIO_OFF3_OUT);
	tmp1 &= ~GPIO_PUD_MASK(GPIO_OFF4_OUT);
	tmp1 &= ~GPIO_PUD_MASK(GPIO_OFF5_OUT);
	tmp1 |= GPIO_PUD_DIS(GPIO_OFF3_OUT);
	tmp1 |= GPIO_PUD_DIS(GPIO_OFF4_OUT);
	tmp1 |= GPIO_PUD_DIS(GPIO_OFF5_OUT);
	pGpio->J0.PUD = tmp1;

	tmp1 = pGpio->J0.DRV;
	tmp1 &= ~GPIO_DRV_MASK(GPIO_OFF3_OUT);
	tmp1 &= ~GPIO_DRV_MASK(GPIO_OFF4_OUT);
	tmp1 &= ~GPIO_DRV_MASK(GPIO_OFF5_OUT);
	tmp1 |= GPIO_DRV_HIGH(GPIO_OFF3_OUT);
	tmp1 |= GPIO_DRV_HIGH(GPIO_OFF4_OUT);
	tmp1 |= GPIO_DRV_HIGH(GPIO_OFF5_OUT);
	pGpio->J0.DRV = tmp1;

	tmp1 = pGpio->J0.CONPDN;
	tmp1 &= ~GPIO_CONPDN_MASK(GPIO_OFF3_OUT);
	tmp1 &= ~GPIO_CONPDN_MASK(GPIO_OFF4_OUT);
	tmp1 &= ~GPIO_CONPDN_MASK(GPIO_OFF5_OUT);
	tmp1 |= GPIO_CONPDN_HOLD(GPIO_OFF3_OUT);
	tmp1 |= GPIO_CONPDN_HOLD(GPIO_OFF4_OUT);
	tmp1 |= GPIO_CONPDN_HOLD(GPIO_OFF5_OUT);
	pGpio->J0.CONPDN = tmp1;

	tmp1 = pGpio->J0.PUDPDN;
	tmp1 &= ~GPIO_PUDPND_MASK(GPIO_OFF3_OUT);
	tmp1 &= ~GPIO_PUDPND_MASK(GPIO_OFF4_OUT);
	tmp1 &= ~GPIO_PUDPND_MASK(GPIO_OFF5_OUT);
	tmp1 |= GPIO_PUDPND_DIS(GPIO_OFF3_OUT);
	tmp1 |= GPIO_PUDPND_DIS(GPIO_OFF4_OUT);
	tmp1 |= GPIO_PUDPND_DIS(GPIO_OFF5_OUT);
	pGpio->J0.PUDPDN = tmp1;
}

static void mLedDeviceInit(void)
{
}

//static void mLedIrqHander(void)
//{
//}

static void mLedInterruptInit(void)
{
}

void mLedInit(void)
{
	mLedClockInit();
	mLedGpioInit();
	mLedDeviceInit();
	mLedInterruptInit();
}

void mLedSetOn(MLed_Enum led)
{
	GPIO_Struct pGpio = (GPIO_Struct)GPIO_BASE;
	uint32_t tmp1;

	tmp1 = pGpio->J0.DAT;

	switch(led)
	{
		case MLED_L1:
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF3_OUT);
			tmp1 |= GPIO_DAT_LOW(GPIO_OFF3_OUT);
			break;

		case MLED_L2:
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF4_OUT);
			tmp1 |= GPIO_DAT_LOW(GPIO_OFF4_OUT);
			break;

		case MLED_L3:
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF5_OUT);
			tmp1 |= GPIO_DAT_LOW(GPIO_OFF5_OUT);
			break;

		case MLED_L123:
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF3_OUT);
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF4_OUT);
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF5_OUT);
			tmp1 |= GPIO_DAT_LOW(GPIO_OFF3_OUT);
			tmp1 |= GPIO_DAT_LOW(GPIO_OFF4_OUT);
			tmp1 |= GPIO_DAT_LOW(GPIO_OFF5_OUT);
			break;
	}

	pGpio->J0.DAT = tmp1;
}

void mLedSetOff(MLed_Enum led)
{
	GPIO_Struct pGpio = (GPIO_Struct)GPIO_BASE;
	uint32_t tmp1;

	tmp1 = pGpio->J0.DAT;

	switch(led)
	{
		case MLED_L1:
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF3_OUT);
			tmp1 |= GPIO_DAT_HIGH(GPIO_OFF3_OUT);
			break;

		case MLED_L2:
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF4_OUT);
			tmp1 |= GPIO_DAT_HIGH(GPIO_OFF4_OUT);
			break;

		case MLED_L3:
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF5_OUT);
			tmp1 |= GPIO_DAT_HIGH(GPIO_OFF5_OUT);
			break;

		case MLED_L123:
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF3_OUT);
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF4_OUT);
			tmp1 &= ~GPIO_DAT_MASK(GPIO_OFF5_OUT);
			tmp1 |= GPIO_DAT_HIGH(GPIO_OFF3_OUT);
			tmp1 |= GPIO_DAT_HIGH(GPIO_OFF4_OUT);
			tmp1 |= GPIO_DAT_HIGH(GPIO_OFF5_OUT);
			break;
	}

	pGpio->J0.DAT = tmp1;
}

void mLedSetShine(MLed_Enum led)
{
	GPIO_Struct pGpio = (GPIO_Struct)GPIO_BASE;
	uint32_t tmp1;

	tmp1 = pGpio->J0.DAT;

	switch(led)
	{
		case MLED_L1:
			tmp1 ^= GPIO_DAT_HIGH(GPIO_OFF3_OUT);
			break;

		case MLED_L2:
			tmp1 ^= GPIO_DAT_HIGH(GPIO_OFF4_OUT);
			break;

		case MLED_L3:
			tmp1 ^= GPIO_DAT_HIGH(GPIO_OFF5_OUT);
			break;

		case MLED_L123:
			tmp1 ^= GPIO_DAT_HIGH(GPIO_OFF3_OUT);
			tmp1 ^= GPIO_DAT_HIGH(GPIO_OFF4_OUT);
			tmp1 ^= GPIO_DAT_HIGH(GPIO_OFF5_OUT);
			break;
	}

	pGpio->J0.DAT = tmp1;
}

void mLedTest(void)
{
	volatile uint32_t delay;
	uint32_t time = 0xFFFFF;
	
	mLedSetOff(MLED_L123);

	while(1)
	{
		delay = time;
		while(delay--);
		mLedSetOn(MLED_L1);
		delay = time;
		while(delay--);
		mLedSetOn(MLED_L2);
		delay = time;
		while(delay--);
		mLedSetOn(MLED_L3);
		delay = time/4;
		while(delay--);
		mLedSetOn(MLED_L123);
		delay = time/4;
		while(delay--);
		mLedSetOff(MLED_L123);
		delay = time/4;
		while(delay--);
		mLedSetOn(MLED_L123);
		delay = time/4;
		while(delay--);
		mLedSetOff(MLED_L123);
		delay = time/4;
		while(delay--);
		mLedSetOn(MLED_L123);
		delay = time/4;
		while(delay--);
		mLedSetOff(MLED_L123);
	}
}
