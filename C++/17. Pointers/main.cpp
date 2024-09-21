#include <iostream>
using namespace std;

void getNumber(int *intPointer);
void swapValues(int *a, int *b);
void swapAddresses(int *&a, int *&b);

// Pointers can be the return type of a function - function must not return a pointer to a local variable in the function; should only return a pointer to data
//                                                 that was  passed to the function as an argument or to dynamically allocate memory inside the function
int *newArray(int *&s);

int main()
{
	// Pointers - each variable in a program uses a unique location in memory that has an address. The address operator & is used to access the address of a variable:
	int number = 17;
	cout << &number << endl; // Print the hex address
	cout << "===============================================" << endl;

        // Pointer variable (pointer) - a variable that holds, stores, the address of a memory location. Alternate way to access memory locations. 
	//				Size of pointer for 32 bit the size is 4 bytes and for 64 bit the size is 8 bytes.
	int* intPtr; // Definition - can hold the address of an int or the variable that intptr points to has type int
	intPtr = &number;
	cout << intPtr << endl; // Print the hex address
	cout << *intPtr << endl; // Prints the content of the address which is 17
	*intPtr = 9; // Changes the content of the address from 17 to 9
	cout << *intPtr << endl;
	cout << number << endl;
	cout << "===============================================" << endl;

	// Pointers and Arrays
	int values[3] = { 1, 2, 3 };
	cout << values << endl; // will display the hex address of the first element
	cout << values[0] << endl; // displays 1
	cout << &values[0] << endl; // will display the hex address of the first element
	cout << *values << endl; // will display 1. array name can be used as a constant pointer, so *values can be read as "the value being pointed by values"
	int* valuesPointer = values; // Pointer can be used as an array name
	cout << valuesPointer[2] << endl; // displays 3
	cout << *(valuesPointer + 2) << endl; // displays 3. (address in valuesPointer) + (2 * size of int(this is done automatically))
	cout << *(values + 2) << endl; // displays 3. (address in values) + (2 * size of int(this is done automatically))
	cout << "===============================================" << endl;

	// Array elements
	cout << values[1] << endl; // Access by using []. Array notation
	cout << *(values + 1) << endl; // Access by using subscript arithmetic. Pointer Notation
	cout << valuesPointer[1] << endl; // Pointer to an array and []. Array notation
	cout << *(valuesPointer + 1) << endl; // Pointer to an array and subscript arithmetic. Pointer Notation
	cout << "===============================================" << endl;

	// Pointer Arithmetic
	cout << *valuesPointer++ << endl; // Points 1 then will go to the next address which is the address for int 2
	cout << *valuesPointer-- << endl; // Outputs 2 then will go to the previous address which is the addres for int 1
	cout << *valuesPointer << endl; // Outputs 1
	cout << ++ * valuesPointer << endl; // Will go to the next address which is the address for int 2 and then will output 2
	*valuesPointer -= 1; // Goes to the previous address which is the address for int 1
	cout << *valuesPointer << endl;  // Outputs 1
	valuesPointer += 2; // Skips to the last element
	cout << *valuesPointer << endl; // Outputs 3
	cout << "===============================================" << endl;

	// Pointer Subtraction
	cout << valuesPointer - values << endl; // Will output 2 because is the number of integers between valuesPointer and values
	cout << "===============================================" << endl;

	// Pointer Initialization
	int* integerPointer = 0, * integerPointer2 = NULL; // Can be initialize to zero or null
	int magicNumber, * magicPointer = &magicNumber;
	cout << magicPointer << endl; // Output address of magic number
	*magicPointer = 2; // sets the content of magic number by using a pointer
	cout << *magicPointer << endl; // outputs the content of magic number by using a pointer
	cout << magicNumber << endl; // outputs the content of magic number
	cout << "===============================================" << endl;

	// Pointer comparison
	int value = 80, value2 = 40,
		* intPointerValue = &value, *intPointerValue2 = &value2;

	if (intPointerValue < intPointerValue2) // Compares the addresses
	{
		cout << "Comparing the addresses, intPointerValue2 has the bigger address" << endl;
	}
	else
	{
		cout << "Comparing the addresses, intPointerValue has the bigger address" << endl;
	}

	if (*intPointerValue < *intPointerValue2)
	{
		cout << "Comparing the values, intPointerValue2 has the bigger value" << endl;
	}
	else
	{
		cout << "Comparing the values, intPointerValue has the bigger value" << endl;
	}
	cout << "===============================================" << endl;

	// Pointer in Functions - Pointers can be parameter and they work like reference parameter to allow changes to argument from within a function. Must be dereference to access content of the address
	int number1, number2= 20, *intPointer1 = &number1, *intPointer2 = &number2;
	getNumber(intPointer1);
	cout << number1 << endl;
	cout << "===============================================" << endl;
	cout << "Swaping values..." << endl;
	swapValues(intPointer1, intPointer2);
	cout << "Number1: " << number1 << endl;
	cout << "Number2: " << number2 << endl;
	cout << "intPointer1: " << intPointer1 << " pointing to number1: " << *intPointer1 << endl;
	cout << "intPointer2: " << intPointer2 << " pointing to number2: " << *intPointer2 << endl;
	cout << "===============================================" << endl;
	cout << "Swaping addresses..." << endl;
	swapAddresses(intPointer1, intPointer2);
	cout << "Number1: " << number1 << endl;
	cout << "Number2: " << number2 << endl;
	cout << "intPointer1: " << intPointer1 << " << pointing to number2 now: " << *intPointer1 << endl;
	cout << "intPointer2: " << intPointer2 << " << pointing to number1 now: " << *intPointer2 << endl;
	cout << "===============================================" << endl;

	// Pointers to Constants - The value stored in the location where the pointer is pointing is a constant. The value cannot be change after its initialized
	const float dollars[] = {100.55, 200.50};
	const float *pointerDollar = dollars; // Can be read as: pointerDollar is a pointer to a constant that is a float
		// *pointerDollar = 20; // Won't compile

	// Constant Pointer - The address in the pointer cannot change after the pointer is initialized
	int maxNumber = 20;
	int *const pointerMaxNumber = &maxNumber; // Can be read as: pointerMaxNumber is a constant pointer to an integer
	*pointerMaxNumber = 80; // The value at the address can change
		//pointerMaxNumber = &a;// The address in the pointer cannot change.
	cout << *pointerMaxNumber << endl;
	cout << "===============================================" << endl;

	// Constant Pointer to Constant - The value stored in the location where the pointer is pointing is constant and the addres in the pointer cannot be change
	const int size = 39;
	const int *const pointerToSize = &size; // Can be read as: pointerToSize is a constant pointer to a constant integer
		//pointerToSize = &a;   // The address in the pointer cannot change
		//*pointerToSize = 23;  // The value at the address cannot change

	// Dynamic Memory Allocation - allocating storage for a variable while the program is running
	int *arraySize = new int; // new operator allocates memory dynamically and returns the address of the location
	cout << "Enter array desired size: ";
	cin >> *arraySize;
	int *dynamicArray = new int[*arraySize];

	for (int i = 0; i < *arraySize; i++)
	{
		cout << "Enter score " << i+1 << ": ";
		cin >> dynamicArray[i];
	}
	for (int i = 0; i < *arraySize; i++)
	{
		cout << "Score " << i + 1 << ": " << dynamicArray[i] << endl;
	}

	// Releasing Dynamic Memory - keyword 'delete' to free dynamic memory, 'delete []' for arrays
	cout << "Deleating dynamic memory...\n";
	delete arraySize;
	delete [] dynamicArray;

	// Returning Pointers from functions
	int* arraySize2 = new int; // new operator allocates memory dynamically and returns the address of the location
	cout << "Enter array desired size: ";
	cin >> *arraySize2;
	int* array1 = newArray(arraySize2);
	for (int i = 0; i < *arraySize2; i++)
	{
		cout << "Enter score " << i + 1 << ": ";
		cin >> array1[i];
	}
	for (int i = 0; i < *arraySize2; i++)
	{
		cout << "Score " << i + 1 << ": " << array1[i] << endl;
	}
	delete arraySize2;
	delete [] array1;
	return 0;
}

void getNumber(int* intPointer)
{
	cout << "Input a number: ";
	cin >> *intPointer;
}

void swapValues(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swapAddresses(int *&a, int *&b)
{
	int *temp = a;
	a = b;
	b = temp;
}

int *newArray(int *&s)
{
	int *dynamicArray = new int[*s];
	return dynamicArray;
}
