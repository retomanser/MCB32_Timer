//-------------------------------------------------------------------------------------------------
// FILE NAME    Ports.h
// LANGUAGE     C
//
// DESCRIPTION  Initialization and defines of the port pins
//              on the Evalboard MSC32 with STM32F107VC (Connectivity Line - F1xx CL)
//
//-------------------------------------------------------------------------------------------------

#ifndef _PORTS_H_
#define _PORTS_H_


//------------------------------------------------------------------
// Port initialization values and access defines and macros
//------------------------------------------------------------------
// In the following, the first initialization of the port pin
// for proper system start is made.
// The setting of the function select registers will be handled
// in the specific init of the modules.
//
// GPIOx_ODR    Ouput Data / Pull-up/down
// GPIOx_CRL    Control Low  (0..7)
// GPIOx_CRH    Control High (8..15)
// GPIOx_IDR    Input Data
// GPIOx_BSRR   Bit Set (Set/Reset)
// GPIOx_BRR    Bit Reset


//------------------------------------------------------------------
// Port A                               Cfg      Mod    Cfg Mod Out
// PA0  - WakeupButton                  Flt      In    - 01 00   0
// PA1  - (ETH_RMII_REF_CLK)            Flt      In    - 01 00   0
// PA2  - (ETH_RMII_MDIO)               AltPP    OutHi - 10 11   0
// PA3  - PinPA3                        GpPP     OutHi - 00 11   0
// PA4  - not used                      Pull Dwn In    - 10 00   0
// PA5  - (SPI1_SCK)                    Flt      In    - 01 00   0
// PA6  - (SPI1_MISO)                   Flt      In    - 01 00   0
// PA7  - (SPI1_MOSI)                   Flt      In    - 01 00   0
//
// PA8  - (MCO)                         AltPP    OutMe - 10 01   0
// PA9  - (USB_OTG_FS_VBUS)             Pull Dwn In    - 10 00   0
// PA10 - (USB_OTG_FS_ID)               Pull Dwn In    - 10 00   0
// PA11 - (USB_OTG_FS_DM)               Pull Dwn In    - 10 00   0
// PA12 - (USB_OTG_FS_DP)               Pull Dwn In    - 10 00   0
// PA13 - (JTMS-SWDIO)                  Pull Up  In    - 10 00   1
// PA14 - (JTCK-SWCLK)                  Pull Dwn In    - 10 00   0
// PA15 - (JTDI)                        Pull Up  In    - 10 00   1
//
// GPIOA_CRL/CRH MODEx  Dir/Speed
// (Dir/Speed)          00: (In)    Input (reset state)
//                      01: (OutMe) Output, medium speed (10 MHz)
//                      10: (OutLo) Output, low speed (2 MHz)
//                      11: (OutHi) Output, high speed (50 MHz)
//
// GPIOA_CRL/CRH CFGx   Input Config/Type (In)
//                      00: (Ana)   Analog Input (reset state)
//                      01: (Flt)   Floating input (reset state)
//                      10: (Pull)  Input with pull-up/down
//                      11: (---)   Reserved
//
// GPIOA_CRL/CRH CFGx   Output Config/Type (OutX)
//                      00: (GpPP)  GP out Push-Pull
//                      01: (GpOD)  GP out Open-Drain
//                      10: (AltPP) Alternate out Push-Pull
//                      11: (AltOD) Alternate out Open-Drain

#define InitValue_GPIOA_ODR     0xA000      // Data (Pull up/down)
#define InitValue_GPIOA_CRL     0x44483B44  // Control Low
#define InitValue_GPIOA_CRH     0x88888889  // Control High


// PA0 - In - WakeupButton (high active)
#define WakeupButtonPortBitMask     1<<0
#define WakeupButtonInPort          GPIOA
#define WakeupButtonPressed         (WakeupButtonInPort->IDR & WakeupButtonPortBitMask)
#define WakeupButtonReleased        (!(WakeupButtonInPort->IDR & WakeupButtonPortBitMask))

// PA3 - Out - PinPA3 - Test/Debug-Output
#define PinPA3PortBitMask   1<<3
#define PinPA3OutPort       GPIOA
#define SetPinPA3           PinPA3OutPort->BSRR = PinPA3PortBitMask
#define ClrPinPA3           PinPA3OutPort->BRR = PinPA3PortBitMask


