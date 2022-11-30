#include "main.h"


DynArray<int> MainArray;

void PrintArray();

void SortMenu();
void AddToArray();
void DeleteFromArray();
void SearchArray();

void ClearCin();

int main()
{
std::cout << "Welcome to my dynamic array learning project!" << std::endl;

	//Array, not sortedm initialized as an int array.
MainArray.AddToArray(1);
MainArray.AddToArray(3);
MainArray.AddToArray(5);
MainArray.AddToArray(2);
MainArray.AddToArray(4);
MainArray.AddToArray(6);

	PrintArray();
	std::cout << std::endl;

	bool runProgram = true;

do
{
	system("cls");
	PrintArray();
		std::cout << "Please select your option: " << std::endl;
		std::cout << "1: Add to array " << std::endl;
		std::cout << "2: ????Delete from array " << std::endl;
		std::cout << "3: Search in array " << std::endl;
		std::cout << "4: Sort array " << std::endl;

		char menuSelection{};
	std::cin >> menuSelection;

		switch (menuSelection)
		{
			//Add to Array
		case '1':
		ClearCin();
		std::cout << "Selected add to array" << std::endl;
		AddToArray();
		break;
			//Delete from array
		case '2':
			ClearCin();
			std::cout << "Selected delete from array" << std::endl;
			DeleteFromArray();
			break;
			//Runs search function
		case '3':
			ClearCin();
			std::cout << "Selected search in array" << std::endl;
			SearchArray();
			break;
			//Runs sorting
		case '4':
			ClearCin();
			std::cout << "Selected sorting option" << std::endl;
			SortMenu();
			break;
		default:
			std::cout << "Nothing entered, try again" << std::endl;
			ClearCin();
		}

		
	
}
while (runProgram);
	return 0;
}

void PrintArray()
{
	for (int i = 0; i < MainArray.ArrayNumOfElem; i++)
		std::cout << MainArray[i] << " " << std::endl;
}


void SortMenu()
{
	char Selection = 0;
	std::cout << "Select your sorting method: " << std::endl;
	std::cout << "1: Selectionsort " << std::endl;
	std::cout << "2: Quicksort " << std::endl;
	std::cout << "3: Bubblesort " << std::endl;
	std::cout << "4: Insertionsort " << std::endl;
	std::cin >> Selection;

	switch (Selection)
	{
	case '1':
		MainArray.SelectionSort();
		break;
	case '2':
		MainArray.QuickSort(0, MainArray.ArrayMaxSize-1);
		break;
	case '3':
		MainArray.BubbleSort();
		break;
	case '4':
		MainArray.InsertionSort();
		break;
	default:
		break;
	}
}

void ClearCin()
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}

void AddToArray()
{
	int Selection;
	std::cout << "Add to array selected, please enter what you wish to add to the array (array has been initialized as int array): " << std::endl;
	std::cin >> Selection;
	MainArray.AddToArray(Selection);

	std::cout << "Array is now: " << std::endl;
	PrintArray();

}

void DeleteFromArray()
{
	int Selection = 0;
	std::cout << "Selected delete from array,  " << std::endl;
	std::cin >> Selection;

	MainArray.RemoveElement(Selection);
}

void SearchArray()
{
	int Selection = 0;
	std::cout << "Selected Search array, (this way is only usable for int at this time, search works, just not this input method for other types): " << std::endl;
	std::cin >> Selection;

	MainArray.SearchArray(Selection);
}
