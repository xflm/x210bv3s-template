#ifndef _PAD_CONF_H_
#define _PAD_CONF_H_

typedef enum {
	PAD_CON_P0            = 0,
	PAD_CON_P1            = 4,
	PAD_CON_P2            = 8,
	PAD_CON_P3            = 12,
	PAD_CON_P4            = 16,
	PAD_CON_P5            = 20,
	PAD_CON_P6            = 24,
	PAD_CON_P7            = 28,
	PAD_CON_Px_MASK       = 0xF,
	PAD_CON_Px_INPUT      = 0x0,
	PAD_CON_Px_OUTPUT     = 0x1,
	PAD_CON_Px_INT        = 0xF,

	PAD_CON_A0_P0_UART0_RX      = 0x2<<0,
	PAD_CON_A0_P1_UART0_TX      = 0x2<<4,
	PAD_CON_A0_P2_UART0_CTS     = 0x2<<8,
	PAD_CON_A0_P3_UART0_RTS     = 0x2<<12,

	PAD_CON_A0_P4_UART1_RX      = 0x2<<16,
	PAD_CON_A0_P5_UART1_TX      = 0x2<<20,
	PAD_CON_A0_P6_UART1_CTS     = 0x2<<24,
	PAD_CON_A0_P7_UART1_RTS     = 0x2<<28,

	PAD_CON_A1_P0_UART2_RX      = 0x2<<0,
	PAD_CON_A1_P0_UART_AUDIO_RX = 0x4<<0,

	PAD_CON_A1_P1_UART2_TX      = 0x2<<4,
	PAD_CON_A1_P1_UART_AUDIO_TX = 0x4<<4,

	PAD_CON_A1_P2_UART3_RX      = 0x2<<8,
	PAD_CON_A1_P2_UART2_CTS     = 0x3<<8,

	PAD_CON_A1_P3_UART3_TX      = 0x2<<12,
	PAD_CON_A1_P3_UART2_RTS     = 0x3<<12,

	PAD_CON_D0_P0_TOUT0         = 0x2<<0,
	PAD_CON_D0_P1_TOUT1         = 0x2<<4,
	PAD_CON_D0_P2_TOUT2         = 0x2<<8,
	PAD_CON_D0_P3_TOUT3         = 0x2<<12,

	PAD_CON_JO_P1_MSM_ADDR1     = 0x2<<4,
	PAD_CON_JO_P1_CAM_B_DATA1   = 0x3<<4,
	PAD_CON_JO_P1_CF_ADDR1      = 0x4<<4,
	PAD_CON_JO_P1_MIPI_ESC_CLK  = 0x5<<4,

	PAD_CON_JO_P2_MSM_ADDR2     = 0x2<<8,
	PAD_CON_JO_P2_CAM_B_DATA2   = 0x3<<8,
	PAD_CON_JO_P2_CF_ADDR2      = 0x4<<8,
	PAD_CON_JO_P2_TS_CLK        = 0x5<<8,

	PAD_CON_JO_P3_MSM_ADDR3     = 0x2<<12,
	PAD_CON_JO_P3_CAM_B_DATA3   = 0x3<<12,
	PAD_CON_JO_P3_CF_IORDY      = 0x4<<12,
	PAD_CON_JO_P3_TS_SYNC       = 0x5<<12,
} PAD_CONEnum;

typedef enum {
	PAD_PUD_P0         = 0,
	PAD_PUD_P1         = 2,
	PAD_PUD_P2         = 4,
	PAD_PUD_P3         = 6,
	PAD_PUD_P4         = 8,
	PAD_PUD_P5         = 10,
	PAD_PUD_P6         = 12,
	PAD_PUD_P7         = 14,
	PAD_PUD_Px_MASK    = 0x3,
	PAD_PUD_Px_DISABLE = 0x0,
	PAD_PUD_Px_DOWN    = 0x1,
	PAD_PUD_Px_UP      = 0x2,
} PAD_PUDEnum;

typedef enum {
	PAD_DAT_P0      = 0,
	PAD_DAT_P1      = 1,
	PAD_DAT_P2      = 2,
	PAD_DAT_P3      = 3,
	PAD_DAT_P4      = 4,
	PAD_DAT_P5      = 5,
	PAD_DAT_P6      = 6,
	PAD_DAT_P7      = 7,
	PAD_DAT_Px_MASK = 1,
	PAD_DAT_Px_LOW  = 0,
	PAD_DAT_Px_HIGH = 1,
} PAD_DATEnum;

#endif /* _PAD_CONF_H_ */
