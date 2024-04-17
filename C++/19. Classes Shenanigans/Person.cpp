#include "Person.h"
int Person::personCount = 0; // Static Member Variable initialized to 0
// this Pointer - can be used to access members that may be hidden by parameters with the same name
Person::Person(string name = "", int age = 0)
{
	this->name = name; // using ->
	(*this).age = age; // using * and . operators
	personCount++;
}

void Person::setName(const string n)
{
	name = n;
}

void Person::setAge(const int a)
{
	age = a;
}

int Person::getPersonCount()
{
	return personCount;
}

int Person::getAge() const
{
	return age;
}

string Person::getName() const
{
	return name;
}
