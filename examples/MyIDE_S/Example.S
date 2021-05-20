/*	GCC assembly language avr-gcc */
	
/*	The best tutorial for avr-gcc:
	http://www.nongnu.org/avr-libc/user-manual/assembler.html */
 
/*	https://sourceware.org/binutils/docs-2.19/as/index.html
	https://sourceware.org/binutils/docs-2.19/as/AVR_002dChars.html#AVR_002dChars
	https://sourceware.org/binutils/docs-2.19/as/AVR_002dRegs.html#AVR_002dRegs 
	https://sourceware.org/binutils/docs-2.19/as/AVR_002dModifiers.html#AVR_002dModifiers 
	https://sourceware.org/binutils/docs-2.19/as/AVR-Opcodes.html#AVR-Opcodes 
	http://ww1.microchip.com/downloads/en/appnotes/doc42055.pdf */
		
/*	https://sites.google.com/site/manfredfettinger/divers/arduino-assembler
	https://rwf.co/dokuwiki/doku.php?id=smallcpus
	https://tenbaht.github.io/posts/migrating-from-avra-to-avr-as/
	https://sourceware.org/binutils/docs-2.35/as/index.html#SEC_Contents
	https://community.platformio.org/t/pure-avr-assembler-programming/6499/22
	https://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/Assembler_und_Inline-Assembler
	https://www.cypherpunk.at/2014/09/native-assembler-programming-on-arduino
	https://www.avrfreaks.net/forum/assembler-compiler-and-linker-questions 
	https://www.8051projects.net/files/public/1242392126_2569_FT22383_avr_tutorial.pdf page 96 
	http://www.avr-asm-download.de/beginner_de.pdf page 28 
	https://gcc.gnu.org/wiki/avr-gcc 
	https://rn-wissen.de/wiki/index.php?title=GNU_Assembler 
	http://web.engr.oregonstate.edu/~traylor/ece473/lectures/assembly.pdf 
	http://www.ee.nmt.edu/~elosery/spring_2019/ee308/resource_files/atmel_studio_avr-as.pdf 
	https://www.codeproject.com/Articles/712610/AVR-Assembler */

/*	As in C programs, this includes the central processor-specific file
	containing the IO port definitions for the device. */
	
/*	In detail:	
	<avr/io.h> includes following headers: 
	<avr/sfr_defs.h>, <avr/portpins.h>,
	<avr/common.h>, <avr/version.h>,
	and depending on microprocessor e.g. <avr/iom328p.h>. */
	
#include <avr/io.h>

/*	Task: Turns on an LED which is connected to PD4 (Arduino digital pin 4) */
/*	See example in "ATmega328P" datasheet page 61
	...
	; Define pull-ups and set outputs high, assuming pins are in input state
	; Define directions for port pins
	ldi r16,(1<<PB7)|(1<<PB6)|(1<<PB1)|(1<<PB0)
	ldi r17,(1<<DDB3)|(1<<DDB2)|(1<<DDB1)|(1<<DDB0)
	out PORTB,r16
	out DDRB,r17
	; Insert nop for synchronization
	nop
	...
*/

/*	Dealing with port addresses e.g. ATmega328:
	in <avr/iom328p.h> DDRB is defined as: "#define DDRB _SFR_IO8(0x04)"
	which adds the __SFR_OFFSET of  0x20, thus DDRB becomes 0x24
	so we cant use DDRB without coversion in out- and in-mnemonics.
	We need to use "out _SFR_IO_ADDR(DDRB), r16"
	which subtracts the __SFR_OFFSET again. 
	
	Preferred alternative is assigning a new value to "__SFR_OFFSET"
	which overwrites the value from <avr/sfr_defs.h>.
	In this case the macro "#define DDRB _SFR_IO8(0x04)" does not add 0x20.
	*/
#define __SFR_OFFSET 0

	.text				; following code in flash-memory
	
/*	Declare the function main  entry point as "global",
	because C-compiler looks for main() */
	.global main
	
main:
	; using sbi
									; (sbi A, b) A means the I/O Register; 'b' means a bit.
									; Without "_SFR_OFFSET defined to 0" 
									; we need to use "out _SFR_IO_ADDR(DDRB), r16".
									; 'b' has to be between 0 and 7
									; PD4 = 4 is defined in <avr/portpins.h>									
	; sbi _SFR_IO_ADDR(PORTD), PD4	; With above not redefined__SFR_OFFSET	
	sbi PORTD, PD4					; With above redefined __SFR_OFFSET to 0
	
	; sbi _SFR_IO_ADDR(DDRD), PD4	; With above not redefined__SFR_OFFSET
	sbi DDRD, PD4					; With above redefined __SFR_OFFSET to 0

	; alternativly using out
									; (out A, Rr) A means the I/O Register; Rr means a data-register
	; ldi r16, 1 << PD4				; define pull-up and set output high
	; ldi r17, 1 << PD4				; define direction for port pin PD4
									; we cant use PD4 directly, because we need the 4th bit
									; we need "0001 0000" and not PD4 (PD4 = 4 = 0000 0100)
									; so we need to shift the bit 4 times (1 << PD4)	
	
	; out _SFR_IO_ADDR(PORTD), r16	; With above not redefined__SFR_OFFSET
	; out PORTD, r16				; With above redefined __SFR_OFFSET to 0
	; out _SFR_IO_ADDR(DDRD), r16	; With above not redefined__SFR_OFFSET
	; out DDRD, r17					; With above redefined __SFR_OFFSET to 0	
	nop

Start:
	rjmp Start
	
.end
