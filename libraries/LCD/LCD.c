// LCD 16x2 4 bit customized for ATmega328
// see info.txt

#include <avr/io.h>					// AVR std. library file  
#include <util/delay.h>
#include <stdlib.h>					// needed for iota()-function 
#include "LCD.h"

	// LCD DB4-DB7 <--  PORTC bit PC2-PC5
	// all data-wires needs to be on the same port
volatile uint8_t* LCD_PORT;			// address of data-port
volatile uint8_t* LCD_DDR;			// address of data-port DDRx
	// LCD data pins DB4 <---> PC2 ATmega hardware pin
uint8_t DB4;						
uint8_t DB5;
uint8_t DB6;
uint8_t DB7;

// the RS-wire and EN-wire needs to be on the same port
volatile uint8_t* LCD_DDR_RS_EN;	// address of DDRx for RS and EN 
volatile uint8_t* LCD_PORT_RS;		// address of port for RS
volatile uint8_t* LCD_PORT_EN;		// address of port for EN
uint8_t LCD_RS;						// LCD RS pin <---> ATmega hardware pin PB1; (RS: 1=data, 0=command)
uint8_t LCD_EN;						// LCD EN pin <---> ATmega hardware pin PB0; (EN: trigger impulse)	

uint8_t _flag_Entry   = 0x04;		// I/D=0 means the cursor position is decremented (moves right to left).
									// I/D=1 means the cursor position is incremented (moves left to right).
									// S=0 means normal operation, the display remains still, and the cursor moves.
									// S=1 means the display moves with the cursor.
uint8_t _flag_Display = 0x08;		// display on D = 1, display off D = 0
									// cursor on C = 1, cursor off C = 0
									// blink on C = B, blink off B = 0								

// LCD initialize function 
  // lcd_init( LCD_PORT_RS_EN, LCD_RS, LCD_EN, LCD_PORT, DB4, DB5, DB6, DB7)
void lcd_init( volatile uint8_t* _LCD_PORT_RS_EN, uint8_t _LCD_RS, uint8_t _LCD_EN, 
				volatile uint8_t* _LCD_PORT,      uint8_t _DB4, uint8_t _DB5, uint8_t _DB6, uint8_t _DB7) {

	// setting PORTx and DDRx for data
	LCD_PORT      = _LCD_PORT;			// address of data-port
	LCD_DDR       = _LCD_PORT - 1;		// address of DDR data-port
										// DDRx-address (is one address below PORTx address)
	
	// setting PORTx and DDRx for RS and EN
	LCD_PORT_RS	  = _LCD_PORT_RS_EN;		// address RS-port
	LCD_PORT_EN	  = _LCD_PORT_RS_EN;		// address EN-port
	LCD_DDR_RS_EN = _LCD_PORT_RS_EN - 1;	// address DDR RS-port and EN-port
											// DDRx-address (is one address below PORTx address) 		
	
	// setting pins for RS and EN 
	LCD_RS = _LCD_RS;
	LCD_EN = _LCD_EN;		
					 
	// setting LCD data pins
	DB4	= _DB4;
	DB5	= _DB5;
	DB6	= _DB6;
	DB7	= _DB7;	
					 			 
    // set pins to output
	// the variable LCD_DDR is a pointer that means the address of e.g. PORTD ==> (&PORTD)
	// *( LCD_DDR); the "*" points to the contents of LCD_DDR
	// 1 << DB4) setting the bit of a certain pin        
	*( LCD_DDR)        |= ( 1 << DB4) | (1 << DB5) | (1 << DB6) | (1 << DB7);
	*( LCD_DDR_RS_EN ) |= ( 1 << LCD_RS );   // RS pin
	*( LCD_DDR_RS_EN ) |= ( 1 << LCD_EN );   // EN pin

    // set pins to 0
    *( LCD_PORT )    &= ~( (1 << DB4) | (1 << DB5) | (1 << DB6) | (1 << DB7) );	
	*( LCD_PORT_RS ) &= ~( 1 << LCD_RS );
	*( LCD_PORT_EN ) &= ~( 1 << LCD_EN ); 
	
	_delay_ms (20);				// LCD Power ON delay always >15ms
 
    // this is according to the hitachi HD44780 datasheet
    // figure 24, pg 46		
	write4bits ( 0x30 );		// 0b00110000; we start in 8bit mode
	_delay_us ( 4500 );

	write4bits ( 0x30 );		// second try		
	_delay_us ( 4500 );

	write4bits ( 0x30 );		// third try	
	_delay_us ( 150 );

	write4bits  ( 0x20 );						// 0b0010 0000; set to 4-bit interface 
	lcd_command ( 0x20 | 0x08 );				// 0b0010 1000; 4-bit mode/ 2 lines / 5x8
	
	_flag_Display = 0x04 | 0x02 | 0x01;			
	lcd_command ( 0x08 | _flag_Display );		// 0b0000 1111; display on / cursor on / blink on

	_flag_Entry = 0x02;							
	lcd_command ( 0x04 | _flag_Entry );			// 0b0000 0110; cursor increment / no scroll
	
	lcd_clear();  								// 0b00000001; clear display 
}	

