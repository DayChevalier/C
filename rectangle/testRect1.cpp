// Rectangle class test driver
// This program demonstrates a various methods related to the 
// general rectangle class.
// Included:  setting variables, area function, perimeter function

#include <iostream>
using namespace std;

#include "rectangle1.h"

int main()
{     
    Rectangle theRect;      // Rectangle is the CLASS; theRect is the OBJECT    
    
    double len, wid, area, perimeter; // Work variables within main      
    
    // Prompt user for dimensions of rectangle
    cout << "Enter rectangle length (space) width: ";
    cin >> len >> wid;
    
    // Set data in the object
    theRect.setAttributes(len, wid);
    
    // Calculate area and perimeter 
    area = theRect.calcArea();
    perimeter = theRect.calcPerimeter();
    
    // Write results to console
    cout << endl;
    cout << "For a " << len << " X " << wid << " rectangle: " << endl;
    cout << "  Area: " << area << "   Perimeter: " << perimeter << endl;
    
    return 0;
    
}  // end main function



