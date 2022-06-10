#include <stdint.h>

struct XIP_SSI_t
{
    uint32_t  CTRLR0;               // Control register 0
    uint32_t  CTRLR1;               // Master Control register 1
    uint32_t  SSIENR;               // SSI Enable
    uint32_t  MWCR;                 // Microwire Control
    uint32_t  SER;                  // Slave enable
    uint32_t  BAUDR;                // Baud rate
    uint32_t  TXFTLR;               // TX FIFO threshold level
    uint32_t  RXFTLR;               // RX FIFO threshold level
    uint32_t  TXFLR;                // TX FIFO level
    uint32_t  RXFLR;                // RX FIFO level
    uint32_t  SR;                   // Status register
    uint32_t  IMR;                  // Interrupt mask
    uint32_t  ISR;                  // Interrupt status
    uint32_t  RISR;                 // Raw interrupt status
    uint32_t  TXOICR;               // TX FIFO overflow interrupt clear
    uint32_t  RXOICR;               // RX FIFO overflow interrupt clear
    uint32_t  RXUICR;               // RX FIFO underflow interrupt clear
    uint32_t  MSTICR;               // Multi-master interrupt clear
    uint32_t  ICR;                  // Interrupt clear
    uint32_t  DMACR;                // DMA control
    uint32_t  DMATDLR;              // DMA TX data level
    uint32_t  DMARDLR;              // DMA RX data level
    uint32_t  IDR;                  // Identification register
    uint32_t  SSI_VERSION_ID;       // Version ID
    uint32_t  DR0;                  //  Data Register 0 (of 36)
    uint32_t  DR1;                  //  Data Register 1 (of 36)
    uint32_t  DR2;                  //  Data Register 2 (of 36)
    uint32_t  DR3;                  //  Data Register 3 (of 36)
    uint32_t  DR4;                  //  Data Register 4 (of 36)
    uint32_t  DR5;                  //  Data Register 5 (of 36)
    uint32_t  DR6;                  //  Data Register 6 (of 36)
    uint32_t  DR7;                  //  Data Register 7 (of 36)
    uint32_t  DR8;                  //  Data Register 8 (of 36)
    uint32_t  DR9;                  //  Data Register 9 (of 36)
    uint32_t  DR10;                 //  Data Register 10 (of 36)
    uint32_t  DR11;                 //  Data Register 11 (of 36)
    uint32_t  DR12;                 //  Data Register 12 (of 36)
    uint32_t  DR13;                 //  Data Register 13 (of 36)
    uint32_t  DR14;                 //  Data Register 14 (of 36)
    uint32_t  DR15;                 //  Data Register 15 (of 36)
    uint32_t  DR16;                 //  Data Register 16 (of 36)
    uint32_t  DR17;                 //  Data Register 17 (of 36)
    uint32_t  DR18;                 //  Data Register 18 (of 36)
    uint32_t  DR19;                 //  Data Register 19 (of 36)
    uint32_t  DR20;                 //  Data Register 20 (of 36)
    uint32_t  DR21;                 //  Data Register 21 (of 36)
    uint32_t  DR22;                 //  Data Register 22 (of 36)
    uint32_t  DR23;                 //  Data Register 23 (of 36)
    uint32_t  DR24;                 //  Data Register 24 (of 36)
    uint32_t  DR25;                 //  Data Register 25 (of 36)
    uint32_t  DR26;                 //  Data Register 26 (of 36)
    uint32_t  DR27;                 //  Data Register 27 (of 36)
    uint32_t  DR28;                 //  Data Register 28 (of 36)
    uint32_t  DR29;                 //  Data Register 29 (of 36)
    uint32_t  DR30;                 //  Data Register 30 (of 36)
    uint32_t  DR31;                 //  Data Register 31 (of 36)
    uint32_t  DR32;                 //  Data Register 32 (of 36)
    uint32_t  DR33;                 //  Data Register 33 (of 36)
    uint32_t  DR34;                 //  Data Register 34 (of 36)
    uint32_t  DR35;                 //  Data Register 35 (of 36)
    uint32_t  DR36;                 //  Data Register 36 (of 36)
    uint32_t  RX_SAMPLE_DLY;        //  RX sample delay
    uint32_t  SPI_CTRLR0;           //  SPI control
    uint32_t  TXD_DRIVE_EDGE;       //  TX drive edge
};