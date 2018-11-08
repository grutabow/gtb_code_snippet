@set path=%path%;D:\bin\gcc-arm-none-eabi\Win32\bin

arm-none-eabi-gcc -c -mcpu=cortex-r5 -mfloat-abi=soft -mthumb-interwork -o vector.o vector.S
arm-none-eabi-gcc -c -mcpu=cortex-r5 -mthumb -mthumb-interwork -mno-unaligned-access -g -o file1.o  file1.c

arm-none-eabi-gcc -mcpu=cortex-r5 -g -nostartfiles --specs=nosys.specs -o mybox.elf -Wl,-Map=target.map file1.o vector.o -lc -Wl,--entry=int_irq

arm-none-eabi-objdump -d mybox.elf > as_output.txt
arm-none-eabi-objcopy -O binary mybox.elf  mybox.bin


pause

