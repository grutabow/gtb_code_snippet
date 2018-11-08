
set path=%path%;D:\bin\gcc-arm-none-eabi\Win32\bin

arm-none-eabi-gcc -E -mcpu=Cortex-r5 -o output.pre  j.c

pause
