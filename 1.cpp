//******************************************************************
// CST 180 In-Class Assignment 7 Work File
// Filename : doubleBubble.cpp
// Name:  YOUR_NAME_HERE 
//******************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAX_ARRAY = 20;           // Max number of zip code entries

void getData(ifstream& inFile, int key[], int data[], int& numVals);
void sortArray(int array[], int data[], int elems);
void writeArray(int array1[], int array2[], int elems);

int main()
{
    ifstream fileIn;    // Input file identifier               
    
    // Declare parallel arrays for zip code data
    int key[MAX_ARRAY];       // Array for key values
    int data[MAX_ARRAY];      // Array for data values
    int numElems;             // Actual number of values in array 
                              //   (1 more than largest index)
                                                                
    fileIn.open("myData.txt");   // Open file
    
    if (fileIn.fail() )          // Test for file existence
    {
      cout <<  "Problem opening file";
      exit(-1);
    }
    
    // Read file and count values in array
    getData(fileIn,key,data,numElems);
    
    // Write contents of arrays - before sorting
    writeArray(key, data, numElems);
    
    // Close file
    fileIn.close();    
   
    // Sort array
    sortArray(key, data, numElems);
    
    // Write contents of arrays - after sorting
    writeArray(key, data, numElems);
        
    return 0;                
}

//***************************************************************
// This function reads 3 sets of integers from a file and stores
// the values in an array.  It returns the loaded arrays and the
// number of elements in the array
// File format:  zip_code  latitude  longitude
//***************************************************************
void getData(ifstream& inFile, int key[], int data[], int& numVals)
{
    int i = 0;
    
    inFile >> key[i] >> data[i];            // Priming read              
    while (!inFile.eof() && i < MAX_ARRAY)        
    {
       i++;        
       inFile >> key[i] >> data[i];         // Continuation read             
    }            
    numVals = i;
}

/************************************************************/
/* This function receives a list of values of type int      */
/* as an array.  The function performs a bubble sort and    */
/* returns the list in ascending order.                     */
/* Note:  elems is number of elements in list               */
/************************************************************/
void sortArray(int array[], int data[], int elems)
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

			 temp = data[count];
             data[count] = data[count + 1];
             data[count + 1] = temp;
          }
       }
   }
}

//************************************************************
// This writes the contents of two parallel arrays of 
// integers
//************************************************************
void writeArray(int array1[], int array2[], int elems)
{
   for (int i = 0; i < elems; i++)
   {
      cout << setw(4) << array1[i] << "   " 
           << setw(4) << array2[i] << endl;   
   }
   cout << endl;
}


