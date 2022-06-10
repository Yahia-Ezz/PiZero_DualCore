#include <stdint.h>
#include "XIP.h"
void ResetHandler(void) __attribute__((section(".BLINK"))); // explicitly save the ResetHandler function in the .Blink Section
extern int main(void);

extern uint32_t __data_start;
extern uint32_t __data_end;
extern uint32_t __data_load;
extern uint32_t __bss_start;
extern uint32_t __bss_end;


#define XIP_SSI_BASE_ADDRESS 	0x18000000
#define DFS_32 	16U
#define TMOD 	8U
void ResetHandler(void)  
{
	volatile uint32_t *SRC, *DEST;
	struct XIP_SSI_t *XIP_SSI = (void*)XIP_SSI_BASE_ADDRESS;

	/* INIT XIP as master */
	
	XIP_SSI->SSIENR = 0;	//Disable serial devices

	XIP_SSI->CTRLR0 |= 	((32-1)<<DFS_32)	|
						(0x3<<TMOD);				

	XIP_SSI->CTRLR1 = 0;  // 1 frame ( n -1 )

	XIP_SSI->SSIENR = 1; 	//Disable serial devices


	/* Clear Non initialized Variables - Variables set to 0 and static variables */
	for (DEST = &__bss_start; DEST < &__bss_end; DEST++)
	{
		*DEST = (uint32_t) 0X0U;
	}

	/*Load .data variables from FLASH to RAM*/
	for (SRC = &__data_load, DEST = &__data_start; DEST < &__data_end;	SRC++, DEST++)
	{
		*DEST = *SRC;
	}
 
	/* Mark the End of Stack to check for Overflow  */
	*((volatile uint32_t*) &__bss_end) = 0xDEADBEEF;
 
    main(); 
} 