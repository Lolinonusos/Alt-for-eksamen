#include <iostream>
#include <iostream>
#include <vector>
#include <string>

#include "Hashtable.h"
#include "LinkedList.h"


int main() {
	
	int keys[15] = {};
	
	int size = sizeof(keys) / sizeof(keys[0]);
	
	for (int i = 0; i < size; i++) {
	 	keys[i] = (rand() % 101);
	}
	
	HashTable<char*> charTable(10);



	char word[] = "skrankel";

	charTable.insertItem(word);
	charTable.displayHash();
	
	
	std::cout << "\n\nInteger table coming right up!\n" << std::endl;

	HashTable<int> intTable(10);

	srand(time(0));


	for (int i = 0; i < 20; i++) {
		
		int random = rand() % 50;
		
		intTable.insertItem(random);
	}

	intTable.displayHash();
	intTable.search(32);

	int test = charTable.tableLength;
	
	return 0;
}