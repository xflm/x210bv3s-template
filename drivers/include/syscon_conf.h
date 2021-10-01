#ifndef _SYSCON_CONF_H_
#define _SYSCON_CONF_H_


typedef enum {
	SYSCON_CLK_SEL_MASK         = 0xFU,
	SYSCON_CLK_SEL_XXTI         = 0x0,
	SYSCON_CLK_SEL_XUSBXTI      = 0x1,
	SYSCON_CLK_SEL_SCLK_HDMI27M = 0x2,
	SYSCON_CLK_SEL_SCLK_USBPHY0 = 0x3,
	SYSCON_CLK_SEL_SCLK_USBPHY1 = 0x4,
	SYSCON_CLK_SEL_SCLK_HDMIPHY = 0x5,
	SYSCON_CLK_SEL_SCLK_MPLL    = 0x6,
	SYSCON_CLK_SEL_SCLK_EPLL    = 0x7,
	SYSCON_CLK_SEL_SCLK_VPLL    = 0x8,
	SYSCON_CLK_SEL4_UART3       = 28,
	SYSCON_CLK_SEL4_UART2       = 24,
	SYSCON_CLK_SEL4_UART1       = 20,
	SYSCON_CLK_SEL4_UART0       = 16,
} SYSCON_CLK_SELEnum;

typedef enum {
	SYSCON_CLK_DIV_MASK         = 0xFU,
	SYSCON_CLK_DIV_1            = 0x0,
	SYSCON_CLK_DIV_2            = 0x1,
	SYSCON_CLK_DIV_3            = 0x2,
	SYSCON_CLK_DIV_4            = 0x3,
	SYSCON_CLK_DIV_5            = 0x4,
	SYSCON_CLK_DIV_6            = 0x5,
	SYSCON_CLK_DIV_7            = 0x6,
	SYSCON_CLK_DIV_8            = 0x7,
	SYSCON_CLK_DIV_9            = 0x8,
	SYSCON_CLK_DIV_10           = 0x9,
	SYSCON_CLK_DIV_11           = 0xA,
	SYSCON_CLK_DIV_12           = 0xB,
	SYSCON_CLK_DIV_13           = 0xC,
	SYSCON_CLK_DIV_14           = 0xD,
	SYSCON_CLK_DIV_15           = 0xE,
	SYSCON_CLK_DIV_16           = 0xF,
	SYSCON_CLK_DIV4_UART3       = 28,
	SYSCON_CLK_DIV4_UART2       = 24,
	SYSCON_CLK_DIV4_UART1       = 20,
	SYSCON_CLK_DIV4_UART0       = 16,
} SYSCON_CLK_DIVEnum;


#endif /* _SYSCON_CONF_H_ */