//------------------------------------------------------------------
// Port B                               Cfg      Mod    Cfg Mod Out
// PB0  - not used                      Pull Dwn In    - 10 00   0
// PB1  - not used                      Pull Dwn In    - 10 00   0
// PB2  - (BOOT1)                       Pull Dwn In    - 10 00   0
// PB3  - (JTDO)                        AltPP    OutHi - 10 11   0
// PB4  - (nJTRST)                      Pull Up  In    - 10 00   1
// PB5  - not used                      Pull Dwn In    - 10 00   0
// PB6  - (USART1-TXD) / remap          AltPP    OutMe - 10 01   0
// PB7  - (USART1-RXD) / remap          Pull Up  In    - 10 00   1
//
// PB8  - (I2C1-SCL) / remap            AltOD    OutMe - 11 01   0
// PB9  - (I2C1-SDA) / remap            AltOD    OutMe - 11 01   0
// PB10 - not used                      Pull Dwn In    - 10 00   0
// PB11 - (ETH_RMII_TXEN)               AltPP    OutHi - 10 11   0
// PB12 - (ETH_RMII_TXD0)               AltPP    OutHi - 10 11   0
// PB13 - (ETH_RMII_TXD1)               AltPP    OutHi - 10 11   0
// PB14 - not used                      Pull Dwn In    - 10 00   0
// PB15 - not used                      Pull Dwn In    - 10 00   0
//
// GPIOA_CRL/CRH MODEx  Dir/Speed
//                      00: (In)    Input (reset state)
//                      01: (OutMe) Output, medium speed (10 MHz)
//                      10: (OutLo) Output, low speed (2 MHz)
//                      11: (OutHi) Output, high speed (50 MHz)
//
// GPIOA_CRL/CRH CFGx   Input Config/Type (In)
//                      00: (Ana)   Analog Input (reset state)
//                      01: (Flt)   Floating input (reset state)
//                      10: (Pull)  Input with pull-up/down
//                      11: (---)   Reserved
//
// GPIOA_CRL/CRH CFGx   Output Config/Type (OutX)
//                      00: (GpPP)  GP out Push-Pull
//                      01: (GpOD)  GP out Open-Drain
//                      10: (AltPP) Alternate out Push-Pull
//                      11: (AltOD) Alternate out Open-Drain

#define InitValue_GPIOB_ODR     0x0090      // Data (Pull up/down)
#define InitValue_GPIOB_CRL     0x8988B888  // Control Low
#define InitValue_GPIOB_CRH     0x88BBB8DD  // Control High


//------------------------------------------------------------------
// Port C                               Cfg      Mod    Cfg Mod Out
// PC0  - not used                      Pull Dwn In    - 10 00   0
// PC1  - (ETH_RMII_MDC) / remap        AltPP    OutHi - 10 11   0
// PC2  - not used                      Pull Dwn In    - 10 00   0
// PC3  - not used                      Pull Dwn In    - 10 00   0
// PC4  - (ADC_IN14)                    Ana      In    - 00 00   0
// PC5  - SdCardDetect                  Flt      In    - 01 00   0
// PC6  - not used                      Pull Dwn In    - 10 00   0
// PC7  - not used                      Pull Dwn In    - 10 00   0
//
// PC8  - nLcdChipSelect                GpPP     OutLo - 00 10   1
// PC9  - UsbVbusEnable                 GpPP     OutLo - 00 10   0
// PC10 - (SPI3-SCK) / remap            AltPP    OutHi - 10 11   0
// PC11 - (SPI3-MISO) / remap           AltPP    OutHi - 10 11   0
// PC12 - (SPI3-MOSI) / remap           Pull Up  In    - 10 00   1
// PC13 - (TAMPER) / TamperButton       Flt      In    - 01 00   0
// PC14 - (OSC32_IN) / not used         Pull Dwn In    - 10 00   0
// PC15 - (OSC32_OUT) / not used        Pull Dwn In    - 10 00   0
//
// GPIOA_CRL/CRH MODEx  Dir/Speed
//                      00: (In)    Input (reset state)
//                      01: (OutMe) Output, medium speed (10 MHz)
//                      10: (OutLo) Output, low speed (2 MHz)
//                      11: (OutHi) Output, high speed (50 MHz)
//
// GPIOA_CRL/CRH CFGx   Input Config/Type (In)
//                      00: (Ana)   Analog Input (reset state)
//                      01: (Flt)   Floating input (reset state)
//                      10: (Pull)  Input with pull-up/down
//                      11: (---)   Reserved
//
// GPIOA_CRL/CRH CFGx   Output Config/Type (OutX)
//                      00: (GpPP)  GP out Push-Pull
//                      01: (GpOD)  GP out Open-Drain
//                      10: (AltPP) Alternate out Push-Pull
//                      11: (AltOD) Alternate out Open-Drain

