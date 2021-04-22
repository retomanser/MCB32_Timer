//-------------------------------------------------------------------------------------------------
// FILE NAME    RunLed.c
// LANGUAGE     C
//
// DESCRIPTION  blinking led for status
//-------------------------------------------------------------------------------------------------

#include "stm32f10x.h"
#include "Ports.h"
#include "RunLed.h"
#include "TypeDef.h"
#include "TimerTicker.h"

//--------------------------------------------------------------------------------------------------
// Defines and constants

const UInt32 RunLedCycleTime = 10000; // Count in 100 us (timer ticks) for a blink frequency 1 Hz
const UInt32 RunLedOnTime 	 =  2000; // Count in 100 us (timer ticks)

//--------------------------------------------------------------------------------------------------
// Initialize the RunLed
//--------------------------------------------------------------------------------------------------
void InitRunLed(void)
{

}   // InitRunLed()

//--------------------------------------------------------------------------------------------------
// RunLed to blink
//--------------------------------------------------------------------------------------------------
void RunLedHandler(void)
{
	static UInt32 theRunLedTimer = 0;
	
    //----------------------------------------
    // RunLed

	if (IsTimeElapsed(theRunLedTimer, RunLedCycleTime))
    {
        // Cycle time is elapsed, load/reload timers for next cycle
        theRunLedTimer = GetStartTime();   // Reload timer for frequency/next cycle
        SetRunLed;       // Switch on the Run LED
    }
    
	if (IsTimeElapsed(theRunLedTimer, RunLedOnTime))
    {
        // on time is elapsed
        ClrRunLed;       // Switch off the Run LED
    }	

}   // RunLedHandler()

//-------------------------------------------------------------------------------------------------
// EOF RunLed.c
//-------------------------------------------------------------------------------------------------
