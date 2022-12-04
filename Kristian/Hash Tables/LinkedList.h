#pragma once
#include <string>
#include <iostream>

struct Item
{
	std::string Value;
	Item* next;
};


class LinkedList
{

	// // // Variables // // //
public:
	Item* Head;
	int length;


	// // // Functions // // //
public:
	LinkedList();


	//Inserting new item at the end of the list
	void insertItem(Item* newItem);

	//Deletes specific item, returns true if item exists and has been deleted
	bool removeItem(std::string Value);

	//Returns the item by its value, if needed add more data to specific "node/item"
	//Nullptr if value does not exist
	Item* returnItem(std::string Value);

	//Returns length of list
	int GetListLength();


	//Might not implement yet
	void PrintList();

	~LinkedList();

};
