#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define MAX_STATE 3

uint8_t state = 0;
uint8_t decreasing = 0;

static void turn_off_all(void);
static void turn_on(uint8_t led_id);

int main (void)
{
    DDRD |= (1 << PD2);
    DDRD |= (1 << PD3);
    DDRD |= (1 << PD4);
    DDRD |= (1 << PD5);

    while (1)
    {

        /* Turn off previous LED (all) */
        turn_off_all();

        /* Turn on LED <state> */
        turn_on(state);
        _delay_ms(100);

        /* If at the end of one side, switch direction */
        if (state == MAX_STATE)
        {
            decreasing = 1;
        }
        else if (state == 0)
        {
            decreasing = 0;
        }
        
        /* Increment/Decrement LED */
        if (decreasing) 
        {
            state--;
        }
        else
        {
            state++;
        }
        
    }
}


static void turn_off_all(void) 
{
    PORTD = 0;
}

static void turn_on(uint8_t led_id)
{
    switch (led_id)
    {
    case 0:
        PORTD = (1 << PB2);
        break;
    
    case 1:
        PORTD = (1 << PB3);
        break;

    case 2:
        PORTD = (1 << PB4);
        break;

    case 3:
        PORTD = (1 << PB5);
        break;
    
    default:
        break;
    }
}