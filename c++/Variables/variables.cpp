#include <iostream>
#include <string> // To create and use string objects
using namespace std;

int main()
{
	// Variable are symbolic names that refer to a physical memory addresses that we use to store values.
	// This is a variable DECLARATION. Consists of a dataType variableName. The data type is int(store an integer value) and the given name is "quantity" 
	int quantity; // Identifier (name of the variable) first character must be a letter or underscore; it can have digits but not as first character.

	// This is a variable INITIALIZATION. variableName = value assigned
	quantity = 20;

	// You can declare and initialize variable in a single line
	int quantity2 = 25;

	// You can perform math operations (+, -, *, /, %)
	int sum = quantity + quantity2;
	cout << "Quantity: " << quantity << endl;
	cout << "Quantity 2: " << quantity2 << endl;
	cout << "Sum of both: " << sum << endl;

	// Data types
	// int datatype: The value it can hold is the set of all whole numbers. Valid: 5, -19, 10, 0   Invalid: 2.4, 3.0
	// unsigned integer type values are always positive.
	int integerType = 10000; // Size = 4 bytes = 32 bits. Usual Range: -2147483648 to 2147483647
	unsigned int unsignedInt = 40000; // Size = 4 bytes = 32 bits. Usual Range: 0 to 4294967295  
	short shortInteger = -2000; // Size = 2 bytes = 16 bits. Usual Range: -32768 to 32768
	unsigned short unsignedShort = 60000; // Size = 2 bytes = 16 bits. Usual Range: 0 to 65535
	long int longInt = 3455; // Size = 8 bytes = 64 bits. Usual Range: -9223372036854775808 to 9223372036854775807
	unsigned int unsignedLongInt = 89089084; // Size = 8 bytes = 64 bits. Usual Range: 0 to 18446744073709551615
	long long int longLongInt = 879405412; // Size = 8 bytes = 64 bits. Usual Range: -(2^63) to (2^63)-1
	unsigned long long int unsignedLongLongInt = 7454654654; // Size = 8 bytes = 32 bits. Usual Range: 0 to 18,446,744,073,709,551,615 

	// float datatype: The value it can hold is the set of all real numbers. Any positive/negative number with floating points.  Can be also written in exponential notation
	float floatType = 5.5; // Size = 4 byte = 32 bits. Usual Range: -3.4e-38 to 3.4e+38 (7 digits) 
	double doubleType = 5.5200; // Size = 8 byte = 64 bits. Usual Range: -1.7e-308 to 1.7e+308 (16 digits) 
	long double longDouble = 4.120; // Size = 8 byte = 64 bits. Usual Range: -1.7e-308 to 1.7e+308 (16 digits but may provide more precision) 

	// char datatype: The value it can hold consists of single characters. Letters of the alphabet (uppercase/lowercase), Digits (0 to 9), and special symbols
	char charType = 'A'; // Size = 1 byte = 8 bits. Usual Range: -127 to 127 or 0 to 255
	unsigned char unsignedCharType = 'b'; // Size = 1 byte = 8 bits. Usual Range: 0 to 255

	// string datatype: The value it can hold consists of sequence of characters, these characters are stored in memory next to each other
	string name = "SeccreDev"; // Size = In Microsoft Visual Studio it is 40 bytes = 320 bits
	cout << name << endl;

	// bool datatype: The value it can hold represents boolean (logical) data, restricted to 'true' or 'false' values. false is represented by 0, true by 1
	bool incomplete = false; // If we were to output it to the console a 0 will appear
	bool completed = true; // If we were to output it to the console a 1 will appear

	// Using sizeof operator to get the size in number of bytes of any datatype or variable
	cout << "Size of string: " << sizeof(string) << " bytes" << endl;
	
	// Declaring and initializing some variables. Variable cannot be used before it is declared
	string username = "Rope", animal = "Cat", vehicle;
	
	cout << "Username: " << username << endl
		 << "Animal: " << animal << endl;

	vehicle = "Train";
	cout << "Vehicle: " << vehicle << endl;

	// C++ / operator performs integer division if both operands are integers, if one of the operand has a floating-point the result will have a floating-point
	cout << 10 / 4 << endl; // Outputs 2
	cout << 10. / 4 << endl; // Outputs 2.5

	// C++ % operator computes the remainder resulting from integer division. If one of the operand has a floating-point it will result in an error
	cout << 10 % 2 << endl; // Outputs 0
	// cout << 10. % 2 << endl; // Throws an error

	/*
	* Multi-line comment
	*/

	return 0;
}
