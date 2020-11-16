#include <avr/io.h>
#include <util/delay.h>
extern "C" {
#include "lcd.h"
}

int main() {
	unsigned char i;

	//Initialize LCD module
	InitLCD(LS_BLINK|LS_ULINE);

	//Clear the screen
	LCDClear();

	//Simple string printing
	LCDWriteString("Hallo Enno ");
	
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



