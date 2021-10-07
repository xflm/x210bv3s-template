#include "mboard.h"
#include "mled.h"
#include "mdebug.h"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	mBoardInit();
	mLedSetOff(MLED_L123);
	//mLedTest();
	//mUartTest();
	mTimTest();

	return 0;
}
