#include <iostream>
#include <string>
#ifndef ANIMAL_H
#define ANIMAL_H
using namespace std;

class Animal
{
private:
	int animalAge;
	string animalName;
	
	// An entire class can be declared a friend of a class
	friend class Person; // All member functions of Person have unrestricted access to all members of Animal, including the private members. This is not recommended.
	                     // Friendship should only be used with functions that MUST have access to the private members of a class

public:
	/// Constructor
	Animal(string name = "", int age = 0)
	{
		animalName = name; 
		animalAge = age; 
	}

	// Setters
	void setAnimalAge(const int a)
	{
		animalAge = a;
	}
	void setAnimalName(const string n)
	{
		animalName = n;
	}

	// Getters
	int getAnimalAge() const
	{
		return animalAge;
	}

	string getAnimalName() const
	{
		return animalName;
	}
};
#endif
