#include <Arduino.h>

#include "arduinoFFT.h"
  
#define SAMPLES 16               //Must be a power of 2
#define SAMPLING_FREQUENCY 50000  //Hz
#define REFRESH_RATE 10           //Hz
#define ARDUINO_IDE_PLOTTER_SIZE 500
  
arduinoFFT FFT = arduinoFFT();
  
unsigned long sampling_period_us;
unsigned long useconds_sampling;
 
unsigned long refresh_period_us;
unsigned long useconds_refresh;
  
double vReal[SAMPLES];
double vImag[SAMPLES];
double start[SAMPLES];
uint8_t analogpin = A0;

void read_data(){
  useconds_refresh = micros();
  for(int i=0; i<SAMPLES; i++){
    useconds_sampling = micros();
  
    vReal[i] = analogRead(analogpin);
    vImag[i] = 0;
  
    while(micros() < (useconds_sampling + sampling_period_us)){
      //wait...
    }
  }
  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
}



void setup() {
  Serial.begin(115200);
 
  sampling_period_us = round(1000000*(1.0/SAMPLING_FREQUENCY));
  refresh_period_us = round(1000000*(1.0/REFRESH_RATE));
 
  pinMode(analogpin, INPUT);
  read_data();
  for(int i = 0 ; i < SAMPLES / 2 ; i++) start[i] = vReal[i];
}
  
void loop() {
   read_data();
   for(int i =6 ; i < 7; i++){
    Serial.print(vReal[i] - start[i]);
    Serial.print(" ");
   }
  Serial.println();
 
}