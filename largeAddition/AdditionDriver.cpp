//This program is built to input massive integers and add them.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "AdditionHeader.h"

int main()
{	  

	LongInt A("pgm8num1.txt");
	LongInt B("pgm8num2.txt");
	LongInt C;

	A.write();
	B.write();

	C = A + B;
	C.write();

    return 0;
}