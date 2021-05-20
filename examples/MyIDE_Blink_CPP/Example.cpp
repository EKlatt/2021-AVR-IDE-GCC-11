// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
// https://www.arduino.cc/en/Reference/PortManipulation
// https://playground.arduino.cc/Code/BitMath/
// https://sites.google.com/site/qeewiki/books/avr-guide/digital-outputs
// https://de.wikibooks.org/wiki/C-Programmierung_mit_AVR-GCC/_Hello_World
// https://www.mikrocontroller.net/articles/Kategorie:AVR-GCC-Tutorial#16-Bit_Register_.28ADC.2C_ICR1.2C_OCR1x.2C_TCNT1.2C_UBRR.29

/* Hardware: connect PD4 with 300 Ohm resistor to ground
 * Task: Blinking LED
*/

#ifndef F_CPU
#define F_CPU 16000000				// CPU frequency for proper time calculation in delay function
#endif	

#include <avr/io.h>					// Defines names for AVR registers: SFR special function registers
									// includes <avr/iom328p.h>
									// #include <avr/sfr_defs.h>
									// #include <avr/portpins.h>
									
#include <util/delay.h>

int main(void) {
									// ATmega328P "7810D–AVR–01/15" page 61, 73, 280
									// Register DDRD defined in <avr/iom328p.h>
									// bit numbers
									// DDD4 defined in <avr/iom328p.h> (ATmega datasheet page 280)
									// DD4  defined in <avr/portpins.h> generic								
    DDRD |= (1 << DDD4);  			// make DDD4 an output (like ATmega example)

    for(;;) {
									// ATmega328P "7810D–AVR–01/15" page 61, 73, 280
									// Register PORTD defined in <avr/iom328p.h>
									// bit numbers
									// PORTD4 defined in <avr/iom328p.h>  (ATmega datasheet page 280)
									// PORT4  defined in <avr/portpins.h> generic
									// PD4    defined in <avr/portpins.h> (like ATmega example)
									// PD4 is the hardware description of the ATmega328 PIN
									
        PORTD ^= (1 << PORTD4); 	// toggle Pin PD4
        _delay_ms(1000);  			// delay for a second
    }

    return 0;  						// the program executed successfully
}