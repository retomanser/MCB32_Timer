//-------------------------------------------------------------------------------------------------
// FILE NAME    Ports.c
// LANGUAGE     C
//
// DESCRIPTION  Initialization of the port pins
//
//--------------------------------------------------------------------------------------------------

#include "stm32f10x.h"
#include "Ports.h"


//--------------------------------------------------------------------------------------------------
// Function prototypes for local use
//--------------------------------------------------------------------------------------------------
void ApplyDefaultPortRemapping(void);


//--------------------------------------------------------------------------------------------------
// Port pin initialization after reset
//--------------------------------------------------------------------------------------------------
void InitPorts(void)
{
    // Enable alternate function I/O clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    // and remap the port with default alternate function
    ApplyDefaultPortRemapping();

    // Init Port A
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIOA->ODR = InitValue_GPIOA_ODR;       // Data
    GPIOA->CRL = InitValue_GPIOA_CRL;       // Control Low
    GPIOA->CRH = InitValue_GPIOA_CRH;       // Control High

    // Init Port B
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIOB->ODR = InitValue_GPIOB_ODR;       // Data
    GPIOB->CRL = InitValue_GPIOB_CRL;       // Control Low
    GPIOB->CRH = InitValue_GPIOB_CRH;       // Control High

    // Init Port C
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIOC->ODR = InitValue_GPIOC_ODR;       // Data
    GPIOC->CRL = InitValue_GPIOC_CRL;       // Control Low
    GPIOC->CRH = InitValue_GPIOC_CRH;       // Control High

    // Init Port D
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    GPIOD->ODR = InitValue_GPIOD_ODR;       // Data
    GPIOD->CRL = InitValue_GPIOD_CRL;       // Control Low
    GPIOD->CRH = InitValue_GPIOD_CRH;       // Control High

    // Init Port E
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
    GPIOE->ODR = InitValue_GPIOE_ODR;       // Data
    GPIOE->CRL = InitValue_GPIOE_CRL;       // Control Low
    GPIOE->CRH = InitValue_GPIOE_CRH;       // Control High

}   // InitPorts()


//--------------------------------------------------------------------------------------------------
// Default port remapping after system start, as a part of the port initialization
//--------------------------------------------------------------------------------------------------
void ApplyDefaultPortRemapping(void)
{
    // Remap UART1: USART1_TX PA9  -> PB6
    //              USART1_RX PA10 -> PB7
    GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);

    // Remap UART2: USART2_TX PA2 -> PD5
    //              USART2_RX PA3 -> PD6
    GPIO_PinRemapConfig(GPIO_Remap_USART2, ENABLE);

    // Remap I2C1: I2C1_SCL PB6 -> PB8
    //             I2C1_SDA PB7 -> PB9
    GPIO_PinRemapConfig(GPIO_Remap_I2C1, ENABLE);

    // Remap SPI3: SPI3_SCK  PB3 -> PC10
    //             SPI3_MISO PB4 -> PC11
    //             SPI3_MOSI PB5 -> PC12
    GPIO_PinRemapConfig(GPIO_Remap_SPI3, ENABLE);

    // Remap ETH (RMII): ETH_RX_DV-CRS_DV PA7 -> PD8
    //                   ETH_RXD0         PC4 -> PD9
    //                   ETH_RXD1         PC5 -> PD10
    GPIO_PinRemapConfig(GPIO_Remap_ETH, ENABLE);

}   // ApplyDefaultPortRemapping()


//-------------------------------------------------------------------------------------------------
// EOF Ports.c
//-------------------------------------------------------------------------------------------------
