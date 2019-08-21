// This file includes implementations for functions of the general
// rectangle class
// File:  rectangle1.cpp (implementing member functions)

#include <iostream>
using namespace std;

#include "rectangle1.h"

// Set data variables for rectangle object
void Rectangle::setAttributes(double l, double w)
{
    length = l;
    width = w;
}

// Calculate perimenter of rectangle object given length
// and width currently stored
double Rectangle::calcPerimeter()
{
    return 2 * length + 2 * width;
}

// Calculate area of rectangle object given length
// and width currently stored
double Rectangle::calcArea()
{
    return length * width;
}
