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

	std::cout << "Root value: " << Gongaga->getRoot()->data << std::endl;

	
	std::cout << "\nInsert an integer:\n";
	//std::cin >> key;
	
	key = 3;

	Gongaga->insertIntoTree(key);

	Gongaga->find(8);
	
	Gongaga->findMax();
	Gongaga->findMin(Gongaga->getRoot());
	std::cout << "\nInorder traversal:\n";
	Gongaga->inorder();
	//Gongaga->remove(8);
	//std::cout << "\nInorder with 8 removed:\n";
	//Gongaga->inorder();

	std::cout << "\nPreorder traversal:\n";
	Gongaga->preorder();

	std::cout << "\nPostorder traversal:\n";
	Gongaga->postorder();

	//std::cout << "Root value: " << Gongaga->getRoot();
	//Gongaga->findMin();

	return 0;
}