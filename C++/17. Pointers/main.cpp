#include <iostream>
using namespace std;

int main()
{
	// Pointers - each variable in a program uses a unique location in memory that has an address. The address operator & is used to access the address of a variable:
	int number = 17;
	cout << &number << endl; // Print the hex address

    // Pointer variable (pointer) - a variable that holds, stores, the address of a memory location. Alternate way to access memory locations. 
	//								Size of pointer for 32 bit the size is 4 bytes and for 64 bit the size is 8 bytes.
	int* intPtr; // Definition - can hold the address of an int or the variable that intptr points to has type int
	intPtr = &number;
	cout << intPtr << endl; // Print the hex address
	cout << *intPtr << endl; // Prints the content of the address which is 17
	*intPtr = 9; // Changes the content of the address from 17 to 9
	cout << *intPtr;

	return 0;
}