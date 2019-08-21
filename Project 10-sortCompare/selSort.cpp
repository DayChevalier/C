// This program uses the selection sort algorithm to sort an 
// array in ascending order.

#include <iostream>
using namespace std;

// Function prototypes
void selectionSort(int array[], int elems);
void showArray(int array[], int elems);

int main(void)
{
    int arraySize = 6;
    int values[] = {5, 7, 2, 8, 9, 1};    // Hardcoded initialized array

    // Display unsorted list
    cout << "The unsorted values are\n";
    showArray(values, arraySize);
    
    // Sort values
    selectionSort(values, arraySize);
    
    // Display sorted list
    cout << "The sorted values are\n";
    showArray(values, arraySize);
    
    return 0;
}

//**************************************************************
// Definition of function selectionSort.                       *
// This function performs an ascending order selection sort on *
// array. elems is the number of elements in the array.        *
//**************************************************************
void selectionSort(int array[], int elems)
{
    int startScan, minIndex, minValue;

    for (startScan = 0; startScan < (elems - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < elems; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

//**************************************************************
// Definition of function showArray.                           *
// This function displays the contents of array. elems is the  *
// number of elements.                                         *
//**************************************************************
void showArray(int array[], int elems)
{
    for (int count = 0; count < elems; count++)
        cout << array[count] << " ";
    cout << endl;
}

