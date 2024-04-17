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
