#include <iostream>
using namespace std;

/*
*  Function definition - consists of:
*									 return type: data type of the value the function returns. if a function doesnt return a value it's data type is void.
*									 name: name of the function
*									 paramater list: the variables that hold the values that are passed to the function when it is called. Parameters for functions are local variables
*                                    body: statements that perform the function's task
*/
void printHeading(string h1); // Function prototype - has 1 parameter in this case: string h1 (can have more than one); the data type has to be specified for each parameter
void displayName(string firstName, string lastName); // Function prototype - has 2 parameter in this case
int sumOfNumbers(int a, int b);

/// Default Arguments - values that are passed automatically if arguments are missing from a function call. The parameters without defaults must be declared first 
int multiplyThreeNumbers(int firstNumber, int secondNumber = 1, int thirdNumber = 1);

/// References Variable as Parameters - allows a function to work with the original argument from the function call, does not creat a copy of the argument. Allos function to modify values stored in the calling env.
void getDimensions(int &d1, int &d2); // reference variable (&) - makes so the changes made to the variable are made to the argument it refers to

/// Overloaded functions - two or more functions that have the same name but different data types parameters or different number of parameters or both
//void getArea(int a);
//void getArea(int a, int b);
//void getArea(int a, float b);
//void getArea(double a, double b);

/// Function template - pattern for creating definitions of functions that differ only in the type of data they manipulate. Better than overloaded functions as they only need to be defined once
///                     when the compiler encounters a call to the function, it generates code to handle the specific data types used in the call
///                     we can overload template function
template<class T>
T square(T side);

template <class T>
void swapValues(T& a, T& b);

// Template with multiple types
template<class T1, class T2, class T3>
void backwards(T1 p1, T2 p2, T3 p3);


int main() // this is the function header it consists of: int is the return type, main is the name, () is the paramater list (although here is empty)
{
	string heading = "Heading", name = "Seccre", lName = "Dev";
	int number = 5, total, numberToBeSquared = 5, height = 0, width = 0, squared, value1 = 90, value2 = 20;
	// Function call - program will execute the body of the function, values passed to a function are arguments; the number of arguments in the call must match the function prototype.
	// Pass by value - argument is passed to a function but the function cannot modified the original argument (the function has a copy of the value but not the original)
	printHeading(heading); // 1 argument copied to the function (pass by value)
	displayName(name, lName); // 2 arguments copied to the function (pass by value)
	total = sumOfNumbers(number, number); // 
	cout << "Total: " << total << endl;
	cout << "Multiply 3 numbers: " << multiplyThreeNumbers(5) << endl; // Two default arguments that are set to = 1. Result is 5 * 1 * 1
	// Pass by reference - argument is passed to a function and the function can modified the original argument
	getDimensions(height, width); // Pass by reference only works with variables, does not work with constants or expressions
	cout << "Height: " << height << endl; // Will print out the inputted height of getDimensions(int &d1, int &d2);
	cout << "Width: " << width << endl; // Will print out the inputted width of getDimensions(int &d1, int &d2);

	// Function templates
	squared = square(numberToBeSquared);
	cout << "Squared number: " << squared << endl;

	swapValues(value1, value2); // value1 is 90, value2 is 20
	cout << "Value1: " << value1 << endl; // now value1 is 20
	cout << "Value2: " << value2 << endl; // now value2 is 90

	backwards(1, 'A', "MAL");

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

void getDimensions(int &d1, int &d2)
{
	cout << "Please input the height of the object: ";
	cin >> d1;
	cout << "Please input the width of the object: ";
	cin >> d2;
}

template<class T>
T square(T side)
{
	return side * side;
}

template<class T>
void swapValues(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T1, class T2, class T3>
void backwards(T1 p1, T2 p2, T3 p3)
{
	cout << p3 << p2 << p1;
}
