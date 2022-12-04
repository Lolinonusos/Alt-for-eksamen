#include <iostream>

using namespace std;

/*

class LinkedList
{
	// Constructor
	int head = NULL;
	int length = 0;

	int position = NULL;
	int next = 0;

	// Retrieve a value in a given position
	int get(int position)
	{
		// Throw error if position is greater than the length of the LinkedList.
		if (position >= this->length)
		{
			cout << "Position outside of list range" << endl;
		}

		// Start with the head of the list
		int current = this->head;

		// Go through all of the items using node.next until we reach the specified position.
		for (int index = 0; index < position; index++)
		{
			//current = current.next;
		}
	}
};

*/

// video: https://www.youtube.com/watch?v=HKfj0l7ndbc&ab_channel=CodeBeauty -------------------------------------------------------------------------------

/*
class Node
{
public:
	int Value;
	Node* Next;
};

void printList(Node*n)
{
	while (n != NULL)
	{
		cout << n->Value << endl;
		n = n->Next;
	}
}

int main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->Value = 1;
	head->Next = second;

	second->Value = 2;
	second->Next = third;

	third->Value = 3;
	third->Next = NULL;

	printList(head);

}
*/ 