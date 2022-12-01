#pragma once

#include <vector>

#include "LinkedList.h"

template<typename T>
class HashTable {
public:
	

	std::vector<LinkedList<T>*> listArray;
	int tableLength = 0; // Total amount of linked list we will allow
	
	HashTable(int value) {
		tableLength = value;
		//listArray = std::vector<LinkedList<T>*>(tableLength); // Defining size of the vector
		listArray = std::vector <LinkedList<T>*>(tableLength);
		for (int i = 0; i < tableLength; i++) {
			LinkedList<T>* newList = new LinkedList<T>();
			listArray[i] = newList;
		}
	}


	// Place an item in correct array location
	int hashFunction(T key) {

	//	unsigned int stringLength = 0;

	//	if (key[1] != 0) {
	//		for (int i = 0; i < key.size(); i++) {
	//			stringLength ++;
	//		}
	//	}

	//	// If key inserted is a string
	//	if (stringLength > 1) {
	//		std::cout << "Inserting as array type; string or other" << std::endl;
	//		return stringLength % tableLength;
	//	}
	//	else
	//	{
	//		int i = key & tableLength;
	//		std::cout << "Inserting as non array; singular value" << std::endl;
		return std::hash<T>()(key) % tableLength;
	//	}
	}

	
	void insertItem(T key) {

		int insertAt = hashFunction(key);
			
		listArray[insertAt]->addAtEnd(key);

	}

	
	void deleteItem();

	
	void displayHash()
	{
		for (int i = 0; i < tableLength; i++) {
			std::cout << "\nValues at index " << i << ": " << std::endl;
			listArray[i]->printList();
			std::cout << std::endl;
		}
	}

	void search(T input) {

		int searchAt = hashFunction(input);

		std::cout << "\nSearcing index " << searchAt << "... " << std::endl;

		listArray[searchAt]->find(input);
	}
	
	std::vector<LinkedList<int>> bucketList; // Vector holding different linked lists

	//~HashTable();
};


