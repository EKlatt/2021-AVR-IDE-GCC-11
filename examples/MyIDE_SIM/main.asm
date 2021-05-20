; main.asm
; turns on an LED which is connected to PD4
; read header file of present microprocessor
.nolist
.include "m328Pdef.inc"	; Define device ATmega328
.list

; hardware information
; ports and pins
.equ LedOut = PORTD
.equ LedDir = DDRD
; variables
; .equ var = 12
; constants
; .equ const = 13	
.equ myLED = 0b00010000  ;set port PD4 to output mode
; register definitions
; .def rmp = r16

; data in SRAM
.dseg
.org SRAM_START
; data:	.byte 2			; reserve 2 bytes for variable data

; code in FLASH
.cseg
.org 0x00				; is always "0"
	rjmp Main 	; Reset Vector
	reti ; interrupt vector 1
	reti ; interrupt vector 2
	reti ; interrupt vector 3
	reti ; interrupt vector 4
	reti ; interrupt vector 5
	reti ; interrupt vector 6
	reti ; interrupt vector 7
	reti ; interrupt vector 8
	reti ; e.g. ADC-int

; interrupt service routines
	
; main Program Start
Main:
	ldi r16,0            ;reset system status
	out SREG,r16         ;init stack pointer
	ldi r16,low(RAMEND)  ;0xff
	out SPL,r16
	ldi r16,high(RAMEND) ;0x08
	out SPH,r16

	;ldi r16,0b00010000   ;set port PD4 to output mode
	ldi r16, myLED
	out LedDir,r16

	clr r17
Mainloop:
	 eor r17,r16          ;invert output bit
	 out LedOut,r17        ;write to port
	 call Wait            ;wait some time
	 rjmp Mainloop        ;loop forever

Wait:
	 push r16
	 push r17
	 push r18

	 ldi r16,0x20         ;loop 0x400000 times
	 ldi r17,0x00         ;~12 million cycles
	 ldi r18,0x00         ;~0.7s at 16 Mhz
w0:
	 dec r18
	 brne w0
	 dec r17
	 brne w0
	 dec r16
	 brne w0

	 pop r18
	 pop r17
	 pop r16
	 ret
