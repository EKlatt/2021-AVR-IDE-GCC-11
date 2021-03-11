# Assembler-Manual<br>
You may write in Assembler. Take in account, that in this case we are using GNU "avr-gcc-10.1.0".<br>
This means after precompiling we use "avr-as.exe" for assembling.<br>

Therefore "makefile" expects the file extension capital 'S'. Thus a valid filename is "example.S".<br>

**Differences of avr-as.exe**<br>

The main advantage of avr-as over e.g. avra is the possibility to generate linkable .o object files that can be mixed with C files.<br>

Unfortunately, the syntax differs slightly between these two assemblers. And it turns out that the syntax differences are big enough to make the conversion of existing source code a non-trivial task that tends to take way longer than expected.<br>

> See: https://tenbaht.github.io/posts/migrating-from-avra-to-avr-as/<br>
>

**GNU-AS**

> See: [An Introduction to the GNU Assembler (korea.ac.kr)](http://esca.korea.ac.kr/Research/ARM/GNU_Assembler_Intro_ARM.pdf)<br>

| **SVR-GCC Assembly Language Syntax** |                                                              |
| :----------------------------------- | ------------------------------------------------------------ |
| #include <avr/io.h>                  | C-precompiler directive                                      |
| label: instruction                   | new location of the program counter                          |
| ; my comment                         | comment starts with a colon ":"                              |
| /* ... */    and //                  | C-style comments are allowed                                 |
| .byte 0x55                           | inserts the byte 0x55                                        |
| .ascii "JNZ"                         | inserts the bytes 0x4A 0x4E 0x5A                             |
| .data .text                          | executable code is meant to appear in a .text section        |
| .end                                 | end of this source code file                                 |
| .equ adams, (5 * 8) + 2              | set the value of symbol to expression                        |
| .set adams, 42                       | alternative to .equ                                          |
| adams = 42                           | alternative to .equ                                          |
| .global main                         | nesessary because C-precompiler looks for main-function      |
| .include "filename"                  | insert the contents of filename                              |
| mov r16, 74                          | decimal number 74                                            |
| mov r16 ,0x4A                        | hexadecimal number 0x4A                                      |
| mov r16, 0b1001010                   | binary number 0b1001010                                      |
| mov r16, number                      | using preliminary defined number                             |
| .nolist .list                        | assembly listings are not generated or generated             |
| .org new-lc                          | advance the location counter of the current section to new-lc |
| lo8(val)                             | `lo8` Takes the least significant 8 bits of a 16-bit integer |
| hi8(val)                             | `hi8` Takes the most significant 8 bits of a 16-bit integer  |
|                                      |                                                              |

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

  

  **Example<br>**

  ------

  #include &lt;avr/io.h&gt;<br>
  #include &lt;util/delay.h&gt;<br>
  #include &lt;string.h&gt;<br>
  #include "LCD.h"&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;// customized for ATmega328P<br>
  #include "LCD_PRINT.h";&ensp;&ensp;&ensp;&ensp;// include header for LCD print-functions<br>

  #include &lt;avr/io.h&gt;<br>
  #include &lt;util/delay.h&gt;<br>
  #include &lt;string.h&gt;<br>
  #include "LCD.h"&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;// customized for ATmega328P<br>
  #include "LCD_PRINT.h";&ensp;&ensp;&ensp;&ensp;// include header for LCD print-functions<br>

int main() {<br>
&emsp;&emsp;// initialize LCD with choosen hardware connections<br>
&emsp;&emsp;// notice one port for RS and EN, and one port for data-connections<br>
&emsp;&emsp;// lcd_init( &lt;PORT of RS and EN&gt;, &lt;RS-pin&gt;, &lt;EN-pin&gt;, &lt;PORT of data&gt;, &lt;DB4-pin&gt;, &lt;DB5-pin&gt;, &lt;DB6-pin&gt;, &lt;DB7-pin&gt;)<br>
&emsp;&emsp;&emsp;// e.g.<br>
&emsp;&emsp;&emsp;// notice &PORTB instead of PORTB; because we need the address<br>
&emsp;&emsp;&emsp;// LCD RS      <-->  PORTB Bit PB0     (RS: 0=data, 1=command)<br>
&emsp;&emsp;&emsp;// LCD EN      <-->  PORTB Bit PB1     (EN: 1-impuls for data ready)<br>
&emsp;&emsp;&emsp;// notice &PORTC instead of PORTC; because we need the address<br>
&emsp;&emsp;&emsp;// LCD DB4     <-->  PORTC Bit PC2<br>
&emsp;&emsp;&emsp;// LCD DB5     <-->  PORTC Bit PC3<br>		
&emsp;&emsp;&emsp;// LCD DB6     <-->  PORTC Bit PC4<br>		
&emsp;&emsp;&emsp;// LCD DB7     <-->  PORTC Bit PC5<br>	
<br>
&emsp;lcd_init( &PORTB, PB0, PB1, &PORTC, PC2, PC3, PC4, PC5);<br>
<br>
&emsp;lcd_print('X');<br>	
&emsp;_delay_ms(2000);<br>
<br>
&emsp;lcd_clear();<br>
&emsp;char str[24];<br>
&emsp;strcpy(str, "Hello world");<br>
&emsp;lcd_print(str);<br>	
&emsp;_delay_ms(2000);<br>
<br>
&emsp;lcd_clear();<br>
&emsp;strcpy(str, "Integer");<br>
&emsp;lcd_print(str);<br>
&emsp;lcd_setcursor(0,1);<br>
&emsp;lcd_print(-32767);<br>
&emsp;_delay_ms(2000);<br>
<br>
&emsp;lcd_clear();<br>
&emsp;strcpy(str, "unsigned Integer");<br>		
&emsp;lcd_print(str);<br>
&emsp;lcd_setcursor(0,1);<br>
&emsp;lcd_print(65535U);<br>
&emsp;_delay_ms(2000);<br>
<br>
&emsp;lcd_clear();<br>
&emsp;strcpy(str, "long");<br>	
&emsp;lcd_print(str);<br>
&emsp;lcd_setcursor(0,1);<br>
&emsp;lcd_print(-2147483647);<br>		
&emsp;_delay_ms(2000);<br>
<br>
&emsp;lcd_clear();<br>
&emsp;strcpy(str, "unsigned long");<br>			
&emsp;lcd_print(str);<br>
&emsp;lcd_setcursor(0,1);<br>
&emsp;lcd_print(4294967295UL);<br>		
&emsp;_delay_ms(2000);<br>
<br>
&emsp;lcd_clear();<br>
&emsp;strcpy(str, "double");<br>			
&emsp;lcd_print(str);<br>
&emsp;lcd_setcursor(0,1);<br>
&emsp;lcd_print(334567.123);<br>		
&emsp;_delay_ms(2000);<br>
<br>
&emsp;lcd_clear();<br>
&emsp;strcpy(str, "Hannover");<br>			
&emsp;lcd_print_xy(1, 1, str);<br>
<br>
&emsp;while(1) {<br>
&emsp;}<br>
&emsp;return 0;<br>
}<br>

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



