#include <iostream>

#include "sorters.h"
#include "searchers.h"

// Add elements to the array - done!
// Insert elements and values at specific indexes - done!
// Remove elements from the array - done?
// Expand the array - done!
// Shrink the array - done!
// Search the array using a search algorithm
	// Linear Search - functioning
	// Iterative Binary Search - functioning
	// Recursive Binary Search - 

// Use 4 of the sorting algorithms
	// Selection Sort - functioning
	// Bubble Sort - functioning
	// Merge Sort
	// Quick Sort - functioning
	// Heap Sort - functioning
	// Introsort ?

template <typename T>
class DArray {
public:

	DArray();
	
	void addValue(int value); // Insert something at the end
	void removeAt(int position); // Remove element at a specific position
	void insertAt(int index, int value); // Insert somewhere specific
	
	void expand(); // Expand array
	void shorten(); // Shrink array

	//int currentlyContains(); // Showcase elements currently held in array
	
	T* arrey; // by being a pointer it let's me put different things into it, like an array (I think)
	
	// return current size of arrey
	int retSize();

	void printArrey(T* arr);
	
	~DArray();
	
private:

	 
	int capacity = 0; // How long the array is, should always be 1 more than arreySize
	int arreySize = 0; // How many elements currently held, should always be 1 less than capacity

};


template <typename T>
DArray<T>::DArray() {
	this->capacity = 1;
	this->arreySize = 0;
	arrey = new T[capacity]; // puts an array into arrey
}


// Adds value at the end of the array
template <typename T>
void DArray<T>::addValue(int value) {
	if (this->arreySize < this->capacity) {
		std::cout << "Adding value without problem\n" << std::endl;
		this->arrey[arreySize] = value;
		std::cout << "Added: " << this->arrey[arreySize] << std::endl;
		arreySize += 1;
	}
	else { // Array is full, expand it
		std::cout << "Expanding\n" << std::endl;
		this->expand();
		this->arrey[arreySize] = value;
		std::cout << "Added: " << this->arrey[arreySize] << std::endl;
		arreySize += 1;
	}
}


// Expand array when it is to short
template <typename T>
void DArray<T>::expand() {

	this->capacity += 1;
	T* temp_arrey = new int[capacity];

	// Copy elements form arrey to temp_arrey
	for (int i = 0; i < (capacity - 1); i++)
	{
		temp_arrey[i] = arrey[i];
	}
	
	delete[] arrey;
	arrey = temp_arrey;
}


// Remove an element at a specific position
template <typename T>
void DArray<T>::removeAt(int position) {
	
	// Making sure we remove an element at a position that actually exists
	if (position < 0 || position >= capacity) {
		std::cout << "Out of array bounds, unable to remove element" << std::endl;
		return;
	}

	capacity -= 1;
	arreySize -= 1;
	T* temp_arrey = new T[capacity];

	//moveBack(position);
	//arrey[position] = NULL;

	// Copy everything before removed element
	for (int i = 0; i < position; i++) {
		temp_arrey[i] = arrey[i];
	}

	// Move everything from position one space back
	for (int i = position; i < arreySize - 1; i++){
		temp_arrey[i] = arrey[i + 1];
	}

	delete[] arrey;
	arrey = temp_arrey;
	std::cout << "Element removed" << std::endl;
}


template <typename T>
void DArray<T>::insertAt(int index, int value) {
	// Do this if trying to insert at a position less than 0
	if (index < 0) {
		
		int moves = 0;
		
		std::cout << "Out of array bounds, expanding" << std::endl;
		for (int i = 0; i > index; i--) {
			expand();
			moves += 1;
		}
		arreySize += moves;
		index = 0;
		T* temp_arrey = new T[capacity];

		for (int i = 0; i < capacity; i++) {
			if (i == index) {
				temp_arrey[i] = value;
			}
			else if(i >= moves) {
				temp_arrey[i] = arrey[i - moves];
			}
			else {
				temp_arrey[i] = NULL;
			}
			std::cout << temp_arrey[i] << std::endl;
		}
		
		delete[] arrey;
		arrey = temp_arrey;
		
	}
	// Do this if trying to insert at a position larger than the arrays capacity
	else if(index >= capacity) {
		std::cout << "Out of array bounds, expanding" << std::endl;
		int prevSize = 0;
		
		int prevCap = index - capacity - 1;
		
		for (int i = 0; i <= (prevCap + 1); i++) {
			expand();
			prevSize += 1;
		}
		
		arreySize += prevSize;
		T* temp_arrey = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			if (i == index) {
				temp_arrey[i] = value;
			}
			else if (i < prevCap) {
				temp_arrey[i] = arrey[i];
			}
			else {
				temp_arrey[i] = NULL;
			}
		}
		delete[] arrey;
		arrey = temp_arrey;
	}
	else
	{
		arrey[index] = value;
	}
	
}

