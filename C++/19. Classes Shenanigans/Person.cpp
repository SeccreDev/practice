#include "Person.h"

// Static Member Variable must be initialized outside of the class declaration
int Person::personCount = 0; // Static Member Variable initialized to 0

// Setters
void Person::setName(const string n)
{
	name = n;
}

void Person::setAge(const int a)
{
	age = a;
}


// Getters
int Person::getAge() const
{
	return age;
}

string Person::getName() const
{
	return name;
}

// Static Member Functions
int Person::getPersonCount()
{
	return personCount;
}

void Person::incrementPersonCount() // The definition of a static function is not preceded by the keyword static, but the prototype is.
{
	personCount++;
}

// Friend Function - definition
void setMembers(Person &p, int age, string name) // & to pass by reference and modify it
{
	p.age = age;
	p.name = name;
}

// Friend Function - another class
void Person::setAnimal(Animal &d, int age, string name)
{
	d.setAnimalAge(age);
	d.setAnimalName(name);
}

void Person::printAnimal(Animal d)
{
	cout << "Animal Age: " << d.getAnimalAge() << endl;
	cout << "Animal Name: " << d.getAnimalName() << endl;
}