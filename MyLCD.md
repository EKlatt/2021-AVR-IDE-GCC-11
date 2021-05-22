# LCD library manual<br>
Like the "Arduino-IDE" MyIDE comes with a folder called "../MyIDE/libraries".<br>
These subfolders are intended for user-libraries which you create or<br>
got from other sources.<br>
Create a subfolder for the user-library and add the *.h and *.o files.<br>
The library-files will be automatically included in the compile- and<br>
link-process.<br>

**LCD Library**<br>
I developped this library in order to make debugging easier.<br>
I followed some ideas from the Arduino-library.<br>

**C++ & Arduino compatibility**
> This libray can not be used in C-language, because I used<br>
> overwriting of functions which is a feature of C++<br>

**LCD initialize functions**<br>

void lcd_init( volatile uint8_t* _LCD_PORT_RS_EN, uint8_t _LCD_RS, uint8_t _LCD_EN,<br>
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;volatile uint8_t* _LCD_PORT, uint8_t _DB4, uint8_t _DB5, uint8_t _DB6, uint8_t _DB7);<br>

| **LCD functions**                           |                                         |
| :------------------------------------------ | --------------------------------------- |
| void lcd_clear();                           | clear display                           |
| void lcd_home( void );                      | home cursor                             |
| void lcd_display_on( void );                | display on                              |
| void lcd_display_off( void );               | display off                             |
| void lcd_cursor_on( void );                 | cursor on                               |
| void lcd_cursor_off( void );                | cursor off                              |
| void lcd_blink_on( void );                  | cursor blink on                         |
| void lcd_blink_off( void );                 | cursor blink off                        |
| void lcd_autoscroll_on( void );             | display moves, cursor still             |
| void lcd_autoscroll_off( void );            | display still, cursor moves             |
| void lcd_leftToRight( void );               | cursor left to right                    |
| void lcd_rightToLeft( void );               | cursor right to left                    |
| void lcd_scrollDisplayLeft( void );         | scroll display left                     |
| void lcd_scrollDisplayRight( void );        | scroll display right                    |
| void lcd_setcursor( uint8_t x, uint8_t y ); | set cursor to column x, line y (0 or 1) |

**LCD print number functions**<br>

* void lcd_print(int);<br>
* void lcd_print(unsigned int);<br>
* void lcd_print(long);<br>
* void lcd_print(unsigned long);<br>
* void lcd_print(double);<br>
* void lcd_print(float);<br>

**New print character functions<br>**
* void lcd_print(char*);<br>

* void lcd_print(char);<br>

* void lcd_print_xy( uint8_t x, uint8_t y, char *data );<br>

  

  **C++ Example**

  ```c++
// LCD 16x2 4 bit customized for ATmega328
  // reference see info.txt in folder ""...\libraries\LCD".
  // this library works only with C++ because of overloading functions
  
  #include <avr/io.h>					// include AVR std. library file  
  #include <util/delay.h>				// include inbuilt defined delay header file
#include <string.h> 				// function strcpy()
  #include "LCD.h"					// include header for LCD functions
  #include "LCD_PRINT.h"				// include header for LCD print-functions
  
  // Breadport-connections
  // LCD Pin 1 GND       	<-->		GND
  // LCD Pin 2 VCC       	<-->		+5V  
  // LCD Pin 3 VO       	<-->		GND (contrast adjust)  
  // LCD Pin 4 RS       	<-->		PB0  
  // LCD Pin 5 R/W       	<-->		GND  
  // LCD Pin 6 E       	<-->		PB1  
  // LCD Pin 7-10 		not used  
  // LCD Pin 11 DB4       <-->		PC2  
  // LCD Pin 12 DB5       <-->		PC3
  // LCD Pin 13 DB6       <-->		PC4  
  // LCD Pin 14 DB7       <-->		PC5  
  // LCD Pin 15 LED(+)    <-->		+5V (220 Ohm resistor)
  // LCD Pin 16 LED(-)    <-->		GND     
  		
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
  ```
  

------

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



