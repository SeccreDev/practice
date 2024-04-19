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
	
	// Friend Class
	Person popuri;
	Animal dog;
	popuri.setAnimal(dog, 15, "Lucy");
	popuri.printAnimal(dog);
	cout << "===========================================\n";

	// Member-wise Assignment - can use = to assign one object to another, or to initialize an object with another object's data thanks to the copy constructor
	Person ama("Ama Lee", 20), ama2;
	ama2 = ama; // Assigning object ama to ama2. ama2 will copy ama values. Default Copy constructor called
	cout << "ama: " << ama.getAge() << " " << ama.getName() << endl;
	cout << "ama2: " << ama2.getAge() << " " << ama2.getName() << endl;
	ama2.setName("Ama Long");
	ama2.setAge(90);
	cout << "ama: " << ama.getAge() << " " <<  ama.getName() << endl;
	cout << "ama2: " << ama2.getAge() << " " << ama2.getName() << endl;
	cout << "===========================================\n";

	Person ama3 = ama2; // Initializing ama3 with the data of ama2. Default Copy constructor called
	cout << "ama2: " << ama2.getAge() << " " << ama2.getName() << endl;
	cout << "ama3: " << ama3.getAge() << " " << ama3.getName() << endl;
	ama3.setName("Ama Three");
	ama3.setAge(3);
	cout << "ama2: " << ama2.getAge() << " " << ama2.getName() << endl;
	cout << "ama3: " << ama3.getAge() << " " << ama3.getName() << endl;
	cout << "===========================================\n";





	return 0;
}

