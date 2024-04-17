#include <iostream>
#include "Person.cpp"
using namespace std;

// Static Member Variable must be defined outside of the class declaration
//int Person::personCount = 0; // Static Member Variable initialized to 0

int main()
{
	// Static Member Variables can be accessed or modified by any object of the class, all modifications are visible to all objects of the class
	Person p1, p2;
	cout << p1.getPersonCount();


	return 0;
}

