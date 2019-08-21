//******************************************************************
// CST 180 In-Class Assignment 7 Work File
// Name:  YOUR_NAMES_HERE 
//******************************************************************
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LIST_SIZE = 100;                // Max list size

// Function prototypes
void GetList(int inList[],int& listsize,int maxlistsize, ifstream& inFile);
void DisplayList(int theList[],int listsize);
void sortArray(int array[], int elems);
void RemoveDuplicates(int theList[], int& listSize);
void OrdListInsert(int list[], int& numElems, int newint);
void OrdListDelete(int list[], int& numElems, int oldint);
void MergeLists(int list1[],   int list1Elems, 
                int list2[],   int list2Elems,
                int outList[], int& outListElems);


int main()
{
    cout << "Assignment 7: YOUR_NAME(S)_HERE" << endl << endl;
   
    int List1[MAX_LIST_SIZE], List2[MAX_LIST_SIZE], List3[MAX_LIST_SIZE];   
    int list1_size, list2_size, list3_size;                
    
    // Read both input lists from files                                    
    ifstream inList1("list1.txt");
    GetList(List1, list1_size ,MAX_LIST_SIZE, inList1);

    ifstream inList2("list2.txt");
    GetList(List2, list2_size, MAX_LIST_SIZE, inList2);
    
    // Display list 1 
    cout << "List 1 (initial): " << endl;
    DisplayList(List1, list1_size);
    
    // Display list 2 
    cout << "List 2 (initial): " << endl;
    DisplayList(List2, list2_size);

	cout << "Sorted List 1: " << endl;
sortArray(List1, list1_size);
DisplayList(List1, list1_size);

cout << "Duplicate-removed list 2: " << endl;
RemoveDuplicates(List2, list2_size);
DisplayList(List2, list2_size);

cout << "Numbers added and removed list1: " << endl;
OrdListInsert(List1, list1_size, 14);
OrdListInsert(List1, list1_size, 24);
OrdListDelete(List1, list1_size, 11);
DisplayList(List1, list1_size);

cout << "List 3: " << endl;
MergeLists(List1, list1_size, 
                List2, list2_size,
                List3, list3_size);
DisplayList(List3, list3_size);

    // ==================================================

    
    // ENTER REQUIRED LIST ACTIONS HERE
    // ( AND DECLARE NECESSARY FUNCTIONS BELOW)
    
    
    // ==================================================

    
    return 0;
}

/************************************************************/
/* This function opens a file to retrieve a list of integer */
/* values.  Values are stored in an array and passed to the */
/* calling routine.                                         */
/*   Parameters:                                            */
/*        list            array of integers to build        */
/*        listsize        number of integers in list        */
/*        maxlistsize     max size allowable for list array */
/*        inFile          file containing list              */
/************************************************************/
void GetList(int inList[],int& listsize,int maxlistsize, ifstream& inFile)
{
    int ListElement;
    
    int i = 0;
    inFile >> ListElement;
    while(inFile && i < maxlistsize)
    {    
        inList[i] = ListElement;
        i++;
        inFile >> ListElement;
    }
    listsize = i;        // Size of list is lastindex + 1
}

/************************************************************/
/* This function writes a list to console output:  one list */
/* item at a time.                                          */
/************************************************************/
void DisplayList(int theList[],int listsize)
{
    for (int i = 0;i < listsize; i++)
        cout << theList[i] << " ";
    cout << endl << endl;
}

/************************************************************/
/* This function receives a list of values of type int      */
/* as an array.  The function performs a bubble sort and    */
/* returns the list in ascending order.                     */
/* Note:  elems is number of elements in list               */
/************************************************************/
void sortArray(int array[], int elems)
{
    int temp, end;

   for (end = elems - 1; end >= 0; end--)
   {
       for (int count = 0; count < end; count++)
       {
          if (array[count] > array[count + 1])
          {
             temp = array[count];
             array[count] = array[count + 1];
             array[count + 1] = temp;
          }
       }
   }
}


/************************************************************/
/* This function receives an ordered list of integers and   */
/* removes duplicate values (in adjacent storage elements)  */
/*   Parameters:                                            */
/*        list            array of integers to build        */
/*        listsize        number of integers in list        */
/************************************************************/
void RemoveDuplicates(int theList[], int& listSize)
{
    int i,j;
    i = 0;
    while (i < listSize-1)                  // For all list elements (up to last)
    {
        if (theList[i] == theList[i+1])     // if next list item is duplicate
        {
            for (j=i; j<listSize-1; j++)    //   then move elements back one space
                theList[j] = theList[j+1];  //   to overlay the duplicate
            listSize--; 
        }
        else
             i++;                           // otherwise, go to next element 
    } 
}


/************************************************************/
/* This function receives an integer, an array containing   */
/* an ordered list, and the size of the list.  It inserts   */
/* a new integer item at appropriate position in the list.  */
/* Note:  Possibility of array overflow not checked         */
/************************************************************/
void OrdListInsert(int list[], int& numElems, int newint)
{
   // Locate position to insert value at - index ptr
   int ptr = 0;
   while (newint > list[ptr] && ptr < numElems)    
      ptr++;
               
   // Move all successors down one array position:  bottom-up
   for (int i = numElems; i > ptr; i--)
      list[i] = list[i-1];
   
   // Insert net item   
   list[ptr] = newint;
     
   // Adjust number of elements in list  
   numElems++;                                 
}

/************************************************************/
/* This function receives an integer, an array containing   */
/* an ordered list, and the size of the list.  It deletes   */
/* the integer from the list and adjusts the list order     */
/************************************************************/
void OrdListDelete(int list[], int& numElems, int oldint)
{
   // Locate item to delete
   int ptr = 0;
   while (oldint != list[ptr] && ptr < numElems)    
      ptr++;
   
   // Move all successors up one position - deleting target value           
   for (int i = ptr; i < numElems - 1; i++)
      list[i] = list[i+1];
           
   // Adjust number of elements in list  
   numElems--;                                 
}


/****************************************************************/
/* This function receives an two ordered lists of integers and  */
/* merges them into one combined ordered list.                  */
/* Predconditions:  There are no duplicates in lists or between */
/* lists.  Lists are not empty.  Combined list does not exceed  */
/* max lists size.                                              */
/****************************************************************/
void MergeLists(int list1[],   int list1Elems, 
                int list2[],   int list2Elems,
                int outList[], int& outListElems)
{
   int ptr1, ptr2, outPtr;
   ptr1 = 0;
   ptr2 = 0;
   outPtr = 0;
   
   // While neither list empty, merge lists
   while (ptr1 < list1Elems && ptr2 < list2Elems)
   {
      if (list1[ptr1] < list2[ptr2])
      {
         outList[outPtr] = list1[ptr1];
         ptr1++;
      }
      else
      {
         outList[outPtr] = list2[ptr2];
         ptr2++;
      }
      outPtr++;   
   }

   // While items remain in list 1, fill end of output list
   while (ptr1 < list1Elems)
   {
      outList[outPtr] = list1[ptr1];
      ptr1++;
      outPtr++;
   }

   // While items remain in list 2, fill end of output list
   while (ptr2 < list2Elems)
   {
      outList[outPtr] = list2[ptr2];
      ptr2++;
      outPtr++;
   }
   
   outListElems = outPtr;    // Capture number of items in final list
}