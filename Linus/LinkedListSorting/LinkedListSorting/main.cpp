#include <iostream>

#include "LinkedList.h"
#include "SortAlgorithms.h"

const int fixedArray[] = { 10,20,8,15,12,17,25 };

int main() {

	int loopSize{ sizeof(fixedArray) / sizeof(fixedArray[0]) };

	LinkedList* list{ new LinkedList };

	for (int i = 0; i < loopSize; i++) {
		list->addAtEnd(fixedArray[i]);
	}

	list->printHeadToTail();

	std::cout << "Removing 25" << std::endl;
	list->remove(25);

	list->printHeadToTail();


	return 0;
}