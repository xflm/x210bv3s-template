#include "vic_hw.h"
#include "vic.h"
#include "pad_hw.h"
#include "led.h"
#include <stdint.h>

void VIC_Config(const VIC_ConfigStruct *config)
{
	VIC_Struct * VICx = &GVIC->V[config->vic];
	uint32_t bit = 0x1<<config->port;

	VICx->VECT_ADDR[config->port] = (uint32_t)config->func;
	VICx->VEC_PRIORITY[config->port] = config->priority;

	if(config->type == VIC_TYPE_IRQ)
	{
		VICx->INT_SELECT &= ~bit;
	}
	else
	{
		VICx->INT_SELECT |= bit;
	}

	if(config->state == VIC_STATE_EN)
	{
		VICx->INT_ENABLE |= bit;
	}
	else
	{
		VICx->INT_CLEAR |= bit;
	}
}

void VIC_Enable(VIC_Enum vic, VICx_PortEnum port, VIC_StateEnum state)
{
	VIC_Struct * VICx = &GVIC->V[vic];
	uint32_t bit = 0x1<<port;

	if(state == VIC_STATE_EN)
	{
		VICx->INT_ENABLE |= bit;
	}
	else
	{
		VICx->INT_CLEAR |= bit;
	}
}

void IRQ_Handler(void)
{
	if(GVIC->V[0].IRQ_STATUS)
	{
		((VIC_Func)(GVIC->V[0].ADDRESS))();
		GVIC->V[0].ADDRESS = 0;
		return;
	}

	if(GVIC->V[1].IRQ_STATUS)
	{
		((VIC_Func)(GVIC->V[1].ADDRESS))();
		GVIC->V[1].ADDRESS = 0;
		return;
	}

	if(GVIC->V[2].IRQ_STATUS)
	{
		((VIC_Func)(GVIC->V[2].ADDRESS))();
		GVIC->V[2].ADDRESS = 0;
		return;
	}

	if(GVIC->V[3].IRQ_STATUS)
	{
		((VIC_Func)(GVIC->V[3].ADDRESS))();
		GVIC->V[3].ADDRESS = 0;
		return;
	}
}

void FIQ_Handler(void)
{
	if(GVIC->V[0].FIQ_STATUS)
	{
		((VIC_Func)(GVIC->V[0].ADDRESS))();
		GVIC->V[0].ADDRESS = 0;
		return;
	}

	if(GVIC->V[1].FIQ_STATUS)
	{
		((VIC_Func)(GVIC->V[1].ADDRESS))();
		GVIC->V[1].ADDRESS = 0;
		return;
	}

	if(GVIC->V[2].FIQ_STATUS)
	{
		((VIC_Func)(GVIC->V[2].ADDRESS))();
		GVIC->V[2].ADDRESS = 0;
		return;
	}

	if(GVIC->V[3].FIQ_STATUS)
	{
		((VIC_Func)(GVIC->V[3].ADDRESS))();
		GVIC->V[3].ADDRESS = 0;
		return;
	}
}
