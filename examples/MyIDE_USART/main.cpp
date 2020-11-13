// https://learn.sparkfun.com/tutorials/data-types-in-arduino/all

#ifndef F_CPU
#define F_CPU 16000000					// CPU frequency for delay function
#endif	

#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"						// customized for ATmega328P

#define MaxLen 32						// Buffer-length for incoming data
char ReceivedString[MaxLen];			// Buffer for Serial Input


int main(void) {
	USART_Init();						// USART initialization for 9600 baud, ATmega328
	print("Hello world\n");				// "Hello world" - String["..."], '\0' automatically added
	   
	while (1) {
		char char_Value = 'a';				// the single character 'a'
		print(char_Value);
		println();							// just a linefeed
											// C-char string terminated with '\0'
		char msg1[6] = {'o', 'k', 'a', 'y', '\r', '\0'};
		print(msg1);
		println();
		
		int int_Value = -32767;				// int16_t - signed number from -32768 to 32767
		print(int_Value);
		println();
	
		unsigned int uint_Value = 65535; 	// uint16_t - unsigned number from 0-65535
		print(uint_Value);
		println();
		
		long long_Value = -2147483647;		// int32_t  - signed number from -2,147,483,648 to 2,147,483,647
		print(long_Value);
		println();
	
		unsigned long ulong_Value = 4294967295;	// uint32_t - unsigned number from 0 to 4,294,967,295.
		print(ulong_Value);
		println();
												// float- signed number from -3.4028235E38 to 3.4028235E38
												// this numbers can't be printed
		float flt_Value = 1.2346;				// rounded to 1.235 because we have 3 decimal digits
		print(flt_Value);
		println();
	
		double dbl_Value = 123456.12345;		// same as float
		print(dbl_Value);
		println();

		USART_Transmit('?');
											// asking for a one character input
		unsigned char letter = USART_Receive_Chr();
		USART_Transmit(letter);
		USART_Transmit('\n');
									
		USART_Transmit('?');
											// "char ReceivedString[MaxLen];" needs to be declared
											// asking for a string input
		USART_Getstring(ReceivedString, sizeof(ReceivedString));
		USART_Putstring(ReceivedString);
		USART_Transmit('\n');		
		
		_delay_ms(2000); 
	}
}