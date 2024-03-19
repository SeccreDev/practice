#include <iostream>
#include <string>
#include <iomanip> // Use to control how output displays for numeric and string data.
#include <cmath> // Useful math functions (abs, sin, cos, tan, sqrt, log, Pow, ceil)
#include <cstdlib> // To generate random numbers
#include <ctime> // Needed for time(), it determines the current calendar time, in seconds.
#include <fstream> // Needed to define a file stream object
using namespace std;

int main()
{
	int length;
	cout << "Enther length: ";
	cin >> length; // console input (cin) is used to read input from the keyboard and the input data is stored in the 'length' variable by using >>
	
	// Expressions can be: A value, a constant, a variable, or a combination of all of them
	int width;
	int height;
	cout << "Enter the width and the height: ";
	cin >> width >> height; // Can input multiple values in succession (separated by spaces)
	cout << "Width: " << width << " Height: " << height << endl;

	// Operations are performed between operands of the same type, if operands do not have the same type C++ will automatically convert one to be the type of the other
	// Coercion: Automatic conversion of an operand to another data type.
	// The Data Type Hierarchy (highest to lowest): long double, double, float, unsigned long, long, unsigned int, int, short
	// When operating on values of different data types the lower rank will be promoted to the higher rank. When using the = operator the expression on right will be converted to the type of variable on left
	// Promotion: converts to a higher type.     Demotion: converts to a lower type
	int notFloat = 2.5;
	cout << notFloat << endl;

	// Type Casting - manual data type conversion
	cout << static_cast<int>(45.90) << endl; // Outputs 45
	cout << static_cast<char>(65) << endl; // Outputs A

	// Type Casting
	char character = 'D';
	cout << character << " is stored as: " << static_cast<int>(character) << endl;

	// Constants - variables whose content cannot be changed, it is common to type them in snakecase-uppercase
	const double AREA_OF_TRIANGLE = 2.5;
	cout << "Area: " << AREA_OF_TRIANGLE << endl;
	//AREA_OF_TRIANGLE = 2.4; // trying to change it will result in an error

	// Combined Assignment - To apply an arithmetic operation to a variable and assign the result as the new value of that variable
	int sum = 0;
	sum = sum + 5;

	// Compound Operators: += -= *= /= %=
	int sum2 = 0;
	sum2 += 5; // Same as sum2 = sum2 + 5;
	int ya = 0;
	ya /= 5 + 10; // The right side will be evaluated first: ya = ya / (5 + 10)

	// Format output with stream manipulators:
	//  setw(x): Print in a field at least x spaces wide, will use more space if specified width is not big enough
	//  left, right: Justification of value from either left or right
	float value = 2.523;
	cout << setw(10) << value << endl;
	cout << left << setw(10) << value << endl;
	//  fixed: Use decimal notation for floating-point values.
	//  setprecision(x): Print floating-point value using x digits after the decimal (if used with fixed())
	//  showpoint: Always print decimal for floating-point values
	cout << fixed << setprecision(3) << value << endl;
	

	// Character input
	char character2;
	//cin >> character2; // Reads any char that is not blank
	//cin.get(character2); // Reads any char
	character2 = cin.get(); // Reads any char
	cin.ignore(); // Skips over next char in the input buffer
	
	// String input
	string word;
	//cin >> word; // This will read a string that has no blank spaces
	getline(cin, word); // This will read a string that has blank spaces
	cin.ignore();
	cout << word << endl;
	string s1 = "apple", s2 = "pie";
	string sweet = s1 + s2; // Will be applepie
	string s3 = "Delicious";
	s3 += sweet; // Will output Deliciousapplepie
	cout << s3 << endl;

	// String useful functions
	//  length() - returns the number of characters in a string
	string hello = "Hello World";
	cout << "Length of 'Hello World'" << hello.length() << endl;

	//  assign() - put repeated characters in a string.
	string bar;
	bar.assign(100, '=');
	cout << bar  << endl;

	// Random number generation
	// rand() - returns a random number between 0 and the largest int the computer holds. Will yield the same sequence of numbers each time the program is run
	// srand(x) - initializes random number generator with unsigned int x. x is the "seed value". Should be called at most once in a program.
	// time() to generate different seed values each time that a program runs
	int max = 10;
	int number;
	number = rand() % max + 1;
	cout << "Random number scaled up to 10: " << number << endl;

	// Files - They can be used for program input/output. Files are stored on secondary storage media and they allow data to be retained between program runs.
	//ifstream inFile; // ifstream - is used as the type to declare an object for an input file
	//ofstream outFile; // ofstream - is used as the type to declare an object for an output file

	// To read data from a file, the file must be opened with the open member function. File name may include the path
	//inFile.open("members.dat"); // Input file must exist for open to work
	//outFile.open("numbers.txt"); // Output file will be created if it does not exist, if it exist it will erased first.

	// We can declare and instantiate in the same line
	ifstream inFile("members.txt");
	ofstream outFile("numbers.txt");

	// Reading from a file and Writing to a file
	outFile << "Lottery numbers"; // Writing to a file by sending the data with <<

	string members;
	getline(inFile, members); // Reading a file and sending the data to members 
	cout << members;

	// File Open Errors
	if (inFile)
	{
		cout << "This will be outputted because the file exists" << endl;
	}
	else
	{
		cout << "Error - file could not be opened" << endl;
	}

	// Closing the files by using close() member functions.
	inFile.close();
	outFile.close();


	return 0;
}
