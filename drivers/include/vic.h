#ifndef _VIC_H_
#define _VIC_H_

#include "soc.h"

#define VIC0_BASE              SOC_VIC0_BASE_ADDR
#define VIC1_BASE              SOC_VIC1_BASE_ADDR
#define VIC2_BASE              SOC_VIC2_BASE_ADDR
#define VIC3_BASE              SOC_VIC3_BASE_ADDR

#define VIC0_PORT_EINT0              0
#define VIC0_PORT_EINT1              1
#define VIC0_PORT_EINT2              2
#define VIC0_PORT_EINT3              3
#define VIC0_PORT_EINT4              4
#define VIC0_PORT_EINT5              5
#define VIC0_PORT_EINT6              6
#define VIC0_PORT_EINT7              7
#define VIC0_PORT_EINT8              8
#define VIC0_PORT_EINT9              9
#define VIC0_PORT_EINT10             10
#define VIC0_PORT_EINT11             11
#define VIC0_PORT_EINT12             12
#define VIC0_PORT_EINT13             13
#define VIC0_PORT_EINT14             14
#define VIC0_PORT_EINT15             15
#define VIC0_PORT_EINT16_31          16
#define VIC0_PORT_MDMA               18
#define VIC0_PORT_PDMA0              19
#define VIC0_PORT_PDMA1              20
#define VIC0_PORT_TIMER0             21
#define VIC0_PORT_TIMER1             22
#define VIC0_PORT_TIMER2             23
#define VIC0_PORT_TIMER3             24
#define VIC0_PORT_TIMER4             25
#define VIC0_PORT_SYS_TIMER          26
#define VIC0_PORT_WDT                27
#define VIC0_PORT_RTC_ALARM          28
#define VIC0_PORT_RTC_TIC            29
#define VIC0_PORT_GPIO_INT           30
#define VIC0_PORT_FIMC3              31

#define VIC1_PORT_CORTEX0_PMU        0
#define VIC1_PORT_CORTEX1_DMAS       1
#define VIC1_PORT_CORTEX2_DMA        2
#define VIC1_PORT_CORTEX3_DMAEXTER   3
#define VIC1_PORT_CORTEX4_CTI        4
#define VIC1_PORT_IEM_APC            5
#define VIC1_PORT_IEM_IEC            6
#define VIC1_PORT_NFC                8
#define VIC1_PORT_CFC                9
#define VIC1_PORT_UART0              10
#define VIC1_PORT_UART1              11
#define VIC1_PORT_UART2              12
#define VIC1_PORT_UART3              13
#define VIC1_PORT_I2C0               14
#define VIC1_PORT_SPI0               15
#define VIC1_PORT_SPI1               16
#define VIC1_PORT_AUDIO_SS           18
#define VIC1_PORT_I2C2               19
#define VIC1_PORT_I2C_HDMI_PHY       20
#define VIC1_PORT_UHOST              23
#define VIC1_PORT_OTG                24
#define VIC1_PORT_MODEMIF            25
#define VIC1_PORT_HSMMC0             26
#define VIC1_PORT_HSMMC1             27
#define VIC1_PORT_HSMMC2             28
#define VIC1_PORT_MIPI_CSI           29
#define VIC1_PORT_MIPI_DSI           30
#define VIC1_PORT_ONENAND_AUDI       31

#define VIC2_PORT_LCD0               0
#define VIC2_PORT_LCD1               1
#define VIC2_PORT_LCD2               2
#define VIC2_PORT_POTATOR            4
#define VIC2_PORT_FIMC0              5
#define VIC2_PORT_FIMC1              6
#define VIC2_PORT_FIMC2              7
#define VIC2_PORT_JPEG               8
#define VIC2_PORT_2D                 9
#define VIC2_PORT_3D                 10
#define VIC2_PORT_MIXER              11
#define VIC2_PORT_HDMI               12
#define VIC2_PORT_I2C_HDMI_DDC       13
#define VIC2_PORT_MFC                14
#define VIC2_PORT_TVENC              15
#define VIC2_PORT_I2S0               16
#define VIC2_PORT_I2S1               17
#define VIC2_PORT_AC97               19
#define VIC2_PORT_PCM0               20
#define VIC2_PORT_PCM1               21
#define VIC2_PORT_SPDIF              22
#define VIC2_PORT_ADC_TSADC          23
#define VIC2_PORT_PENDN_TSADC        24
#define VIC2_PORT_KEY_PAD            25
#define VIC2_PORT_INT_HASH_SSS       27
#define VIC2_PORT_INT_FEED_CTRL_SSS  28
#define VIC2_PORT_PCM2               29
#define VIC2_PORT_SDM_IRQ            30
#define VIC2_PORT_SDM_FIQ            31

#define VIC3_PORT_MMC3               2
#define VIC3_PORT_CEC                3
#define VIC3_PORT_TSI                4
#define VIC3_PORT_ADC1_TSADC         9
#define VIC3_PORT_PENDN1_TSADC       10

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
	MDevBase_t dev;
	uint32_t port;
	VIC_TypeEnum type;
	VIC_StateEnum state;
	VIC_PriorityEnum priority;
	VIC_Func func;
} VIC_RegisterStruct;

void VIC_PreInit(void);
void VIC_Register(const VIC_RegisterStruct *vic);
void VIC_Enable(MDevBase_t dev, uint32_t port);
void VIC_Disable(MDevBase_t dev, uint32_t port);
void IRQ_Handler(void);
void FIQ_Handler(void);

#endif /* _VIC_H_ */
