#include "uart.h"
#include "uart_hw.h"

static const uint16_t uartDivSlot[16] = {
    0x0000, 0x0080, 0x0808, 0x0888, 0x2222, 0x4924, 0x4A52, 0x54AA,
    0x5555, 0xD555, 0xD5D5, 0xDDD5, 0xDDDD, 0xDFDD, 0xDFDF, 0xFFDF
};

#define UART_CALC_BRDIV(CLK, BAUD)    ((CLK)/16/(BAUD)-1)
#define UART_CALC_DIVSLOT(CLK, BAUD)  uartDivSlot[((CLK)%(16*(BAUD))/16)]

MDevStat_e UART_Init(const UART_InitStruct *init)
{
	UART_Struct pUart = (UART_Struct)init->dev;

	/* clear interrupt */
	pUart->INTP = UART_INTP_ALL;
	pUart->LCON = init->lcon;
	pUart->CON  = init->con;
	pUart->INTM = init->intm;
	//pUart->BRDIV = UART_CALC_BRDIV(66000000, init->baud);
	//pUart->DIVSLOT = UART_CALC_DIVSLOT(66000000, init->baud);

	return MDEV_STAT_OK;
}

MDevStat_e UART_TxByte(MDevBase_t dev, uint8_t byte)
{
	UART_Struct pUart = (UART_Struct)dev;

	while(!(pUart->TRSTATE & UART_TRSTATE_TX_EMPTY));
	pUart->TXH = byte;

	return MDEV_STAT_OK;
}

MDevStat_e UART_TxBytes(MDevBase_t dev, const uint8_t *bytes, uint32_t len)
{
	UART_Struct pUart = (UART_Struct)dev;

	while(len--)
	{
		while(!(pUart->TRSTATE & UART_TRSTATE_TX_EMPTY));
		pUart->TXH = *bytes++;
	}

	return MDEV_STAT_OK;
}

MDevStat_e UART_TxString(MDevBase_t dev, const char *str)
{
	UART_Struct pUart = (UART_Struct)dev;

	while(*str)
	{
		while(!(pUart->TRSTATE & UART_TRSTATE_TX_EMPTY));
		pUart->TXH = *str++;
	}

	return MDEV_STAT_OK;
}

MDevStat_e UART_RxByte(MDevBase_t dev, uint8_t *ch)
{
	UART_Struct pUart = (UART_Struct)dev;

	while(!(pUart->TRSTATE & UART_TRSTATE_RX_READY));
	*ch =  pUart->RXH;

	return MDEV_STAT_OK;
}

void UART_IrqHandler(void *p)
{
	UART_IrqStruct *irq = (UART_IrqStruct *)p;
	UART_Struct pUart = (UART_Struct)irq->dev;
	uint32_t flag = pUart->INTP;

	if(flag & UART_INTP_RX)
	{
		irq->rx(pUart->RXH);
		pUart->INTP |= UART_INTP_RX;
	}
	else if(flag & UART_INTP_TX)
	{
		pUart->INTP |= UART_INTP_TX;
		pUart->INTM |= UART_INTM_TX_DIS;
	}
	else if(flag & UART_INTP_ERR)
	{
		pUart->INTP |= UART_INTP_ERR;
	}
	else
	{
		pUart->INTP |= UART_INTP_MODEM;
	}
}
