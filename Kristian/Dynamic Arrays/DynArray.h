#pragma once

	int MainArray[10] = { 0,1,2,3,4,5,6,7,9 };

	//Information about Array
	int GetValueAt(int index);
	int GetArraySize();
	int SearchArray(int SearchFor);

	//Adding or changing
	void InsertValue(int index, int value);
	void AddToArray(int Value);
	void ExpandArray();

	//Removing

	void RemoveElement();


int ArraySize;
	int ArrayMaxSize;
	int ArrayIndex;
	int ArrayNumOfElem;
