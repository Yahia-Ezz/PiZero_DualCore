#include <stdint.h>

void ResetHandler(void) __attribute__((section(".BLINK"))); // explicitly save the ResetHandler function in the .Blink Section
extern int main(void);

#define RESETS_RESET_BASE_ADDRESS       *((volatile uint32_t*) (0x4000C000 + 0x00) )
#define RESETS_DONE_BASE_ADDRESS        *((volatile uint32_t*) (0x4000C000 + 0x08) )

#define GPIO_OUT_SET_BASE_ADDRESS       *((volatile uint32_t*) (0xD0000000 + 0x14) )
#define GPIO_OUT_CLR_BASE_ADDRESS       *((volatile uint32_t*) (0xD0000000 + 0x18) )
#define GPIO_OE_BASE_ADDRESS            *((volatile uint32_t*) (0xD0000000 + 0x20) )
#define GPIO_OE_SET_BASE_ADDRESS        *((volatile uint32_t*) (0xD0000000 + 0x24) )
#define GPIO_OE_CLR_BASE_ADDRESS        *((volatile uint32_t*) (0xD0000000 + 0x28) )


#define GPIO_25_CTRL_BASE_ADDRESS       *((volatile uint32_t*) (0x40014000 + 0xCC) )

void ResetHandler(void) 
{
     /* Release IO_BANK0 from reset */
    RESETS_RESET_BASE_ADDRESS &=~ (1<<5);

    /* Wait for reset to be finish */
    while( !(RESETS_DONE_BASE_ADDRESS & (1<<5)) );

    /* set the function select to SIO */
    GPIO_25_CTRL_BASE_ADDRESS = 0x5;

    /* Enable LED */
    GPIO_OE_SET_BASE_ADDRESS |= (1<<25);
    GPIO_OUT_SET_BASE_ADDRESS |= (1<<25);

    main(); 
}