#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>
#include "MCP4651.h"

static void i2cWrite(uint8_t x) {
  #if ARDUINO >= 100
  Wire.write(x);
  #else
  Wire.send(x);
  #endif
}

MCP4651::MCP4651(uint8_t addr) {
  address = addr;
}

void MCP4651::begin() {
  Wire.begin();
}

void MCP4651::write(uint8_t pot, uint16_t val) {
    Wire.beginTransmission(address);
    i2cWrite((pot & 3) << 4 | ((val >> 8) & 3));
	i2cWrite(val & 0xFF);
    Wire.endTransmission();
}

void MCP4651::increment(uint8_t pot) {
	Wire.beginTransmission(address);
	i2cWrite((pot & 8) << 4 | 6);
	Wire.endTransmission();
}

void MCP4651::decrement(uint8_t pot) {
	Wire.beginTransmission(address);
	i2cWrite((pot & 8) << 4 | 8);
	Wire.endTransmission();
}