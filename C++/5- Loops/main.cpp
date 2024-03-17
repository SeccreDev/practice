#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	/// Increment and Decrement Operators: variable++ same as variable = variable + 1. ++variable increment the variable and is used in any operation within the same statement
	int number = 1, number2 = 2;
	number = ++number2; // number will be equal to 3 because number2 got the value incremented with prefix mode
	cout << "Number: " << number << " Number2: " << number2  << endl;
	number = --number2; // number will be equal to 2 because number2 got the value decreased with prefix mode
	cout << "Number: " << number << " Number2: " << number2 << endl;
	number2 = number++; // number2 will be equal to 2 because number got the value incremented with postfix mode, meaning the value of number changed AFTER the statement
	cout << "Number: " << number << " Number2: " << number2 << endl;

	/// Loops - are part of the program that may execute more than once
	/// While loops execute the statements inside their block as long as the condition is true, it evaluates the condition at the beginning of every loop (is pretest loop).
	int x = 0;
	while(x < 10)
	{
		cout << x << " ";
		x++;
	}
	cout << endl << "Value of x: " << x << endl;

	// While loops must contain code to allow the condition to eventually become false, otherwise the loop will be infinite. 
	/*while (x == 10)
	{
		cout << "Never ending loop" << endl;
	}*/

	// While loops are good for input validation
	int userNumber;
	cout << "Enter a number between 1 and 100: ";
	cin >> userNumber;
	while (userNumber < 1 || userNumber > 100)
	{
		cout << "Please enter a number between 1 and 100: ";
		cin >> userNumber;
	}
	cout << "A valid number has been entered." << endl;

	// Counters - a variable that is incremented/decremented each time a loop repeats. Can be used to control execution of the loop, they must be initialized before entering the loop
	int counter, userCounter;
	cout << "Table of squares\n";
	cout << "How far to go: ";
	cin >> userCounter;
	cout << "\nnumber square\n";
	counter = 1;
	while (counter <= userCounter)
	{
		cout << setw(5) << counter << setw(6) << counter * counter << endl;
		counter++;
	}
	cout << endl;

	/// Do-while loop is a post test loop, the condition is evaluated after the loop executes. Can be used in a menu-driven program to bring back user
	int userExit = 1;
	do
	{
		char userLetter;
		cout << "=========================================================" << endl;
		cout << "A- Print 'Hello World'" << endl;
		cout << "B- Print 'SeccreDev'" << endl;
		cout << "C- Exit the program" << endl;
		cout << "=========================================================" << endl;
		cout << "Which option does the user wants: ";
		cin >> userLetter;
		userLetter = toupper(userLetter);

		switch (userLetter)
		{
		case 'A':
			cout << "Hello World!" << endl;
			break;
		case 'B':
			cout << "SeccreDev" << endl;
			break;
		case 'C':
			cout << "Killing the program..." << endl;
			userExit = 0;
			break;
		default:
			cout << "That is not an option in the menu..." << endl;
		}
	} while (userExit);

	// for loop is a pretest loop that executes zero or more times. Is more counter-controlled
	cout << "For-loop printing out numbers 1 to 10:" << endl;
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		cout << i << endl;
		sum += i;
	}
	cout << "Sum of numbers 1 - 10: " << sum << endl;

	// Initialization and update can contain more than one statement
	for (int i = 1, sum = 0; i <= 11; sum+=i, i++) 
	{
		cout << "Sum: " << sum << endl;
	}
	
	return 0;
}
