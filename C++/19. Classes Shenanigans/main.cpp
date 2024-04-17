#include <iostream>
#include "Person.h"
using namespace std;

int main()
{
	// Static Member Variables can be accessed or modified by any object of the class, all modifications are visible to all objects of the class
	// cout << Person::personCount; // cannot be accessed like this because it is a private member; otherwise it would output the personCount variable
	Person p1, p2;
	cout << p1.getPersonCount() << endl;
	cout << p2.getPersonCount() << endl;
	cout << Person::getPersonCount();

	return 0;
}
