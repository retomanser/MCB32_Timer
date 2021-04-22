//-------------------------------------------------------------------------------------------------
// FILE NAME    main.c
// LANGUAGE     C
//
// DESCRIPTION  The main.c
//
//-------------------------------------------------------------------------------------------------

#include "stm32f10x.h"
#include "Ports.h"
#include "Job.h"
#include "TimerTicker.h"
#include "RunLed.h"
#include "TouchP0P1.h"
#include "TimerInt.h"


int main(void)
{
    // At this stage the microcontroller clock setting is already configured.
    // This is done through SystemInit() which is called from startup
    // file (startup_stm32f10x_cl.s) before to branch to application main.

    InitPorts();    // Brings all the port pins into a save and defined state
	InitTimerTicker();
    InitTouchScreen();
    InitTimerInt();
    InitJob();

    while (1)
    {
        JobHandler();
		RunLedHandler();
    }

}   // main()
