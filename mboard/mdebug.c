/**
 *******************************************************************************
 * @file      mdebug.c
 * @brief     Print debug result interface.
 * @details   Using the vsprintf() function, we construct the format output 
 *   function and provide the function to print memory with ASCII. The print
 *   interface is provided by mio.h file.
 * @author    LiuMingming liumingming@sec-chip.com
 * @date      2020-04-26
 * @version   v1.0.0
 * @copyright Copyright (c) 2020-2020 SEC-CHIP Technology Co., Ltd
 *******************************************************************************
 *
 * @par Update
 *   <table>
 *   <tr><th>Data        <th>Version  <th>Author       <th>Description
 *   <tr><td>2020/02/26  <td>v1.0.0   <td>LiuMingming  <td>
 *     -# Create it..
 *   </table>
 *
 *******************************************************************************
 */


#include "mdebug.h"
#include <stdio.h>
#include <stdarg.h>

#define MDEBUG_BUF_MAX_LEN    1024

static const char hex[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

static char _mdebugBuf[MDEBUG_BUF_MAX_LEN];
static MDebugBytes_t mDebugBytes;
static MDebugString_t mDebugString;

void mDebugRedirect(MDebugBytes_t bytes, MDebugString_t string)
{
	if((bytes != NULL) && (string != NULL))
	{
		mDebugBytes = bytes;
		mDebugString = string;
	}
	else
	{
		mDebugBytes = NULL;
		mDebugString = NULL;
	}
}

void mDebugPuts(const char* dat)
{
	if(dat)
	{
		mDebugString(dat);
		mDebugLineFeed();
	}
}

void mDebugPutStr(const char* dat)
{
	if(dat)
	{
		mDebugString(dat);
	}
}

void mDebugPutn(const uint8_t* dat, uint32_t len)
{
	mDebugBytes(dat, len);
}

void mDebugPrintf(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	/* vsnprintf() will add '\0' at the end of out data. */
	vsnprintf(_mdebugBuf, MDEBUG_BUF_MAX_LEN, fmt, ap);
	va_end(ap);

	mDebugString(_mdebugBuf);
}

void mDebugPutU8(const uint8_t *dat, uint32_t len)
{
	char *p = _mdebugBuf;
	uint32_t i, j;

	i = len % (MDEBUG_BUF_MAX_LEN/3);

	if(i)
	{
		j = i;

		while(j--)
		{
			*p++ = hex[*dat >> 4];
			*p++ = hex[*dat & 0x0F];
			dat++;
		}

		mDebugBytes((uint8_t *)_mdebugBuf, p - _mdebugBuf);
	}

	for(; i < len; i += MDEBUG_BUF_MAX_LEN/3)
	{
		p = _mdebugBuf;
		j = MDEBUG_BUF_MAX_LEN/3;

		while(j--)
		{
			*p++ = hex[*dat >> 4];
			*p++ = hex[*dat & 0x0F];
			dat++;
		}

		mDebugBytes((uint8_t *)_mdebugBuf, p - _mdebugBuf);
	}
}

void mDebugPutMemoryForU8(const char *label, const uint8_t *dat, uint32_t len)
{
	mDebugPutStr(label);
	mDebugPutU8(dat, len);
	mDebugLineFeed();
}

void mDebugPutU16(const uint16_t *dat, uint32_t len)
{
	char *p = _mdebugBuf;
	uint32_t i, j;

	if((uint32_t)dat%2)
	{
		mDebugPuts("The watch memory not align.");

		return;
	}

	i = len % (MDEBUG_BUF_MAX_LEN/5);

	if(i)
	{
		j = i;

		while(j--)
		{
			*p++ = hex[((*dat) >> 12)       ];
			*p++ = hex[((*dat) >> 8 ) & 0x0F];
			*p++ = hex[((*dat) >> 4 ) & 0x0F];
			*p++ = hex[((*dat)      ) & 0x0F];
			*p++ = ' ';
			dat++;
		}

		mDebugBytes((uint8_t *)_mdebugBuf, p - _mdebugBuf);
	}

	for(; i < len; i += MDEBUG_BUF_MAX_LEN/5)
	{
		p = _mdebugBuf;
		j = MDEBUG_BUF_MAX_LEN/5;

		while(j--)
		{
			*p++ = hex[((*dat) >> 12)       ];
			*p++ = hex[((*dat) >> 8 ) & 0x0F];
			*p++ = hex[((*dat) >> 4 ) & 0x0F];
			*p++ = hex[((*dat)      ) & 0x0F];
			*p++ = ' ';
			dat++;
		}

		mDebugBytes((uint8_t *)_mdebugBuf, p - _mdebugBuf);
	}
}

void mDebugPutMemoryForU16(const char *label, const uint16_t *dat, uint32_t len)
{

	mDebugPutStr(label);
	mDebugPutU16(dat, len);
	mDebugLineFeed();
}

void mDebugPutU32(const uint32_t *dat, uint32_t len)
{
	char *p = _mdebugBuf;
	uint32_t i, j;

	if((uint32_t)dat%4)
	{
		mDebugPuts("The watch memory not align.");

		return;
	}

	i = len % (MDEBUG_BUF_MAX_LEN/9);

	if(i)
	{
		j = i;

		while(j--)
		{
			*p++ = hex[((*dat) >> 28)       ];
			*p++ = hex[((*dat) >> 24) & 0x0F];
			*p++ = hex[((*dat) >> 20) & 0x0F];
			*p++ = hex[((*dat) >> 16) & 0x0F];
			*p++ = hex[((*dat) >> 12) & 0x0F];
			*p++ = hex[((*dat) >> 8 ) & 0x0F];
			*p++ = hex[((*dat) >> 4 ) & 0x0F];
			*p++ = hex[((*dat)      ) & 0x0F];
			*p++ = ' ';
			dat++;
		}

		mDebugBytes((uint8_t *)_mdebugBuf, p - _mdebugBuf);
	}

	for(; i < len; i += MDEBUG_BUF_MAX_LEN/9)
	{
		p = _mdebugBuf;
		j = MDEBUG_BUF_MAX_LEN/9;

		while(j--)
		{
			*p++ = hex[((*dat) >> 28)       ];
			*p++ = hex[((*dat) >> 24) & 0x0F];
			*p++ = hex[((*dat) >> 20) & 0x0F];
			*p++ = hex[((*dat) >> 16) & 0x0F];
			*p++ = hex[((*dat) >> 12) & 0x0F];
			*p++ = hex[((*dat) >> 8 ) & 0x0F];
			*p++ = hex[((*dat) >> 4 ) & 0x0F];
			*p++ = hex[((*dat)      ) & 0x0F];
			*p++ = ' ';
			dat++;
		}

		mDebugBytes((uint8_t *)_mdebugBuf, p - _mdebugBuf);
	}
}

void mDebugPutMemoryForU32(const char *label, const uint32_t *dat, uint32_t len)
{
	mDebugPutStr(label);
	mDebugPutU32(dat, len);
	mDebugLineFeed();
}

void mDebugLineFeed(void)
{
	mDebugString(MDEBUG_ENDL);
}
