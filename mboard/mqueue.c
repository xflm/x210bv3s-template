#include "mqueue.h"


typedef enum {
	MQUEUE_LOCK_OFF = 0,
	MQUEUE_LOCK_ON  = 1,
} MQueueLock_e;

typedef enum {
	MQUEUE_FULL_FALSE = 0,
	MQUEUE_FULL_TRUE  = 1,
} MQueueFull_e;

void mQueueInit(MQueue_t *queue, void *buf, uint32_t len,
                MQueueOverWrite_e overwrite)
{
	queue->startBuf = buf;
	queue->endBuf = ((uint8_t*)buf) + len;
	queue->len = len;
	queue->nowPos = buf;
	queue->endPos = buf;
	queue->overwrite = overwrite;
	queue->lock = MQUEUE_LOCK_OFF;
	queue->full = MQUEUE_FULL_FALSE;
}

static void mQueueEndPos(MQueue_t *queue)
{
	if(queue->endPos == queue->endBuf)
	{
		queue->endPos = queue->startBuf;
	}
}

static void mQueueNowPos(MQueue_t *queue)
{
	if(queue->nowPos == queue->endBuf)
	{
		queue->nowPos = queue->startBuf;
	}
}

static int mQueueEndPosLen(MQueue_t *queue)
{
	return queue->endBuf - queue->endPos;
}

static int mQueueNowPosLen(MQueue_t *queue)
{
	return queue->endBuf - queue->nowPos;
}

uint32_t mQueueDataLen(const MQueue_t *queue)
{
	if(queue->full)
	{
		return queue->len;
	}

	if(queue->endPos < queue->nowPos)
	{
		return queue->len - (queue->nowPos - queue->endPos);
	}
	else
	{
		return queue->endPos - queue->nowPos;
	}
}

uint32_t mQueueSpareLen(const MQueue_t *queue)
{
	if(queue->full)
	{
		return 0;
	}

	if(queue->endPos < queue->nowPos)
	{
		return queue->nowPos - queue->endPos;
	}
	else
	{
		return queue->len - (queue->endPos - queue->nowPos);
	}
}

MQueueRet_e mQueueWriteByte(MQueue_t *queue, uint8_t c)
{
	if(mQueueSpareLen(queue))
	{
		mQueueEndPos(queue);
		*queue->endPos++ = c;

		if(queue->endPos == queue->nowPos)
		{
			queue->full = MQUEUE_FULL_TRUE;
		}

		return MQUEUE_RET_OK;
	}

	return MQUEUE_RET_FULL;
}

uint32_t mQueueWriteBytes(MQueue_t *queue, const void *pBuf, uint32_t size)
{
	if(size == 0)
	{
		return 0;
	}

	uint32_t i;
	uint32_t endLen;
	uint32_t spareLen;
	const uint8_t *p = pBuf;

	i = 0;
	spareLen = mQueueSpareLen(queue);
	spareLen = spareLen > size ? size : spareLen;
	endLen = mQueueEndPosLen(queue);

	if(endLen < spareLen)
	{
		for(; i < endLen; ++i)
		{
			*queue->endPos++ = p[i];
		}

		queue->endPos = queue->startBuf;
	}

	for(; i < spareLen; ++i)
	{
		*queue->endPos++ = p[i];
	}

	if(queue->endPos == queue->nowPos)
	{
		queue->full = MQUEUE_FULL_TRUE;
	}

	return spareLen;
}

uint32_t mQueueWriteBytesFromReg(MQueue_t *queue, volatile const uint32_t *reg,
                                 uint32_t count)
{
	if(count == 0)
	{
		return 0;
	}

	uint32_t i;
	uint32_t endLen;
	uint32_t spareLen;

	i = 0;
	spareLen = mQueueSpareLen(queue);
	spareLen = spareLen > count ? count : spareLen;
	endLen = mQueueEndPosLen(queue);

	if(endLen < spareLen)
	{
		for(; i < endLen; ++i)
		{
			*queue->endPos++ = *reg;
		}

		queue->endPos = queue->startBuf;
	}

	for(; i < spareLen; ++i)
	{
		*queue->endPos++ = *reg;
	}

	if(queue->endPos == queue->nowPos)
	{
		queue->full = MQUEUE_FULL_TRUE;
	}

	return spareLen;
}

uint32_t mQueueReadByte(MQueue_t *queue)
{
	mQueueNowPos(queue);

	if(mQueueDataLen(queue))
	{
		queue->full = MQUEUE_FULL_FALSE;

		return *queue->nowPos++;
	}
	else
	{
		return MQUEUE_RET_EMPTY;
	}
}

uint32_t mQueueReadBytes(MQueue_t *queue, void *pBuf, uint32_t size)
{
	if(size == 0)
	{
		return 0;
	}

	uint32_t i;
	uint32_t dataLen;
	uint32_t endLen;
	uint8_t *p = pBuf;

	i = 0;
	mQueueNowPos(queue);
	dataLen = mQueueDataLen(queue);
	dataLen = dataLen > size ? size : dataLen;
	endLen = mQueueNowPosLen(queue);

	if(endLen < dataLen)
	{
		for(; i < endLen; ++i)
		{
			p[i] = *queue->nowPos++;
		}

		queue->nowPos = queue->startBuf;
	}

	for(; i < dataLen; ++i)
	{
		p[i] = *queue->nowPos++;
	}

	queue->full = MQUEUE_FULL_FALSE;

	return dataLen;
}

uint32_t mQueueReadBytesToReg(MQueue_t *queue, volatile uint32_t *reg,
                              uint32_t count)
{
	if(count == 0)
	{
		return 0;
	}

	uint32_t i;
	uint32_t dataLen;
	uint32_t endLen;

	i = 0;
	mQueueNowPos(queue);
	dataLen = mQueueDataLen(queue);
	dataLen = dataLen > count ? count : dataLen;
	endLen = mQueueNowPosLen(queue);

	if(endLen < dataLen)
	{
		for(; i < endLen; ++i)
		{
			*reg = *queue->nowPos++;
		}

		queue->nowPos = queue->startBuf;
	}

	for(; i < dataLen; ++i)
	{
		*reg = *queue->nowPos++;
	}

	queue->full = MQUEUE_FULL_FALSE;

	return dataLen;
}

void mQueueDataClean(MQueue_t *queue)
{
	queue->nowPos = queue->startBuf;
	queue->endPos = queue->startBuf;
	queue->full = MQUEUE_FULL_FALSE;
}
