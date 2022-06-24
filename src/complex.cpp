#include "complex.h"

complex::complex(double a){
    real = a;
}

complex::complex(double a , double b){
    real = a;
    imag = b;
}


complex complex::operator+(const complex& other){
    return complex(real + other.real , imag + other.imag);
}


complex complex::operator-(const complex& other){
    return complex(real - other.real , imag - other.imag);
}


complex complex::operator*(const complex& other){
    return complex(real * other.real - imag * other.imag , imag * other.real + other.imag * real);
}

complex& complex::operator+=(const complex& other){
    *this = (*this) + other;
    return *this;
}

complex& complex::operator-=(const complex& other){
    *this = (*this) - other;
    return *this;
}

complex& complex::operator*=(const complex& other){
    *this = (*this) * other;
    return *this;
}


complex complex::polar(double r , double angle){
    return complex(cos(angle) * r , sin(angle) * r);
}
