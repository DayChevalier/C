// This file defines the specifications for a general rectangle class
// File:  rectangle1.h (defining basic data members and member functions)

class Rectangle
{
    private:                // PRIVATE data members
        double length;
        double width;
        
    public:                 // PUBLIC member functions
        void setAttributes(double l, double w);
        double calcPerimeter();
        double calcArea();
};