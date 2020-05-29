#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

/* Blinks LED Diode on pin 8 (or bit 0 on Port B) */

int main(void)
{
    DDRB |= (1 << PB0);

    while (1) 
    {
        PORTB ^= (1 << PB0);
        _delay_ms(250);
    }
}