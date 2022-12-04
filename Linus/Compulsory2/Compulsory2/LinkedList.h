#pragma once

class Node {
public:
	int Data;
	Node* Next;
	Node* Prev;
	
	Node(int value) {
		Data = value;
		Next = nullptr;
		Prev = nullptr;
	}
	
	~Node() {
		
	}
	
};
	
class LinkedList {
public:
	Node* Head;
	Node* Tail;
	friend Node; // Gives full access to named class

	LinkedList() {
		Head = nullptr;
		Tail = nullptr;
		Head = Tail;
	}
	
	void addAtEnd(int value);
	
	void findDuplicate();

	void remove(int index);

	void insertAt(int dataValue, int index);

	void sortedInsert(int dataValue);
	
	int amountOfElements();

	void printHeadToTail();

	void printTailToHead();

	~LinkedList() {
		
	}
};
