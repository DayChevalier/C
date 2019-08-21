// This file include the functions to implement Heap Sort.


// This is a generic function to swap values of any data type
inline void Swap(int& item1, int& item2)
{
    ItemType tempItem;

    tempItem = item1;
    item1 = item2;
    item2 = tempItem;
}

// This function drives the heapsort algorthm by:
// 1) converting any array into a heap pattern
// 2) swapping and reheaping array to perform sort
inline void HeapSort(int values[], int numValues)
{
    int index;

    // Convert the array of values into a heap
    for (index = numValues/2 - 1; index >= 0; index--)
	   ReheapDown(values, index, numValues-1);

    // Sort the array
    for (index = numValues-1; index >=1; index--)
    {
	   Swap(values[0], values[index]);
	   ReheapDown(values, 0, index-1);
    }
}

// This function includes only the action to reheap down
// to restore a heap from the top-down
void ReheapDown(int elements[], int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;
  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild] <= elements[rightChild])
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
    if (elements[root] < elements[maxChild])
    {
      Swap(elements[root], elements[maxChild]);
      ReheapDown(elements, maxChild, bottom);
    }
  }
}


