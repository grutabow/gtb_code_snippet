OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)

ENTRY(int_irq)

MEMORY
{
    DDR_RO_EXEC : ORIGIN = 0x6000000, LENGTH = 0x2000
    DSP_BUFFER : ORIGIN = 0x7200000, LENGTH = 0x1000
    DSP_BUFFER2 : ORIGIN = 0x7300000, LENGTH = 0x1000
}

SECTIONS
{
    .ddr_ro_exec 0x6000000 :
    {
        * (Init)
        * (.text .text.* .rodata .rodata.*)
        __ddr_ro_exec_end = . ;
    } AT > DDR_RO_EXEC
    
    
    
    .ddr_rw_data 0x68c0000 :
    {
        Image$$DDR_RW_DATA$$Base = . ;
        file1.o (.data .bss COMMON)
        * (.data .bss COMMON)
    }  AT > DDR_RO_EXEC
    Image$$DDR_RW_DATA$$Length = SIZEOF(.ddr_rw_data) ;
    Load$$DDR_RW_DATA$$Base = LOADADDR(.ddr_rw_data) ;
    

}
