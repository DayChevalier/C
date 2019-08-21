// This file defines the specifications for a class to store
// attributes used in functions to add to linked list integers

#include <string>
using namespace std;

#include "LinkedList.h"
#include "StackType.h"


class LongInt
{
    private:                // PRIVATE data members
		LinkedList<int> adderList;

    public:                 // PUBLIC member functions
		LongInt();
        LongInt(string inputFile);
		void write();
		LongInt operator+ (LongInt oper);

};