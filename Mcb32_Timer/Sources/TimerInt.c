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
// blinking frequency: 2 Hz -> every 250ms toggle the LED, interrupt after 250ms
const UInt16 Timer7Prescaler  = 7199; // 72MHz -> clock every 100us
const UInt16 Timer7Autoreload = 2499; // 2500 x 100us -> 250ms

//--------------------------------------------------------------------------------------------------
// Initialize the external Interrupt
//--------------------------------------------------------------------------------------------------
void InitTimerInt(void)
{
    
    // Enable Peripherie Timer6
    RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
   
    
    // Setup timer6:
    TIM7->PSC = Timer7Prescaler;    // set prescaler value
    TIM7->ARR = Timer7Autoreload;   // set autoreload value
    TIM7->DIER = TIM_DIER_UIE;      // enabel update interrupt
    TIM7->CR1 |= TIM_CR1_CEN;       // enable timer
    
    // Setup NVIC
    NVIC_EnableIRQ(TIM7_IRQn);

}   // InitTimerInt()


//--------------------------------------------------------------------------------------------------
// Interrupt Service Routine Timer-Interrupt
//--------------------------------------------------------------------------------------------------
void TIM7_IRQHandler(void)
{
    static Bool theLEDonFlag = False;
        
    // interrupt on Timer6 -> clear pendig bit
    TIM_ClearITPendingBit(TIM7,TIM_IT_Update);

    // toggle Led2
    if (theLEDonFlag)
    {
        ClrLed2;
        theLEDonFlag = False;
    }
    else
    {
        SetLed2;
        theLEDonFlag = True;
    }    
}   // TIM7_IRQHandler()


//-------------------------------------------------------------------------------------------------
// EOF TimerInt.c
//-------------------------------------------------------------------------------------------------
