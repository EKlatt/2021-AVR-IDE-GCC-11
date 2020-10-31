// USART.cpp modified by Enno Klatt using Arduino IDE code
// customized for ATmega328P

#include "USART.h"	

  // Reference 1
void USART_Init(void) {
	UBRR0H = (unsigned char) (MYUBRR >> 8);		// Set baud rate
	UBRR0L = (unsigned char) MYUBRR;
	UCSR0B = (1 << RXEN0)   | (1 << TXEN0);		// Enable receiver and transmitter
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);	// Frame Format: Asynchron 8N1
}

  // Reference 2
void USART_Transmit( unsigned char data ) {		// Send one character to Serial-Output	uint8_t 0 to 255
	while ( !( UCSR0A & (1<<UDRE0)));			// Blocking: Wait for empty transmit buffer Atmel-Documentation
	UDR0 = data;								// Put data into buffer, sends the data
}

  // Reference 3
unsigned char USART_Receive( void ) {			// Receive one character, used in USART_GetString()
	while ( !(UCSR0A & (1<<RXC0)));				// Blocking: Wait for data to be received
	return UDR0;								// Get and return received data from buffer */
	}
	
unsigned char USART_Receive_Chr( void ) {		// Receive one character, if one character is wanted
	USART_Flush();								// Throw away all characters in receive buffer
	while ( !(UCSR0A & (1<<RXC0)));				// Blocking: Wait for data to be received
	return UDR0;								// Get and return received data from buffer */
	}	

  // Reference 4	
void USART_Putstring(char* StringPtr) {
	while(*StringPtr != 0x00){					// Until *StringPtr != '\0' that means "the end of char[]-character" 
		USART_Transmit(*StringPtr);
	StringPtr++;}
}

  // Reference 5
void USART_Getstring( char* Buffer, uint8_t MaxLen ) {		// Get string from Serial-Input
	uint8_t NextChar;
	uint8_t StringLen = 0;
	_delay_ms(10);								// Without delay we loose characters	
	USART_Flush();								// Throw away all characters in receive buffer
												// Because we want a new input of a string	

	NextChar = USART_Receive();					// Get character first attempt
	
	while( !(NextChar == '\n' || NextChar == '\r')  && StringLen < MaxLen - 1 ) {	// Wait until '\r' or '\n'
		*Buffer++ = NextChar;
		StringLen++;
		NextChar = USART_Receive();				// Gert remaining characters
	}
	*Buffer = '\0';								// Add end of char[]-character
}

// are there data to be received
bool USART_Available() {
	return  ( UCSR0A & (1<<RXC0) );				// true if data received
}

void USART_Flush(void) {						// Are there remaining data in the buffer, remove them
	unsigned char dummy;
	while ( UCSR0A & (1<<RXC0) ) {
		dummy = UDR0;
	}
}

void print(int number){							// int16_t	-32768 to 32767
	if (number < 0) {
		USART_Transmit('-');
		number = -number;
	}
	printNumber(number);
	// USART_Transmit('I');
}

void print(unsigned int number){				// uint16_t	0 to 65535
	printNumber(number);
	// USART_Transmit('J');	
}

void print(long number){						// int32_t	-2147483648 to 2147483647
	if (number < 0) {
		USART_Transmit('-');
		number = -number;
	}
	printNumber(number);															
	// USART_Transmit('L');
}

void print(unsigned long number){				// uint32_t	o to 4294967295
	printNumber(number);
	// USART_Transmit('U');
}

void print(double number){
	printFloat(number);	
	// USART_Transmit('D');
}

void print(float number){
	printFloat(number);
	// USART_Transmit('F');	
}

void print(char* string){
	USART_Putstring(string);	
}

void print(char chr){									// int8_t	-128 to 127
	USART_Transmit(chr);
}

void println(){
	USART_Transmit('\n');	
}

void printNumber(unsigned long number) {
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
	USART_Putstring(str);
}

// Copied and modified from Arduino print.cpp
void printFloat(double number) {
	
	uint8_t digits = 3;
	if (number < 0.0) {								// Handle negative numbers
		USART_Transmit('-');
		number = -number;
	}
	
	double rounding = 0.5;						// Round correctly so that print(1.999, 2) prints as "2.00"
	for (uint8_t i=0; i <digits ; ++i)
	rounding /= 10.0;	
	number += rounding;

	unsigned long int_part = (unsigned long)number; // Extract the integer part of the number and print it
	double remainder = number - (double)int_part;
	printNumber(int_part);


	if (digits > 0) USART_Transmit('.');			// Print the decimal point, but only if there are digits beyond
		
	while (digits-- > 0) {							// Extract digits from the remainder one at a time
		remainder *= 10.0;
		unsigned int toPrint = (unsigned int)(remainder);
		USART_Transmit(toPrint + '0');
		remainder -= toPrint;
	}
}

