#ifndef _TIM_H_
#define _TIM_H_

#include "soc.h"

#define TIM_BASE                          SOC_ST_BASE_ADDR 


#define TIM_TCFG_PRESCALER_FF(val)        (((val)&0xFF)<<0)
#define TIM_TCFG_DIVIDER_1                (0x0<<8)
#define TIM_TCFG_DIVIDER_2                (0x1<<8)
#define TIM_TCFG_DIVIDER_4                (0x2<<8)
#define TIM_TCFG_DIVIDER_8                (0x3<<8)
#define TIM_TCFG_DIVIDER_16               (0x4<<8)
#define TIM_TCFG_TCLKB_XXTI_XUSB          (0x0<<12)
#define TIM_TCFG_TCLKB_XrtcXTI            (0x1<<12)
#define TIM_TCFG_TCLKB_XusbXTI            (0x2<<12)
#define TIM_TCFG_TCLKB_APB                (0x3<<12)
#define TIM_TCFG_TICKGEN_SEL_INTEGER      (0x0<<14)
#define TIM_TCFG_TICKGEN_SEL_FRACTIONAL   (0x1<<14)
#define TIM_TCFG_FDIV_SEL_RTC_1MS         (0x0<<15)
#define TIM_TCFG_FDIV_SEL_GENERAL         (0x1<<15)


#define TIM_TCON_TIMER_START              (0x1<<0)
#define TIM_TCON_INTERRUPT_START          (0x1<<3)
#define TIM_TCON_UPDATE_ICNTB             (0x1<<4)
#define TIM_TCON_ONE_SHOT                 (0x1<<0)
#define TIM_TCON_INTERVAL_MODE            (0x1<<5)

#define TIM_TICNTB_VALUE_FFFFFFFF(val)    (val)
#define TIM_TFCNTB_VALUE_FFFF(val)        ((val)&0xFFFF)
#define TIM_TICNTB_VALUE(in, out)         ((in)/2/(out)-1)
#define TIM_TFCNTB_VALUE(in, out)         ((((in)%(2*(out)))*65536)/2/(out))

#define TIM_ICNTB_VALUE_7FFFFFFF(val)     ((val)&0x7FFFFFFF)
#define TIM_ICNTB_UPDATE_ICNTB            (0x1<<31)

#define TIM_INT_CSTAT_ENABLE              (0x1<<0)
#define TIM_INT_CSTAT_INTCNT_STATUS       (0x1<<1)
#define TIM_INT_CSTAT_TICNTB_STATUS       (0x1<<2)
#define TIM_INT_CSTAT_TFCNTB_STATUS       (0x1<<3)
#define TIM_INT_CSTAT_ICNTB_STATUS        (0x1<<4)
#define TIM_INT_CSTAT_TCON_STATUS         (0x1<<5)
#define TIM_INT_CSTAT_INTCNT_EIE          (0x1<<6)
#define TIM_INT_CSTAT_TICNTBWIE           (0x1<<7)
#define TIM_INT_CSTAT_TFCNTB_WIE          (0x1<<8)
#define TIM_INT_CSTAT_ICNTB_WIE           (0x1<<9)
#define TIM_INT_CSTAT_TCON_WIE            (0x1<<10)


typedef struct {
	MDevBase_t dev;
	MDevReg_t tcfg;
	MDevReg_t tcon;
	MDevReg_t ticntb;
	MDevReg_t tfcntb;
	MDevReg_t icntb;
	MDevReg_t int_cstat;
} TIM_InitStruct;

typedef struct {
	MDevBase_t dev;
	void (*expired)(void);
} TIM_IrqStruct;

MDevStat_e TIM_Init(const TIM_InitStruct *tim);
void TIM_Reset(MDevBase_t dev);
void TIM_Start(MDevBase_t dev);
void TIM_Stop(MDevBase_t dev);
void TIM_SetInterruptEnable(MDevBase_t dev, uint32_t int_cstat);
void TIM_SetInterruptDisable(MDevBase_t dev, uint32_t int_cstat);
void TIM_IrqHandler(void *p);

#endif /* _TIM_H_ */
