#include <iostream>
#include <string>

using namespace std;

/*

// Understanding templates function and showing it in print functions --------------

// video: https://www.youtube.com/watch?v=I-hZkUa9mIs&t=926s 

// Templates is basically telling the compiler to write code for you based on 
// the rules you have given it, and the usage of the function/class.

// Instead of having to declare different functions for different types, 
// like a print for string, another for int and another for float, we can use templates!

// Instead of having 3 different print functions
//void print(int value)
//{
//	cout << value << endl;
//}
//void print(float value)
//{
//	cout << value << endl;
//}
//void print(string value)
//{
//	cout << value << endl;
//}

// We can convert it to Template instead
template<typename T>
void print(T value)
{
	cout << value << endl;
}

// Class template --------------

template<typename T, int N>
class Array
{
private:
	//int m_Array[N]; // Now we can change the array size at compiletime.
	T m_Array[N];	  // Now the type can also be decided at compiletime

public:
	int GetSize() const { return N; }
};


// Swap function
template<typename Swap>
void swapThis(Swap& a, Swap& b)
{
	Swap temp = a;
	a = b;
	b = temp;
}


int main()
{
	print(1);
	//print(5.5f); 
	//print("Hello");

	// We can specify it more if wanted, but it is not necessary.
	//print<int>(2);

	cout << "---------------------------------------------------------" << endl;

	// Array
	//Array<5> array; // For "int m_Array[N]
	Array<int, 10> array; // Put it to int, but could be float, string...
	cout << array.GetSize() << endl;

	// Swap
	int a = 5, b = 7;
	cout << "Before swap" << endl;
	cout << a << " - " << b << endl;
	swapThis(a, b);
	cout << "After swapping" << endl;
	cout << a << " - " << b << endl;

	char c = 'c', d = 'd';
	cout << "Before swap" << endl;
	cout << c << " - " << d << endl;
	swapThis(c, d);
	cout << "After swapping" << endl;
	cout << c << " - " << d << endl;

	return 0;
}

*/