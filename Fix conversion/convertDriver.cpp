//This program is built to input infix data and output it as postfix.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ConvertHeader.h"

int main()
{	  
	FixChange convert;

	const int MAX_ARRAY = 10;
	string infixData[MAX_ARRAY];
	int i = 0;


	ifstream inFile ("infix.txt");

	if (inFile.fail() )				// Test for file's existence
    {
      cout <<  "A problem occured trying to open the file";
      exit(-1);
    }

	inFile >> infixData[i];

	while (!inFile.eof() && i <= MAX_ARRAY)
	{
		convert.setInfix(infixData[i]);
		convert.postfixConversion();

		cout << convert.getPostfix() << endl;

		i++;
		inFile >> infixData[i];
	}

	inFile.close();

    return 0;
}