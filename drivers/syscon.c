#include "syscon.h"
#include "syscon_hw.h"


void SYSCON_PreInit(void)
{
	SYSCON_Struct pSyscon = (SYSCON_Struct)SYSCON_BASE;

	pSyscon->CLK_GATE_IP0 = SYSCON_CLK_GATE_IP0_IMEM;
	pSyscon->CLK_GATE_IP1 = 0x00000000;
	pSyscon->CLK_GATE_IP2 = SYSCON_CLK_GATE_IP2_VIC0 |
	                        SYSCON_CLK_GATE_IP2_VIC1 |
	                        SYSCON_CLK_GATE_IP2_VIC2 |
	                        SYSCON_CLK_GATE_IP2_VIC3;
	pSyscon->CLK_GATE_IP3 = SYSCON_CLK_GATE_IP3_SYSCON| 0xFFFFFFFF;
	pSyscon->CLK_GATE_IP4 = 0x00000000;
	pSyscon->CLK_GATE_IP5 &= ~SYSCON_CLK_GATE_IP5_CLK_JPEG;
}
