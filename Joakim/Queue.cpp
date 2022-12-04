#include <iostream>
#include <queue>

using namespace std;

// Queue --------------------------------------------------------------------------------------------------
// 
// video: https://www.youtube.com/watch?v=jaK4pn1jXTo
// 
// FIFO: First In First Out		||		FCFS: First Come First Served
//

void printQueue(queue<int> queue)
{
	while (!queue.empty())
	{
		cout << queue.front() << " ";
		queue.pop();
	}
	cout << endl;
}

int main()
{
	queue<int> myQueue;

	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);

	cout << "Size is " << myQueue.size() << endl;
	cout << "First element is " << myQueue.front() << endl;
	cout << "Last element is " << myQueue.back() << endl;

	cout << "My queue: " << endl;
	printQueue(myQueue);
}





//

// Psuedo code

/*

	class Queue
{


	constructor()
	{
		this.list = [];
		this.length = 0;
	}

	// Pushes values to the end of the list
	enqueue(value)
	{
		this.length++;
		this.list.push(value);
	}

	// Removing item from the start
	dequeue()
	{
		// Dont do anything if there is no items
		if (this.length == 0) return;

		// Shift the first item off the start of the list and return the value
		this.length--;
		return this.list.shift();
	}

	// Peek function for getting the next value without removing it from the queue
	peek()
	{
		return this.list[0];
	}

}
*/
