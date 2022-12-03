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
	// If not using template, just remove everything related to templatt
	int hashFunction(T key) {
		return std::hash<T>()(key) % tableLength;
	}

	
	void insertItem(T key) {

		int insertAt = hashFunction(key);
			
		listArray[insertAt]->addAtEnd(key);

	}

	
	// Delete singular
	void deleteItem(T key) {

		int deleteAt = hashFunction(key);


	}

	// Delete list

	
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


