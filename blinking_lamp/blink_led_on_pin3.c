
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

/* Pin (3) to output to lamp for turning on lamp
*  Pin (4) to read input from button
*/

int main (void)
{
    DDRD |= (1 << PD3);
    while (1) 
    {
        PORTD ^= (1 << PD3); 
        _delay_ms(250);
    }
}