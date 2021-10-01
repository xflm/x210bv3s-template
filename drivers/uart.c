#include "uart_hw.h"
#include "uart_conf.h"
#include "uart.h"
#include "syscon_hw.h"
#include "syscon_conf.h"
#include "pad_hw.h"
#include "pad_conf.h"
#include "vic.h"
#include "led.h"

static const uint16_t uartDivSlot[16] = {
    0x0000, 0x0080, 0x0808, 0x0888, 0x2222, 0x4924, 0x4A52, 0x54AA,
    0x5555, 0xD555, 0xD5D5, 0xDDD5, 0xDDDD, 0xDFDD, 0xDFDF, 0xFFDF
};

#define UART_CALC_BRDIV(CLK, BAUD)    ((CLK)/16/(BAUD)-1)
#define UART_CALC_DIVSLOT(CLK, BAUD)  uartDivSlot[((CLK)%(16*(BAUD))/16)]

static void UART_ClkInit(void)
{
#if 0
	uint32_t tmp;

	tmp = SYSCON->CLK_SRC4;
	tmp &= ~(SYSCON_CLK_SEL_MASK<<SYSCON_CLK_SEL4_UART0);
	tmp |= SYSCON_CLK_SEL_XUSBXTI<<SYSCON_CLK_SEL4_UART0;
	SYSCON->CLK_SRC4 = tmp;

	tmp = SYSCON->CLK_DIV4;
	tmp &= ~(SYSCON_CLK_DIV_MASK<<SYSCON_CLK_DIV4_UART0);
	tmp |= SYSCON_CLK_DIV_1<<SYSCON_CLK_DIV4_UART0;
	SYSCON->CLK_DIV4 = tmp;
#endif
}

static void UART_PadInit(void)
{
#if 0
	uint32_t tmp;

	tmp = GPAD->A0.CON;
	tmp &= ~(PAD_CON_PX_MASK<<PAD_CON_P3 | PAD_CON_PX_MASK<<PAD_CON_P4 |
	         PAD_CON_PX_MASK<<PAD_CON_P5);
	tmp |= PAD_CON_A0_P0_UART0_RX | PAD_CON_A0_P1_UART0_TX;
	GPAD->A0.CON = tmp;

	tmp = GPAD->A0.PUD;
	tmp &= ~(PAD_PUD_PX_MASK<<PAD_PUD_P0 | PAD_PUD_PX_MASK<<PAD_PUD_P1);
	tmp |= PAD_PUD_PX_UP<<PAD_PUD_P0 | PAD_PUD_PX_UP<<PAD_PUD_P1;
	GPAD->A0.PUD = tmp;
#endif
}

static void UART_DriveInit(void)
{
	GUART->U[0].LCON = UART_LCON_WORD_8B | UART_LCON_STOP_1B |
	                   UART_LCON_PARITY_NONE | UART_LCON_MODE_NORMAL;
	GUART->U[0].CON = UART_CON_RMODE_INT_POLL | UART_CON_TMODE_INT_POLL |
	                  UART_CON_SEL_PCLK;
	GUART->U[0].BRDIV = UART_CALC_BRDIV(66000000, 115200);
	GUART->U[0].DIVSLOT = UART_CALC_DIVSLOT(66000000, 115200);
}

static void UART_InterruptInit(void)
{
	VIC_ConfigStruct config;

	GUART->U[0].INTM = UART_INTM_TX_DIS | UART_INTM_MODEM_DIS;
	GUART->U[0].CON |= UART_CON_RX_INT_EN | UART_CON_TX_INT_EN;

	config.func     = UART0_Isr;
	config.port     = VIC1_PORT_UART0;
	config.priority = VIC_PRICRITY_0;
	config.state    = VIC_STATE_EN;
	config.type     = VIC_TYPE_IRQ;
	config.vic      = VIC1;

	VIC_Config(&config);
}

void UART_Init(void)
{
	UART_ClkInit();
	UART_PadInit();
	UART_DriveInit();
	UART_InterruptInit();
}

void UART0_OutByte(uint8_t byte)
{
	while(!(GUART->U[0].TRSTATE & UART_TRSTATE_TX_EMPTY));
	GUART->U[0].TXH = byte;
}

void UART0_OutBytes(const void *bytes, uint32_t len)
{
	const uint8_t *p = (const uint8_t *)bytes;

	while(len--)
	{
		while(!(GUART->U[0].TRSTATE & UART_TRSTATE_TX_EMPTY));
		GUART->U[0].TXH = *p;
		p++;
	}
}

void UART0_OutString(const char *str)
{
	while(*str)
	{
		while(!(GUART->U[0].TRSTATE & UART_TRSTATE_TX_EMPTY));
		GUART->U[0].TXH = *str;
		str++;
	}
}

uint8_t UART0_InByte(void)
{
	while(!(GUART->U[0].TRSTATE & UART_TRSTATE_RX_READY));
	return GUART->U[0].RXH;
}

uint32_t UART0_InBytes(void *bytes, uint32_t len)
{
	uint8_t *p = (uint8_t *)bytes;

	while(len--)
	{
		while(!(GUART->U[0].TRSTATE & UART_TRSTATE_RX_READY));
		*p = GUART->U[0].RXH;
		p++;
	}

	return len;
}

void UART0_StopRun(void)
{
	UART0_OutString("Stop\n");
	UART0_InByte();
}

void UART0_RunCmd(const char *cmd)
{

}

void UART0_RunCmd1(void)
{

}

void UART0_RunCmd2(void)
{

}

void UART0_Isr(void)
{
	uint32_t flag = GUART->U[0].INTP;

	if(flag & UART_INTP_RX)
	{
		GUART->U[0].RXH;
		GUART->U[0].INTP |= UART_INTP_RX;
	}
	else if(flag & UART_INTP_ERR)
	{
		GUART->U[0].INTP |= UART_INTP_ERR;
	}
	else if(flag & UART_INTP_TX)
	{
		GUART->U[0].INTP |= UART_INTP_TX;
	}
	else
	{
		GUART->U[0].INTP |= UART_INTP_MODEM;
	}
}
