#include <iostream>

using namespace std;

#define TABLE_SIZE 10

struct Person 
{
	string name;
	int age;
	//...can add more stuff later, maybe
	bool deletedPerson = false;

	Person* next; 
};

Person* hash_table[TABLE_SIZE];

unsigned int hashish(string name) 
{
	int length = name.size();
	unsigned int hash_value = 0;

	for (int i = 0; i < length; i++)
	{
		hash_value += name[i]; // Gives a randomish value
		hash_value = (hash_value * name[i]) % TABLE_SIZE; // So that it stays within the size of the table (0 - Table_Size-1)
	}

	return hash_value;
}

void init_hash_table()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hash_table[i] = NULL;
	} // table is empty
}

void print_table()
{
	cout << "Start" << endl;

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hash_table[i] == NULL)
		{
			cout << "\t" << i << "\t---\n";
		}
		else
		{
			cout << "\t" << i << "\t";

			Person* tmp = hash_table[i];

			while (tmp != NULL)
			{
				cout << tmp->name << " - ";

				tmp = tmp->next;
			}

			cout << endl;
		}
	}

	cout << "End" << endl << endl;
}

bool hash_table_insert(Person* p)	// To add people to the hash table
{
	if (p == NULL) return false;	// Make sure we dont call this function with a nullptr

	int index = hashish(p->name);

	p->next = hash_table[index];

	hash_table[index] = p;

	return true;
}

// Find a person in the table by their name
Person* hash_table_lookup(string name)
{
	int index = hashish(name);

	Person* tmp = hash_table[index];

	while (tmp != NULL && NULL && hash_table[index]->name == name) // index?
	{
		tmp = tmp->next;
	}

	return tmp;
}

Person* hash_table_delete(string name)
{
	int index = hashish(name);

	Person* tmp = hash_table[index];
	Person* prev = NULL;

	while (tmp != NULL && NULL && hash_table[index]->name == name) // index?
	{
		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp == NULL) return NULL;

	if (prev == NULL)
	{
		// Deleting the head
		hash_table[index] = tmp->next;
	}
	else
	{
		prev->next = tmp->next;
	}

	return tmp;
}

int main()
{
	init_hash_table(); // To make sure the table is empty

	print_table();

	// Person Bob; Bob = { Bob.name = "Bob", Bob.age = 22 }; // Correct



	// Creating people to test if hashTable works 
	Person jacob; jacob = { jacob.name = "Jacob", jacob.age = 256 };
	Person kate; kate = { kate.name = "Kate", kate.age = 27 };
	Person mpho; mpho = { mpho.name = "Mpho", mpho.age = 14 };
	Person sarah; sarah = { sarah.name = "Sarah", sarah.age = 54 };
	Person edna; edna = { edna.name = "Edna", edna.age = 15 };
	Person maren; maren = { maren.name = "Maren", maren.age = 25 };
	Person eliza; eliza = { eliza.name = "Eliza", eliza.age = 34 };
	Person robert; robert = { robert.name = "Robert", robert.age = 1 };
	Person jane; jane = { jane.name = "Jane", jane.age = 75 };

	// Insert these people to the hashTable
	hash_table_insert(&jacob);
	hash_table_insert(&kate);
	hash_table_insert(&mpho);
	hash_table_insert(&sarah);
	hash_table_insert(&edna);
	hash_table_insert(&maren);
	hash_table_insert(&eliza);
	hash_table_insert(&robert);
	hash_table_insert(&jane);


	print_table();

	// Check if a person is in the table
	hash_table_lookup("Mpho");
	hash_table_lookup("George");

	hash_table_delete("Mpho");
	hash_table_lookup("Mpho");
	hash_table_delete("MorenDin");
	hash_table_delete("Mpho");

	print_table();

	return 0;
}