#define InitValue_GPIOC_ODR     0x1100      // Data (Pull up/down)
#define InitValue_GPIOC_CRL     0x884088B8  // Control Low
#define InitValue_GPIOC_CRH     0x8848BB22  // Control High


// PC5 - In - SdCardDetect (uSD-Card detected = low)
#define SdCardDetectPortBitMask   1<<5
#define SdCardDetectInPort        GPIOC
#define SdCardDetected            (!(SdCardDetectInPort->IDR & SdCardDetectPortBitMask))
#define SdCardNotDetected         (SdCardDetectInPort->IDR & SdCardDetectPortBitMask)

// PC8 - Out - LcdChipSelect (low active)
#define LcdChipSelectPortBitMask    1<<8
#define LcdChipSelectOutPort        GPIOC
#define SetLcdChipSelect            LcdChipSelectOutPort->BRR = LcdChipSelectPortBitMask
#define ClrLcdChipSelect            LcdChipSelectOutPort->BSRR = LcdChipSelectPortBitMask

// PC9 - Out - UsbVbusEnable (high active)
#define UsbVbusEnablePortBitMask    1<<9
#define UsbVbusEnableOutPort        GPIOC
#define SetUsbVbusEnable            UsbVbusEnableOutPort->BSRR = UsbVbusEnablePortBitMask
#define ClrUsbVbusEnable            UsbVbusEnableOutPort->BRR = UsbVbusEnablePortBitMask

// PC13 - In - TamperButton (low active)
#define TamperButtonPortBitMask     1<<13
#define TamperButtonInPort          GPIOC
#define TamperButtonPressed         (!(TamperButtonInPort->IDR & TamperButtonPortBitMask))
#define TamperButtonReleased        (TamperButtonInPort->IDR & TamperButtonPortBitMask)


//------------------------------------------------------------------
// Port D                               Cfg      Mod    Cfg Mod Out
// PD0  - not used                      Pull Dwn In    - 10 00   0
// PD1  - not used                      Pull Dwn In    - 10 00   0
// PD2  - not used                      Pull Dwn In    - 10 00   0
// PD3  - not used                      Pull Dwn In    - 10 00   0
// PD4  - not used                      Pull Dwn In    - 10 00   0
// PD5  - (USART2-TXD) / remap          AltPP    OutMe - 10 01   0
// PD6  - (USART2-RXD) / remap          Pull Up  In    - 10 00   1
// PD7  - BacklightEnable               GpPP     OutLo - 00 10   0
//
// PD8  - (ETH_RMII_CRS_DV) / remap     Flt      In    - 01 00   0
// PD9  - (ETH_RMII_RXD0) / remap       Flt      In    - 01 00   0
// PD10 - (ETH_RMII_RXD1) / remap       Flt      In    - 01 00   0
// PD11 - JoySwitchUp                   Flt      In    - 01 00   0
// PD12 - JoySwitchLeft                 Flt      In    - 01 00   0
// PD13 - JoySwitchDown                 Flt      In    - 01 00   0
// PD14 - JoySwitchRight                Flt      In    - 01 00   0
// PD15 - JoySwitchEnter                Flt      In    - 01 00   0
//
// GPIOA_CRL/CRH MODEx  Dir/Speed
//                      00: (In)    Input (reset state)
//                      01: (OutMe) Output, medium speed (10 MHz)
//                      10: (OutLo) Output, low speed (2 MHz)
//                      11: (OutHi) Output, high speed (50 MHz)
//
// GPIOA_CRL/CRH CFGx   Input Config/Type (In)
//                      00: (Ana)   Analog Input (reset state)
//                      01: (Flt)   Floating input (reset state)
//                      10: (Pull)  Input with pull-up/down
//                      11: (---)   Reserved
//
// GPIOA_CRL/CRH CFGx   Output Config/Type (OutX)
//                      00: (GpPP)  GP out Push-Pull
//                      01: (GpOD)  GP out Open-Drain
//                      10: (AltPP) Alternate out Push-Pull
//                      11: (AltOD) Alternate out Open-Drain

#define InitValue_GPIOD_ODR     0x0040      // Data (Pull up/down)
#define InitValue_GPIOD_CRL     0x28988888  // Control Low
#define InitValue_GPIOD_CRH     0x44444444  // Control High


// PD7 - Out - BacklightEnable (high active)
#define BacklightEnablePortBitMask  1<<7
#define BacklightEnableOutPort      GPIOD
#define SetBacklightEnable          BacklightEnableOutPort->BSRR = BacklightEnablePortBitMask
#define ClrBacklightEnable          BacklightEnableOutPort->BRR = BacklightEnablePortBitMask

