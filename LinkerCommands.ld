MEMORY
{
    /* The stage 1 bootloader copies the first 256 bytes from the exnternal flash to SRAM5 then starts execution
       after ensuring the CRC-32/MPEG-2 at the last 4 bytes matches, hence the 252 Bytes for BootUp */

    BootUp (rx) : ORIGIN = 0x10000000, LENGTH = 252        
    FALSH (rx) : ORIGIN = 0x10000100, LENGTH = 2048K - 256
    SRAM0_3 (rwx) : ORIGIN = 0x20000000, LENGTH = 256K
    SRAM4 (rwx) : ORIGIN = 0x20040000, LENGTH = 4K
    SRAM5 (rwx) : ORIGIN = 0x20041000, LENGTH = 4K
}   

ENTRY(ResetHandler)
 
SECTIONS
{
    .BootUp :
    {
        . = ALIGN(4);
        start = .;
        PROVIDE(__BOOTUP_START = .);

        *(.BLINK*)

        PROVIDE(__BOOTUP_END = .);

        ASSERT((__BOOTUP_END - __BOOTUP_START) < 0xFD ,"Error: BootUp OVERFLOW");
    } >SRAM5 AT > BootUp

    .text :
    {
        . = ALIGN(4);
        /* KEEP(*(.ISR_VECTOR_TABLE)) */
        *(.text)
        *(.rodata)
        *(.const)
    
    } > FALSH

    .data :
    {
        . = ALIGN(4);           /* 32 bit bus bandwidth */
        
        __data_start = .;
        *(.data)
        . = ALIGN(4);           /* 32 bit bus bandwidth */
        __data_end = .;

    }> SRAM0_3 AT > FALSH
    
	__data_load= LOADADDR(.data);	/*Fetch load address from LoadMemoAddr([physical])*/

    .bss :
    {
        . = ALIGN(4);           /* 32 bit bus bandwidth */
        __bss_start = .;
        *(.bss)
        *(.common)
        . = ALIGN(4);           /* 32 bit bus bandwidth */
        __bss_end = .;
    }  > SRAM0_3
}