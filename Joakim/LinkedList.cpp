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

// Doubly linked list -------------------------------------------------------------------------------------------------------------------------------------------------

// video: https://www.youtube.com/watch?v=-StYr9wILqo&t=623s

// Can be traversed in two directions (forward and backwards). 

// For first node:
//	1. Create new node
//	2. Set node value
//	3. Set node->next = nullptr and node->previous = nullptr
//	4. head = node and tail = node
//

/* 

class Node
{
public:
	int value;
	Node* next;
	Node* previous;
};

void printForward(Node* head)
{
	Node* traverser = head;

	while (traverser != nullptr)
	{
		cout << traverser->value << endl;

		traverser = traverser->next;
	}
}

void printBackwards(Node* tail)
{
	Node* traverser = tail;

	while (traverser != nullptr)
	{
		cout << traverser->value << endl;

		traverser = traverser->previous;
	}
}

int main()
{
	Node* head;
	Node* tail;

	// Add first node
	Node* node = new Node();

	node->value = 4;
	node->next = nullptr;
	node->previous = nullptr;

	head = node;
	tail = node;

	// Add second node
	node = new Node();
	node->value = 5;
	node->next = nullptr;
	node->previous = tail;
	tail->next = node;
	tail = node;

	// Add third node
	node = new Node();
	node->value = 6;
	node->next = nullptr;
	node->previous = tail;
	tail->next = node;
	tail = node;

	// Add fourth node
	node = new Node();
	node->value = 7;
	node->next = nullptr;
	node->previous = tail;
	tail->next = node;
	tail = node;

	printForward(head);

	printBackwards(tail);

	return 0;
}

*/ 
