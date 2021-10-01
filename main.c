#include "pad_hw.h"
#include "vic_hw.h"
#include <stdint.h>
#include "syscon.h"
#include "pad.h"
#include "uart_conf.h"
#include "led.h"
#include "timer.h"
#include "uart.h"
//#include "mdebug.h"

static void AllInit()
{
	SYSCON_Init();
	PAD_Init();
	UART_Init();
	LED_Init();
	TIMER_Init();
}

void LED_Test(void)
{
	LED_On(LED2);
}

void AA(void)
{
	uint32_t i;

	asm(
		"mrc p15, 0, r0, c12, c0, 0\n"
		"str r0, %[i]\n"
		:[i]"=m"(i)
		:
		:"r0"
	);

//	mDebugPutMemoryForU32("i: ", &i, 1);
}

int main(int argc, const char * const argv[])
{
	(void)argc;
	(void)argv;

	volatile uint32_t delay = 0xFFFF;

	AllInit();

	while(1)
	{
		LED_OnOff(LED1);
		delay = 0xFFFFF;
		while(delay--);
//		mDebugPuts("123\n");
	}

	return 0;
}
