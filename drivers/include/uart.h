#ifndef _UART_H_
#define _UART_H_

#include "soc.h"

#define UART0_BASE                     (SOC_UART_BASE_ADDR+0x0000)
#define UART1_BASE                     (SOC_UART_BASE_ADDR+0x0400)
#define UART2_BASE                     (SOC_UART_BASE_ADDR+0x0800)
#define UART3_BASE                     (SOC_UART_BASE_ADDR+0x0C00)


/**
 * @brief UART line control register, Reset 0x00000000.
 */
#define UART_LCON_WORD_5B              (0x0<<0)
#define UART_LCON_WORD_6B              (0x1<<0)
#define UART_LCON_WORD_7B              (0x2<<0)
#define UART_LCON_WORD_8B              (0x3<<0)
#define UART_LCON_STOP_1B              (0x0<<2)
#define UART_LCON_STOP_2B              (0x1<<2)
#define UART_LCON_PARITY_NONE          (0x0<<3)
#define UART_LCON_PARITY_ODD           (0x4<<3)
#define UART_LCON_PARITY_EVEN          (0x5<<3)
#define UART_LCON_PARITY_FORCED_1      (0x6<<3)
#define UART_LCON_PARITY_FORCED_0      (0x7<<3)
#define UART_LCON_MODE_NORMAL          (0x0<<6)
#define UART_LCON_MODE_INFRARED        (0x1<<6)

/**
 * @brief UART control register, Reset 0x00000000.
 */
#define UART_CON_RMODE_DISABLE         (0x0<<0)
#define UART_CON_RMODE_INT_POLL        (0x1<<0)
#define UART_CON_RMODE_DMA             (0x2<<0)
#define UART_CON_TMODE_DISABLE         (0x0<<2)
#define UART_CON_TMODE_INT_POLL        (0x1<<2)
#define UART_CON_TMODE_DMA             (0x2<<2)
#define UART_CON_SEND_BREAK_SIGNAL     (0x1<<4)
#define UART_CON_LOOP_BACK             (0x1<<5)
#define UART_CON_RX_ERR_INT_EN         (0x1<<6)
#define UART_CON_RX_TIMEOUT_EN         (0x1<<7)
#define UART_CON_RX_INT_EN             (0x1<<8)
#define UART_CON_TX_INT_EN             (0x1<<9)
#define UART_CON_SEL_PCLK              (0x0<<10)
#define UART_CON_SEL_SCLK_UART         (0x1<<10)
#define UART_CON_RX_DMA_BURST_1B       (0x0<<16)
#define UART_CON_RX_DMA_BURST_4B       (0x1<<16)
#define UART_CON_TX_DMA_BURST_1B       (0x0<<20)
#define UART_CON_TX_DMA_BURST_4B       (0x1<<20)

#define UART_FCON_ENABLE               (0x1<<0)
#define UART_FCON_RX_FIFO_RESET        (0x1<<1)
#define UART_FCON_TX_FIFO_RESET        (0x1<<2)
/* UART0: RX_LEVEL=(UART_FCON_RX_FIFO_LEVEL_x+1)*32. */
/* UART1: RX_LEVEL=(UART_FCON_RX_FIFO_LEVEL_x+1)*8. */
/* UART2_3: RX_LEVEL=(UART_FCON_RX_FIFO_LEVEL_x+1)*2. */
#define UART_FCON_RX_FIFO_LEVEL_0      (0x0<<4)
#define UART_FCON_RX_FIFO_LEVEL_1      (0x1<<4)
#define UART_FCON_RX_FIFO_LEVEL_2      (0x2<<4)
#define UART_FCON_RX_FIFO_LEVEL_3      (0x3<<4)
#define UART_FCON_RX_FIFO_LEVEL_4      (0x4<<4)
#define UART_FCON_RX_FIFO_LEVEL_5      (0x5<<4)
#define UART_FCON_RX_FIFO_LEVEL_6      (0x6<<4)
#define UART_FCON_RX_FIFO_LEVEL_7      (0x7<<4)
/* UART0: TX_LEVEL=(UART_FCON_TX_FIFO_LEVEL_x*32. */
/* UART1: TX_LEVEL=(UART_FCON_TX_FIFO_LEVEL_x*8. */
/* UART2_3: TX_LEVEL=(UART_FCON_TX_FIFO_LEVEL_x*2. */
#define UART_FCON_TX_FIFO_LEVEL_0      (0x0<<8)
#define UART_FCON_TX_FIFO_LEVEL_1      (0x1<<8)
#define UART_FCON_TX_FIFO_LEVEL_2      (0x2<<8)
#define UART_FCON_TX_FIFO_LEVEL_3      (0x3<<8)
#define UART_FCON_TX_FIFO_LEVEL_4      (0x4<<8)
#define UART_FCON_TX_FIFO_LEVEL_5      (0x5<<8)
#define UART_FCON_TX_FIFO_LEVEL_6      (0x6<<8)
#define UART_FCON_TX_FIFO_LEVEL_7      (0x7<<8)

