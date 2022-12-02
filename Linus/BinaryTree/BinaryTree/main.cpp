#include <iostream>

#include "BinaryNode.h"


// fixed array
const int fixedArray[] = { 10,20,8,15,12,17,25 };

int main() {

	int loopSize = sizeof(fixedArray) / sizeof(fixedArray[0]);

	Node* Gongaga = new Node(9);

	for (int i = 0; i < loopSize; i++) {
		Gongaga->insertIntoTree(fixedArray[i]);
	}

	int key{};

	std::cout << "Root value: " << Gongaga->getRoot();

	
	std::cout << "Insert an integer:\n";
	//std::cin >> key;
	
	key = 3;

	Gongaga->insertIntoTree(key);

	Gongaga->find(8);
	
	//Gongaga->findMax();
	Gongaga->findMin();
	Gongaga->removeMin();
	//std::cout << "Root value: " << Gongaga->getRoot();
	Gongaga->findMin();

	return 0;
}