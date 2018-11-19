
tcc -c -mcpu=cortex-r5 -mfloat-abi=soft -mthumb-interwork -o vector.o vector.S
tcc -c -mcpu=cortex-r5 -mthumb -mthumb-interwork -g -o file1.o  file1.c

armlink -mcpu=cortex-r5 -g -nostartfiles --specs=nosys.specs -o mybox.elf -Wl,-Map=target.map file1.o vector.o -lc -Wl,--entry=int_irq  -T memory.lds 

fromelf -d mybox.elf > as_output.txt


pause

