// LCD_PRINT.h
// customized for ATmega328P

#ifndef _LCD_PRINT_H_
#define _LCD_PRINT_H_

// number-functions
void lcd_print(int);
void lcd_print(unsigned int);
void lcd_print(long);
void lcd_print(unsigned long);
void lcd_print(double);
void lcd_print(float);

// character functions
void lcd_print(char*);
void lcd_print(char);
void lcd_print_xy( uint8_t x, uint8_t y, char *data ); // send string to LCD cursor x and row y

// functions for internal use
void lcd_printNumber(unsigned long);
void lcd_printFloat(double);

#endif /* LCD_PRINT_H_ */