// https://extremeelectronics.co.in/avr-tutorials/using-lcd-module-with-avrs/
// http://www.peterfleury.epizy.com/avr-software.html
// http://www.peterfleury.epizy.com/doxygen/avr-gcc-libraries/group__pfleury__ic2master.html
// https://www.mikrocontroller.net/articles/HD44780
// http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung
// https://www.mikrocontroller.net/articles/Erweiterte_LCD-Ansteuerung
// https://rn-wissen.de/wiki/index.php/LCD-Modul_am_AVR
// https://www.ulrichradig.de/home/index.php/avr/lc-display
// http://www.sprut.de/electronic/lcd/
// http://www.ne555.at/2014/index.php/atmel-avr-mikrocontrollertechnik/382-lcd-display-ansteuern.html

/*
	Thanks for libray from Avinash Gupta.
    A library to easily access standard lcd modules with AVR series of
    MCUs from Atmel. Use with AVR studio and WinAVR.
    from Author: Avinash Gupta
    Web: www.eXtremeElectronics.co.in
*/
// Altered connections to "LCD.pdef"
// Idea: Leaving digital PINs PD2 to PD7 and PB3 to PB5 unused
//       Leaving analog PINs A4/PC4 and A5/PC5 unused
/*
 * Data lines to A0 to A3 or PORTC PC0 to PC3
 * LCD Pin  7 DB0  ----> Arduino/ATmega Pin A0 PC0
 * LCD Pin  8 DB1  ----> Arduino/ATmega Pin A1 PC1 
 * LCD Pin  9 DB2  ----> Arduino/ATmega Pin A2 PC2
 * LCD Pin 10 DB3  ----> Arduino/ATmega Pin A3 PC3
 
 * Control connections to PORTB
 * LCD Pin 4 RS  ----> Arduino/ATmega Pin 10 PB2
 * LCD Pin 5 R/W ----> Arduino/ATmega Pin  9 PB1
 * LCD Pin 6 E   ----> Arduino/ATmega Pin  8 PB0
*/

extern "C" {
#include "lcd.h"
}

#include <avr/io.h>
#include <util/delay.h>


int main() {
	unsigned char i;

	//Initialize LCD module
	InitLCD(LS_BLINK|LS_ULINE);

	//Clear the screen
	LCDClear();

	//Simple string printing
	LCDWriteString("Hello world ");
	
	//A string on line 2
	LCDWriteStringXY(0,1,"Loading ");

	//Print some numbers
	for (i=0;i<99;i+=1) {
		LCDWriteIntXY(9,1,i,3);
		LCDWriteStringXY(12,1,"%");
		_delay_loop_2(0);	
		_delay_loop_2(0);	
		_delay_loop_2(0);	
		_delay_loop_2(0);	
	}

	//Clear the screen
	LCDClear();

	//Some more text
	LCDWriteString("Hello world");
	LCDWriteStringXY(0,1,"By Enno Klatt");

	//Wait
	for(i=0;i<100;i++) _delay_loop_2(0);

	//Some More ......
	LCDClear();
	LCDWriteString("    eXtreme");
	LCDWriteStringXY(0,1,"  Electronics");
}