// PD11 - In - JoySwitchUp (low active)
#define JoySwitchUpPortBitMask      1<<11
#define JoySwitchUpInPort           GPIOD
#define JoySwitchUpActive           (!(JoySwitchUpInPort->IDR & JoySwitchUpPortBitMask))

// PD12 - In - JoySwitchLeft (low active)
#define JoySwitchLeftPortBitMask    1<<12
#define JoySwitchLeftInPort         GPIOD
#define JoySwitchLeftActive         (!(JoySwitchLeftInPort->IDR & JoySwitchLeftPortBitMask))

// PD13 - In - JoySwitchDown (low active)
#define JoySwitchDownPortBitMask    1<<13
#define JoySwitchDownInPort         GPIOD
#define JoySwitchDownActive         (!(JoySwitchDownInPort->IDR & JoySwitchDownPortBitMask))

// PD14 - In - JoySwitchRight (low active)
#define JoySwitchRightPortBitMask   1<<14
#define JoySwitchRightInPort        GPIOD
#define JoySwitchRightActive        (!(JoySwitchRightInPort->IDR & JoySwitchRightPortBitMask))

// PD15 - In - JoySwitchEnter (low active)
#define JoySwitchEnterPortBitMask   1<<15
#define JoySwitchEnterInPort        GPIOD
#define JoySwitchEnterActive        (!(JoySwitchEnterInPort->IDR & JoySwitchEnterPortBitMask))


//------------------------------------------------------------------
// Port E                               Cfg      Mod    Cfg Mod Out
// PE0  - not used                      Pull Dwn In    - 10 00   0
// PE1  - UsbOverCurrentDetect          Flt      In    - 01 00   0
// PE2  - not used                      Pull Dwn In    - 10 00   0
// PE3  - TouchPenIrq                   Flt      In    - 01 00   0
// PE4  - TouchSpiMiso / SPI bit-bang   Flt      In    - 01 00   0
// PE5  - TouchSpiMosi / SPI bit-bang   GpPP     OutHi - 00 11   0
// PE6  - TouchChipSelect               GpPP     OutMe - 00 01   1
// PE7  - TouchSpiSck / SPI bit-bang    GpPP     OutHi - 00 11   0
//
// PE8  - Led0                          GpPP     OutHi - 00 11   0
// PE9  - Led1                          GpPP     OutHi - 00 11   0
// PE10 - Led2                          GpPP     OutHi - 00 11   0
// PE11 - Led3                          GpPP     OutHi - 00 11   0
// PE12 - Led4                          GpPP     OutHi - 00 11   0
// PE13 - Led5                          GpPP     OutHi - 00 11   0
// PE14 - Led6                          GpPP     OutHi - 00 11   0
// PE15 - RunLed                        GpPP     OutHi - 00 11   1
//
// GPIOA_CRL/CRH MODEx  Dir/Speed
//                      00: (In)    Input (reset state)
//                      01: (OutMe) Output, medium speed (10 MHz)
//                      10: (OutLo) Output, low speed (2 MHz)
//                      11: (OutHi) Output, high speed (50 MHz)
//
// GPIOA_CRL/CRH CFGx   Input Config/Type (In)
//                      00: (Ana)   Analog Input (reset state)
//                      01: (Flt)   Floating input (reset state)
//                      10: (Pull)  Input with pull-up/down
//                      11: (---)   Reserved
//
// GPIOA_CRL/CRH CFGx   Output Config/Type (OutX)
//                      00: (GpPP)  GP out Push-Pull
//                      01: (GpOD)  GP out Open-Drain
//                      10: (AltPP) Alternate out Push-Pull
//                      11: (AltOD) Alternate out Open-Drain

#define InitValue_GPIOE_ODR     0x8040      // Data (Pull up/down)
#define InitValue_GPIOE_CRL     0x31344848  // Control Low
#define InitValue_GPIOE_CRH     0x33333333  // Control High


// PE1 - In - UsbOverCurrentDetect (low active)
#define UsbOverCurrentDetectPortBitMask 1<<1
#define UsbOverCurrentDetectInPort      GPIOE
#define UsbOverCurrentDetected          (!(UsbOverCurrentDetectInPort->IDR & UsbOverCurrentDetectPortBitMask))
#define UsbLoadCurrentOkay              (UsbOverCurrentDetectInPort->IDR & UsbOverCurrentDetectPortBitMask)

