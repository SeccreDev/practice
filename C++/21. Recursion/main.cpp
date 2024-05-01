#include <iostream>
using namespace std;

// Recursive function - a function that calls itself. Is a loop that can be useful in solving problems that can be broken down into smaller sub-problems of the same type.
//						a base case should eventually be reached, at that time the recursion will stop.
void hello() // This fumction calls itself infinitely, a base case is never reached.
{
	cout << "Hello";
	hello();
}

void countDown(int number) 
{
	// Base case is when num == 0
	// Each time a recursive function is called, a new copy of the functions runs with new instances of parameters and local variables being created. As each copy finishes executing, it returns to the part of the program that made the initial call.
	// With each recursive call, the parameter controlling the recursion should move closer to this base case; when that happens the chain of recursvive calls terminates.
	if (number == 0) 
	{
		cout << "ZERO!" << endl;
	}
	else
	{
		cout << number << "..." << endl;
		countDown(number - 1); // recursive call
	}
}

// Types of Recursion: -Direct Recursion: a function calls itself       -Indirect Recursion: function A calls function B, function B calls function A.
