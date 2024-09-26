#include <iostream>
using namespace std;

// Recursive function - a function that calls itself. Is a loop that can be useful in solving problems that can be broken down into smaller sub-problems of the same type.
//						a base case should eventually be reached, at that time the recursion will stop.
// Types of Recursion: -Direct Recursion: a function calls itself
//		       -Indirect Recursion: function A calls function B, function B calls function A.

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

// Finding Factorial by using a Recursive Function
int factorial(int number)
{
	if (number == 0) // Base case
	{
		return 1;
	}
	else
	{
		return number * factorial(number - 1); // Recursive Call
	}
}

// Finding Greatest Common Divisor by using a Recursive Function
int gcd(int x, int y)
{
	if (x % y == 0) // Base case
	{
		return y;
	}
	else
	{
		return gcd(y, x % y); // Recursive Call
	}
}

// Using a Recursive Function for Fibonacci Sequence
int fibonacci(int number)
{
	if (number <= 0) // Base case
	{
		return 0;
	}
	else if (number == 1) // Base case
	{
		return 1;
	}
	else
	{
		return fibonacci(number - 1) + fibonacci(number - 2); // Recursive Call
	}
}

// Binary Search by using a Recursive Function
int recursiveBinarySearch(int array[], int low, int high, int number)
{
	int mid = (low + high) / 2;
	if (low > high) // Base case
	{
		return -1;
	}
	if (array[mid] == number) // Base case
	{
		return mid;
	}
	if (array[mid] > number)
	{
		return recursiveBinarySearch(array, low, mid - 1, number);
	}
	else
	{
		return recursiveBinarySearch(array, mid + 1, high, number);
	}
}

int main()
{
	//hello(); // infinite
	countDown(30);
	cout << "========================\n";
	cout << factorial(10) << endl;
	cout << "========================\n";
	cout << gcd(10, 5) << endl;
	cout << "========================\n";
	cout << fibonacci(30) << endl;
	cout << "========================\n";

	return 0;
}