// PE3 - In - TouchPenIrq (low active)
#define TouchPenIrqPortBitMask  1<<3
#define TouchPenIrqInPort       GPIOE
#define TouchPenIrq             (!(TouchPenIrqInPort->IDR & TouchPenIrqPortBitMask))

// PE4 - In - TouchSpiMiso (bit banging SPI MISO)
#define TouchSpiMisoPortBitMask     1<<4
#define TouchSpiMisoInPort          GPIOE
#define TouchSpiMisoLow             (!(TouchSpiMisoInPort->IDR & TouchSpiMisoPortBitMask))
#define TouchSpiMisoHigh            (TouchSpiMisoInPort->IDR & TouchSpiMisoPortBitMask)

// PE5 - Out - TouchSpiMosi (bit banging SPI MOSI)
#define TouchSpiMosiPortBitMask     1<<5
#define TouchSpiMosiOutPort         GPIOE
#define SetTouchSpiMosi             TouchSpiMosiOutPort->BSRR = TouchSpiMosiPortBitMask
#define ClrTouchSpiMosi             TouchSpiMosiOutPort->BRR = TouchSpiMosiPortBitMask

// PE6 - Out - TouchChipSelect (low active)
#define TouchChipSelectPortBitMask  1<<6
#define TouchChipSelectOutPort      GPIOE
#define SetTouchChipSelect          TouchChipSelectOutPort->BRR = TouchChipSelectPortBitMask
#define ClrTouchChipSelect          TouchChipSelectOutPort->BSRR = TouchChipSelectPortBitMask

// PE7 - Out - TouchSpiSck (bit banging SPI SCK)
#define TouchSpiSckPortBitMask      1<<7
#define TouchSpiSckOutPort          GPIOE
#define SetTouchSpiSck              TouchSpiSckOutPort->BSRR = TouchSpiSckPortBitMask
#define ClrTouchSpiSck              TouchSpiSckOutPort->BRR = TouchSpiSckPortBitMask

// PE8 - Out- Led0 (high active)
#define Led0PortBitMask     1<<8
#define Led0OutPort         GPIOE
#define SetLed0             Led0OutPort->BSRR = Led0PortBitMask
#define ClrLed0             Led0OutPort->BRR = Led0PortBitMask

// PE9 - Out- Led1 (high active)
#define Led1PortBitMask     1<<9
#define Led1OutPort         GPIOE
#define SetLed1             Led1OutPort->BSRR = Led1PortBitMask
#define ClrLed1             Led1OutPort->BRR = Led1PortBitMask

// PE10 - Out- Led2 (high active)
#define Led2PortBitMask     1<<10
#define Led2OutPort         GPIOE
#define SetLed2             Led2OutPort->BSRR = Led2PortBitMask
#define ClrLed2             Led2OutPort->BRR = Led2PortBitMask

// PE11 - Out- Led3 (high active)
#define Led3PortBitMask     1<<11
#define Led3OutPort         GPIOE
#define SetLed3             Led3OutPort->BSRR = Led3PortBitMask
#define ClrLed3             Led3OutPort->BRR = Led3PortBitMask

// PE12 - Out- Led4 (high active)
#define Led4PortBitMask     1<<12
#define Led4OutPort         GPIOE
#define SetLed4             Led4OutPort->BSRR = Led4PortBitMask
#define ClrLed4             Led4OutPort->BRR = Led4PortBitMask

// PE13 - Out- Led5 (high active)
#define Led5PortBitMask     1<<13
#define Led5OutPort         GPIOE
#define SetLed5             Led5OutPort->BSRR = Led5PortBitMask
#define ClrLed5             Led5OutPort->BRR = Led5PortBitMask

// PE14 - Out- Led6 (high active)
#define Led6PortBitMask     1<<14
#define Led6OutPort         GPIOE
#define SetLed6             Led6OutPort->BSRR = Led6PortBitMask
#define ClrLed6             Led6OutPort->BRR = Led6PortBitMask

// PE15 - Out - RunLed (Led7, high active)
#define RunLedPortBitMask   1<<15
#define RunLedOutPort       GPIOE
#define SetRunLed           RunLedOutPort->BSRR = RunLedPortBitMask
#define ClrRunLed           RunLedOutPort->BRR = RunLedPortBitMask


//--------------------------------------------------------------------------------------------------
// Port pin initialization after reset
//--------------------------------------------------------------------------------------------------
void InitPorts(void);


#endif  // _PORTS_H_

//-------------------------------------------------------------------------------------------------
// EOF Ports.h
//-------------------------------------------------------------------------------------------------
