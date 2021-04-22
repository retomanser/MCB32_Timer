//-------------------------------------------------------------------------------------------------
// FILE NAME    TimerTicker.c
// LANGUAGE     C
//
// DESCRIPTION  System timer ticker (timer module)
//
//-------------------------------------------------------------------------------------------------

#include "stm32f10x.h"
#include "TypeDef.h"
#include "TimerTicker.h"


//--------------------------------------------------------------------------------------------------
// Defines and constants

const UInt16 TimerTickerBaseTime = 100;     // Base Tick Time in us for the System TimerTicker


//--------------------------------------------------------------------------------------------------
// Local data

static UInt32 myTimerTicker = 0;


//--------------------------------------------------------------------------------------------------
// Initialize the system timer ticker, using the ARM SysTick Timer as ticker source.
//--------------------------------------------------------------------------------------------------
// SystemClock (in Hz) / 1000000 -> clocks per us
// SysTick Timer reload value = clocks per us * us per tick time
//--------------------------------------------------------------------------------------------------
void InitTimerTicker(void)
{
    SysTick_Config((SystemCoreClock / 1000000) * TimerTickerBaseTime);

}   // InitTimerTicker()


//--------------------------------------------------------------------------------------------------
// Delivers the current myTimerTicker (system timer ticker) in Ticks.
//--------------------------------------------------------------------------------------------------
UInt32 GetStartTime(void)
{
    return myTimerTicker;

}   // GetStartTime()


//--------------------------------------------------------------------------------------------------
// Is the time elapsed?
// Compares (theStartTime + theTimeInTicks) against myTimerTicker.
// The overflow of myTimerTicker (System timer ticker) is managed.
//--------------------------------------------------------------------------------------------------
Bool IsTimeElapsed(UInt32 theStartTime, UInt32 theTimeInTicks)
{
    UInt32 theActualTimerCounter;
    UInt32 theDifference;

    theActualTimerCounter = myTimerTicker;

    // Decide if the time is elapsed, with the handling of the counter overflow
    // For integer (UInt) arithmetic the difference is the right even an overflow happens
    theDifference = theActualTimerCounter - theStartTime;

    return (theDifference >= theTimeInTicks);

}   // IsTimeElapsed()


//--------------------------------------------------------------------------------------------------
// Interrupt handler (Function called by the interrupt of the ARM SysTick Timer).
// The ARM SysTick Timer is used as ticker source for the system timer ticker.
//--------------------------------------------------------------------------------------------------
void SysTick_Handler(void)
{
    myTimerTicker ++;       // Count up the TimerTicker

}   // SysTick_Handler()


//-------------------------------------------------------------------------------------------------
// EOF TimerTicker.c
//-------------------------------------------------------------------------------------------------
