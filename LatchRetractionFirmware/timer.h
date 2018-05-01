/*
* timer.h
*  Contains the methods and definitions for
*  timing function abilities.
*
* Created: 5/1/2018 11:05:42 AM
*  Author: dmh
*/


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/interrupt.h>

#define nop __asm__("nop\n\t");
#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(64 * 256))
#define MILLIS_INC (MICROSECONDS_PER_TIMER0_OVERFLOW / 1000)
#define FRACT_INC ((MICROSECONDS_PER_TIMER0_OVERFLOW % 1000) >> 3)
#define FRACT_MAX (1000 >> 3)

volatile unsigned long timer0_millis = 0;
volatile uint8_t timer0_fract = 0;

volatile uint16_t counter_dr1=0, counter_dr2=0;

/**
* Timer1A Compare Interrupt - Handles the independent operation
*/
ISR (TIMER1_COMPA_vect)
{

}

/**
*  \brief Timer0 overflow interrupt - Increments the global millis variable.
*
*  \param [in] TIMER0_OVF_vect Timer0 Overflow Interrupt Vector.
*/
ISR (TIMER0_OVF_vect)
{
	uint8_t OLD_SREG = SREG;
	cli();

	unsigned long m = timer0_millis;
	uint8_t f = timer0_fract;

	m += MILLIS_INC;
	f += FRACT_INC;

	if (f >= FRACT_MAX)
	{
		f -= FRACT_MAX;
		m += 1;
	}
	timer0_fract = f;
	timer0_millis = m;
	SREG = OLD_SREG;
	sei();
}

/**
*  \brief Interrupt Handler For PCINT23:16 (PIND)
*
*  \param [in] PIND Pin Change Interrupt 2 Vector
*
*  \details This interrupt signal routine is called when any of the DIP settings input pins are changed. It must read the new settings and apply them accordingly.
*/
ISR (PCINT2_vect)
{

}


unsigned long millis(void)
{
	uint8_t old_sreg = SREG;
	cli();
	unsigned long m = timer0_millis;
	SREG = old_sreg;
	sei();
	return m;
}

#endif /* TIMER_H_ */