#include <iostream>

using namespace std;



// Quick sort: https://www.geeksforgeeks.org/quick-sort/

/*

// As Merge sort, Quick sort is a divide and conquer algorithm. Picks an element as a pivot
// and partitions the given array around the picked pivot. There are different versions of
// quickSort that picks pivot in different ways.
// 
//		Always pick the first element as pivot
//		Always pick the last element as a pivot (implemented below)
//		Pick a random element as a pivot
//		Pick median as the pivot
// 
// The key process in quickSort is a partition(). The target of partitions is, given an array
// and an element x of an array as the pivot, put x at its correct position in a sorted array
// and put all smaller elements (smaller than x) before x, and put all greater elements
// (greater than x) after x. All this should be done in linear time. 
// 
// 
//							{10, 80, 30, 90, 40, 50, 70}
//						/	(Partition around 70 (last element))	\
//				{10, 30, 40, 50}								  {90, 80}
//				/	(Partition around 50)			(Partition around 80) \
//			{10, 30, 40}	{}									 {}		  {90}
//			/	(Partition around 40)					
//			{10, 30}		{}
//			/	(Partition around 30)
//		  {10}		{}
// 
// Partition algorithm:
// Following pseudo-code adopts the method given in the CLRS book. Logic is that we satrt 
// from the leftmost element and keep track of the index of smaller (or equal to) elements 
// as i. While traversing, if we find a smaller element, we swap the current element with 
// arr[i]. Otherwise, we ignore the current element.
// 
// Pseudo-code for recursive quickSort function:
// // low -> starting index, high -> ending index
// 
// quicSort(arr[], low, high)
// {
//		if (low < high) 
//		{
//			// pi is partitiong index, arr[pi] is now at right place
//			pi = partition(arr, low, high);
//			quickSort(arr, low, pi - 1);  // Before pi
//			quickSort(arr, pi + 1, high); // After pi
//		}
// }
// 
// Pseudo-code for partition():
// // This function takes last element as pivot, places the pivot element at its correct 
// // position in sorted array, and places all smaller (smaller than pivot) to left of pivot 
// // and all greater elements to right of pivot.
// 
// partition (arr[], low, high)
// {
//		// pivot (Element to be placed at right position)
//		pivot = arr[high];
// 
//		i = (low - 1) // index of smaller element and indicates the right position of pivot 
//						 found so far
//		for (j = low; j <= high - 1; j++)
//		{
//			// if current element is smaller than the pivot
//			if (arr[j] < pivot)
//			{
//				i++; // increment index of smaller element
//				swap arr[i] and arr[j]
//			}
//		}
//		swap arr[i + 1] and arr[high]
//		return (i + 1)
// }
// 
// 
// Implementation:

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// This function takes last element as pivot, places the pivot element at its correct
// position in sorted array, and places all smaller (smaller than pivot) to left of pivot
// and all greater elements to right of pivot
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];	// pivot
	int i = (low - 1); // index of smaller element and indicates the right position of pivot
					   // found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++;	// Increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// The main function that implements quickSort
// arr[] --> Array to be sorted,
// low --> starting index,
// high --> ending index
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		// pi is partitioning index, arr[p] is now at right place
		int pi = partition(arr, low, high);

		// Separately sort elements before partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Hoare's partition scheme:
//This function takes first element as pivot, and places all the elements smaller than the 
// pivot on the left side and all the elements greater than the pivot on the right side.
// It returns the index of the last element on the smaller side.
int hoarePartition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	while (true)
	{
		// Find leftmost element greater than or equal to pivot
		do
		{
			i++;
		} while (arr[i] < pivot);

		// Find rightmost element greater than or equal to pivot
		do
		{
			j--;
		} while (arr[j] < pivot);

		// If two pointers met.
		if (i >= j)
			return j;

		swap(arr[i], arr[j]);
	}
}

// Hoare:
void hoareQuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		// pi is partitioning index, arr[p] is now at right place
		int pi = partition(arr, low, high);

		// Separately sort elements before partition and after partition
		hoareQuickSort(arr, low, pi);
		hoareQuickSort(arr, pi + 1, high);
	}
}

// Function to print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Hoare print:
void hoarePrintArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver code
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);

	// Hoare
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	hoareQuickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	hoarePrintArray(arr, n);

	return 0;
}

*/

// Note:
/*  If we change Hoare’s partition to pick the last element as pivot, then the Hoare’s
	partition may cause QuickSort to go into in an infinite recursion. For example, 
	{10, 5, 6, 20} and pivot is arr[high], then returned index will always be high and 
	call to same QuickSort will be made. To handle a random pivot, we can always swap that 
	random element with the first element and simply follow the above algorithm.
*/

// Comparison
/*  1. Hoare’s scheme is more efficient than Lomuto’s partition scheme because it does three 
	   times fewer swaps on average, and it creates efficient partitions even when all values 
	   are equal.
	2. Like Lomuto’s partition scheme, Hoare partitioning also causes Quick sort to degrade 
	   to O(n^2) when the input array is already sorted, it also doesn’t produce a stable sort.
	3. Note that in this scheme, the pivot’s final location is not necessarily at the index 
	   that was returned, and the next two segments that the main algorithm recurs on are 
	   (lo..p) and (p+1..hi) as opposed to (lo..p-1) and (p+1..hi) as in Lomuto’s scheme.
	4. Both Hoare’s Partition, as well as Lomuto’s partition, are unstable.

	Hoare vs Lomuto: https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/
*/