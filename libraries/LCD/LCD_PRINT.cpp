// LCD_PRINT.cpp modified by Enno Klatt using parts of Arduino IDE code
// customized for ATmega328P
	
#include "LCD.h"
#include "LCD_PRINT.h"

// send character to LCD
void lcd_print(char chr){						// int8_t	-128 to 127
	send_data(chr);
}

// send string to LCD
void lcd_print(char* data){			
	send_data_string(data);	
}

// send string to LCD cursor x and row y 
void lcd_print_xy( uint8_t x, uint8_t y, char* data ) {
    lcd_setcursor( x, y );
    send_data_string( data );
}

// send numbers from int to unsigned long, double and float
void lcd_print(int number){					// int16_t	-32768 to 32767
	if (number < 0) {
		send_data('-');
		number = -number;
	}
	lcd_printNumber(number);
	// send_data('I');
}

void lcd_print(unsigned int number){		// uint16_t	0 to 65535U
	lcd_printNumber(number);
	// send_data('J');	
}

void lcd_print(long number){				// int32_t	-2147483647 to 2147483647
	if (number < 0) {
		send_data('-');
		number = -number;
	}
	lcd_printNumber(number);															
	// send_data('L');
}

void lcd_print(unsigned long number){		// uint32_t	o to 4294967295UL
	lcd_printNumber(number);
	// send_data('U');
}

void lcd_print(double number){
	lcd_printFloat(number);	
	// send_data('D');
}

void lcd_print(float number){
	lcd_printFloat(number);
	// send_data('F');	
}


// internal function which converts number ( positice numbers) to char*
void lcd_printNumber(unsigned long number) {
	int bufferSize = sizeof(unsigned long) * 8 + 1;
	char buffer[bufferSize]; 						// char array which holds the splitted number as char
	char str[bufferSize]; 							// char array which holds the converted number
	uint8_t  digits = 0 ;							// how many digits has the number	
											
	while (number > 0) {
		buffer[digits]	= number%10 + '0';			// get digit and convert digit to character
		number /=10;								// move to the next digit
		digits++;									// get number of digits
	}
													// get number in correct order from left to right
	for(int i = 0; i < digits; i++) str[i] = buffer[digits - 1 - i];  
	str[digits]='\0';								// add end of char-array '\0'
	send_data_string(str);
}

// function which splits double to integer- and remainder-part...
void lcd_printFloat(double number) {
	
	uint8_t digits = 3;
	if (number < 0.0) {							// Handle negative numbers
		send_data('-');
		number = -number;
	}
	
	double rounding = 0.5;						// Round correctly so that print(1.999, 2) prints as "2.00"
	for (uint8_t i=0; i <digits ; ++i)
	rounding /= 10.0;	
	number += rounding;

	unsigned long int_part = (unsigned long)number; // Extract the integer part of the number and print it
	double remainder = number - (double)int_part;
	lcd_printNumber(int_part);


	if (digits > 0) send_data('.');			// Print the decimal point, but only if there are digits beyond
		
	while (digits-- > 0) {					// Extract digits from the remainder one at a time
		remainder *= 10.0;
		unsigned int toPrint = (unsigned int)(remainder);
		send_data(toPrint + '0');
		remainder -= toPrint;
	}
}

