//-------------------------------------------------------------------------------------------------
// FILE NAME    TimerTicker.h
// LANGUAGE     C
//
// DESCRIPTION  System timer ticker (timer module)
//
//-------------------------------------------------------------------------------------------------

#ifndef _TIMERTICKER_H_
#define _TIMERTICKER_H_

#include "TypeDef.h"


//--------------------------------------------------------------------------------------------------
// Function prototypes
//--------------------------------------------------------------------------------------------------
void InitTimerTicker(void);
void DeInitTimerTicker(void);
UInt32 GetStartTime(void);
Bool IsTimeElapsed(UInt32 theStartTime, UInt32 theTimeInTicks);
void TimerTickerIrqDummy(void);


#endif  // _TIMERTICKER_H_

//-------------------------------------------------------------------------------------------------
// EOF TimerTicker.h
//------------------------------------------------------------------------------------------------
