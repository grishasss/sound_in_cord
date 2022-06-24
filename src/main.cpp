#include <Arduino.h>
#include "complex.h"

const uint16_t maxn = 250;
const uint16_t freq1 = 1000;






void setup() { 
	Serial.begin(115200);
	polar(1. , 1.);
}
  
void loop() {
	
	uint16_t val = 0;
	for(uint8_t i = 0 ; i < 10 ; i++){
		val+=analogRead(A0);
		delayMicroseconds(1);
	}
	Serial.println(val / 10);
}