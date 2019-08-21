// This program demonstrates the QuickSort Algorithm
#include <iostream>
using namespace std;

// Function prototypes
void quickSort(int [], int, int);
int partition(int [], int, int);
void swap(int &, int &);

int main()
{
    int array[10] = {7, 3, 9, 2, 0, 1, 8, 4, 6, 5};
    int x; // Counter

    for (x = 0; x < 10; x++)
       cout << array[x] << " ";
    cout << endl;

    quickSort(array, 0, 9);

    for (x = 0; x < 10; x++)
       cout << array[x] << " ";
    cout << endl;

    return 0;
}

//************************************************
// quickSort uses the quicksort algorithm to     *
// sort set, from set[start] through set[end].   *
//************************************************
void quickSort(int set[], int start, int end)
{
    int pivotPoint;

    if (start < end)
    {
        // Get the pivot point
        pivotPoint = partition(set, start, end);
        
        // Sort the first sub list
        quickSort(set, start, pivotPoint - 1);
        
        // Sort the second sub list
        quickSort(set, pivotPoint + 1, end);
    }
}

//**********************************************************
// partition selects the value in the middle of the        *
// array set as the pivot. The list is rearranged so       *
// all the values less than the pivot are on its left      *
// and all the values greater than pivot are on its right. *
//**********************************************************
int partition(int set[], int start, int end)
{
    int pivotValue, pivotIndex, mid;

    mid = (start + end) / 2;
    swap(set[start], set[mid]);
    pivotIndex = start;
    pivotValue = set[start];
 
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (set[scan] < pivotValue)
        {
            pivotIndex++;
            swap(set[pivotIndex], set[scan]);
        }
    }
    swap(set[start], set[pivotIndex]);

    return pivotIndex;
}

//**********************************************
// swap simply exchanges the contents of       *
// value1 and value2.                          *
//**********************************************
void swap(int &value1, int &value2)
{
    int temp = value1;

    value1 = value2;
    value2 = temp;
}
