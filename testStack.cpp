// This program tests a generic stack class that utilizes
// templates for data type definition.
#include <iostream>
using namespace std;

#include "stackType.h"

int main()
{
    // -----------------------------------------
    // Demonstrating work with an integer stack
    // -----------------------------------------

    StackType<int> theStack(15);

    theStack.push(5);    
    theStack.push(7);
	theStack.pop();
    theStack.push(8); 
	cout <<theStack.pop() << endl;
    theStack.push(6); 
	theStack.push(9);
	cout <<theStack.pop()<< endl;
	for(int x = 1;x<5;x++)
		theStack.push(x);
	theStack.pop();
	while(!theStack.isEmpty())
		cout << theStack.pop() << endl;
    

    
    cout << endl << endl;
 
    // -----------------------------------------
    // Demonstrating work with a character stack
    // -----------------------------------------
 

       
    cout << endl << endl;
        
	system("pause");
    return 0;
}

