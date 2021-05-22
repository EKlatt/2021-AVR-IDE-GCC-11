# USART library manual<br>
Like the "Arduino-IDE" MyIDE comes with a folder called "../MyIDE/libraries".<br>
These subfolders are intended for user-libraries which you create or<br>
got from other sources.<br>
Create a subfolder for the user-library and add the *.h and *.o files.<br>
The library-files will be automatically included in the compile- and<br>
link-process.<br>

**USART Library**<br>
I developped this library in order to make debugging easier.<br>
I followed some ideas from the Arduino-library.<br>

**C++ & Arduino compatibility**<br>
> This libray can not used in C-language, because I used<br>
> overwriting of functions which is a feature of C++<br>

**USART functions**<br>
* void USART_Init(void);<br>
* unsigned char USART_Receive_Chr( void );<br>
* unsigned char USART_Receive( void );<br>
* void USART_Transmit( unsigned char );<br>
* void USART_Putstring( char* );<br>
* void USART_Getstring( char*, uint8_t );<br>
* bool USART_Available();<br>
* void USART_Flush();<br>

**New print functions**<br>
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

**C++ Example**<br>
_____________________________________________________________________________________________________<br>

```c++
#ifndef F_CPU
#define F_CPU 16000000					// CPU frequency for delay function
#endif	

#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"						// customized for ATmega328P

#define MaxLen 32						// Buffer-length for incoming data
char ReceivedString[MaxLen];			// Buffer for Serial Input

int main(void) {
	USART_Init();						// USART initialization for 9600 baud, ATmega328P
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
 		_delay_ms(2000); 
	}
}
```

​		

**Implemented data types:<br>**
Derived from https://learn.sparkfun.com/tutorials/data-types-in-arduino/all<br>

| Type                   | Description                                                  |
| :--------------------- | :----------------------------------------------------------- |
| bool (8 bit)           | int8_t    - simple logical true/false 1/0                    |
| char (8 bit)           | int8_t    - signed number from -128 to 127                   |
| unsigned char (8 bit)  | uint8_t   - unsigned number from 0-255                       |
| int (16 bit)           | int16_t  - signed number from -32768 to 32767                |
| unsigned int (16 bit)  | uint16_t - unsigned number from 0-65535                      |
| long (32 bit)          | int32_t  - signed number from -2,147,483,648 to 2,147,483,647 |
| unsigned long (32 bit) | uint32_t - unsigned number from 0-4,294,967,295              |
| float (32 bit)         | signed number from -3.4028235E38 to 3.4028235E38             |
| double                 | same as float                                                |



