#include <iostream>
#include <cstring> // Useful functions that take one or more C-strings as arguments.
#include <cctype> // Character Testing
#include <string>
using namespace std;

int main()
{
	// C-string - sequence of characters stored in adjacent memory locations and terminated by NULL character (the end of the string - \0, int 0, NULL)
	// The name of an array of char is used as a pointer to char. Unlike a string literal, a C-string defined as an array can be referred to in other parts of the program by using the array name
	char strings[50] = "Marco and Polo"; // An array of char can be defined and initialized to a C-string
	cout << strings << endl;
	char *pointerChar = strings; // Pointer to char can also refer to C-strings defined as array of char. Can also dynamically allocate memory for C-string
	cout << pointerChar << endl;
	cout << "======================================" << endl;
	
	// Functions for C-strings
	int sizeOfStrings = strlen(strings); // int strlen(char *string) - Returns length of the C-string NOT the size of the array that has it
	cout << "Size of strings: " << sizeOfStrings << endl;
	
	char strings2[20] = " are cool";
	strcat_s(strings, strings2); // char *strcat(char *destination, char *source) - Takes two C-strings as input. Adds the content of the second string to the end of the first string.
	cout << strings << endl;

	char name[20];
	strcpy_s(name, "Tomas"); // char * strcpy(char *destination, char *source) - Copies a string from a source address to a destination address
	cout << name << endl;

	if (strcmp(strings, strings2) == 0)// int strcmp(char *string, char *string2) - Compares strings stored at two addresses to determine their relative alphabetic order (case sensitive).-1: string is less, 0 strings are equal, 1 string is larger.
	{
		cout << "The strings are equal" << endl;
	}
	else
	{
		cout << "Strings are not equal." << endl;
	}

	char flag[20] = "All base, All one";
	char* found = strstr(flag, "bas"); // char *strstr(char *string, char *string2) - Searches for the occurrence of string2 within string. Returns a pointer to the occurrence of string2 within string if found, Null otherwise.
	cout << found << endl;
	cout << "======================================" << endl;

	// Conversion between string and numeric forms
	int number = atoi("500"); // int atoi(char *numericStr) - converts alphanumeric to int
	long number2 = atol("501230"); // long atol(char *numericStr) - converts alphanumeric to long
	double number3 = atof("2.50"); // double atof(char *numericStr) - converts alphanumeric to double
	double number4 = atof("2.20d");// If the C-string being converted contains non-digits, results are undefined: Function return result of conversion up to first non-digit or 0.
	cout << number << endl;
	cout << number2 << endl;
	cout << number3 << endl;
	cout << number4 << endl;
	cout << "======================================" << endl;

	// Conversion between numeric and string forms
	char numStr[30];
	_itoa_s(3000, numStr, 10); // _itoa_(int number, char *numberString, int base) - converts an int to an alphanumeric string and allows user to specify the base of conversion.
	cout << numStr << endl;
	cout << "======================================" << endl;

	// Array of char can be defined and later have a string copied into it using strcpy_s or cin.getline
	char string[30], string2[40];
	strcpy_s(string, "Hello");
	cout << "Enter the name of your dog: ";
	cin.getline(string2, 40);
	cout << string << endl;
	cout << string2 << endl;
	cout << "======================================" << endl;

	// Character Testing
	char test = 'a';
	if (isalpha(test)) // isalpha() returns true if is alphabetic. False otherwise
	{
		cout << "Is a letter" << endl;
	}
	else
	{
		cout << "Is not a letter" << endl;
	}

	if (isalnum(test)) // isalnum() returns true if is alphabetic or digit. False otherwise
	{
		cout << "Is a letter or a digit" << endl;
	}
	else
	{
		cout << "Is not a letter or a digit" << endl;
	}

	if (isdigit(test)) // isdigit() returns true if is a digit. False otherwise
	{
		cout << "Is a digit" << endl;
	}
	else
	{
		cout << "Is not a digit" << endl;
	}

	if (islower(test)) // islower() returns true if is lowercase letter. False otherwise
	{
		cout << "Is a lowercase letter" << endl;
	}
	else
	{
		cout << "Is not a lowercase letter" << endl;
	}

	if (isupper(test)) // isupper() returns true if is uppercase letter. False otherwise
	{
		cout << "Is an uppercase letter" << endl;
	}
	else
	{
		cout << "Is not an uppercase letter" << endl;
	}

	cout << "======================================" << endl;

	return 0;
}