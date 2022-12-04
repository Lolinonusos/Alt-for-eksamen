#pragma once
#include <iostream>

template <typename T>
void swap(T* xp, T* yp) {
    T temp_arrey = *xp;
    *xp = *yp;
    *yp = temp_arrey;
}


template<typename T>
void selectionSort(T* arr, int n) {
    std::cout << "Selection sorting \n" << std::endl;

    // Loops through the array
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
		
        // Find element of lowest value
        for (int j = i +1; j < n; j++) {
            // Keeps track of current lowest element
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swaps positions of elements
        // Seems to work fine without if statement?
        //	if (minIndex != i) {
        swap(&arr[minIndex], &arr[i]);
        //	}
    }
}


template<typename T>
void bubbleSort(T* arr, int n) {

    // Bubble sort seems to be better for smaller arrays
    // bools for optimization
    
    
    std::cout << "Bubble sorting \n" << std::endl;
	
    //bool swapped;
    for(int i = 0; i < n; i++) {

        //swapped = false;

        for(int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                //swapped = true;
                
                swap(&arr[j], &arr[j + 1]);
		
            }
        }
    }
}


template<typename T>
void merge(T* arr, const int begin, const int middle, const int end) {
    
}
template<typename T>
void mergeSort(T* arr, const int begin, const int end) {

    std::cout << "Merge sorting\n" << std::endl;
	
    if (begin > end) {
        return;
    }
	
    auto middle = (begin + end) / 2;
	
    mergeSort(arr, begin, middle);
    mergeSort(arr, middle + 1, end);
    merge(arr, begin, middle, end);
}


template <typename T>
int partition(T* arr, int begin, int end) {

    int pivot = arr[end];
    int i = (begin - 1); // Index of smaller element and indicates the right

    for (int j = begin; j <= end - 1; j++) {

        // Element is smaller than pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
		
    }

    swap(&arr[i + 1], &arr[end]);
    return(i + 1);
}
template <typename T>
void quickSort(T* arr, int begin, int end) {

    std::cout << "Quick sorting \n" << std::endl;

    if(begin < end) {

        // pi becomes the pivot point in the partition function
        int pi = partition(arr, begin, end);

        // Separately sort elements before and after partition
        quickSort(arr, begin, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}


template <typename T>
void heapify(T* arr, int N, int i) {

    // Largest shall become the root of the heap
    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than root
    if (right < N && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root of the heap
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub tree
        heapify(arr, N, largest);
    }
}
template <typename T>
void heapSort(T* arr, int N) {

    std::cout << "Heap sorting\n" << std::endl;

    // Create a heap of the array
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }
	

    // Extract elements one by one from the heap
    for (int i = N - 1; i > 0; i--) {

        // Swaps highest value towards the root
        swap(&arr[0], &arr[i]);
		
        // Call max heapify on reduced heap
        heapify(arr, i, 0);
    }
}