// send enable pulse
void pulseEnableLine() {
	*LCD_PORT_EN |=  ( 1 << LCD_EN);     // Set enable to 1
	_delay_us(20);              		 // delay
	*LCD_PORT_EN &= ~( 1 << LCD_EN);     // Set enable to 0
}

// send 4-bits to LCD 
void write4bits( uint8_t data) {
	// clear PORT-pins
    *LCD_PORT &= ~( (1 << DB4) | (1 << DB5) | (1 << DB6) | (1 << DB7) );	
	// we get a byte, but we only use the higher bits
	if (data & 0b00010000) *LCD_PORT |= ( 1 << DB4 );
	if (data & 0b00100000) *LCD_PORT |= ( 1 << DB5 );
	if (data & 0b01000000) *LCD_PORT |= ( 1 << DB6 );
	if (data & 0b10000000) *LCD_PORT |= ( 1 << DB7 );
}

// split byte into higher and lower nibble
void byte_to_nibble(uint8_t data) {
									// e.g.                              0100 0001
	write4bits ( data );            // start with higher bits:           0100 xxxx
	pulseEnableLine();	
	write4bits ( data << 4 );        // then lower bits 0100 0001 << 4 => 0001 xxxx 
	pulseEnableLine();	
}

// switch to data-mode
void lcd_data( uint8_t data ) {
	*LCD_PORT_RS |= ( 1 << LCD_RS );		// set RS to 1 => data mode
	byte_to_nibble ( data );
	_delay_us(46); 	
}

// switch to command-mode
void lcd_command( uint8_t data ) {
    *LCD_PORT_RS &= ~( 1 << LCD_RS );	// set RS to 0 => command mode
	byte_to_nibble ( data );
	_delay_us(42); 	
}

// function clear display
void lcd_clear() {
	lcd_command (0x01);			// 0b00000001; clear display  
    _delay_ms(2);
}

// funcion home cursor
void lcd_home( void ) {
    lcd_command (0x02);			// 0b00000010; cursor home
    _delay_ms(2);
}

// display on 0000 1 D=1 C B
void lcd_display_on( void ) {
	_flag_Display |= 0x04;				// display on D=1 ( set 0x04 )
										// Display On/Off Control (0x08)						
    lcd_command (0x08 | _flag_Display);	// 0b0000 11xx; display on
    _delay_ms(2);
}

// display off 0000 1 D=0 C B
void lcd_display_off( void ) {
	_flag_Display &= ~0x04;				// display off D=1 ( clear 0x04 )
										// Display On/Off Control (0x08)										
    lcd_command (0x08 | _flag_Display);	// 0b000010xx; display off
    _delay_ms(2);
}

// cursor on 0000 1 D C=1 B
void lcd_cursor_on( void ) {
	_flag_Display |= 0x02;				// cursor on C=1 ( set 0x02 )
										// Display On/Off Control (0x08)						
    lcd_command (0x08 | _flag_Display);	// 0b0000 1x1x; cursor on
    _delay_ms(2);
}

// cursor off 0000 1 D C=0 B
void lcd_cursor_off( void ) {
	_flag_Display &= ~0x02;				// cursor off C=0 ( clear 0x02 )
										// Display On/Off Control (0x08)						
    lcd_command (0x08 | _flag_Display);	// 0b0000 1x0x; cursor off
    _delay_ms(2);
}

