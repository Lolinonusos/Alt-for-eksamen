#include <iostream>

using namespace std;

// Bubble sort: https://www.geeksforgeeks.org/bubble-sort/

/*
// How it works --------------------------------------------------------------------------

// Bubble sort is the simplest sorting algorithm that works by repeatedly swapping 
// the adjacent elements if they are in the wrong order. This algorithm is not suitable
// for large data sets as its average and worst-case time complexity is quite high.
//
// 
// Input: arr[] = {5, 1, 4, 2, 8}
// 
// 1. Bubble starts with every first two elements, 
//	  comparing them to check which one is greater.
//	  
//		(5 1 4 2 8) -> (1 5 4 2 8), Here, algo compares the first two elements,
//									and swaps since 5 > 1.
//		(1 5 4 2 8) -> (1 4 5 2 8), Swap since 5 > 4.
//		(1 4 5 2 8) -> (1 4 2 5 8), Swap since 5 > 2.
//		(1 4 2 5 8) -> (1 4 2 5 8), Does not swap, since they are in order.
// 
// 2. Now during second iteration it should look like this:
//		(1 4 2 5 8) -> (1 4 2 5 8)
//		(1 4 2 5 8) -> (1 2 4 5 8), Swap since 4 > 2.
//		(1 2 4 5 8) -> (1 2 4 5 8)
//		(1 2 4 5 8) -> (1 2 4 5 8)
// 
// 3. Now, the array is already sorted but our algorithm does not know if it is completed.
//	  The algorithm needs one whole pass without any swap to know it is sorted.
//		(1 2 4 5 8) -> (1 2 4 5 8)
//		(1 2 4 5 8) -> (1 2 4 5 8)
//		(1 2 4 5 8) -> (1 2 4 5 8)
//		(1 2 4 5 8) -> (1 2 4 5 8)
//


// How to solve ------------------------------------------------------------------------------------------

void bubblesort(int arr[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place

		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);

	}

}

void printArray(int arr[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 5, 1, 4, 2, 8 };
	int N = sizeof(arr) / sizeof(arr[0]);

	bubblesort(arr, N);

	cout << "Sorted array: \n";

	printArray(arr, N);

	return 0;
}

// Time complexity: O(N^2)
// Auxiliary Space: O(1)



// Optimized Implementation of Bubble Sort:
//		The above function always runs O(N^2) time even if the array is sorted. 
//		It can be optimized by stopping the algorithm if the inner loop did not
//		cause any swap.
//

void bubbleSortOptimized(int arr[], int n)
{
	int i, j;
	bool swapped;

	for (i = 0; i < n - 1; i++)
	{
		swapped = false;

		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped by inner loop, then break
		if (swapped == false)
			break;
	}
}


// Recursive implementation of Bubble Sort -----------------------------------------------------------------------

// 1. Place the largest element at its position, this operation makes sure the 
//	  first largest element will be placed at the end of the array.
// 2. Recursively call for rest n - 1 element with the same operation and 
//    place the next greater element at their position.
// 3. The base condition for this recursion call would be, when the number
//	  of elements in the array becomes 0 or 1 then, simply return (as they are 
//	  already sorted).
// 
// 
// Implementation:
//

void bubbleSortRecursive(int arr[], int n)
{
	if (n == 0 || n == 1)
	{
		return;
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
		}
	}

	bubbleSortRecursive(arr, n - 1);
}

*/
