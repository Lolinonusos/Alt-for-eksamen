#include <iostream>

using namespace std;


// Merge sort: https://www.geeksforgeeks.org/merge-sort/

/*

// Based on the Divide and Conquer paradigm. In this algo, the array is initially divided
// into two equal halves and then they are combined in a sorted manner.
// 
// Working process:
// As a recursive algorithm continously splits the array in half until it cannot be further
// divided. Which means that if the array becomes empty or has only one element left, the
// dividing will stop, that is the base case to stop the recursion. If the array has multiple
// elements, split the array into halves and recursively invoke the merge sort on each of 
// the halves. Finally when both halves are sorted, the merge operation is applied. Merge 
// operation is the process of taking two smaller sorted arrays and combining them to 
// eventually make a larger one.
// 
// 
// arr[] = {38, 27, 43, 3, 9, 82, 10}
// 
// At first, check if the left index of array is less than the right index, if yes then
// calculate its mid point. 
// 
// l = Left index		r = Right index
// 
// is i < r
// Yes
// m = i + (r - 1) / 2
// 
// The merge sort first divides the whole array iteratively (do it again and again, to improve)
// into equal halves, unless the atomic values are achieved.
// 
// Here our array is 7 items, so it is divided into two arrays of size 4 and 3 respectively.
// 
// Again, find if left index is less than the right index for both arrays, if yes, then again
// calculate mid points for both the arrays. 
// 
//					{38, 27, 43, 3, 9, 82, 10}
//		{38, 27, 43, 3}						{9, 82, 10}
// 
// Further divide these two arrays into further halves, until the atomic units of the array is
// reached and further division is not possible. 
// 
//	  {38, 27}			{43, 3}				{9, 82}			{10}
// {38}		{27}	  {43}	  {3}		   {9}	 {82}
// 
// After dividing the array into the smallest units, start merging the elements again based on 
// comparison of size of elements.
// Firstly, compare the element for each list and then combine them into another list in a 
// sorted manner.
// 
// {38}		{27}		{43}	{3}			{9}		{82}
//	  {27, 38}			   {3, 43}			  {9, 82}	{10}
//			 {3, 27, 38, 43}					{9, 10, 82}
//						{3, 9, 10, 27, 38, 43, 82}
// 
// ALGO -----------------------------------------------------------------------------------------------
// 
// 1. Start
// 2. Declare array and left, right, mid variable
// 3. Perform merge function
//		if left > right
//			return
//		mid = (left + right) / 2
//		mergesort(array, left, mid)
//		mergesort(array, mid + 1, right)
//		merge(array, left, mid, right)
// 4. Stop
// 
// 
// Follow these steps:
// 
// mergeSort (arr[], l, r)
// If r > l
// 
// Find the middle point to divide the array into two halves:
//		middle m = l + (r - l) / 2
// Call mergeSort for first half:
//		Call mergeSort(arr, l, m) 
// Call mergeSort for second half:
//		Call mergeSort(arr, m + 1, r)
// Merge the two halves sorted in steps 2 and 3:
//		Call merge(arr, l, m, r)
//


// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne], * rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto
		indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left;	// Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

			indexOfSubArrayOne++;
		}

		else
		{
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];

			indexOfSubArrayTwo++;
		}

		indexOfMergedArray++;
	}

	// Copy the remaining elements of left[], if there are any
	while (indexOfSubArrayOne < subArrayOne)
	{
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo)
	{
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];

		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is right index of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;		// Return recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// Utility functions
// Function to print an array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);

	return 0;
}

// Time complexity
//
// O(N log(N)), sorting arrays on different machines. Merge Sort is a recursive algo and the 
// time complexity can be expressed as following recurrence relation.
// 
// T(n) = 2T(n/2) + 0(n)
//

*/
