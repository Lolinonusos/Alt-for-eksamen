#include <iostream>
#include "HashTable.h"

int main()
{
	std::cout << "Hash Table program running" << std::endl;

    Item* Fruit = new Item{ "Apple", NULL };
    Item* Game = new Item{ "Splinter Cell", NULL };
    Item* Beer = new Item{ "AAss", NULL };
    Item* Stream = new Item{ "Twitch", NULL };
    Item* User = new Item{ "Admin", NULL };
    

    HashTable Table;

    Table.AddItem(Fruit);
    Table.AddItem(Game);
    Table.AddItem(Beer);
    Table.AddItem(Stream);
    Table.AddItem(User);

    Table.PrintTable();


	return 0;
}