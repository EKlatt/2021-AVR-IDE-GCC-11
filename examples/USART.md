# Library-Manual
Like the "Arduino-IDE" MyIDE comes with a folder called "../MyIDE/libraries".<br>
These subfolders are intended for user-libraries which you create or<br>
got from other sources.<br>
Create a subfolder for the user-library and add the *.h and *.o files.<br>
The library-files will be automatically included in the compile- and<br>
link-process.<br>

**USART Library**<br>
I developped this library in order to make debugging easier.
I followed some ideas from the Arduino-library.

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
	

Implemented data types
Copied from https://learn.sparkfun.com/tutorials/data-types-in-arduino/all

boolean (8 bit)        int8_t    - simple logical true/false 1/0
byte (8 bit)           int8_t    - unsigned number from 0-255
char (8 bit)           int8_t    - signed number from -128 to 127. 
unsigned char (8 bit)  uint8_t   - unsigned number from 0-255
word (16 bit)          uint16_t  - unsigned number from 0-65535

int (16 bit)           int16_t  - signed number from -32768 to 32767.
unsigned int (16 bit)  uint16_t - unsigned number from 0-65535 

long (32 bit)          int32_t  - signed number from -2,147,483,648 to 2,147,483,647
unsigned long (32 bit) uint32_t - unsigned number from 0-4,294,967,295.

float (32 bit)                  - signed number from -3.4028235E38 to 3.4028235E38. 



