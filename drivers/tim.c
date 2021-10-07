#include "tim.h"
#include "tim_hw.h"

MDevStat_e TIM_Init(const TIM_InitStruct *tim)
{
	TIM_Struct pTim = (TIM_Struct)tim->dev;

	pTim->TCFG = tim->tcfg;
	pTim->TCON = tim->tcon;
	pTim->TICNTB = tim->ticntb;
	pTim->TFCNTB = tim->tfcntb;
	pTim->ICNTB = tim->icntb;
	pTim->INT_CSTAT = tim->int_cstat;

	return MDEV_STAT_OK;
}

void TIM_Reset(MDevBase_t dev)
{
	_TIM_Reset(dev);
}

void TIM_Start(MDevBase_t dev)
{
	TIM_Struct pTim = (TIM_Struct)dev;
	uint32_t tmp1;

	tmp1 = pTim->TCON;
	tmp1 |= TIM_TCON_TIMER_START;
	pTim->TCON = tmp1;
}

void TIM_Stop(MDevBase_t dev)
{
	TIM_Struct pTim = (TIM_Struct)dev;
	uint32_t tmp1;

	tmp1 = pTim->TCON;
	tmp1 &= ~TIM_TCON_TIMER_START;
	pTim->TCON = tmp1;
}

void TIM_SetInterruptEnable(MDevBase_t dev, uint32_t int_cstat)
{
	TIM_Struct pTim = (TIM_Struct)dev;
	uint32_t tmp1;

	tmp1 = pTim->INT_CSTAT;
	tmp1 |= int_cstat;
	pTim->INT_CSTAT = tmp1;
}

void TIM_SetInterruptDisable(MDevBase_t dev, uint32_t int_cstat)
{
	TIM_Struct pTim = (TIM_Struct)dev;
	uint32_t tmp1;

	tmp1 = pTim->INT_CSTAT;
	tmp1 &= ~int_cstat;
	pTim->INT_CSTAT = tmp1;
}

void TIM_IrqHandler(void *p)
{
	TIM_IrqStruct *irq = (TIM_IrqStruct *)p;
	TIM_Struct pTim = (TIM_Struct)irq->dev;
	uint32_t flag = pTim->INT_CSTAT;

	if(flag & TIM_INT_CSTAT_INTCNT_STATUS)
	{
		pTim->INT_CSTAT |= TIM_INT_CSTAT_INTCNT_STATUS;
		return;
	}
}
