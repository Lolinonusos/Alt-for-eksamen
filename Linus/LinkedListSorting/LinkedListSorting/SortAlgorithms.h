#pragma once

#include "LinkedList.h"

// Probably smart to pass in array if dealing with those

void dataSwap(int& x, int& y) {
	int tmp{ y };
	y = x;
	x = tmp;
}

Node* nodeSwap(Node* x, Node* y) {
	Node* tmp{ y->next };
	y->next = x;
	x->next = tmp;
	return y;
}

void selectionSort(LinkedList* list, int listSize) {

	Node* mainLoopPtr{ list->head }; // Points to nodes using the for loop
	Node* subLoopPtr{ nullptr }; // Points to nodes using the while loop
	Node* minPtr{ nullptr }; // Points to the node that holds the current smallest value found

	for (int i{ 0 }; i < listSize; i++) {
		
		minPtr = mainLoopPtr;
		subLoopPtr = mainLoopPtr->next;

		while (subLoopPtr != nullptr) {
			
			// Found node with value that is smaller
			// minPtr will point to that node
			if (subLoopPtr->data < minPtr->data) {
				minPtr = subLoopPtr;
			}
			subLoopPtr = subLoopPtr->next;
		}
		dataSwap(mainLoopPtr->data, minPtr->data);
		
		mainLoopPtr = mainLoopPtr->next;

	
	}
}

void bubbleSort(LinkedList* list, int listSize) {

	Node* headPtr{ list->head };
	Node* firstPtr{ list->head };
	Node* secondPtr{ nullptr };

	bool swapped = false;

	//for (int i{ 0 }; i < listSize; i++) {
	while (firstPtr != nullptr) {

		secondPtr = firstPtr->next;

		//headPtr = list->head;
		swapped = false;
		
		//for (int j{ 0 }; j < listSize - i - 1; j++) {
		while (secondPtr != nullptr) {

			std::cout << firstPtr->data << std::endl;
			std::cout << secondPtr->data << std::endl;


			if (firstPtr->data > secondPtr->data) {
				std::cout << "Bubbble Swap" << std::endl;
				//headPtr = nodeSwap(firstPtr, secondPtr);
				dataSwap(firstPtr->data, secondPtr->data);
				//swapped = true;
			}
			secondPtr = secondPtr->next;
			//headPtr = headPtr->next;
		}
			firstPtr = firstPtr->next;

	/*	
		if (swapped == false) {
			break;
		}*/
	}
}


void partition(LinkedList*, int noll, int listSize) {

}

void quickSort(LinkedList* list, int noll, int listSize) {

}