#include <iostream>
using namespace std;

int main()
{
	/*
	* Relational Operators - are used to compare numeric and char values to determine relative order 
	* Operators: (> greater than, < less than, >= greater than or equal to, <= less than or equal to, == equal to, != not equal to)
	* Relational expression results in a boolean, they either evaluate to true or to false
	* The Hierarchy of the relational operators: -Highest (> >= < <=)  -Lowest (== !=)
	*/
	int number1 = 2, number2 = 100;
	bool theResult = (number1 == number2);
	cout << (number1 < number2) << endl; // It will output 1, which means the result is true
	cout << (number1 > number2) << endl; // It will output 0, which means the result is false
	cout << (number1 != number2) << endl; // True
	cout << theResult << endl;


	// if statement - supports the use of a decision structure, giving a program more than one path of execution. Statements are conditionally executed or skipped over depending if the condition passes.
	int number = 5;
	if (number == 5) // As the condition passes, the statements inside the braces '{}' will be executed.  Curly braces {} can be omitted if the statements inside the 'if' block is one statement
	{
		cout << "The number is equal to 5." << endl;
	}
	if (number != 5) // This condition is not met, the statements will not be executed
	{
		cout << "The number is not equal to 5." << endl;
	}

	// if/else statement - allows a choice between statements depending on whether the condition is true or false
	number = 11;
	if (number == 11)
		cout << "The number is equal to 11" << endl; // As the condition is met the statements inside the if block will execute, the statements inside the else block will be skipped 
	else
		cout << "The number appears to be: " << number << " and not 5." << endl;

	if (number % 2 == 0)
		cout << "The number " << number << "is even" << endl; 
	else
		cout << "The number " << number << " is odd." << endl; // else statement runs as the condition inside the if statement was not met

	// if/else if statement - consists of a chain of if statements that test in order until one is found to be true. A final else can be used to provide a default statement when none of the conditions are met
	int grade;
	cout << "Please enter your score: ";
	cin >> grade;


	if (grade >= 90)
		cout << "You got an A! Congratulations!" << endl;
	else if (grade >= 80)
		cout << "You got a B! Nice job!" << endl;
	else if (grade >= 70)
		cout << "You got a C! Good but we both know you can do better!" << endl;
	else if (grade >= 60)
		cout << "You got a D... Terrible..." << endl;
	else if (grade >= 0)
		cout << "You got a F! Have I failed as a professor?" << endl;
	else
		cout << "That is not a valid score..." << endl;

	// flag - is a variable that signals a condition, usually implemented as a bool.
	bool validMonth = true;
	int monthNumber;
	
	cout << "Please enter a number that represents a month: ";
	cin >> monthNumber;

	if (monthNumber < 0 || monthNumber > 12)
	{
		cout << "The inputted number does not represent a month." << endl;
		validMonth = false; //  Flag set to false as the inputted number does not represent a month
	}
	
	if (validMonth) // Condition will be evaluated. The previous if statement determines if the flag is true or false.
	{
		if (monthNumber == 1) // Nested if statements. If statements within an if statement to evaluate more than one condition
		{
			cout << "The month is January." << endl;
		}
		else if (monthNumber == 2)
		{
			cout << "The month is February." << endl;
		}
		else if (monthNumber == 3)
		{
			cout << "The month is March." << endl;
		}
		else if (monthNumber == 4)
		{
			cout << "The month is April." << endl;
		}
		else if (monthNumber == 5)
		{
			cout << "The month is May." << endl;
		}
		else if (monthNumber == 6)
		{
			cout << "The month is June." << endl;
		}
		else if (monthNumber == 7)
		{
			cout << "The month is July." << endl;
		}
		else if (monthNumber == 8)
		{
			cout << "The month is August." << endl;
		}
		else if (monthNumber == 9)
		{
			cout << "The month is September." << endl;
		}
		else if (monthNumber == 10)
		{
			cout << "The month is October." << endl;
		}
		else if (monthNumber == 11)
		{
			cout << "The month is November." << endl;
		}
		else
		{
			cout << "The month is December." << endl;
		}
	}
	

	/*
	* Logical Operators - used to create relational expressions from other relation expressions
	* Operators: (&& - means 'and' evaluates to true if both expressions are true)
	*			 (|| - means 'or' evaluates to true if one of the expressions is true)
	*			 (! - means 'not' reverses the value of the expression. true expression becomes false and vice versa)
	* The Hierarchy of the logical operators: -Highest (!)  -Mid (&&)  -Lowest (||)
	*/
	bool logicTrue = true;
	int randomNumber = 2;
	int randomNumber2 = 3;
	
	if (randomNumber > randomNumber2 || logicTrue)
	{
		cout << "This will execute as long as one of the values is true" << endl;
	}

	if (randomNumber < randomNumber2 && logicTrue)
	{
		cout << "This will execute as long as both of the values are true" << endl;
	}
	
	// Conditional Operator - can be used to create a short if/else statements (condition? expresion1 : expresion2;)
	int x = 0, y = 11, z = 0;

	x < 0 ? y = 10 : z = 20;
	cout << z << endl; // Will print out 20 as the previous statement changed the value of z
	
	// Conditional Expression - An expression that uses a conditional operator.
	string oddOrEven = !(y % 2) ? "Odd" : "Even";
	cout << y << " is " << oddOrEven << endl;

	// Menu-Driven Program - the program is controlled by user selecting from a list of actions. In this example is from a list of numbers but letters can also be used
	int userChoice;
	cout << "=========================================================" << endl;
	cout << "1- Print 'Hello World'" << endl;
	cout << "2- Print 'SeccreDev'" << endl;
	cout << "3- Exit the program" << endl;
	cout << "=========================================================" << endl;
	cout << "Which option does the user wants: ";
	cin >> userChoice;

	if (userChoice == 1)
		cout << "Hello World!" << endl;
	else if (userChoice == 2)
		cout << "SeccreDev" << endl;
	else if (userChoice == 3)
	{
		cout << "Killing the program..." << endl;
		return 0;
	}
	else
		cout << "That is not an option in the menu..." << endl;

	// Switch statement - Uses the value of an integer expression to determine the statements to execute. Switch statements are better for menu-driven program
	// break - is used to stop execution in the current block. It is useful to exit the switch statement.
	// Recreating previous menu driven program with a switch statement
	char userLetter;
	cout << "=========================================================" << endl;
	cout << "a- Print 'Hello World'" << endl;
	cout << "b- Print 'SeccreDev'" << endl;
	cout << "c- Exit the program" << endl;
	cout << "=========================================================" << endl;
	cout << "Which option does the user wants: ";
	cin >> userLetter;

	switch (userLetter)
	{
		case 'a':
			cout << "Hello World!" << endl;
			break;
		case 'b':
			cout << "SeccreDev" << endl;
			break;
		case 'c':
			cout << "Killing the program..." << endl;
			return 0;
		default:
			cout << "That is not an option in the menu..." << endl;
	}
	
	return 0;
}