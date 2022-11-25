#include "MainDeclarations.h"

int RandomArray[40];
	LinkedList LL1;

void PopulateArray();
void PrintList();

int main()
{
	//Poppulating array and sending the information to the linked list
	PopulateArray();
	for (int i = 0; i < 40; i++)
	{
		//LL1.data = RandomArray[i];
		LL1.AddAtEnd(RandomArray[i]);
	}

	//Prints the list both forwards and backwards
	PrintList();
	return 0;
}

void PopulateArray()
{
	std::srand(time(0));
	for (int i = 0; i <= 40; i++)
	{
		RandomArray[i] = rand() % 113;
	}
}

void PrintList()
{
	std::cout << "Print backwards: " << std::endl;
	LL1.PrintDataBackward();

	LL1.DeleteElement(2);
	std::cout << "Print forwards: " << std::endl;

	LL1.PrintDataForward();
}