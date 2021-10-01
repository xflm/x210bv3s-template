#ifndef _VIC_H_
#define _VIC_H_

typedef enum {
	VIC0 = 0,
	VIC1 = 1,
	VIC2 = 2,
	VIC3 = 3,
} VIC_Enum;

typedef enum {
	VIC0_PORT_EINT0            = 0,
	VIC0_PORT_EINT1            = 1,
	VIC0_PORT_EINT2            = 2,
	VIC0_PORT_EINT3            = 3,
	VIC0_PORT_EINT4            = 4,
	VIC0_PORT_EINT5            = 5,
	VIC0_PORT_EINT6            = 6,
	VIC0_PORT_EINT7            = 7,
	VIC0_PORT_EINT8            = 8,
	VIC0_PORT_EINT9            = 9,
	VIC0_PORT_EINT10           = 10,
	VIC0_PORT_EINT11           = 11,
	VIC0_PORT_EINT12           = 12,
	VIC0_PORT_EINT13           = 13,
	VIC0_PORT_EINT14           = 14,
	VIC0_PORT_EINT15           = 15,
	VIC0_PORT_EINT16_31        = 16,
	VIC0_PORT_MDMA             = 18,
	VIC0_PORT_PDMA0            = 19,
	VIC0_PORT_PDMA1            = 20,
	VIC0_PORT_TIMER0           = 21,
	VIC0_PORT_TIMER1           = 22,
	VIC0_PORT_TIMER2           = 23,
	VIC0_PORT_TIMER3           = 24,
	VIC0_PORT_TIMER4           = 25,
	VIC0_PORT_SYS_TIMER        = 26,
	VIC0_PORT_WDT              = 27,
	VIC0_PORT_RTC_ALARM        = 28,
	VIC0_PORT_RTC_TIC          = 29,
	VIC0_PORT_GPIO_INT         = 30,
	VIC0_PORT_FIMC3            = 31,
	VIC1_PORT_CORTEX0_PMU      = 0,
	VIC1_PORT_CORTEX1_DMAS     = 1,
	VIC1_PORT_CORTEX2_DMA      = 2,
	VIC1_PORT_CORTEX3_DMAEXTER = 3,
	VIC1_PORT_CORTEX4_CTI      = 4,
	VIC1_PORT_IEM_APC          = 5,
	VIC1_PORT_IEM_IEC          = 6,
	VIC1_PORT_NFC              = 8,
	VIC1_PORT_CFC              = 9,
	VIC1_PORT_UART0            = 10,
	VIC1_PORT_UART1            = 11,
	VIC1_PORT_UART2            = 12,
	VIC1_PORT_UART3            = 13,
	VIC1_PORT_I2C0             = 14,
	VIC1_PORT_SPI0             = 15,
	VIC1_PORT_SPI1             = 16,
	VIC1_PORT_AUDIO_SS         = 18,
	VIC1_PORT_I2C2             = 19,
	VIC1_PORT_I2C_HDMI_PHY     = 20,
	VIC1_PORT_UHOST            = 23,
	VIC1_PORT_OTG              = 24,
	VIC1_PORT_MODEMIF          = 25,
	VIC1_PORT_HSMMC0           = 26,
	VIC1_PORT_HSMMC1           = 27,
	VIC1_PORT_HSMMC2           = 28,
	VIC1_PORT_MIPI_CSI         = 29,
	VIC1_PORT_MIPI_DSI         = 30,
	VIC1_PORT_ONENAND_AUDI     = 31,
	VIC2_PORT_LCD0             = 0,
	VIC2_PORT_LCD1             = 1,
	VIC2_PORT_LCD2             = 2,
	VIC2_PORT_POTATOR          = 4,
	VIC2_PORT_FIMC0            = 5,
	VIC2_PORT_FIMC1            = 6,
	VIC2_PORT_FIMC2            = 7,
	VIC2_PORT_JPEG             = 8,
	VIC2_PORT_2D               = 9,
	VIC2_PORT_3D               = 10,
	VIC2_PORT_MIXER            = 11,
	VIC2_PORT_HDMI             = 12,
	VIC2_PORT_I2C_HDMI_DDC     = 13,
	VIC2_PORT_MFC              = 14,
	VIC2_PORT_TVENC            = 15,
	VIC2_PORT_I2S0             = 16,
	VIC2_PORT_I2S1             = 17,
	VIC2_PORT_AC97             = 19,
	VIC2_PORT_PCM0             = 20,
	VIC2_PORT_PCM1             = 21,
	VIC2_PORT_SPDIF            = 22,
	VIC2_PORT_ADC_TSADC        = 23,
	VIC2_PORT_PENDN_TSADC      = 24,
	VIC2_PORT_KEY_PAD          = 25,
	VIC2_PORT_INT_HASH_SSS     = 27,
	VIC2_PORT_INT_FEED_CTRL_SSS= 28,
	VIC2_PORT_PCM2             = 29,
	VIC2_PORT_SDM_IRQ          = 30,
	VIC2_PORT_SDM_FIQ          = 31,
	VIC3_PORT_MMC3             = 2,
	VIC3_PORT_CEC              = 3,
	VIC3_PORT_TSI              = 4,
	VIC3_PORT_ADC1_TSADC       = 9,
	VIC3_PORT_PENDN1_TSADC     = 10,
} VICx_PortEnum;

typedef enum {
	VIC_TYPE_IRQ = 0x0,
	VIC_TYPE_FIQ = 0x1,
} VIC_TypeEnum;

typedef enum {
	VIC_STATE_EN  = 0x1,
	VIC_STATE_DIS = 0x0,
} VIC_StateEnum;

typedef enum {
	VIC_PRICRITY_HIGHEST = 0x0,
	VIC_PRICRITY_0       = 0x0,
	VIC_PRICRITY_1       = 0x1,
	VIC_PRICRITY_2       = 0x2,
	VIC_PRICRITY_3       = 0x3,
	VIC_PRICRITY_4       = 0x4,
	VIC_PRICRITY_5       = 0x5,
	VIC_PRICRITY_6       = 0x6,
	VIC_PRICRITY_7       = 0x7,
	VIC_PRICRITY_8       = 0x8,
	VIC_PRICRITY_9       = 0x9,
	VIC_PRICRITY_10      = 0xA,
	VIC_PRICRITY_11      = 0xB,
	VIC_PRICRITY_12      = 0xC,
	VIC_PRICRITY_13      = 0xD,
	VIC_PRICRITY_14      = 0xE,
	VIC_PRICRITY_15      = 0xF,
	VIC_PRICRITY_LOWEST  = 0xF,
} VIC_PriorityEnum;

typedef void(*VIC_Func)(void);

typedef struct {
	VIC_Enum vic;
	VICx_PortEnum port;
	VIC_TypeEnum type;
	VIC_StateEnum state;
	VIC_PriorityEnum priority;
	VIC_Func func;
} VIC_ConfigStruct;

void VIC_Config(const VIC_ConfigStruct *config);
void VIC_Enable(VIC_Enum vic, VICx_PortEnum port, VIC_StateEnum state);
void IRQ_Handler(void);
void FIQ_Handler(void);

#endif /* _VIC_H_ */
