#define F_CPU 16000000  			// CPU frequency for proper time calculation in delay function

#include <avr/io.h>					// includes iom328p.h 
#include <util/delay.h>

int main(void)
{
    DDRD |= (1 << PD4);  			// make PB5 an output

    for(;;)
    {
        PORTD ^= (1 << PD4); 		// toggle PD6
        _delay_ms(1000);  			// delay for a second
    }

    return 0;  // the program executed successfully
}