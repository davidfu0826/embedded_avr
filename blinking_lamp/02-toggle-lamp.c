#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

/*
* Program Description:
*   This program will toggle a LED diode (PIN3) for each 
*   button (PIN4) press on the AVR-microprocessor atmega1284p.
*
* Compilation process on Windows with Cygwin and AVRDUDE:
*   The following commands are used to flash the AVR-microprocessor (Arduino Uno R3)
*   >> avr-gcc -mmcu=atmega328p  -g toggle-lamp.c  -o toggle-lamp.elf -O1
*   >> avr-objcopy -j .text -j .data -j .bss -O ihex 02-toggle-lamp.elf 02-toggle-lamp.hex
*   >> avrdude -p m328p -c arduino -P COM3 -e -U flash:w:02-toggle-lamp.hex 
*
* General info about pins:
* - DDRx - Data direction register x, 0 - input, 1 - output
* - PINx - Read register
* - PORTx - Write register
*
* Pin (3) to output to lamp for turning on lamp
* Pin (4) to read input from button
*/


int main (void)
{
    DDRD |= (1 << PD3);  // Set PIN 3 to write
    DDRD &= ~(1 << PD4); // Set PIN 4 to read
    
    while (1)
    {
        /* Check if button is pressed */
        if (!(PIND & (1 << PD4))) // Read from PIN 4
        {
            /* Toggle state */
            PORTD ^= (1 << PD3); // Write to PIN 3
            _delay_ms(50);
            while (!(PIND & (1 << PD4))) {}
        }
        /* Wait a few microseconds inbetween each button check*/
        _delay_ms(50);
    }
}
