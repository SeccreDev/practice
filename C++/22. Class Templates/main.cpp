#include <iostream>
#include "ClassTemp.h"
using namespace std;

int main()
{
	// To create an object of a class defined by a template, specify the actual parameters for the formal data types
	ClassTemp<int> intAdd;
	ClassTemp<string> stringAdd;
	cout << intAdd.add(5, 8) << endl;
	cout << stringAdd.add("Maria", " Luis") << endl;

	return 0;
}
