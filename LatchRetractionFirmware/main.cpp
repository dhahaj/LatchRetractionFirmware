/*
* LatchRetractionFirmware.cpp
*
* Created: 5/1/2018 8:41:39 AM
* Author : dmh
*/

#include <avr/io.h>
#include <util/delay.h>
#include "door.h"
#include "timer.h"
#include "dip.h"

Door door1(PB5, &PINB, &PORTB, &DDRB);
Door door2(PD6, &PIND, &PORTD, &DDRD);

uint8_t pins[] = { PC0, PC1, PC2, PC3, PC4 };
Dip dip(pins, &PINC, &PORTC, &DDRC);

void init(void)
{
	TCCR0A |= _BV(CS01) | _BV(CS00);  // Initialize timer0 with a prescaler of 64
	sbi(TIMSK0, TOIE0);               // enable timer 0 overflow interrupt

	TCCR1B |= _BV(WGM12);             // Configure timer 1 for CTC mode
	TIMSK1 |= _BV(OCIE1A);            // Enable Output Compare Interrupt Channel A
	sei();                            // Turn on interrupts
}

int main(void)
{
	init();

	door1.setMode(OUTPUT);
	door2.setMode(OUTPUT);
	door1.setState(LOW);
	//door2.setState(LOW);

	for(;;)
	{
		unsigned long t = millis();
		while(millis() - t < 1000);

		door1.toggleState();
		door2.toggleState();
	}
}

