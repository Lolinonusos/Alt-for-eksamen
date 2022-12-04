#include <iostream>

using namespace std;
/*

//#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (Person*) (0xFFFFFFFFFFFFFFFFUL) // trying nullptr instead


//typedef struct Person Person; // Do I have to type it twice? 

struct Person // Not sure if typedef is needed here 
{
	string name; // string name[MAX_NAME]
	int age;
	//...can add more stuff later, maybe
	bool deletedPerson = false;
};

Person* hash_table[TABLE_SIZE]; 
 
unsigned int hashish(string name) // Using hash was ambiguous
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
			//printf("\t%i\t---\n", i); 
			cout << "\t" << i << "\t---\n";
		}
		else if (hash_table[i] == DELETED_NODE)
		{
			cout << "\t" << i << "\t--- <deleted>" << endl;
		}
		else
		{
			//printf("\t%i\t%s\n", hash_table[i]->name);
			cout << "\t" << i << "\t" << hash_table[i]->name << endl; 
		}
	}

	cout << "End" << endl << endl;
}

bool hash_table_insert(Person* p)	// To add people to the hash table
{
	if (p == NULL) return false;	// Make sure we dont call this function with a nullptr

	int index = hashish(p->name); 

	for (int i = 0; i < TABLE_SIZE; i++) // Making sure to find a new location for the person should the index be occupied 
	{
		int searchTry = (i + index) % TABLE_SIZE;

		if (hash_table[searchTry] == NULL || hash_table[searchTry] == DELETED_NODE) 
		{
			hash_table[searchTry] = p;

			return true;
		}
	}

	//if (hash_table[index] != NULL)
	//	return false;				// Means something is already stored here so we cant store anything else.

	//hash_table[index] = p;
	//
	//return true;

	return false;
}

// Find a person in the table by their name
Person* hash_table_lookup(string name)
{
	int index = hashish(name);

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		int searchTry = (i + index) % TABLE_SIZE;

		if (hash_table[searchTry] == NULL)
		{
			//return false; // It is not here
			cout << "Person named " << name << " not found" << endl;
			return NULL;
		}

		if (hash_table[searchTry] == DELETED_NODE)
		{
			cout << name << " was already deleted" << endl;

			continue;
		}

		if (hash_table[searchTry] != NULL && hash_table[searchTry]->name == name)
		{
			//cout << "HashTable[searchTry] adress: " << hash_table[searchTry] << endl;

			cout << "Found " << name << " at index " << index << endl;

			return hash_table[searchTry];
		}
	}

	return NULL;

	//if (hash_table[index] != NULL && hash_table[index]->name == name)
	//{
	//	//cout << "Found " << name << " at index " << hash_table[index] << endl; // returns index as memory location
	//	cout << "Found " << name << " at index " << index << endl;

	//	return hash_table[index];
	//}
	//else
	//{
	//	cout << "Person named " << name << " not found" << endl;

	//	return NULL;
	//}
}

Person* hash_table_delete(string name)
{
	int index = hashish(name);

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		int searchTry = (i + index) % TABLE_SIZE;

		if (hash_table[searchTry] == NULL) return NULL;

		if (hash_table[searchTry] == DELETED_NODE)
		{
			//cout << name << " has already been deleted" << endl;

			continue;
		}

		if (hash_table[searchTry]->name == name)
		{
			Person* tmp = hash_table[searchTry];
			//hash_table[searchTry] = DELETED_NODE; 
			//cout << "HashTable[searchTry] adress: " << hash_table[searchTry] << endl;

			hash_table[searchTry] = DELETED_NODE;

			return tmp; 
		}
	}

	return NULL;


	/*int index = hashish(name);

	if (hash_table[index] != NULL && hash_table[index]->name == name)
	{
		Person* tmp = hash_table[index];
		hash_table[index] = NULL;

		cout << "Deleted person named " << name << " from the list" << endl;

		return tmp;
	}
	else
	{
		hash_table_lookup(name);
		cout << "Can not delete persons that does not exists" << endl;

		return NULL;
	}
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

	//cout << "Jacob => " << hashish("Jacob") << endl; 
	////printf("Jacob => %u\n", hashish("Jacob")); 
	//cout << "Natalie => " << hashish("Natalie") << endl;
	//cout << "Bob => " << hashish("Bob") << endl;
	//cout << "Tr => " << hashish("Tr") << endl;
	//cout << "Aa => " << hashish("Aa") << endl;
	//cout << "Bb => " << hashish("Bb") << endl;
	//cout << "Cc => " << hashish("Cc") << endl;

	return 0;
}

*/ 