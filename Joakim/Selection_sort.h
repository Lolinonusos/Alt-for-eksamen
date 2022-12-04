#pragma once

using namespace std;

// Selection sort: https://www.geeksforgeeks.org/selection-sort/ 


// How it works ----------------------------------------------------------------------------------------

// int arr[] = { 64, 25, 12, 22, 11 }; 

// First the algorithm runs through the whole array from index 0 to 4 in order. 
// By doing this, it finds that 11 is the lowest value 64 and 11 therefore switches 
// positions. 11 goes to index 0.
// 
// arr[] = {11, 25, 12, 22, 64}
// 
// For index 1, where currently 25 sits, the algorithm again searches sequantially.
// It finds that 12 is the second lowest value, so the values swap places.
// 
// arr[] = {11, 12, 25, 22, 64}
// 
// For index 2, where 25 now is present, the algorithm searches again.
// It finds 22 to be the third lowest value, so the values swap places.
// 
// arr[] = {11, 12, 22, 25, 64}
// 
// Same for index 4, where it finds 25 to be the lowest value, so it leaves the
// array as it is.
// 
// Lastly the largest value present in the array automatically get placed at the
// last position in the array.
// The resulted array is the sorted array.
// 
// arr[] = {11, 12, 22, 25, 64}
//


// How to solve -------------------------------------------------------------------------------

// 1. Initialize miminum value (min_idx) to location 0.
// 2. Traverse the array to find the minimum element in the array.
// 3. While traversing if any element smaller than min_idx is found then swap
//	  both values.
// 4. Then, increment min_idx to point to the next element.
// 5. Repeat until the array is sorted.
//


// Implementation ------------------------------------------------------------------------------

// Swap function
//void swap(int* xp, int* yp)
//{
//	int temp = *xp;
//	*xp = *yp;
//	*yp = temp;
//}
//
//void selectionSort(int arr[], int n)
//{
//	int i, j, min_idx;
//
//	// One by one move boundary of unsorted array
//	for (i = 0; i < n - 1; i++)
//	{
//		// Find the minimum element in unsorted array
//		min_idx = i;
//
//		for (j = i + 1; j < n; j++)
//			if (arr[j] < arr[min_idx])
//				min_idx = j;
//
//		// Swap the found element with the first element
//		if (min_idx != i)
//			swap(&arr[min_idx], &arr[i]);
//	}
//}
//
//void printArray(int arr[], int size) 
//{
//	int i;
//
//	for (i = 0; i < size; i++)
//		cout << arr[i] << " ";
//	cout << endl; 
//}
