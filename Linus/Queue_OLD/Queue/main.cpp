#include <iostream>

class Node {
public:
	int Data;
	Node* Nxt;
	Node* Prev;
};


class Queue {
public:
	Node* Head;
	Node* Tail;
	int Size;
	
	Queue() {
		Head = NULL;
		Tail = NULL;
		Size = 0;
	}

	Node* DeQ() {
		
	}

	void Add(int value) {
		Node* newNode = new Node;

		newNode->Data = value;
		newNode->Nxt = NULL;
		newNode->Prev = NULL;
		
		if (Head == NULL) { // Head will always point to the first node
			Head = newNode;
			Tail = Head;
		}
		else { // 
			newNode->Prev = Tail;
			Tail->Nxt = newNode;
			Tail = newNode;
		}
	}

	void PrintQ() {

		std::cout << " " << std::endl; 
	}
	
	~Queue() {
		
	}
};

int main() {
	
	Queue *Q1 = new Queue; 
	Q1->Add(1);

	Q1->PrintQ();

}
