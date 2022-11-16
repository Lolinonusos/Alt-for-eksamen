#pragma once

#include <vector>

#include "LinkedList.h"

template<typename T>
class HashTable {
public:
	
	int tableLength = 0; // Total amount of linked list we will allow

	std::vector<LinkedList<T>> array;
	
	HashTable(int value) {
		tableLength = value;
		//std::vector
	}


	// Place an item in correct array location
	int hashFunction(T key, int tableLength) {

		unsigned int hashValue = 0;

		for (int i = 0; i < key; i++) {
			hashValue += key;
		}

		return hashValue % tableLength;
	}

	
	void insertItem();

	
	void deleteItem();

	
	void displayHash()
	{
		for (int i = 0; i < tableLength; i++) {
			std::cout << array[i].printHeadToTail() << std::endl;
		}
	}

	// void search?
	
	std::vector<LinkedList<int>> bucketList; // Vector holding different linked lists

	//~HashTable();
};
