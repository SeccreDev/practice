#include <iostream>
using namespace std;

/*
*  Function definition - consists of:
*									 return type: data type of the value the function returns. if a function doesnt return a value it's data type is void.
*									 name: name of the function
*									 paramater list: the variables that hold the values that are passed to the function when it is called
*                                    body: statements that perform the function's task
*/
void printHeading(); // Function prototypes

int main() // this is the function header it consists of: int is the return type, main is the name, () is the paramater list (although here is empty)
{
	printHeading(); // Function call - program will execute the body of the function
}

void printHeading() // Function declaration
{
	cout << "Heading\n";
}