// Shorten the array when unnecessary long
template <typename T>
void DArray<T>::shorten() {

}


template <typename T>
int DArray<T>::retSize() {
	return arreySize;
}

template <typename T>
void DArray<T>::printArrey(T* arr) {
	for (int i = 0; i < retSize(); i++) {
		std::cout << arrey[i]<< std::endl;
	}
}

// Goodbye
template <typename T>
DArray<T>::~DArray() {
	delete[] this->arrey;
}


void selectSearchMethod() {
	
}


void selectSortMethod() {
	
}


int main() {

	DArray<int> Ayy1;

	int choice = 0;
	
	while (choice != 7) {
		
		int add = 0;
		int indIns = 0;
		int valIns = 0;
		int indRem = 0;
		
		std::cout << "1: Add value to array" << std::endl;
		std::cout << "2: Insert value at user chosen index" << std::endl;
		std::cout << "3: Remove a user chosen index" << std::endl;
		std::cout << "4: Print array" << std::endl;
		std::cout << "5: Search array for value" << std::endl;
		std::cout << "6: Sort array" << std::endl;
		std::cout << "7: Automatic (will exit program)" << std::endl;
		std::cout << "8: Exit" << std::endl;
			
		std::cin >> choice;
		
		switch (choice) {
		case 1:
			std::cin >> add;
			Ayy1.addValue(add);
			break;
		case 2:
			std::cout << "Insert value: ";
			std::cin >> valIns;
			std::cout << "Insert index: ";
			std::cin >> indIns;
			Ayy1.insertAt(indIns, valIns);
			break;
		case 3:
			std::cout << "insert index to remove: ";
			std::cin >> indRem;
			Ayy1.removeAt(indRem);
			break;
		case 4:
			Ayy1.printArrey(Ayy1.arrey);
			break;
		case 5:
			selectSearchMethod();
			break;
		case 6:
			selectSortMethod();
			break;
		case 7:
			std::cout << "Running automatic process\n" << std::endl;
			break;
		case 8:
			return 0;
		};
		
	}
	// insert values
	Ayy1.addValue(10);
	Ayy1.addValue(7);
	Ayy1.addValue(100);
	Ayy1.addValue(1);
	Ayy1.addValue(20);

	//Ayy1.removeAt(1);
	
	Ayy1.addValue(69);
	Ayy1.addValue(34);

	Ayy1.insertAt(1, 8);
	
	std::cout << "\nChecking all elements: " << std::endl;

	int x = 10;

	// Sort algorithms
	//selectionSort(Ayy1.arrey, Ayy1.retSize());
	bubbleSort(Ayy1.arrey, Ayy1.retSize());
	//mergeSort(Ayy1.arrey, 0, Ayy1.retSize());
	//quickSort(Ayy1.arrey, 0, Ayy1.retSize() - 1);
	//heapSort(Ayy1.arrey, Ayy1.retSize());
	
	// Search algorithms
	linearSearch(Ayy1.arrey, Ayy1.retSize(), x);
	//binarySearchIterative(Ayy1.arrey, 0, Ayy1.retSize(), x);
	//binarySearchRecursive(Ayy1.arrey, 0, Ayy1.retSize(), x); // not working correctly right now
	
	Ayy1.printArrey(Ayy1.arrey);

	std::cout << "Automatic process finished.";
	
	return 0;
}
