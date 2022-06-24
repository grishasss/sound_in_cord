#include <Arduino.h>
#include "complex.h"
#include "fft.h"
const uint16_t num = 1 << 7;




fft FFT;

uint16_t D[num];
void setup() { 
	Serial.begin(115200);
	FFT.set_data_size(num);
	pinMode(A0, INPUT);
}
  
void loop() {
	
	for(uint16_t i = 0 ; i < num ; i++){
		D[i] = analogRead(A0);
		delayMicroseconds(2);
	}
	FFT.upload_data(D);
	FFT.calc();
	
	for(uint16_t i = 0 ; i < num ; i++){
		Serial.print(round(FFT.V[i].real));
		Serial.print(" ");
	}
	Serial.print("\n");
	// delay();
}