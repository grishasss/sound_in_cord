#pragma once


#include <Arduino.h>
#include <complex.h>

class fft{
public:
    uint16_t *data;
    complex *V , *kor;
    uint16_t n;
    uint8_t logn;

    fft();
    
    void set_data_size(uint16_t size);
    void upload_data(uint16_t*D);
    void calc();
};