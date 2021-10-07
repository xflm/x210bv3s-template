#include "mboard.h"
#include "vic.h"
#include "mled.h"
#include "muart.h"
#include "mdebug.h"
#include "mtim.h"
#include "syscon.h"

void mBoardInit(void)
{
	mDebugRedirect(mUartPutBytes, mUartPutString);
	VIC_PreInit();
	SYSCON_PreInit();
	mLedInit();
	mUartInit();
	mTimInit();
}
