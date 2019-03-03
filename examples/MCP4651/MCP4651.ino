#include <Wire.h>
#include <MCP4651.cpp>
#define addr 0x28

MCP4651 pot(addr);

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  pot.write(0,0);
  for (int i=0; i<=256;i++){
    pot.increment(0);
    delay(100);
  }
  delay(5000);
  for (int i=0; i<=256;i++){
    pot.decrement(0);
    delay(100);
  }
  delay(5000);
}
