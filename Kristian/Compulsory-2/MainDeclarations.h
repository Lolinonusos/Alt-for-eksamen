#pragma once
#include <iostream>

class Node
{
public:

	int data;
	Node* Next;
	Node* Previous;
};

class LinkedList : public Node
{
public:
	Node* head;
	Node* tail;

	//LinkedList constructor
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		head = tail;
	}
	~LinkedList()
	{
	/*	if (Next == nullptr)
		{
			Previous->Next = nullptr;
		}

		if (Previous == nullptr)
		{
			Next->Previous = nullptr;
		}

		if ((Previous != nullptr) && (Next != nullptr))
		{
			Previous->Next = this->Next;
			Next->Previous = this->Previous;
		}*/
		//Må kanskje ikke ha denne?
		//delete this;
	}

	//Adding to list
	//Adds element at beginning
	void AddAtEnd(int data);
	void AddInMiddle(int data);
	void AddInBeginning(int data);

	//Deleting
	void DeleteElement(int index);

	//Information
	//Prints List Backwards and forwards.
	void PrintDataForward();
	void PrintDataBackward();
	//Returns number of elements in list
	int ReturnElements();
	//Sort List
	void SortList();

	void RemoveDuplicates();
};

void LinkedList::AddAtEnd(int data)
{
	Node* newNode = new Node();
	newNode->data = data;

	newNode->Next = nullptr;
	newNode->Previous = nullptr;
	
	if (head == nullptr)
	{
		head = newNode;
		tail = head;
	}

	else
	{
		newNode->Previous = tail;
		tail->Next = newNode;
		tail = newNode;
	}
	
}

void LinkedList::AddInBeginning(int data)
{
	Node* newNode = new Node();
	newNode->data = data;

	newNode->Next = head;
	head = newNode;
	//if (tail == nullptr) //head
	//{
	//	tail = newNode;
	//	head = tail;
	//}
	//else
	//{
	//	newNode->Next = head;
	//}
}

void LinkedList::DeleteElement(int index)
{
	Node* NodePtr = head;
	int indexCheck = 0;
	while (indexCheck < index)
	{
		
		NodePtr = NodePtr->Next;

		indexCheck++;
	}

	Node* nextNode = NodePtr->Next;
	Node* prevNode = NodePtr->Previous;

	nextNode->Previous = prevNode;
	prevNode->Next = nextNode;

	free(NodePtr);
	
}


void LinkedList::PrintDataBackward()
{
	Node* NodePtr = head;

	while (NodePtr != nullptr)
	{
		std::cout << NodePtr->data << " | ";
		NodePtr = NodePtr->Next;
	}
	std::cout << std::endl;
}

void LinkedList::PrintDataForward()
{
	Node* NodePtr = tail;

	while (NodePtr != nullptr)
	{
		std::cout << NodePtr->data << " | ";
		NodePtr = NodePtr->Previous;
	}
	std::cout << std::endl;
}

int LinkedList::ReturnElements()
{
	Node* temporary = head;

	int num = 0;

	while(temporary != nullptr)
	{
		temporary = temporary->Next;
		num += 1;
	}

	return num;
}

void LinkedList::SortList()
{
	Node* current = head;
	Node* temp = nullptr;


	if (head == nullptr)
	{
		return;
	}
	else
	{
		//Loops until the current node is a nullptr. 
		while (current != nullptr)
		{
			temp = current->Next;

			while (temp != nullptr)
			{
				if (current->data > temp->data)
				{
					int a = current->data;
					current->data = temp->data;
					temp->data = a;
				}
				temp = temp->Next;
			}
			current = current->Next;
		}
	}
}

void LinkedList::RemoveDuplicates()
{
	this->ReturnElements();



}
