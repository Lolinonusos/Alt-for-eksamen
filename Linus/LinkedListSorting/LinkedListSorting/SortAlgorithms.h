#pragma once

#include "LinkedList.h"

// Probably smart to pass in array if dealing with those

void swap(int& x, int& y) {
	int tmp{ x };
	x = y;
	y = tmp;
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
		swap(mainLoopPtr->data, minPtr->data);
		
		mainLoopPtr = mainLoopPtr->next;
	}
}

void bubbleSort(LinkedList* list, int listSize) {

}

void quickSort(LinkedList* list, int listSize) {

}