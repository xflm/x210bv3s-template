/**
 *******************************************************************************
 * @file      mdebug.h
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


#ifndef _MDEBUG_H_
#define _MDEBUG_H_

#include <stdint.h>

//#define MDEBUG_NEW_LINE_LF      /*  \n  */
//#define MDEBUG_NEW_LINE_CR      /*  \r  */
#define MDEBUG_NEW_LINE_CRLF    /* \r\n */

#ifdef MDEBUG_NEW_LINE_LF
#define MDEBUG_ENDL   "\n"
#elif defined MDEBUG_NEW_LINE_CRLF
#define MDEBUG_ENDL   "\r\n"
#else /* MDEBUG_NEW_LINE_CR */
#define MDEBUG_ENDL   "\r"
#endif /* MDEBUG_NEW_LINE_LF */


typedef void (*MDebugBytes_t)(const uint8_t *bytes, uint32_t len);
typedef void (*MDebugString_t)(const char *str);

void mDebugRedirect(MDebugBytes_t bytes, MDebugString_t string);
void mDebugPuts(const char* dat);
void mDebugPutStr(const char* dat);
void mDebugPutn(const uint8_t* dat, uint32_t len);
void mDebugPutU8(const uint8_t *dat, uint32_t len);
void mDebugPutU16(const uint16_t *dat, uint32_t len);
void mDebugPutU32(const uint32_t *dat, uint32_t len);
void mDebugPutMemoryForU8(const char *label, const uint8_t *dat, uint32_t len);
void mDebugPutMemoryForU16(const char *label, const uint16_t *dat, uint32_t len);
void mDebugPutMemoryForU32(const char *label, const uint32_t *dat, uint32_t len);
void mDebugPrintf(const char *fmt, ...);
void mDebugLineFeed(void);

#endif /* _MDEBUG_H_ */

