#include <iostream>
#include "Person.h"
//#include "Animal.h"
using namespace std;

int main()
{
	// Static Member Variables can be accessed or modified by any object of the class, all modifications are visible to all objects of the class
	Person p1, p2;
	// Static Member Variables using an object and another one using the class scope resolution operator (Person::)
	//cout << Person::personCount; // cannot be accessed like this because it is a private member; otherwise it would output the personCount variable
	//cout << p1.personCount; // cannot be accessed like this because it is a private member; otherwise it would output the personCount variable
	
	// Calling Static Member Function
	cout << p1.getPersonCount() << endl; // Calling the static member function from an object. Outputs 2
	Person::incrementPersonCount();
	cout << Person::getPersonCount() << endl; // Calling the static member function using the class scope resolution operator. Outputs 3
	cout << p2.getPersonCount() << endl; // Calling the static member function from an object. Outputs 3
	
	cout << "===========================================\n";

	// Friend function - calling
	Person p3;
	setMembers(p3, 50, "William");
	cout << "Person 3 Name: " << p3.getName() << endl;
	cout << "Person 3 Age: " << p3.getAge() << endl;
	cout << "===========================================\n";
	
	// Friend class
	Person popuri;
	Animal dog;
	popuri.setAnimal(dog, 15, "Lucy");
	popuri.printAnimal(dog);

	return 0;
}

