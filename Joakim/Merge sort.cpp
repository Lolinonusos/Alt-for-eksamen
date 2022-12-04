#include <iostream>

using namespace std;

// Merge sort: https://www.geeksforgeeks.org/merge-sort/

// How it works -------------------------------------------------------------------

// Like a recursive algorithm continuously splits the array in half until it
// cannot be further divided. This means that if the array becomes empty or
// has only on eelement left, the dividing will stop, i.e. it is the base 
// case to stop the recursion. If the array has multiple elements, 
// split the array into halves and recursively invoke the merge sort on each ha
//
