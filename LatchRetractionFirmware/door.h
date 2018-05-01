
#ifndef DOOR_H_
#define DOOR_H_

#include <inttypes.h>

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

#define OUTPUT  0
#define INPUT   1
#define LOW     0
#define HIGH    1

#define DDR_HIGH (*ddr |= _offset)  ///< Set the DDR register to HIGH for the pin
#define DDR_TOGGLE (*ddr ^= _offset)  ///< Set the DDR register to the inverse for the pin
#define DDR_LOW (*ddr &= _ioffset)  ///< Set the DDR register to LOW for the pin

#define PORT_HIGH (*port |= _offset)  ///< Set the PORT register to HIGH for the pin
#define PORT_TOGGLE (*port ^= _offset)  ///< Set the PORT register to the inverse for the pin
#define PORT_LOW (*port &= _ioffset)  ///< Set the PORT register to LOW for the pin

#define DDR_ON (*ddr & _offset)  ///< Get the DDR register for the pin (HIGH, LOW) with other pins forced to 0
#define DDR_OFF (*ddr | _ioffset)  ///< Get the DDR register for the pin (HIGH, LOW) with other pins forced to 1

#define PORT_ON (*port & _offset)  ///< Get the PORT register for the pin (HIGH, LOW) with other pins forced to 0
#define PORT_OFF (*port | _ioffset)  ///< Get the PORT register for the pin (HIGH, LOW) with other pins forced to 1

#define PIN_ON (*pin & _offset)  ///< Get the PIN register for the pin (HIGH, LOW) with other pins forced to 0
#define PIN_OFF (*pin | _ioffset)  ///< Get the PIN register for the pin (HIGH, LOW) with other pins forced to 1

class Door
{
    public:
      Door(uint8_t,  volatile uint8_t*, volatile uint8_t*, volatile uint8_t*);
      void setActive();
      void setMode(uint8_t);
      void setState(uint8_t);
      void toggleState(void);

    private:
      uint8_t pin;
      uint8_t _offset;
      uint8_t _ioffset;
      volatile uint8_t* pin_port;
      volatile uint8_t* port;
      volatile uint8_t* ddr;
      void init();
};


#endif