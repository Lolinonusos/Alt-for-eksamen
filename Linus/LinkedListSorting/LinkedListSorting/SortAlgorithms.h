#pragma once

#include "LinkedList.h"

// Probably smart to pass in array if dealing with those

void swap(int& x, int& y) {
	int tmp{ y };
	y = x;
	x = tmp;
}

//Node* nodeSwap(Node* x, Node* y) {
//	Node* tmp{ y->next };
//	y->next = x;
//	x->next = tmp;
//	return y;
//}

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


void bubbleSort(LinkedList* list) {

	Node* outerWhilePtr{ list->head }; // 
	Node* innerWhilePtr{ nullptr };

	while (outerWhilePtr != nullptr) {

		innerWhilePtr = outerWhilePtr->next;

		while (innerWhilePtr != nullptr) {

			//std::cout << outerWhilePtr->data << std::endl;
			//std::cout << innerWhilePtr->data << std::endl;

			if (outerWhilePtr->data > innerWhilePtr->data) {
				//std::cout << "Bubbble Swap" << std::endl;
				swap(outerWhilePtr->data, innerWhilePtr->data);
			}
			innerWhilePtr = innerWhilePtr->next;
		}
		outerWhilePtr = outerWhilePtr->next;
	}
}


Node* partition(Node* start, Node* end) {
	if (start == end || start == nullptr || end == nullptr) {
		return start;
	}

	Node* pivotPrev = start;
	Node* current = start;
	int pivInt = end->data;

	while (start != end) {
		if (start->data < pivInt) {
			pivotPrev = current;
			int tmp = current->data;
			current->data = start->data;
			start->data = tmp;
			current = current->next;
		}
		start = start->next;
	}

	int tmp = current->data;
	current->data = pivInt;
	end->data = tmp;

	return pivotPrev;
}

void quickSort(LinkedList* list, Node* start, Node* end) {

	if (start == nullptr || start == end || start == end->next) {
		return;
	}

	Node* pivot = partition(start, end);
	quickSort(list, start, pivot);

	if (pivot != nullptr && pivot == start) {
		quickSort(list, pivot->next, end);
	}

	else if (pivot != nullptr && pivot->next != nullptr) {
		quickSort(list, pivot->next->next, end);
	}
}