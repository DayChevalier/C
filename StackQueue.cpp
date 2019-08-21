// In-Class Assignment 6
// Test stacks and queues

#include <iostream>
using namespace std;

#include "StackType.h"
#include "QueueType.h"

int main()
{
    StackType<int> theStack(30);
    QueueType<int> theQueue(30);
    
	theStack.push(3);
	theStack.push(7);
	theQueue.enqueue(9);
	theStack.push(8);
	theStack.pop();
	theQueue.enqueue(theStack.pop());
	theQueue.enqueue(1);
	theQueue.enqueue(2);
	theStack.push(6);
	theQueue.enqueue(3);
	theStack.push(theQueue.dequeue());

	while(!theQueue.isEmpty())
		cout << theQueue.dequeue() << " ";
	while(!theStack.isEmpty())
		cout<< theStack.pop() << " ";
	cout << endl;
	system("pause");

    int value;   // For storing a popped or dequeued value

    // ENTER ALGORITHM HERE

return 0;
}
