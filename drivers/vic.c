#include "vic_hw.h"
#include "vic.h"

void VIC_PreInit(void)
{
	VIC_Struct pVic0 = (VIC_Struct)VIC0_BASE;
	VIC_Struct pVic1 = (VIC_Struct)VIC1_BASE;
	VIC_Struct pVic2 = (VIC_Struct)VIC2_BASE;
	VIC_Struct pVic3 = (VIC_Struct)VIC3_BASE;

	pVic0->INT_CLEAR = 0xFFFFFFFF;
	pVic1->INT_CLEAR = 0xFFFFFFFF;
	pVic2->INT_CLEAR = 0xFFFFFFFF;
	pVic3->INT_CLEAR = 0xFFFFFFFF;
}

void VIC_Register(const VIC_RegisterStruct *vic)
{
	VIC_Struct pVic = (VIC_Struct)vic->dev;
	uint32_t bit = 0x1<<vic->port;

	pVic->VECT_ADDR[vic->port] = (uint32_t)vic->func;
	pVic->VEC_PRIORITY[vic->port] = vic->priority;

	if(vic->type == VIC_TYPE_IRQ)
	{
		pVic->INT_SELECT &= ~bit;
	}
	else
	{
		pVic->INT_SELECT |= bit;
	}

	if(vic->state == VIC_STATE_EN)
	{
		pVic->INT_ENABLE |= bit;
	}
	else
	{
		pVic->INT_CLEAR |= bit;
	}
}

void VIC_Enable(MDevBase_t dev, uint32_t port)
{
	VIC_Struct pVic = (VIC_Struct)dev;
	uint32_t bit = 0x1<<port;

	pVic->INT_ENABLE |= bit;
}

void VIC_Disable(MDevBase_t dev, uint32_t port)
{
	VIC_Struct pVic = (VIC_Struct)dev;
	uint32_t bit = 0x1<<port;

	pVic->INT_CLEAR |= bit;
}

void IRQ_Handler(void)
{
	VIC_Struct pVic0 = (VIC_Struct)VIC0_BASE;
	VIC_Struct pVic1 = (VIC_Struct)VIC1_BASE;
	VIC_Struct pVic2 = (VIC_Struct)VIC2_BASE;
	VIC_Struct pVic3 = (VIC_Struct)VIC3_BASE;

	if(pVic0->IRQ_STATUS)
	{
		((VIC_Func)(pVic0->ADDRESS))();
		pVic0->ADDRESS = 0;
		return;
	}

	if(pVic1->IRQ_STATUS)
	{
		((VIC_Func)(pVic1->ADDRESS))();
		pVic1->ADDRESS = 0;
		return;
	}

	if(pVic2->IRQ_STATUS)
	{
		((VIC_Func)(pVic2->ADDRESS))();
		pVic2->ADDRESS = 0;
		return;
	}

	if(pVic3->IRQ_STATUS)
	{
		((VIC_Func)(pVic3->ADDRESS))();
		pVic3->ADDRESS = 0;
		return;
	}
}

void FIQ_Handler(void)
{
	VIC_Struct pVic0 = (VIC_Struct)VIC0_BASE;
	VIC_Struct pVic1 = (VIC_Struct)VIC1_BASE;
	VIC_Struct pVic2 = (VIC_Struct)VIC2_BASE;
	VIC_Struct pVic3 = (VIC_Struct)VIC3_BASE;

	if(pVic0->FIQ_STATUS)
	{
		((VIC_Func)(pVic0->ADDRESS))();
		pVic0->ADDRESS = 0;
		return;
	}

	if(pVic1->FIQ_STATUS)
	{
		((VIC_Func)(pVic1->ADDRESS))();
		pVic1->ADDRESS = 0;
		return;
	}

	if(pVic2->FIQ_STATUS)
	{
		((VIC_Func)(pVic2->ADDRESS))();
		pVic2->ADDRESS = 0;
		return;
	}

	if(pVic3->FIQ_STATUS)
	{
		((VIC_Func)(pVic3->ADDRESS))();
		pVic3->ADDRESS = 0;
		return;
	}
}
