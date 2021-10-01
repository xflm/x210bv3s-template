#include "syscon_hw.h"
#include "syscon_conf.h"
#include "syscon.h"
#include <stdint.h>


void SYSCON_Init(void)
{
#if 0
	uint32_t tmp;

	/*************************_UART0_*************************/
	tmp = SYSCON->CLK_SRC4;
	tmp &= ~(SYSCON_CLK_SEL_MASK<<SYSCON_CLK_SEL4_UART0);
	tmp |= SYSCON_CLK_SEL_XUSBXTI<<SYSCON_CLK_SEL4_UART0;
	SYSCON->CLK_SRC4 = tmp;

	tmp = SYSCON->CLK_DIV4;
	tmp &= ~(SYSCON_CLK_DIV_MASK<<SYSCON_CLK_DIV4_UART0);
	tmp |= SYSCON_CLK_DIV_1<<SYSCON_CLK_DIV4_UART0;
	SYSCON->CLK_DIV4 = tmp;
	/*************************_UART0_*************************/
#endif
}
