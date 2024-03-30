#include <iostream>
using namespace std;

int main()
{
	/// Array - variable that can store multiple values of the same type. Values are stored in consecutive memory locations
	const int SIZE = 10;
	int tests[SIZE]; // The array has 10 number of int elements from 0 to 9. These elements must be assigned. size of array in bytes = number of elements(10) * bytes needed for each element (4 for int) = 40 bytes
	
	// Each array element has an index used to access individual elements stored in the array. The first subscript is 0 and the last subscript is SIZE - 1
	tests[0] = 100; // Assigns 100 to the first element of the array
	cout << "First test score: " << tests[0] << endl; // Prints out the first element of the array: 100
	//cout << tests; // Prints the memory address?
	cout << "Enter second test score: ";
	cin >> tests[1];
	cout << "Second test score: " << tests[1] << endl;

	// Accessing each element of an array with a loop
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Input the score for test number "  << i + 1 << ":";
		cin >> tests[i];
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Test score for test number " << i + 1 << ": " << tests[i] << endl;
	}

	return 0;
}
