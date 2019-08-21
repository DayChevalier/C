// This demonstrates the depth of binary search trees generated with random
// keys.  The depth of each tree is directly related to the search efficiency
// for the tree.
// Range of random numbers is 0 ... 32,767^2  ( rand() * rand() )

#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "BinTreeType.h"

const int START  = 100;     // Define range for simulation
const int FINISH = 1000000;

int main()
{    
    srand(time(0));            // set seed with clock function
    
    BinTreeType<int> theTree;

    int valueToAdd;
    
    // Write report headings
    cout << "Tree Nodes   Tree Depth" << endl;

    // Generate given number of random inserts; then multiply by 10 and repeat
    for (int numberInserts = START; numberInserts <= FINISH; numberInserts *= 10)
    {
        for (int i = 1; i <= numberInserts; i++)
        {
           valueToAdd = rand() * rand();    // Insert random integers
           theTree.insertNode(valueToAdd);
        }
    
        // Write output line
        cout << setw(10) << numberInserts 
             << setw(10) << theTree.treeDepth() << endl;
    }

	system("pause");
   return 0;
}