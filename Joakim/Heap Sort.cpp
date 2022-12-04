#include <iostream>

using namespace std;

// Heap sort: https://www.geeksforgeeks.org/heap-sort/

/*

// Similar to Selection sort. Based on Binary heap data structure. We first find
// the minimum element and place the minimum element at the beginning. Repeat for 
// the remaining elements.
// 
// Heap sort is an in-place algortihm. Its typically not stable, but can be made 
// stable. Typically 2-3 times slower than well-implemented QuickSort. The reason
// for slowness is a lack of locality of reference. 
// 
// Advantages: 
//		Efficient - time required increases logarithmically while other algorithms
//					may grow exponentially slower as the number of items to sort 
//					increases.
//		Minimal memory usage
//		Simple to understand.
// 
// Applications of HeapSort: 
//		Mainly used in hybrid algorithms like the IntroSort.
//		Sort a nearly sorted (or K sorted) array.
//		k largest (or smallest) elements in an array.
// 
// Heapify:			
// Heapify is the process of creating a heap data structure from a Binary Tree
// represented using an array. It is used to create Min-Heap or Max-Heap.
// Start from the first index of the non-leaf node whose index is given by n/2.
// Heapify uses recursion.
// 
// Algorithm for Heapify:
// 
//		heapify(array)
//		Root = array[0]
// 
//		Largest = largest(array[0], array[2 * 0 + 1] / array[2 * 0 + 2])
// 
//		if (Root != Largest)
//			Swap (Root, Largest)
// 
// 
// How does Heapify work?
// 
// Array = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
// 
//				Corresponding Complete Binary Tree:
//								1
//							 /	   \
//						   3	     5
//						 /   \	    /   \
//						4      6    13    10
//					  /	 \    /  \
//                   9    8   15  17
// 
// The task to build a Max-Heap from above array.
// 
// Total nodes = 11.
// Last non-leaf node index = (11/2) - 1 = 4.
// Therefore, last non-leaf node = 6.
// To build the heap, heapify only the nodes: [1, 3, 5, 4, 6] in reverse order.
// 
// Heapify 6: Swap 6 and 17.
// Heapify 4: Swap 4 and 9.
// Heapify 5: Swap 13 and 5.
// Heapify 3: First swap 3 and 17, again swap 3 and 15.
// Heapify 1: First swap 1 and 17, again swap 1 and 15, finally swap 1 and 6.
// 
// 
// Heap sort algorithm:
// 
// First convert the array into heap data structure using heapify, than one by 
// one delete the root node of the Max-heap and replace it with the last node 
// in the heap and then heapify the root of the heap. Repeat this process until 
// size of heap is greater than 1.
// 
// Follow the given steps to solve the problem:
//		- Build a max heap from the input data.
//		- At this point, the maximum element is stored at the root of the heap.
//		  Replace it with the last item of the heap followed by reducing the 
//		  size of the heap by 1. Finally, heapify the root of the tree.
//		- Repeat step 2 while the size of the heap is greater than 1.
// 
// Note: The heapify procedure can only be applied to a node if its children nodes
//		 are heapified. So the heapification must be performed in the bottom-up
//		 order.
// 
// 
// Implementation:
//

// To heapify a subtree rooted with node i, which is an index in arr[].
// n is size of heap.
void heapify(int arr[], int N, int i)
{
	// Initialize largest root
	int largest = i;

	// left
	int l = 2 * i + 1;

	// right
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, N, largest);
	}
}

void heapSort(int arr[], int N)
{
	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i > 0; i--)
		heapify(arr, N, i);

	// One by one extract an element from heap
	for (int i = N - 1; i > 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// Call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);

	cout << "Sorted array is \n";
	printArray(arr, N);
}

*/