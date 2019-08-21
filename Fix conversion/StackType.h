// Specification file for the generic stack class
// The variable "ItemType" is replaced with the chosen
// data type for the stack.

template <class ItemType>
class StackType
{
private:
    ItemType *stackArray;
    int stackSize;
    int top;

public:
    StackType(int);
    ~StackType();
    void push(ItemType);
    ItemType pop();
    void clear();
    bool isFull();
    bool isEmpty();
	ItemType showTop();
};
    
// Implementation file for the generic stack class
#include <iostream>
#include <string>
using namespace std;

//*******************
// Constructor      *
//*******************

template <class ItemType>
StackType<ItemType>::StackType(int size)
{
    stackArray = new ItemType[size]; 
    stackSize = size; 
    top = -1;
}

//*******************
// Destructor       *
//*******************

template <class ItemType>
StackType<ItemType>::~StackType()
{
    delete [] stackArray;
}


//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
// PRECONDITION: Stack is NOT FULL                *
//*************************************************

template <class ItemType>
void StackType<ItemType>::push(ItemType item)
{
    top++;
    stackArray[top] = item;
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
// PRECONDITION: Stack is NOT EMPTY                  *
//****************************************************

template <class ItemType>
ItemType StackType<ItemType>::pop()
{
    ItemType item = stackArray[top];
    top--;
    
    return item;
}

//****************************************************
// Member function clear "empties" the stack by      *
// altering the "top" pointer index                  *
//****************************************************

template <class ItemType>
void StackType<ItemType>::clear()
{
    top = -1;
}

//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise.                     *
//***************************************************

template <class ItemType>
bool StackType<ItemType>::isFull()
{
    bool status;

    if (top == stackSize - 1)
        status = true;
    else
        status = false;

    return status;
}

//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************

template <class ItemType>
bool StackType<ItemType>::isEmpty()
{
    bool status;

    if (top == -1)
        status = true;
    else 
        status = false;

    return status;
}

//****************************************************
// Member function showTop returns the value of the  *
// top of the stack, with out removing it completely *
//****************************************************

template <class ItemType>
ItemType StackType<ItemType>::showTop()
{
	ItemType value = stackArray[top];
    
    return value;
}