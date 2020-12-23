// ADC.cpp
// https://gist.github.com/Wollw/2396604
// https://embedds.com/adc-on-atmega328-part-1/
// https://maker.pro/custom/tutorial/how-to-take-analog-readings-with-an-avr-microcontroller
// https://garretlab.web.fc2.com/en/arduino/inside/hardware/arduino/avr/cores/arduino/wiring.c/init.html

#include <avr/io.h>
#include "ADC.h"

void InitADC() {
	/* The ADMUX(ADC Multiplexer Selection Register) controls the reference voltage, 
	* the presentation of the ADC conversion(left adjust or right adjust) 
	* and analog channel selection. */
	ADMUX  |= (0 << REFS1) | (1 << REFS0);				     // Default referece voltage (5 V in case of Arduino Uno).
	/* The ADLAR determines the presentation of the ADC conversion result.
	* It is set to 0, right adjusted, by the Arduino software. */
	ADMUX  &= ~(1 << ADLAR);
	/* The ADCSRA(ADC Control and Status Register A)
	* is a register to control AD conversion. 
	* The ADPS are the bits to determine the division factor 
	* between the system clock frequency and the 
	* input clock to the AD converter.*/
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);	 // set prescaller to 128 (range 50-200 kHz)
	ADCSRA |= (1 << ADEN);							         // enable AD conversion   
}

uint16_t readADC(uint8_t ADCchannel) {
	uint8_t low, high;

	/* ADCchannel is the analog pin we want to use.  ADMUX's bits 0 to 4 are
	 * the binary representations of the numbers of the pins so we can
	 * just 'OR' the pin's number with ADMUX to select that pin.
	 * We first zero the four bits by setting ADMUX equal to its higher
	 * four bits. */
	ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);

	/* Setting theADSC(ADC Start Conversion) to 1, 
	* the chip begins AD conversion. 
	* While AD conversion is executed, this bit is 1. 
	* After finishing the conversion, it becomes 0. */
	ADCSRA |= (1 << ADSC);

	/* This is an idle loop that just wait around until the conversion
	 * is finished.  It constantly checks ADCSRA's ADSC bit, which we just
	 * set above, to see if it is still set.  This bit is automatically
	 * reset (zeroed) when the conversion is ready so if we do this in
	 * a loop the loop will just go until the conversion is ready. */
	 while( ADCSRA & (1<<ADSC) );
	 
	// we have to read ADCL first; doing so locks both ADCL
	// and ADCH until ADCH is read.  reading ADCL second would
	// cause the results of each conversion to be discarded,
	// as ADCL and ADCH would be locked when it completed.
	low  = ADCL;
	high = ADCH;

	// combine the two bytes
	return (high << 8) | low;	 
}
