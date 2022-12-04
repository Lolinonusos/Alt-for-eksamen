#include <iostream>
#include <map>
#include <string>
#include <list> 

using namespace std;

// Map -------------------------------------------------------------------------

// video: https://www.youtube.com/watch?v=aEgG4pidcKU

// Dictionary application

/*
int main()
{
	map<string, string> myDictionary;

	myDictionary.insert(pair<string, string>("apple", "der Apfel"));
	myDictionary.insert(pair<string, string>("banana", "die Banane"));
	myDictionary.insert(pair<string, string>("orange", "die Orange, die Apfelsine"));
	myDictionary.insert(pair<string, string>("strawberry", "die Erdbeere"));

	// Prints the map. Since it is strings, it does it alphabetically (ascending order). If it were numbers it would also be ascending order.
	for (auto pair : myDictionary)
	{
		cout << pair.first << " - " << pair.second << endl;
	}

	// To not have the map be in ascending order we could say:
	//unordered_map<string, string> unorderedMap;
	// However, we then would have to #include <unordered_map>

	// Keys (first) have to be unique. Values (second) does not have to be.
	
	// To alter the value of a Key:
	myDictionary["strawberry"] = "Die Erdbeere";

	// To get the size of the map:
	cout << myDictionary.size() << endl;

	// To delete all elements from the map:
	myDictionary.clear();

	// To delete a single element:
	myDictionary.erase("apple");

	return 0;
}

*/

// Pokedex

/*
int main()
{
	map<string, list<string>> pokedex;

	list<string> pikachuAttacks{ "thunder shock", " tail whip", " quick attack" }; 
	list<string> charmanderAttacks{ "flame thrower", "scary face" };
	list<string> chikoritaAttacks{ "razor leaf", "poison powder" };

	pokedex.insert(pair<string, list<string>>("Pikachu", pikachuAttacks));
	pokedex.insert(pair<string, list<string>>("Charmander", charmanderAttacks));
	pokedex.insert(pair<string, list<string>>("Chikorita", chikoritaAttacks));

	for (auto pair : pokedex)
	{
		cout << pair.first << " - ";

		for (auto attack : pair.second)
			cout << attack << ", ";

		cout << endl;
	}

	return 0;
}

*/