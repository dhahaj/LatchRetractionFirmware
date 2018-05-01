
#include "door.h"
#include <avr/io.h>
#include <avr/interrupt.h>

Door::Door(uint8_t _pin, volatile uint8_t* _pin_port, volatile uint8_t* _port, volatile uint8_t* _ddr)
{
	this->pin = _pin;
	this->pin_port = _pin_port;
	this->port = _port;
	this->ddr = _ddr;
	_offset = (1 << pin);
	_ioffset = ~_offset;
	init();
}

void Door::setActive()
{

}

void Door::init()
{
	setMode(OUTPUT);
}

/**
Set the pin mode

@param mode the mode of the pin (OUTPUT, INPUT)
*/
void Door::setMode(uint8_t mode)
{
	uint8_t oldSREG = SREG;
	cli();
	if (mode == INPUT)
	DDR_LOW;
	else
	DDR_HIGH;
	SREG = oldSREG;
}

/**
Set the pin state

@param state the state of the pin (HIGH, LOW)
*/
void Door::setState(uint8_t state)
{
	uint8_t oldSREG = SREG;
	cli();
	if (state == LOW)
	PORT_LOW;
	else
	PORT_HIGH;
	SREG = oldSREG;
}


/**
* \brief Toggle the pin state (HIGH -> LOW, LOW -> HIGH)
*
*
* \return void
*/
void Door::toggleState(void)
{
	uint8_t oldSREG = SREG;
	cli();
	PORT_TOGGLE;
	SREG = oldSREG;
}