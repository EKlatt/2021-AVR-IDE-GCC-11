# Library-Manual<br>
Like the "Arduino-IDE" MyIDE comes with a folder called "../MyIDE/libraries".<br>
These subfolders are intended for user-libraries which you create or<br>
got from other sources.<br>
Create a subfolder for the user-library and add the *.h and *.o files.<br>
The library-files will be automatically included in the compile- and<br>
link-process.<br>

**USART Library**<br>
I developped this library in order to make debugging easier.<br>
I followed some ideas from the Arduino-library.<br>

**USART functions<br>**
* void USART_Init(void);<br>
* unsigned char USART_Receive_Chr( void );<br>
* unsigned char USART_Receive( void );<br>
* void USART_Transmit( unsigned char );<br>
* void USART_Putstring( char* );<br>
* void USART_Getstring( char*, uint8_t );<br>
* bool USART_Available();<br>
* void USART_Flush();<br>

**New print functions<br>**
* void print(int);<br>
* void print(unsigned int);<br>
* void printNumber(unsigned long);<br>
* void print(long);<br>
* void print(unsigned long);<br>
* void printFloat(double);<br>
* void print(double);<br>
* void print(float);<br>
* void print(char*);<br>
* void print(char);<br>
* void println();<br>

**Example<br>**
<p>________________________________________________________________________________________________________<br>
#include <avr/io.h><br>
#include <util/delay.h><br>
#include "USART.h"						// customized for ATmega328P<br>

int main(void) {<br>
	USART_Init();						// USART initialization for 9600 baud, ATmega328<br>
	print("Hello world\n");				// "Hello world" - String["..."], '\0' automatically added<br>
<br>	   
	while (1) {<br>
		char char_Value = 'a';				// the single character 'a'<br>
		print(char_Value);<br>
		println();							// just a linefeed<br>
											// C-char string terminated with '\0'<br>
		char msg1[6] = {'o', 'k', 'a', 'y', '\r', '\0'};<br>
		print(msg1);<br>
		println();<br>
<br>		
		int int_Value = -32767;				// int16_t - signed number from -32768 to 32767<br>
		print(int_Value);<br>
		println();<br>
		_delay_ms(2000); <br>
	}<br>
}<br>		
</p>
**Implemented data types:<br>**
Derived from https://learn.sparkfun.com/tutorials/data-types-in-arduino/all<br>

bool (8 bit)           int8_t    - simple logical true/false 1/0<br>
char (8 bit)           int8_t    - signed number from -128 to 127. <br>
unsigned char (8 bit)  uint8_t   - unsigned number from 0-255<br>

int (16 bit)           int16_t  - signed number from -32768 to 32767.<br>
unsigned int (16 bit)  uint16_t - unsigned number from 0-65535<br> 

long (32 bit)          int32_t  - signed number from -2,147,483,648 to 2,147,483,647<br>
unsigned long (32 bit) uint32_t - unsigned number from 0-4,294,967,295.<br>

float (32 bit)                  - signed number from -3.4028235E38 to 3.4028235E38.<br>
								- numbers can't be printed<br>
double 							- same as float<br> 



