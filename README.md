# Embedded Programming Project: AVR-microcontroller
Personal home-project with AVR-microcontroller

## My Windows environment
The **Cygwin** environment is used as it provides GNU-Toolchain (e.g. avr-gcc and avr-objcopy). In addition, in order to flash and program the microprocessor we use **AVRDUDE** (which you can download, you may need to set environmental path to it in order to use it in CLI).

Example compilation process of `hello-world.c` (involves flashing the AVR-microprocessor on Arduino Uno R3:
```
>> avr-gcc -mmcu=atmega1284p  -g hello-world.c -o hello-world.elf -O1
>> avr-objcopy -j .text -j .data -j .bss -O ihex hello-world.elf hello-world.hex
>> avrdude -p m328p -c arduino -P COM3 -e -U flash:w:hello-world.hex
```
