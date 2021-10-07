#ifndef _MQUEUE_H_
#define _MQUEUE_H_

#include <stdint.h>

typedef enum {
	MQUEUE_OVERWRITE_DIS  = 0,
	MQUEUE_OVERWRITE_EN   = 1,
	MQUEUE_OVERWRITE_TRUE = 3,
} MQueueOverWrite_e;

typedef enum {
	MQUEUE_RET_OK    = 0,
	MQUEUE_RET_FULL  = 0xFFFFFFFF,
	MQUEUE_RET_EMPTY = 0xFFFFFFFF,
} MQueueRet_e;

typedef struct {
	uint8_t *startBuf;
	uint8_t *endBuf;
	uint16_t len;
	volatile uint8_t *endPos;   /* End of the receive position. */
	volatile uint8_t *nowPos;   /* Current position of reading. */
	uint8_t lock;      /* MQueueLock_e */
	volatile uint8_t full;      /* MQueueFull_e */
	volatile uint8_t overwrite; /* MQueueOverWrite_e */
} MQueue_t;

#define MQUEUE_DEFINE(BUF, LEN, OVERWRITE) { \
	.startBuf = BUF, \
	.endBuf = BUF + LEN, \
	.len    = LEN, \
	.endPos = BUF, \
	.nowPos = BUF, \
	.lock   = 0, \
	.full   = 0, \
	.overwrite = OVERWRITE, \
}

void mQueueInit(MQueue_t *queue, void *buf, uint32_t len, MQueueOverWrite_e overwrite);
uint32_t mQueueDataLen(const MQueue_t *queue);
uint32_t mQueueSpareLen(const MQueue_t *queue);
void mQueueDataClean(MQueue_t *queue);

MQueueRet_e mQueueWriteByte(MQueue_t *queue, uint8_t c);
uint32_t mQueueWriteBytes(MQueue_t *queue, const void *pBuf, uint32_t size);
uint32_t mQueueWriteBytesFromReg(MQueue_t *queue, volatile const uint32_t *reg, uint32_t count);

uint32_t mQueueReadByte(MQueue_t *queue);
uint32_t mQueueReadBytes(MQueue_t *queue, void *pBuf, uint32_t size);
uint32_t mQueueReadBytesToReg(MQueue_t *queue, volatile uint32_t *reg, uint32_t count);

#endif /* _MQUEUE_H_ */

