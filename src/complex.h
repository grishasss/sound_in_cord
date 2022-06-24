#pragma once


#include <Arduino.h>

class complex{
public:
    complex();
    complex(double a);
    complex(double a , double b);
    
    
    double real , imag;
    

    complex operator+(const complex& other);
    complex operator-(const complex& other);
    complex operator*(const complex& other);
    
    complex& operator+=(const complex& other);
    complex& operator-=(const complex& other);
    complex& operator*=(const complex& other);
    void debug();

};

complex polar(double a , double angle);