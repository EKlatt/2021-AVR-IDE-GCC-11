// USART.h
// customized for ATmega328P

#ifndef USART_H_
#define USART_H_

#define F_CPU 16000000UL			// Clock Speed 
#define BAUD 9600UL					// baud rate
#define MYUBRR (F_CPU/16UL/BAUD-1)	// C++ macro for calculation of register values

#include <avr/io.h>                 // the AVR-library gives us access to Usart-registers
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>                 // for itoa()-function

// USART functions
void USART_Init(void);
unsigned char USART_Receive_Chr( void );
unsigned char USART_Receive( void );
void USART_Transmit( unsigned char );
void USART_Putstring( char* );
void USART_Getstring( char*, uint8_t );
bool USART_Available();
void USART_Flush();

// New Arduino functions
void print(int);
void print(unsigned int);
void printNumber(unsigned long);
void print(long);
void print(unsigned long);
void printFloat(double);
void print(double);
void print(float);
void print(char*);
void print(char);

void println();

#endif /* USART_H_ */