#include <iostream>

using namespace std;

// GeeksForGeeks: https://www.geeksforgeeks.org/what-is-linked-list/

/*

class Node
{
public:
	int data;
	Node* next;
};

// Can also be solved by using constructor
class node
{
public:
	int data;
	node* next;

	// A constructor is called here
	node(int value)
	{
		// It automatically assigns the value to the data
		data = value;

		// Next pointer is pointed to NULL
		next = NULL;
	}
};

void printList(Node* n)
{
	while (n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
}

// Driver's code for 3 nodes
void ThreeNodes()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// Allocate 3 nodes in the heap
	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1;			// Assign data in the first node
	head->next = second;	// Link first node with the second node

	second->data = 2;		// Assign data to the second node
	second->next = third;	// Link second node with the third node

	third->data = 3;		// Assign data to the third node
	third->next = NULL;		// Next pointer of the third block made NULL to indicate end of linked list

	printList(head);
}


// Given a reference (pointer to pointer) to the head of a list and an int,
// inserts a new node on the front of the list
void push(Node** head_ref, int new_data)
{
	// 1. Allocate node
	Node* new_node = new Node();

	// 2. Put in the data
	new_node->data = new_data;

	// 3. Make next of new node as head
	new_node->next = (*head_ref);

	// 4. Move the head to point to the new node
	(*head_ref) = new_node;
}


// Given a node prev_node, insert a new node after the given prev_node
void insertAfter(Node* prev_node, int new_data)
{
	// 1. Check if the given prev_node is NULL
	if (prev_node == NULL)
	{
		cout << "The given previous node cannot be NULL";
		return;
	}

	// 2. Allocate new node
	Node* new_node = new Node();

	// 3. Put in the data
	new_node->data = new_data;

	// 4. Make next of new node as next of prev_node
	new_node->next = prev_node->next;

	// 5. Move the next of prev_node as new_node
	prev_node->next = new_node;
}

// Given a reference (pointer to pointer) to the head of a list and an int,
// appends a new node at the end
void addAtEnd(Node** head_ref, int new_data)
{
	// 1. Allocate node
	Node* new_node = new Node();

	// Used in step 5
	Node* last = *head_ref;

	// 2. Put in the data
	new_node->data = new_data;

	// 3. This new node is going to be the last node, so make next of it as NULL
	new_node->next = NULL;

	// 4. If the linked list is empty, then make the new node as head
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	// 5. Else traverse till the last node
	while (last->next != NULL)
	{
		last = last->next;
	}

	// 6. Change the next of last node
	last->next = new_node;
	return;
}



// ------------- node connstructor -------------------------------------------------

// Function to insert an element at head position
void insertAtHead(node*& head, int val)
{
	node* n = new node(val);
	n->next = head;
	head = n;
}

// Function to insert an element at a specified position
void insertAfter(node* head, int key, int val)
{
	node* n = new node(val);

	if (key == head->data)
	{
		n->next = head->next;
		head->next = n;

		return;
	}

	node* temp = head;

	while (temp->data != key)
	{
		temp = temp->next;

		if (temp == NULL)
		{
			return;
		}
	}

	n->next = temp->next;
	temp->next = n;
}


// Function to insert an element at the end
void insertAtTail(node*& head, int val)
{
	node* n = new node(val);

	if (head == NULL)
	{
		head = n;
		return;
	}

	node* temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = n;
}


// Function to print the singly linked list
void print(node*& head)
{
	node* temp = head;

	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}

	cout << "NULL" << endl;
}


//main

//int main()
//{
//	//ThreeNodes();
//
//	
//	// STart with empty list
//	Node* head = NULL;
//
//	// Insert 6. So linked list becomes 6->NULL
//	addAtEnd(&head, 6);
//
//	// Insert 7 at the beginning
//	// So linked list becomes 7->6->NULL
//	push(&head, 7);
//
//	// Insert 1 at the beginning.
//	// So linked list becomes 1->7->6->NULL
//	push(&head, 1);
//
//	// Insert 4 at the end.
//	// So linked list becomes 1->7->6->4->NULL
//	addAtEnd(&head, 4);
//
//	// Insert 8, after 7.
//	// SO linked list becomes 1->7->8->6->4->NULL
//	insertAfter(head->next, 8);
//
//	cout << "Created Linked list is: ";
//	printList(head);
//
//	
//
//	//------------- node constructor ---------------------------------------------
//	
//	// Declaring an empty linked list
//	node* head = NULL;
//
//	insertAtHead(head, 1);
//	insertAtHead(head, 2);
//	cout << "After insertion at head: ";
//	print(head);
//	cout << endl;
//
//	insertAtTail(head, 4);
//	insertAtTail(head, 5);
//	cout << "After insertion at tail: ";
//	print(head);
//	cout << endl;
//
//	insertAfter(head, 1, 2);
//	insertAfter(head, 5, 6);
//	cout << "After insertion at a given position: ";
//	print(head);
//	cout << endl;
//
//	return 0;
//}
//

*/ 