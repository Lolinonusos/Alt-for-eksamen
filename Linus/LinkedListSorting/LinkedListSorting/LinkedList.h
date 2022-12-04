#pragma once

#include "Node.h"

class LinkedList {
public:
	
	int listLength{ 0 };

	Node* head{nullptr};
	Node* tail{nullptr};


	LinkedList() {
		head = tail;
	}

	void addAtEnd(int input) {

		Node* newNode = new Node(input);

		if (head == nullptr) {
			head = newNode;
			tail = head;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		listLength += 1;
	}

	// 
	void sortedInsert(int input) {

		listLength += 1;
	}

	// Removes by key value, not index
	void remove(int key) {

		Node* toDelete{ head };
		Node* secondToLast { nullptr };

		if (key == head->data) {
			head = head->next;
			// If doubly
			// Head->previos = nullptr
			delete toDelete;
		}
		else {
			while (key != toDelete->data) {
				secondToLast = toDelete;
				toDelete = toDelete->next;
			}
			if (toDelete == tail) {
				tail = secondToLast;
			}
			secondToLast->next = toDelete->next;
			delete toDelete;
		}
	}

	void printHeadToTail() {
		Node* printPtr = head;

		std::cout << "Print from Head to Tail" << std::endl;

		while (printPtr != nullptr) {
			std::cout << printPtr->data << std::endl;
			printPtr = printPtr->next;
		}
	}
};
