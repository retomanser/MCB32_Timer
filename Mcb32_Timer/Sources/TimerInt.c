//-------------------------------------------------------------------------------------------------
// FILE NAME    TimerInt.c
// LANGUAGE     C
//
// DESCRIPTION  Test of a Timer-Interrupt: Blinking LED
//
//-------------------------------------------------------------------------------------------------

#include "stm32f10x.h"
#include "Ports.h"
#include "TimerInt.h"
#include "TypeDef.h"

//--------------------------------------------------------------------------------------------------
// Defines and constants
// your code

//--------------------------------------------------------------------------------------------------
// Initialize the external Interrupt
//--------------------------------------------------------------------------------------------------
void InitTimerInt(void)
{
    
    // Enable Peripherie Timer6
// your code
   
    
    // Setup timer6:
// your code

    // set prescaler value
    // set autoreload value
    // enabel update interrupt
    // enable timer
    
    // Setup NVIC
// your code

}   // InitTimerInt()


//--------------------------------------------------------------------------------------------------
// Interrupt Service Routine Timer-Interrupt
//--------------------------------------------------------------------------------------------------
void TIM6_IRQHandler(void)
{
    // Interrupt on TIM6 -> toggle LED2
// your code
    
    // interrupt on Timer6 -> clear pendig bit

    // toggle Led2

}


//-------------------------------------------------------------------------------------------------
// EOF TimerInt.c
//-------------------------------------------------------------------------------------------------
