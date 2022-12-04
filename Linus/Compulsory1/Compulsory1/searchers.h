#pragma once
#include <iostream>

template<typename T>
void linearSearch(T* arr, int N, int x) {
	std::cout << "Linear searching\n" << std::endl;
	
	for (int i = 0; i < N; i++) {
		if (arr[i] == x) {
			std::cout << "Element " << x << " is at index " << i << std::endl;
			return;
		}
	}
	std::cout << "Element " << x << " could not be found in the array" << std::endl;
	

}

// Iterative
template<typename T>
void binarySearchIterative(T* arr, int l, int r, int x) {
	std::cout << "Iterative binary searching\n" << std::endl;

	while (l <= r) {
		int mid = (l + r) / 2;

		// Found what we searched for
		if (x == + arr[mid]) {
			std::cout << "Found " << x << " at index " << mid << std::endl;
			return;
		}
		else if (x > arr[mid]) { // x is on the right side

			l = mid + 1;
		}
		else { // x is on the left side
			r = mid + 1;
		}
	}
}


// Recursive (Divide and conquer style)
template<typename T>
void binarySearchRecursive(T* arr, int l, int r, int x) {

	std::cout << "Recursive binary searching\n" << std::endl;
	
	int mid = (l + r) / 2;

	for (int i = l; i <= r; i++) {
		if (l >= r || mid != x) {
			
			std::cout << "Element " << x << " could not be found in the array" << std::endl;
		}
		else {
		}
		int mid = (l + r) / 2;
		
		std::cout << "Element " << x << " is at index " << i << std::endl;
	}
}