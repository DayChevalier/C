// This program is a test driver to demonstrate various functions of
// a binary search tree.

#include <fstream>
#include <iostream>
using namespace std;

#include "BinTreeType.h"

int main()
{    
    
    BinTreeType<char> theTree;
    
    // Insert various characters into tree
    theTree.insertNode('H');
    theTree.insertNode('C');
    theTree.insertNode('R');
    theTree.insertNode('A');
    theTree.insertNode('S');
    theTree.insertNode('Q');
    theTree.insertNode('B');
    theTree.insertNode('F');
    theTree.insertNode('Z');
    theTree.insertNode('M');
    theTree.insertNode('D');
    theTree.insertNode('X');
   
    // Test with deletes and inserts
    /*theTree.deleteNode('K');
    theTree.deleteNode('P');
    theTree.deleteNode('X');
    theTree.deleteNode('N');*/

    
    // Display tree in various traveral orders
    cout << "Pre-Order" << endl;
    theTree.displayPreOrder();
    cout << endl << endl;
    
    cout << "In-Order" << endl;
    theTree.displayInOrder();
    cout << endl << endl;

    cout << "Post-Order" << endl;
    theTree.displayPostOrder();
    cout << endl << endl;   
        
	theTree.insertNode('G');
	theTree.deleteNode('Q');
	theTree.insertNode('I');
	theTree.insertNode('Y');
	theTree.deleteNode('R');
	theTree.deleteNode('H');
	theTree.deleteNode('C');
	theTree.insertNode('H');

	cout << endl << "After Changes: " << endl;	

    // Display tree in various traveral orders
    cout << "Pre-Order" << endl;
    theTree.displayPreOrder();
    cout << endl << endl;
    
    cout << "In-Order" << endl;
    theTree.displayInOrder();
    cout << endl << endl;

    cout << "Post-Order" << endl;
    theTree.displayPostOrder();
    cout << endl << endl;   
    return 0;  // End program
}

