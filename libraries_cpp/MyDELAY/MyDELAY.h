// MyDELAY.h by Enno Klatt
// Task: Delay-function with variable time-parameter
//       Include with:                 #include "MyDelay.h"
//       Init in main()-function with: delay_timer1_init()
//       Call delay with:              myDelay_us(<microseconds>)
//       Allowed delays:               5 to 32768 microseconds
//
// English
// https://sites.google.com/site/qeewiki/books/avr-guide/timers-on-the-atmega328
// https://www.robotshop.com/community/forum/t/arduino-101-timers-and-interrupts/13072
// https://www.visualmicro.com/page/Timer-Interrupts-Explained.aspx
// https://www.simsso.de/?type=arduino/timer-interrupts
// https://www.digikey.com/en/maker/projects/multi-tasking-the-arduino-part-1/b23d9e65c4d342389d20cbd542c46a28
// German
// https://www.heise.de/developer/artikel/Timer-Counter-und-Interrupts-3273309.html

#include<avr/interrupt.h>								
volatile uint8_t timeIsGone = false;	// notifier for occured interrupt 
	
// initialize Timer1
void delay_timer1_init() {
  // Timer1
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << CS11);    // set prescale = 8
  TCNT1 = 0;                // resest timer 
  OCR1A = 2900		;       // set "Output Compare Register 1A" for init run
  TIMSK1 |= (1 << OCIE1A);  // enable Timer1 (Output Compare Interrupt Enable 1A)
  sei();                    // enable global interrupts
}

// Timer1 Compare Match A interrupt
ISR(TIMER1_COMPA_vect) {
	TCNT1 = 0; 				// resest timer
	timeIsGone = true; 		// notice occuring interrupt 
}

// Delay works within 5 to 32768 microseconds
void myDelay_us(uint16_t delayInMicros){
	if (delayInMicros >= 32768) delayInMicros = 32768;	
	if (delayInMicros < 5) delayInMicros = 5;	
	
	// set "output compare register" "OCR1A" of Timer1 depending on delayInMicros
	// calculate  OCR1A = (deltaT * cpufreq / prescale)
	OCR1A = (long int) delayInMicros  * 16 / 8;		// these are the ticks for Timer1
	while (!timeIsGone);							// wait until interrupt occurs
	timeIsGone = false;
}
