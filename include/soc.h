#ifndef _SOC_H_
#define _SOC_H_

/*************** Memory Map ***************/
#define DRAM0_START_ADDR          0x20000000 /* 512MB */
#define DRAM0_END_ADDR            0x3FFFFFFF
#define DRAM1_START_ADDR          0x40000000 /* 1GB */
#define DRAM1_END_ADDR            0x7FFFFFFF
#define IROM_START_ADDR           0xD0000000 /* 64KB */
#define IROM_END_ADDR             0xD000FFFF
#define IRAM_START_ADDR           0xD0020000 /* 96KB */
#define IRAM_END_ADDR             0xD0037FFF

/********* Peripheral Address Map **********/
#define SYSCON_BASE_ADDR          0xE0100000
#define GPIO_BASE_ADDR            0xE0200000
#define PCM1_BASE_ADDR            0xE1200000
#define SPI0_BASE_ADDR            0xE1300000
#define SPI1_BASE_ADDR            0xE1400000
#define UART_BASE_ADDR            0xE2900000
#define VIC0_BASE_ADDR            0xF2000000
#define VIC1_BASE_ADDR            0xF2100000
#define VIC2_BASE_ADDR            0xF2200000
#define VIC3_BASE_ADDR            0xF2300000
#define PWM_BASE_ADDR             0xE2500000


typedef enum {
	STATUS_FALSE = 0,
	STATUS_TRUE  = !STATUS_FALSE,
} STATUS_Enum;

typedef volatile unsigned int       _RW;
typedef volatile unsigned int       _OW;
typedef volatile const unsigned int _OR;
typedef unsigned int                _NU;

#endif /* _SOC_H_ */
