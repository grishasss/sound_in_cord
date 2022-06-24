#include <Arduino.h>

class complex{
    complex() = default;
public:

    complex(double a);
    complex(double a , double b);
    complex polar(double a , double angle);
    
    double real , imag;

    complex operator+(const complex& other);
    complex operator-(const complex& other);
    complex operator*(const complex& other);
    
    complex& operator+=(const complex& other);
    complex& operator-=(const complex& other);
    complex& operator*=(const complex& other);
   

};

