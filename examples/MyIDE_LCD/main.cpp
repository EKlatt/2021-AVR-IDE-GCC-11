// LCD 16x2 4 bit customized for ATmega328
// reference see info.txt
// this library works only with c++ because of overloading functions

#include <avr/io.h>					// include AVR std. library file  
#include <util/delay.h>				// include inbuilt defined delay header file
#include <string.h> 				// function strcpy()
#include "LCD.h"					// include header for LCD functions
#include "LCD_PRINT.h"				// include header for LCD print-functions

int main() {
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
	
	lcd_init( &PORTB, PB0, PB1, &PORTC, PC2, PC3, PC4, PC5);
	
	lcd_print('X');	
	_delay_ms(2000);

	lcd_clear();
	char str[24];
	strcpy(str, "Hello world");
	lcd_print(str);	
	_delay_ms(2000);
	
	lcd_clear();
	strcpy(str, "Integer");
	lcd_print(str);
	lcd_setcursor(0,1);
	lcd_print(-32767);
	_delay_ms(2000);
	
	lcd_clear();
	strcpy(str, "unsigned Integer");		
	lcd_print(str);
	lcd_setcursor(0,1);
	lcd_print(65535U);
	_delay_ms(2000);
	
	lcd_clear();
	strcpy(str, "long");	
	lcd_print(str);
	lcd_setcursor(0,1);
	lcd_print(-2147483647);		
	_delay_ms(2000);

	lcd_clear();
	strcpy(str, "unsigned long");			
	lcd_print(str);
	lcd_setcursor(0,1);
	lcd_print(4294967295UL);		
	_delay_ms(2000);

	lcd_clear();
	strcpy(str, "double");			
	lcd_print(str);
	lcd_setcursor(0,1);
	lcd_print(334567.123);		
	_delay_ms(2000);
	
	lcd_clear();
	strcpy(str, "Hannover");			
	lcd_print_xy(1, 1, str);
	
	while(1) {
	}
	return 0;
}
