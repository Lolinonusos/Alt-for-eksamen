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
	
	HashTable<int> table(7);

	table.insertItem(96);
	table.displayHash();
	
	int test = table.tableLength;
	
	return 0;
}