#include <iostream>

using namespace std;

/*

// Hash Table in C/C++ - A complete implementation: https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus

// STL data structure for hash table
//std::unordered_map() 

// Any Hash Table implementation has the following three components:
//		A good Hash function to map keys to values
//		A Hash Table Data Structure that supports insert, search and delete operations
//		A Data Structure to account for collision of keys
// 
// To show handling of collision cases----------------------------------------------------------------
// 
//		This is a simple hash function that sums the ASCII (Letters assigned numbers) value.
//

#define CAPACITY 50000 // Size of the Hash Table

unsigned long hash_function(char* str)
{
	unsigned long i = 0;

	for (int j = 0; str[j]; j++)	// Sums ASCII value
		i += str[j];

	return i % CAPACITY;	// Must return a number within the capacity of the hash table.
							// Otherwise, we may access an unbound memory location, leading to error
}
// Can test for different strings and check if they collide or not. For example, the strings
// "Hel" and "Cau" will collide, since they have the same ASCII value.


// Define Hash Table data structures --------------------------------------------------------------------

//		A Hash Table is an array of items, which themselves are a {key: value} pair.
// Firstly define item structure
typedef struct Ht_item Ht_item;

// Define the Hash Table Item here
struct Ht_item
{
	char* key;
	char* value;
};

// Now the Hash Table has an array of pointers which themselves point to Ht_item, so it is a 
// double-pointer. 
// Other than that we will also keep track of the number of elements in the Hash table
// using count, and store the size of the table in size.

typedef struct HashTable HashTable;

// Define the Hash Table here
struct HashTable
{
	// Contains an array of pointers to items
	Ht_item** items;
	int size;
	int count;
};


// Create the Hash Table and its items --------------------------------------------------------------

// We need functions to create a new Hash table into memory and also create its items.

// Let's create the item first. This is very simple since we only need to allocate memory
// for its key and value and return a pointer to the item.

Ht_item* create_item(char* key, char* value)
{
	// Creates a pointer to a new hash table item
	Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));
	item->key = (char*)malloc(strlen(key) + 1);
	item->value = (char*)malloc(strlen(value) + 1);

	strcpy(item->key, key);
	strcpy(item->value, value);

	return item;
}

// now lets write the code for creating the table. This allocates memory for the wrapper
// structure HashTable, and sets all its items to NULL (Since they arent used).

HashTable* create_table(int size)
{
	// Creates a new HashTable
	HashTable* table = (HashTable*)malloc(sizeof(HashTable));

	table->size = size;
	table->count = 0;
	table->items = (Ht_item**)calloc(table->size, sizeof(Ht_item*));

	for (int i = 0; i < table->size; i++)
		table->items[i] = NULL;

	return table;
}

// Almost done with this part. Now we must remember to free up memory that has been allocated
// on the heap using malloc(), calloc().

// Functions which free up a table item and the whole table too.

void free_item(Ht_item* item)
{
	// Frees an item
	free(item->key);
	free(item->value);
	free(item);
}

void free_table(HashTable* table)
{
	// Frees the table
	for (int i = 0; i < table->size; i++)
	{
		Ht_item* item = table->items[i];

		if (item != NULL)
			free_item(item);
	}

	free(table->items);
	free(table);
}

// We havge now completed our groundwork to building a functional Hash Table. 
// Lets now start writing our insert(), search() and delete() methods. 

// Inser into the Hash Table -----------------------------------------------------------------------

// Create a function ht_insert() that performs this task for us.

// This takes in a HashTable pointer, a key and a valueas parameters.
void ht_insert(HashTable* table, char* key, char* value);

// Now there are a certain steps involved in the insert function.
//		Create the item based on the {key: value} pair.
//		Compute the index based on the hash function.
//		Check if the index is already occupied or not, by comparing key.
//				If not occupied, we can directly insert into index.
//				Otherwise, it is a collision, and we need to handle it.

// Step 1: Directly call create_item(key, value).
//int index = hash_function(key);



*/


