#pragma once
#include <iostream>
#include "Dynamic.h"

template <class T>
class DynArray
{
public:
	DynArray();
	~DynArray();

	T& operator[](int index);

//void ArrayPrint();


//Information about Array
int SearchArray(T SearchFor);

//Adding or changing
void InsertValue(int index, int value);
void AddToArray(const T& value);
void ExpandArray();

//Removing

void RemoveElement(int index);

public:
	T* PointerMain;
int ArraySize; //Elements in the array
int ArrayMaxSize = 1;	//Current max amount of elements that CAN go in the array
int NextIndex;		
int ArrayNumOfElem;

//Sorting

int low;
int high;

void SelectionSort();

void QuickSort(int low, int high);
int Partition(int low, int high);
void Swap(int* yp, int* xp);


void BubbleSort();

void InsertionSort();

};

template <class T>
DynArray<T>::DynArray()
{
	this->ArrayMaxSize = 1;
	this->ArrayNumOfElem = 0;
	this->NextIndex = 0;

	this->PointerMain = new T[ArrayMaxSize]{};


}

template <class T>
DynArray<T>::~DynArray()
{
	delete[] PointerMain;
}

template <class T>
T& DynArray<T>::operator[](int index)
{
	T* pnewa;
	if (index >= ArrayNumOfElem)
	{
		pnewa = new T[index + 1];

		for (int i = 0; i < NextIndex; i++)
		{pnewa[i] = PointerMain[i];}

		for (int j = NextIndex; j < index + 1; j++)
		{pnewa[j] = 0;}

		ArrayMaxSize = index + 1;

		delete[] PointerMain;
		PointerMain = pnewa;
	}
	if (index > NextIndex)
	{
		NextIndex = index + 1;
	}

	return *(PointerMain + index);
}


template <class T>
int DynArray<T>::SearchArray(T SearchFor)
{

	for (int i = 0; i < ArrayNumOfElem; i++)
	{
		if (PointerMain[i] == SearchFor)
		{
			return i;
		}
	}
	return -1;
}

template <class T>
void DynArray<T>::AddToArray(const T& value)
{
	if (this->ArrayNumOfElem < this->ArrayMaxSize)
	{
		this->PointerMain[this->ArrayNumOfElem++] = value;
		//ArrayNumOfElem++;
	}
	else
	{
		this->ExpandArray();
		this->PointerMain[this->ArrayNumOfElem++] = value;
	}
}

template <class T>
void DynArray<T>::ExpandArray()
{
	ArrayMaxSize += 1;
	T* TempArray = new T[ArrayMaxSize];

	for (int i = 0; i < this->ArrayNumOfElem; i++)
	{
		TempArray[i] = PointerMain[i];	//Creates the temp array
	}

	delete[] PointerMain;		//Replaces current main with the temp array.
	PointerMain = TempArray;
}

template <class T>
void DynArray<T>::RemoveElement(int index)
{
	if (index == ArrayNumOfElem)
	{
		PointerMain[index] = NULL;
		ArrayNumOfElem--;
	}
	else if (index < ArrayNumOfElem)
	{
		T* TempArray = new T[ArrayMaxSize];
			int j = 0;
		for (int i = 0; i < this->ArrayNumOfElem; i++)
		{
			if (index != i)
			{
			TempArray[j] = PointerMain[i];	//Creates the temp array
			j++;
			}
			else
			{
				//j++;
			}
		}
		this->ArrayNumOfElem -= 1;
			delete[] PointerMain;		//Replaces current main with the temp array.
			PointerMain = TempArray;
	}
	else
	{
		std::cout << "Index out of boundary, nothing deleted" << std::endl;
	}
}

template <class T>
void DynArray<T>::SelectionSort()
{
	for (int i = 0; i < ArrayMaxSize - 1; i++)
	{
		int minIndex = i;

		for(int j= i + 1; j < ArrayMaxSize; j++)
		{
			if (PointerMain[j] < PointerMain[minIndex])
			{
				minIndex = j;
			}
		}
		Swap(&PointerMain[minIndex], &PointerMain[i]);
	}
}

template <class T>
void DynArray<T>::QuickSort(int low, int high)
{
	if (low < high)
	{
		int ParInd = Partition(low, high);
		QuickSort(low, ParInd - 1);
		QuickSort(ParInd + 1, high);
	}

}

template <class T>
int DynArray<T>::Partition(int low, int high)
{
	int pivot = PointerMain[high];
	int i = (low - 1);

	for (int j = low; j <= high -1; j++)
	{
		if (PointerMain[j] < pivot)
		{
			i++;
			Swap(&PointerMain[i], &PointerMain[j]);
		}
	}
	Swap(&PointerMain[i + 1], &PointerMain[high]);
	return (i + 1);
}

template <class T>
void DynArray<T>::Swap(int* yp, int* xp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

template <class T>
void DynArray<T>::BubbleSort()
{
	for(int i = 0; i <ArrayMaxSize - 1; i++)
	{
		for(int j = 0; j < ArrayMaxSize - i - 1; j++)
		{
			if (PointerMain[j] > PointerMain[j + 1])
			{
				Swap(&PointerMain[j], &PointerMain[j + 1]);
			}
		}
	}
}

template <class T>
void DynArray<T>::InsertionSort()
{
	for (int i = 1; i < ArrayNumOfElem; i++)
	{
		T TempArr = PointerMain[i];
		int j = i - 1;

		while (j >= 0 && TempArr <= PointerMain[j])
		{
			PointerMain[j + 1] = PointerMain[j];
			j = j - 1;
		}
		PointerMain[j + 1] = TempArr;
	}

}
