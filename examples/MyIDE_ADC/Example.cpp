// Example.cpp
// Reading analog values from ATmega analog pins ADC0 and ADC1
// Analog pins ADC2 to ADC5 are used for LCD
// http://www.extremeelectronics.co.in
// https://www.electronicwings.com/avr-atmega/lm35-temperature-sensor-interfacing-with-atmega1632

#include <avr/io.h>					// include AVR std. library file  
#include <util/delay.h>				// include inbuilt defined delay header file
#include <string.h> 				// function strcpy()
#include "LCD.h"					// include header for LCD functions
#include "LCD_PRINT.h"				// include header for LCD print-functions
#include "ADC.h"					// include header for analogread-functions

int main() {
	InitADC();													// initialize ATmega for analog input
	// initialize LCD with choosen hardware connections
	// notice one port for RS and EN, and one port for data-connections
	// lcd_init( <PORT of RS and EN>, <RS-pin>, <EN-pin>, <PORT of data>, <DB4-pin>, <DB5-pin>, <DB6-pin>, <DB7-pin>)
		// e.g.
		// notice &PORTB instead of PORTB; because we need the address
		// LCD RS      <-->  PORTB Bit PB0     (RS: 0=data, 1=command)
		// LCD EN      <-->  PORTB Bit PB1     (EN: 1-impuls for data ready)
		// notice &PORTC instead of PORTC; because we need the address
		// LCD DB4     <-->  PORTC Bit PC2
		// LCD DB5     <-->  PORTC Bit PC3		
		// LCD DB6     <-->  PORTC Bit PC4		
		// LCD DB7     <-->  PORTC Bit PC5		
	lcd_init( &PORTB, PB0, PB1, &PORTC, PC2, PC3, PC4, PC5);	// initialize LCD
	
	char str[24];						// buffer for strings
	int potval;

	while(1) {
										// ATmega328 Pin 23; Arduino Pin A0; analog Pin ADC0
		//potval = readADC(1) * 0.488;	// reading potentiometer value from ADC0 and calculate temperature (LM35)
										// sending potentiometer value to LCD
		potval = readADC(0);								
		lcd_clear();

		strcpy(str, "Potentiometer:");
		lcd_print(str);
		lcd_setcursor(5, 1);		
		lcd_print (potval); 
		_delay_ms(500);	
	} 
}
