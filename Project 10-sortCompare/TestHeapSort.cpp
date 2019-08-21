// This program demonstrates the HeapSort algorithm on a list
// of integers

#include <fstream>
#include <iostream>
using namespace std;

#include "HeapSort.cpp"

// Function prototypes
void GetList(int[],int&,int);
void DisplayList(int[],int);

const int MAX_LIST_SIZE = 100;      // Max list size
                                    // (for array declaration)
int main()
{
    int    InList[MAX_LIST_SIZE];   // Array of list elements
    int ListSize;                   // Index of last list element
                                        
    GetList(InList,ListSize,MAX_LIST_SIZE);
    
    // Write list prior to sort
    cout << endl << "BEFORE" << endl;
    DisplayList(InList,ListSize);
    
    HeapSort(InList,ListSize);
    
    // Write list after sort
    cout << endl << "AFTER" << endl;
    DisplayList(InList,ListSize);
    
    return 0;
}

/************************************************************/
/* This function opens a file to retrieve a list of integer */
/* values.  Values are stored in an array and passed to the */
/* calling routine.                                         */
/************************************************************/
void GetList(int inList[],int& listsize,int maxlistsize)
{
    ifstream InFile ("listData.txt");
    int ListElement;
    
    int i = 0;
    InFile >> ListElement;
    while(InFile && i < maxlistsize)
    {
        inList[i] = ListElement;
        i++;
        InFile >> ListElement;
    }
    listsize = i;        // Size of list
}

/************************************************************/
/* This function writes a list to console output:  one list */
/* item at a time.                                  */
/************************************************************/
void DisplayList(int theList[],int listsize)
{
   for (int i = 0;i < listsize; i++)
      cout << theList[i] << ' ';
   cout  << endl;
}
