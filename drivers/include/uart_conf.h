#ifndef _UART_CONF_H_
#define _UART_CONF_H_

/**
 * @brief UART line control register, Reset 0x00000000.
 */
typedef enum {
	UART_LCON_WORD_5B         = 0x0<<0,
	UART_LCON_WORD_6B         = 0x1<<0,
	UART_LCON_WORD_7B         = 0x2<<0,
	UART_LCON_WORD_8B         = 0x3<<0,
	UART_LCON_STOP_1B         = 0x0<<2,
	UART_LCON_STOP_2B         = 0x1<<2,
	UART_LCON_PARITY_NONE     = 0x0<<3,
	UART_LCON_PARITY_ODD      = 0x4<<3,
	UART_LCON_PARITY_EVEN     = 0x5<<3,
	UART_LCON_PARITY_FORCED_1 = 0x6<<3,
	UART_LCON_PARITY_FORCED_0 = 0x7<<3,
	UART_LCON_MODE_NORMAL     = 0x0<<6,
	UART_LCON_MODE_INFRARED   = 0x1<<6,
} UART_LCONEnum;

/**
 * @brief UART control register, Reset 0x00000000.
 */
typedef enum {
    UART_CON_RMODE_DISABLE     = 0x0<<0,
    UART_CON_RMODE_INT_POLL    = 0x1<<0,
    UART_CON_RMODE_DMA         = 0x2<<0,
    UART_CON_TMODE_DISABLE     = 0x0<<2,
    UART_CON_TMODE_INT_POLL    = 0x1<<2,
    UART_CON_TMODE_DMA         = 0x2<<2,
    UART_CON_SEND_BREAK_SIGNAL = 0x1<<4,
    UART_CON_LOOP_BACK         = 0x1<<5,
    UART_CON_RX_ERR_INT_EN     = 0x1<<6,
    UART_CON_RX_TIMEOUT_EN     = 0x1<<7,
    UART_CON_RX_INT_EN         = 0x1<<8,
    UART_CON_TX_INT_EN         = 0x1<<9,
    UART_CON_SEL_PCLK          = 0x0<<10,
    UART_CON_SEL_SCLK_UART     = 0x1<<10,
    UART_CON_RX_DMA_BURST_1B   = 0x0<<16,
    UART_CON_RX_DMA_BURST_4B   = 0x1<<16,
    UART_CON_TX_DMA_BURST_1B   = 0x0<<20,
    UART_CON_TX_DMA_BURST_4B   = 0x1<<20,
} UART_CONEnum;

typedef enum {
    UART_FCON_ENABLE               = 0x1<<0,
    UART_FCON_RX_FIFO_RESET        = 0x1<<1,
    UART_FCON_TX_FIFO_RESET        = 0x1<<2,
    /* UART0: RX_LEVEL=(UART_FCON_RX_FIFO_LEVEL_x+1)*32. */
    /* UART1: RX_LEVEL=(UART_FCON_RX_FIFO_LEVEL_x+1)*8. */
    /* UART2_3: RX_LEVEL=(UART_FCON_RX_FIFO_LEVEL_x+1)*2. */
    UART_FCON_RX_FIFO_LEVEL_0      = 0x0<<4,
    UART_FCON_RX_FIFO_LEVEL_1      = 0x1<<4,
    UART_FCON_RX_FIFO_LEVEL_2      = 0x2<<4,
    UART_FCON_RX_FIFO_LEVEL_3      = 0x3<<4,
    UART_FCON_RX_FIFO_LEVEL_4      = 0x4<<4,
    UART_FCON_RX_FIFO_LEVEL_5      = 0x5<<4,
    UART_FCON_RX_FIFO_LEVEL_6      = 0x6<<4,
    UART_FCON_RX_FIFO_LEVEL_7      = 0x7<<4,
    /* UART0: TX_LEVEL=(UART_FCON_TX_FIFO_LEVEL_x*32. */
    /* UART1: TX_LEVEL=(UART_FCON_TX_FIFO_LEVEL_x*8. */
    /* UART2_3: TX_LEVEL=(UART_FCON_TX_FIFO_LEVEL_x*2. */
    UART_FCON_TX_FIFO_LEVEL_0      = 0x0<<8,
    UART_FCON_TX_FIFO_LEVEL_1      = 0x1<<8,
    UART_FCON_TX_FIFO_LEVEL_2      = 0x2<<8,
    UART_FCON_TX_FIFO_LEVEL_3      = 0x3<<8,
    UART_FCON_TX_FIFO_LEVEL_4      = 0x4<<8,
    UART_FCON_TX_FIFO_LEVEL_5      = 0x5<<8,
    UART_FCON_TX_FIFO_LEVEL_6      = 0x6<<8,
    UART_FCON_TX_FIFO_LEVEL_7      = 0x7<<8,
} UART_FCONEnum;

typedef enum {
    UART_TRSTATE_RX_READY  = 0x1<<0,
    UART_TRSTATE_TX_EMPTY  = 0x1<<1,
    UART_TRSTATE_TX_FINISH = 0x1<<2,
} UART_TRSTATEEnum;

typedef enum {
    UART_ERSTATE_OVER   = 0x1<<0,
    UART_ERSTATE_PARITY = 0x1<<1,
    UART_ERSTATE_FRAME  = 0x1<<2,
    UART_ERSTATE_BREAK  = 0x1<<3,
} UART_ERSTATEEnum;

typedef enum {
    UART_FSTATE_RX_COUNT = 0xFF<<0,
    UART_FSTATE_RX_FULL  = 0x01<<8,
    UART_FSTATE_RX_ERR   = 0x01<<9,
    UART_FSTATE_TX_COUNT = 0xFF<<16,
    UART_FSTATE_TX_FULL  = 0x01<<24,
} UART_FSTATEEnum;

/**
 * @brief UART interrupt pending register, the infomation mask by INTM.
 *   Write it to clear interrupt.
 */
typedef enum {
    UART_INTP_RX    = 0x1<<0,
    UART_INTP_ERR   = 0x1<<1,
    UART_INTP_TX    = 0x1<<2,
    UART_INTP_MODEM = 0x1<<3,
} UART_INTPEnum;

/**
 * @brief UART interrupt source pendding register, it is the raw infomation.
 */
typedef enum {
    UART_INTSP_RX_EN     = ~(0x1<<0),
	UART_INTSP_RX_DIS    = 0x1<<0,
    UART_INTSP_ERR_EN    = ~(0x1<<1),
	UART_INTSP_ERR_DIS   = 0x1<<1,
    UART_INTSP_TX_EN     = ~(0x1<<2),
	UART_INTSP_TX_DIS    = 0x1<<2,
    UART_INTSP_MODEM_EN  = ~(0x1<<3),
	UART_INTSP_MODEM_DIS = 0x1<<3,
} UART_INTSPEnum;

/**
 * @brief UART interrupt mask register, if 1, the interrupt will be masked. 
 */
typedef enum {
    UART_INTM_RX_EN     = ~(0x1<<0),
	UART_INTM_RX_DIS    = 0x1<<0,
    UART_INTM_ERR_EN    = ~(0x1<<1),
	UART_INTM_ERR_DIS   = 0x1<<1,
    UART_INTM_TX_EN     = ~(0x1<<2),
	UART_INTM_TX_DIS    = 0x1<<2,
    UART_INTM_MODEM_EN  = ~(0x1<<3),
	UART_INTM_MODEM_DIS = 0x1<<3,
} UART_INTMEnum;


#endif /* _UART_CONF_H_ */
