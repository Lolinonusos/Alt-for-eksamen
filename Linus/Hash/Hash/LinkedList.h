#pragma once

#include <iostream>
#include <vector>

template <typename T>
class Node {
public:
	T Data;
	Node* Next;

	Node<T>(T value) {
		Data = value;
		Next = nullptr;
	}

	//~Node() {
};


template <typename T>
class LinkedList{
public:
	Node<T>* Head;
	Node<T>* Tail;

	
	LinkedList() {
		Head = nullptr;
		Tail = nullptr;
	}

	void addAtEnd(T value) {

		Node<T>* newNode = new Node<T>(value);
		
		newNode->Next = nullptr;
		//newNode->Data = value;
		
		if (Head == nullptr) {
			Head = newNode;
			Tail = Head;
		}
		else {
			Tail->Next = newNode;
			Tail = newNode;
		}
	}

	void remove(int index) {
		Node<T>* del = Head;

		// Index is less than zero
		if (index < 0) {
			std::cout << "Indexes below 0 does not exist." << std::endl;
			return;
		}

		// Index 0 is the head
		// Delete Head node
		if (index == 0) {
			Head = del->Next;
		
			free(del);
			return;
		}
		else {
			// Find node to remove
			for (int i = 0; i <= index - 1; i++) {
				del = del->Next;
				if (del->Next == nullptr) {
					std::cout << "Index is out of bounds." << std::endl;
					return;
				}
			}

			// Create two pointers that point to the nodes surrounding the
			// node del is currently pointing to
			//Node* NextNode = del->Next;
			//Node<T>* PrevNode = del->Prev;

			// Connect surrounding nodes
			//NextNode->Prev = PrevNode;
			//PrevNode->Next = NextNode;

			// Removes the node del points to and frees up the memory
			free(del);
			return;
		}
	}

	void insertAt(T dataValue, int index) {
		Node<T>* temp = Head;

		Node<T>* node1 = new Node(dataValue);
		//node1->Data = dataValue;

		// Move temp to correct position
		for (int i = 0; i <= index; i++) {
			temp = temp->Next;
		}

		// Sara gave huge help!
		// A pointer that points to the node which is previous to the one
		// temp points to
		Node* PrevNode = temp->Prev;

		// Connects new node with the node temp points to
		node1->Next = temp;

		// Connects the new node with the node PrevNode points to
		//node1->Prev = PrevNode;
		PrevNode->Next = node1;
	}

	//int amountOfElements();

	void printList() {
		Node<T>* printPtr = Head;
		std::cout << "Print from Head to Tail" << std::endl;
		while (printPtr != nullptr) {
			std::cout << printPtr->Data << std::endl;
			printPtr = printPtr->Next;
		}
	}

	~LinkedList() {
		
	}
};





