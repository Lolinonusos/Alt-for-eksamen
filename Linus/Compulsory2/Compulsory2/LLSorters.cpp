#include "LLSorters.h"
#include <iostream>



void sort() {
	
	
}

// Geeks for Geeks
void selectionSort(Node* Head, int size) {
	std::cout << "Selection sorting \n" << std::endl;
	
	Node* loopPtr = Head;

	// traverse the list
	for (int i = 0; i < size - 1; i++) {
		Node* minData = loopPtr;
		Node* r = loopPtr->Next;

		// traverse the unsorted sublist
		while (r) {
			if (minData->Data > r->Data) {
				minData = r;
			}
			r = r->Next;
		}
		int x = loopPtr->Data;
		loopPtr->Data = minData->Data;
		minData->Data = x;
		loopPtr = loopPtr->Next;
	}
}

void insertionSort(Node* Head) {


	
}
