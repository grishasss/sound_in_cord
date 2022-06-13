#include <Arduino.h>


const uint16_t maxn = 250;
const uint16_t freq1 = 1000;

uint16_t data[maxn];

void read_analog(){
	for(uint16_t i = 0; i < maxn; i++){
		data[i] = analogRead(A0);
		delayMicroseconds(2);
	}
}

double power_of_freq(uint16_t freq){
	double X = 0;
	uint16_t start = freq - 10;
	uint16_t end = freq + 10;
	for(uint16_t w = start; w < end; w++){
		double x = 0;
		for(uint16_t j = 0 ; j < maxn ; j++){
			x += sin((double)j * w) * data[j];
		}
		X+=x*x;
	}
	return X / (start - end);
}



void setup() { 
	Serial.begin(115200);
}
  
void loop() {
	read_analog();
	Serial.print(power_of_freq(1000) * 1000);
	Serial.print("\n");
	// Serial.println(power_of_freq(1000));
}