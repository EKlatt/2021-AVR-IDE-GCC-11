// LCD.h
// LCD 16x2 4 bit customized for ATmega328
// see info.txt

#include <stdint.h>	

#ifndef F_CPU
	#define F_CPU 16000000		// CPU frequency for delay function
#endif

#ifndef _LCD_H
#define _LCD_H

// prototype LCD functions
// internal send data/command-functions 
void pulseEnableLine();						// send enable pulse
void write4bits( uint8_t data);				// send 4-bits to LCD
void byte_to_nibble(uint8_t data); 			// split byte into higher and lower nibble
void send_data( uint8_t data );				// switch to data-mode, send one character to LCD
void send_data_string( const char *data );	// send string to LCD
void lcd_command( uint8_t data ); 			// switch to command-mode

// LCD-user-functions
										// LCD initialize function
void lcd_init( volatile uint8_t* _LCD_PORT_RS_EN, uint8_t _LCD_RS, uint8_t _LCD_EN, 
				volatile uint8_t* _LCD_PORT,       uint8_t _DB4, uint8_t _DB5, uint8_t _DB6, uint8_t _DB7);
void lcd_clear();						// function clear display
void lcd_home( void );					// funcion home cursor
void lcd_display_on( void );			// display on 0000 1 D=1 C B
void lcd_display_off( void );			// display off 0000 1 D=0 C B
void lcd_cursor_on( void );				// cursor on 0000 1 D C=1 B 
void lcd_cursor_off( void );			// cursor off 0000 1 D C=0 B 
void lcd_blink_on( void );				// blink on 0000 1 D C B=1 
void lcd_blink_off( void );				// blink off 0000 1 D C B=0 
void lcd_autoscroll_on( void );			// display moves, cursor still: 0000 0 1 I/D S=1 
void lcd_autoscroll_off( void );		// display still, cursor moves: 0000 0 1 I/D S=0 
void lcd_leftToRight( void );			// cursor left to right: 0000 0 1 I/D=1 S
void lcd_rightToLeft( void );			// cursor right to left: 0000 0 1 I/D=0 S=0 
void lcd_scrollDisplayLeft( void );		//  scroll the display: 000 1 S/C=1 R/L=0 x x 	
void lcd_scrollDisplayRight( void );	//  scroll the display: 000 1 S/C=1 R/L=1 x x 
void lcd_setcursor( uint8_t x, uint8_t y );	// set cursor to line y (0 or 1); column x 

#endif  
