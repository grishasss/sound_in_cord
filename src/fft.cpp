#include "fft.h"

fft::fft(){

}

void fft::set_data_size(uint16_t nn){
    n = nn;
    while((1 << logn) < n) logn++;
    V = new complex[n];
}

void fft::upload_data(uint16_t *D){
    for(uint16_t i = 0; i < n ; i++){
        uint16_t mask = 0;
        for(uint8_t j = 0 ; j < logn ; j++){
            mask |= (((i >> j) & 1) << (logn - j - 1));
        }
        V[mask] = complex(D[i]);
    }
}


void fft::calc(){
    
}