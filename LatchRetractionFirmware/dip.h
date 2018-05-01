/*
* dip.h
*
* Created: 5/1/2018 11:28:31 AM
*  Author: dmh
*/


#ifndef DIP_H_
#define DIP_H_

//#include <stdbool.h>

class Dip
{
	public:

	Dip(uint8_t* _pins, volatile uint8_t* _pin_port, volatile uint8_t* _port, volatile uint8_t* _ddr)
	{
		*pins = *_pins;
		this->pin_port = _pin_port;
		this->port = _port;
		this->ddr = _ddr;
		init();
	}

	private:

	void init(void)
	{
		for(unsigned int i=0; i < 5; i++)
		{
			*ddr |= _BV(pins[i]);
			sbi(*port, _BV(pins[i]));
		}
	}

	uint8_t pins[4];
	volatile uint8_t* pin_port;
	volatile uint8_t* port;
	volatile uint8_t* ddr;
};

#endif /* DIP_H_ */