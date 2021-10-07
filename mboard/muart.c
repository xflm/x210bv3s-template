#include "muart.h"
#include "mboard.h"
#include "syscon.h"
#include "syscon_hw.h"
#include "gpio.h"
#include "gpio_hw.h"
#include "uart.h"
#include "uart_hw.h"
#include "vic.h"
#include "mqueue.h"

volatile uint32_t uartbaud = 115200;
static uint8_t muartBuf[128];
static MQueue_t muartQueue[1] = {
	MQUEUE_DEFINE(muartBuf, sizeof(muartBuf), 1),
};

static void mUartClockInit(void)
{
	SYSCON_Struct pSyscon = (SYSCON_Struct)SYSCON_BASE;
	uint32_t tmp1;

	tmp1 = pSyscon->CLK_GATE_IP3;
	tmp1 |= SYSCON_CLK_GATE_IP3_GPIO;
	tmp1 |= SYSCON_CLK_GATE_IP3_UART2;
	pSyscon->CLK_GATE_IP3 = tmp1;

	tmp1 = pSyscon->CLK_GATE_IP2;
	tmp1 |= SYSCON_CLK_GATE_IP2_VIC1;
	tmp1 |= SYSCON_CLK_GATE_IP2_HSMMC3; /* no why */
	pSyscon->CLK_GATE_IP2 = tmp1;

	tmp1 = pSyscon->CLK_GATE_IP1;
	tmp1 |= SYSCON_CLK_GATE_IP1_CFCON; /* no why */
	pSyscon->CLK_GATE_IP1 = tmp1;
}

static void mUartGpioInit(void)
{
	GPIO_Struct pGpio = (GPIO_Struct)GPIO_BASE;
	uint32_t tmp1;

	tmp1 = pGpio->A1.CON;
	tmp1 &= ~GPIO_CON_MASK(GPA1_0_UART_2_RXD);
	tmp1 &= ~GPIO_CON_MASK(GPA1_1_UART_2_TXD);
	tmp1 |= GPIO_CON_FUNC(GPA1_0_UART_2_RXD);
	tmp1 |= GPIO_CON_FUNC(GPA1_1_UART_2_TXD);
	pGpio->A1.CON = tmp1;

	tmp1 = pGpio->A1.PUD;
	tmp1 &= ~GPIO_PUD_MASK(GPA1_0_UART_2_RXD);
	tmp1 &= ~GPIO_PUD_MASK(GPA1_1_UART_2_TXD);
	tmp1 |= GPIO_PUD_PU(GPA1_0_UART_2_RXD);
	tmp1 |= GPIO_PUD_DIS(GPA1_1_UART_2_TXD);
	pGpio->A1.PUD = tmp1;

	tmp1 = pGpio->A1.DRV;
	tmp1 &= ~GPIO_DRV_MASK(GPA1_0_UART_2_RXD);
	tmp1 &= ~GPIO_DRV_MASK(GPA1_1_UART_2_TXD);
	tmp1 |= GPIO_DRV_LOW(GPA1_0_UART_2_RXD);
	tmp1 |= GPIO_DRV_HIGH(GPA1_1_UART_2_TXD);
	pGpio->A1.DRV = tmp1;

	tmp1 = pGpio->A1.CONPDN;
	tmp1 &= ~GPIO_CONPDN_MASK(GPA1_0_UART_2_RXD);
	tmp1 &= ~GPIO_CONPDN_MASK(GPA1_1_UART_2_TXD);
	tmp1 |= GPIO_CONPDN_HOLD(GPA1_0_UART_2_RXD);
	tmp1 |= GPIO_CONPDN_HOLD(GPA1_1_UART_2_TXD);
	pGpio->A1.CONPDN = tmp1;

	tmp1 = pGpio->A1.PUDPDN;
	tmp1 &= ~GPIO_PUDPND_MASK(GPA1_0_UART_2_RXD);
	tmp1 &= ~GPIO_PUDPND_MASK(GPA1_1_UART_2_TXD);
	tmp1 |= GPIO_PUDPND_PU(GPA1_0_UART_2_RXD);
	tmp1 |= GPIO_PUDPND_DIS(GPA1_1_UART_2_TXD);
	pGpio->A1.PUDPDN = tmp1;
}

static void mUartDeviceInit(void)
{
	UART_InitStruct initUart;

	initUart.dev = UART2_BASE;
	initUart.lcon = UART_LCON_WORD_8B | UART_LCON_STOP_1B |
	                UART_LCON_PARITY_NONE | UART_LCON_MODE_NORMAL;
	initUart.con = UART_CON_RMODE_INT_POLL | UART_CON_TMODE_INT_POLL |
	               UART_CON_SEL_PCLK | UART_CON_RX_INT_EN |
	               UART_CON_TX_INT_EN | UART_CON_RX_ERR_INT_EN | UART_CON_RX_TIMEOUT_EN;
	initUart.intm = UART_INTM_TX_DIS | UART_INTM_MODEM_DIS;
	initUart.baud = uartbaud;

	UART_Init(&initUart);
}

static void mUartRxIrqHander(uint8_t ch)
{
	mQueueWriteByte(muartQueue, ch);
}

static void mUartIrqHander(void)
{
	UART_IrqStruct irq = {
		.dev = UART2_BASE,
		.rx = mUartRxIrqHander,
	};

	UART_IrqHandler(&irq);
}

static void mUartInterruptInit(void)
{
	VIC_RegisterStruct vic;

	vic.func     = mUartIrqHander;
	vic.port     = VIC1_PORT_UART2;
	vic.priority = VIC_PRICRITY_1;
	vic.state    = VIC_STATE_EN;
	vic.type     = VIC_TYPE_IRQ;
	vic.dev      = VIC1_BASE;

	VIC_Register(&vic);
}

void mUartInit(void)
{
	mUartClockInit();
	mUartGpioInit();
	mUartDeviceInit();
	mUartInterruptInit();
}

void mUartPutString(const char *str)
{
	UART_TxString(UART2_BASE, str);
}

void mUartPutBytes(const uint8_t *bytes, uint32_t len)
{
	UART_TxBytes(UART2_BASE, bytes, len);
}

void mUartTest(void)
{
	volatile uint32_t delay;
	uint32_t time = 0xFFFFF;
	uint8_t ch;
	
	while(1)
	{
		delay = time;
		while(delay--);
		mUartPutString("hello\r\n");

		while(mQueueDataLen(muartQueue))
		{
			ch = mQueueReadByte(muartQueue);
			mUartPutBytes(&ch, 1);
		}
	}
}
