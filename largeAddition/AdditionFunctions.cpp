// These functions recieve infix data and converts it to postfix

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

#include "AdditionHeader.h"

//Default constructor
LongInt::LongInt()
{
}

//Parameterized constructor
LongInt::LongInt(string inputFile)
{
    char number;
	int newNumber;
	StackType<int> sortStack(500);


	ifstream inFile(inputFile.c_str());

	if (inFile.fail() )				// Test for file's existence
    {
      cout <<  "A problem occured trying to open the file";
      exit(-1);
    }



    inFile >> number;                      // Priming read
	while (!inFile.eof())
	{
		newNumber = int(number - 48);
        sortStack.push(newNumber);   
        inFile >> number;                 // Continuation read
	}
	inFile.close();



    int stackNumber;

	while (sortStack.isEmpty() == false)
	{
		stackNumber = sortStack.pop();
        adderList.insertNode(stackNumber);    
	}

}



//This function gets the infix string
void LongInt::write()
{
	adderList.displayList();
}

//overloading the + operators...
LongInt LongInt::operator+ (LongInt oper)
{
	StackType<int> sortingStack(500);
	LinkedList<int> summedList;
	LongInt answer;
    int stackNumber;
	int first;
	int second;
	int tens = 0;
	int ones;
	int place = 0;

	adderList.resetList();
	oper.adderList.resetList();


	while(adderList.atEnd() == false && oper.adderList.atEnd() == false)
	{
		adderList.getNextItem();
		oper.adderList.getNextItem();

		first = adderList.displayNode(place); //call for custom operation to display current place number
		second = oper.adderList.displayNode(place); //call for custom operation to display current place number in other list

		if (tens == 0)
		{
			ones = first + second;			//these aren't adding properly, create a LinkList function to display 1 node at a time.
			if (ones >= 10)
			{
				ones = ones % 10;
				tens = 1;
			}
		}
		else
		{
			ones = tens + first + second;
			if (ones >= 10)
			{
				ones = ones % 10;
				tens = 1;
			}
		}
		place++;
        sortingStack.push(ones);
	}




	while (sortingStack.isEmpty() == false)
	{
		stackNumber = sortingStack.pop();
        summedList.insertNode(stackNumber);    
	}


//At this point the program would put the linkedlist SummedList
//and put it into the LongInt Answer to be outputted



	return 	answer;

}