#define UART_TRSTATE_RX_READY          (0x1<<0)
#define UART_TRSTATE_TX_EMPTY          (0x1<<1)
#define UART_TRSTATE_TX_FINISH         (0x1<<2)

#define UART_ERSTATE_OVER              (0x1<<0)
#define UART_ERSTATE_PARITY            (0x1<<1)
#define UART_ERSTATE_FRAME             (0x1<<2)
#define UART_ERSTATE_BREAK             (0x1<<3)

#define UART_FSTATE_RX_COUNT           (0xFF<<0)
#define UART_FSTATE_RX_FULL            (0x01<<8)
#define UART_FSTATE_RX_ERR             (0x01<<9)
#define UART_FSTATE_TX_COUNT           (0xFF<<16)
#define UART_FSTATE_TX_FULL            (0x01<<24)

/**
 * @brief UART interrupt pending register, the infomation mask by INTM.
 *   Write it to clear interrupt.
 */
#define UART_INTP_RX                   (0x1<<0)
#define UART_INTP_ERR                  (0x1<<1)
#define UART_INTP_TX                   (0x1<<2)
#define UART_INTP_MODEM                (0x1<<3)
#define UART_INTP_ALL                  0x0F

/**
 * @brief UART interrupt source pendding register, it is the raw infomation.
 */
#define UART_INTSP_RX_EN               (0x1<<0)
#define UART_INTSP_ERR_EN              (0x1<<1)
#define UART_INTSP_TX_EN               (0x1<<2)
#define UART_INTSP_MODEM_EN            (0x1<<3)

/**
 * @brief UART interrupt mask register, if 1, the interrupt will be masked. 
 */
#define UART_INTM_RX_DIS               (0x1<<0)
#define UART_INTM_ERR_DIS              (0x1<<1)
#define UART_INTM_TX_DIS               (0x1<<2)
#define UART_INTM_MODEM_DIS            (0x1<<3)

typedef struct {
	MDevBase_t dev;
	MDevReg_t lcon;
	MDevReg_t con;
	MDevReg_t intm;
	uint32_t baud;
} UART_InitStruct;

typedef struct {
	MDevBase_t dev;
	void (*rx)(uint8_t ch);
	void (*tx)(void);
	void (*err)(void);
} UART_IrqStruct;

MDevStat_e UART_Init(const UART_InitStruct *init);
MDevStat_e UART_TxByte(MDevBase_t dev, uint8_t byte);
MDevStat_e UART_TxBytes(MDevBase_t dev, const uint8_t *bytes, uint32_t len);
MDevStat_e UART_TxString(MDevBase_t dev, const char *str);
MDevStat_e UART_RxByte(MDevBase_t dev, uint8_t *ch);
MDevStat_e UART_RxBytes(MDevBase_t dev, uint8_t *bytes, uint32_t max, uint32_t *len);
void UART_IrqHandler(void *p);

#endif /* _UART_H_ */
