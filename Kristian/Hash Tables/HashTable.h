#pragma once

#include "LinkedList.h"

class HashTable
{
public:

	// // // VARIABLES // // //

	private:
	//pointer to the array to the hash table.
		LinkedList* Table;

	//Table size, Prime number for å hindre collisions, får en mer jevn spredning
		int TableLength = 13;

	//Table size of actually used slots.
		int usedLength;

	// // // FUNCTIONS // // //

public:

	//Constructor, kan legge til custom size, men ikke nå.
	HashTable();

	//Deconstructor, yeetus deletus hash tableus
	~HashTable();

	//Location finder, BYTT FRA STRING OM DU BYTTER TYPE ITEM
	int hash(std::string ItemID);

	//Add new item to table, Legger til newItem i table.
	void AddItem(Item* newItem);

	//Deletes item, BYTT FRA STRING OM DU BYTTER TYPE ITEM, 
	bool removeItem(std::string ItemID);

	//Returns the item youre looking for, hopefully
	Item* getItem(std::string ItemID);

	//Print the entire table, row for row
	void PrintTable();

	//Returns 
	int GetItemAmount();


};
