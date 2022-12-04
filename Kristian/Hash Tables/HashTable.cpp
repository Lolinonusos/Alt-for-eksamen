#include "HashTable.h"

HashTable::HashTable()
{
	Table = new LinkedList[TableLength];

}

HashTable::~HashTable()
{
	delete[] Table;
}

//Basic hash function, will probably have collisions and get slowed down. 
int HashTable::hash(std::string ItemID)
{
	int HashValue = 0;
	for (int i = 0;i < ItemID.length(); i++)
	{
		HashValue += ItemID[i];
	}

	HashValue = (ItemID.length() * HashValue) % TableLength;

	return HashValue;
}

void HashTable::AddItem(Item* newItem)
{
	//Decides placement in the Table after rules set in HASH function.
	int placement = hash(newItem->Value);

	//Adds item in the linked list located at "placement", and calls the add function in that linked list
	Table[placement].insertItem(newItem);

}

Item* HashTable::getItem(std::string ItemID)
{
	int placement = hash(ItemID);

	return Table[placement].returnItem(ItemID);

}

void HashTable::PrintTable()
{
	std::cout << "Printing hash table: " << std::endl;

	for (int i = 0; i < TableLength; i++)
	{
		std::cout << "Row nr. " << i + 1 << ": ";
		Table[i].PrintList();
	}
}

int HashTable::GetItemAmount()
{
	int ItemAmount = 0;

	for (int i = 0; i < TableLength; i++)
	{
		ItemAmount += Table[i].GetListLength();
	}
	return ItemAmount;
}

bool HashTable::removeItem(std::string ItemID)
{

	return false;
}