// blink on 0000 1 D C B=1
void lcd_blink_on( void ) {
	_flag_Display |= 0x01;				// blink on B=1 ( set 0x01 )
										// Display On/Off Control (0x08)						
    lcd_command (0x08 | _flag_Display);	// 0b0000 1xx1; blink on
    _delay_ms(2);
}

// blink off 0000 1 D C B=0
void lcd_blink_off( void ) {
	_flag_Display &= ~0x01;				// blink off B=0 ( clear 0x01 )
										// Display On/Off Control (0x08)						
    lcd_command (0x08 | _flag_Display);	// 0b0000 1xx0; blink off
    _delay_ms(2);
}

// display moves, cursor still: 0000 0 1 I/D S=1
void lcd_autoscroll_on( void ) {
	_flag_Entry |= 0x01;					// screan moves S=1 ( set 0x01 )
										// Entry Mode Set (0x04)						
    lcd_command (0x04 | _flag_Entry);	// 0b0000 01x1; display moves; cursor still
    _delay_ms(2);
}

// display still, cursor moves: 0000 0 1 I/D S=0
void lcd_autoscroll_off( void ) {
	_flag_Entry &= ~0x01;				// cursor moves S=0 ( clear 0x01 )
										// Entry Mode Set (0x04)						
    lcd_command ( 0x04 | _flag_Entry);	// 0b0000 01x0; display still; cursor moves
    _delay_ms(2);
}

// cursor left to right: 0000 0 1 I/D=1 S
// This is for text that flows Left to Right
void lcd_leftToRight( void ) {
	_flag_Entry |= 0x02;					// cursor left I/D=1 ( set 0x02 )
										// Entry Mode Set (0x04)						
    lcd_command ( 0x04 | _flag_Entry);	// 0b0000 011x; cursor moves left
    _delay_ms(2);
}

// cursor right to left: 0000 0 1 I/D=0 S=0
// This is for text that flows Right to Left
void lcd_rightToLeft( void ) {
	_flag_Entry &= ~0x02;				// cursor left I/D=0 ( clear 0x02 )
										// Entry Mode Set (0x04)						
    lcd_command ( 0x04 | _flag_Entry);	// 0b0000 010x; cursor moves right
    _delay_ms(2);
}

//  scroll the display: 000 1 S/C=1 R/L=0 x x									
// These commands scroll the display without changing the RAM									
void lcd_scrollDisplayLeft( void ) {
										// S/C: shift display (0x08)
										// R/L: shift to the left (0x00)										
										// Cursor or Display Shift (0x10)
    lcd_command ( 0x10 | 0x08 | 0x00);	// 0b0001 1 0 x x;						
    _delay_ms(2);
}

//  scroll the display: 000 1 S/C=1 R/L=1 x x									
// These commands scroll the display without changing the RAM	
void lcd_scrollDisplayRight( void ) {
										// S/C: shift display (0x08)
										// R/L: shift to the right (0x04)										
										// Cursor or Display Shift (0x10)
    lcd_command ( 0x10 | 0x08 | 0x04);	// 0b0001 1 1 x x;	
    _delay_ms(2);
}

// set cursor to line y (0 or 1); column x
void lcd_setcursor( uint8_t x, uint8_t y ) {
    uint8_t xy;
    // Set DD RAM Address 0b1xxxxxxx  (Display Data RAM) => 0x80	
	if ( y == 0)  xy = 0x80 + 0x00 + x;		// first row
	if ( y == 1)  xy = 0x80 + 0x40 + x;		// second row		
 
    lcd_command( xy );
}

// send single character to LCD
void lcd_char( uint8_t data ) {
	lcd_data( data );
}

// send string to LCD
void lcd_string( const char *data ) {
    while( *data != '\0' )
        lcd_data( *data++);
}

// send string to LCD cursor x and row y 
void lcd_string_xy( uint8_t x, uint8_t y, const char *data ) {
    lcd_setcursor( x, y );
    lcd_string( data );
}

// send int number to LCD
void lcd_number( int16_t number) {
	char data [33];
	itoa (number, data, 10);
	lcd_string( data );
}

// send int number to LCD cursor x and row y
void lcd_number_xy( uint8_t x, uint8_t y, int16_t number ) {
    lcd_setcursor( x, y );
    lcd_number( number);	
}
 
