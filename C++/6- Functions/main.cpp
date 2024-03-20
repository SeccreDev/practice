#include <iostream>
using namespace std;

/*
*  Function definition - consists of:
*									 return type: data type of the value the function returns. if a function doesnt return a value it's data type is void.
*									 name: name of the function
*									 paramater list: the variables that hold the values that are passed to the function when it is called
*                                    body: statements that perform the function's task
*/
void printHeading(string h1); // Function prototype - has 1 parameter in this case: string h1 (can have more than one); the data type has to be specified for each parameter
void displayName(string firstName, string lastName); // Function prototype - has 2 parameter in this case
int sumOfNumbers(int a, int b);

/// Default Arguments - values that are passed automatically if arguments are missing from a function call. The parameters without defaults must be declared first 
int multiplyThreeNumbers(int firstNumber, int secondNumber = 1, int thirdNumber = 1);

int main() // this is the function header it consists of: int is the return type, main is the name, () is the paramater list (although here is empty)
{
	string heading = "Heading", name = "Seccre", lName = "Dev";
	int number = 5, total, square;
	// Function call - program will execute the body of the function, values passed to a function are arguments; the number of arguments in the call must match the function prototype.
	// Pass by value - argument is passed to a function but the function cannot modified the original argument (the function has a copy of the value but not the original)
	printHeading(heading); // 1 argument copied to the function (pass by value)
	displayName(name, lName); // 2 arguments copied to the function (pass by value)
	total = sumOfNumbers(number, number); // 
	cout << "Total: " << total << endl;
	cout << "SquaredNumber: " << multiplyThreeNumbers(5) << endl; // Two default arguments that are set to = 1. Result is 5 * 1 * 1
}

void printHeading(string h1) // Function declaration
{
	cout << h1 << endl;
}

void displayName(string firstName, string lastName)
{
	cout << "Name: " << firstName << lastName << endl;
}

int sumOfNumbers(int a, int b)
{
	return a + b; // returns a value and ends the execution of the function, can be placed anywhere. The return value must be of the same data type as the declared return type (if not it will try to be converted)
}

int multiplyThreeNumbers(int firstNumber, int secondNumber, int thirdNumber)
{
	return firstNumber * secondNumber * thirdNumber;
}
