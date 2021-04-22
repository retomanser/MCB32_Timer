//-------------------------------------------------------------------------------------------------
// FILE NAME    Job.c
// LANGUAGE     C
//
// DESCRIPTION  Job to do
//
//-------------------------------------------------------------------------------------------------

#include "stm32f10x.h"
#include "Ports.h"
#include "Job.h"
#include "TypeDef.h"
#include "TimerTicker.h"
#include "TouchP0P1.h"


//--------------------------------------------------------------------------------------------------
// Defines and constants

const UInt32 CountCycleTimeSlow = 10000; // Count in 100 us (timer ticks) for a blink frequency 1 Hz
const UInt32 CountCycleTimeFast =  1000; // Count in 100 us (timer ticks) for a blink frequency 1 Hz

//--------------------------------------------------------------------------------------------------
// Initialize the Job to do
//--------------------------------------------------------------------------------------------------
void InitJob(void)
{
    setScreenDir(VER);			    //LCD vertical
    printAt(0, "Beispiel Timer Interrupt");  //line 0: title
    printAt(9, "Beachte: RunLed!");
    printAt(10, "Test: Zeichnen auskommentieren");
    setTextcolor(YELLOW);
}   // InitJob()


//--------------------------------------------------------------------------------------------------
// Job to do
//--------------------------------------------------------------------------------------------------
void JobHandler(void)
{
	static UInt32 theCountCycleTimer = 0;
    static UInt32 theCounter = 0;
    static UInt32 theCountCycleTime = CountCycleTimeSlow;
	
    
	//----------------------------------------
    // Counter
    
	if (IsTimeElapsed(theCountCycleTimer, theCountCycleTime))
    {
        // Cycle time is elapsed, load/reload timers for next cycle
        theCountCycleTimer = GetStartTime();   // Reload timer for frequency/next cycle

		theCounter ++;
        
        // Draw something that takes a lot of time
        rectan(0,20,239,100,1, LIGHT_RED, 1);   // this takes a lot of time
        rectan(0,20,239,100,1, LIGHT_GREEN, 1); // this takes a lot of time

        printAt(18,"Cnt: ");       //line 14: title
        printDec(5, theCounter);   //Fieldsize 5: value
    }
    
    
    //----------------------------------------
    // TamperButton to clear the counter

    if (TamperButtonPressed)
    {
        SetLed1;
        theCounter = 0;
    }
    else
    {
        ClrLed1;
    }	
			
}   // JobHandler()


//-------------------------------------------------------------------------------------------------
// EOF Job.c
//-------------------------------------------------------------------------------------------------
