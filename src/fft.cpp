#include "fft.h"

fft::fft(){

}

void fft::set_data_size(uint16_t nn){
    n = nn;
    while((1 << logn) < n) logn++;

    V = new complex[n];
    kor = new complex[logn];
    kor[logn - 1] = polar(1 , 2 * acos(-1) / n);
    // kor[logn - 1].debug();
    for(int8_t i = logn - 2; i >=0 ; i--){
        kor[i] = kor[i + 1] * kor[i + 1];
    }
}

void fft::upload_data(uint16_t *D){
    for(uint16_t i = 0; i < n ; i++){
        uint16_t mask = 0;
        for(uint8_t j = 0 ; j < logn ; j++){
            mask |= (((i >> j) & 1) << (logn - j - 1));
        }
        V[mask] = complex(D[i]);
        // V[mask].debug();
    }
}


void fft::calc(){
    for(uint8_t lvl = 1; lvl < logn ; lvl++){
        uint16_t step = 1 << lvl;
        for(uint16_t i = 0; i < n ; i+=step){
            complex w(1);
            for(uint16_t j = i; j < i + (step >> 1) ; j++){
                complex tmp = V[j];
                V[j] = tmp + w * V[j + (step >> 1)];
                V[j + (step >> 1)] = tmp - w * V[j + (step >> 1)];
                w = w * kor[lvl];
                // w.debug();
            }
        }
    }
}