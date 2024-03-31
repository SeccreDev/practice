#include <iostream>
#include <fstream>
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

	// Getting array data from a file
	int sales[SIZE];
	ifstream dataFile("sales.dat");
	if (!dataFile)
		cout << "Error opening data file\n";
	else
	{
		// Input from file to the array
		for (int i = 0; i < SIZE; i++)
		{
			dataFile >> sales[i];
		}
		// Outputting the array's content
		for (int i = 0; i < SIZE; i++)
		{
			cout << sales[i] << endl;
		}
		dataFile.close();
	}

	// No bound checking - there are no checks in c++ that an array subscript is in range. An invalid array subscript can cause program to overwrite other memory
	int num[SIZE]; // Index is 0 to 9
	//num[10] = 25; // Not valid

	// Array initialization with a list
	int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// Partial Array Initialization
	int numbers2[SIZE] = { 0, 20, 40 }; // Array is initialized with fewer values than the size declarator, remaining elements will be set to 0 or empty string
	cout << numbers2[3]; // Outputs 0


	return 0;
}