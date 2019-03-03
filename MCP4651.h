#ifndef MCP4651_H
#define MCP4651_H

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Wire.h>

class MCP4651  {
  protected:
	uint8_t address;
  public:
    // Constructor 
    MCP4651(uint8_t addr = 0x28);

    // Methods
    void begin();
	void write(uint8_t pot, uint16_t val);
	void increment(uint8_t pot);
	void decrement(uint8_t pot);
};
#endif