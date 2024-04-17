#include <iostream>
#include <string>
#ifndef PERSON_H
#define PERSON_H
using namespace std;

class Person
{
	private:
		// Static Member Variable - one instance of variable for the entire class (it iss shared by all objects of the class).
		//                          can be initialized, used, before any class objects are created. Can be used to accumulate values from
		//                          a number of different objects, or to count the number of objects instantiated...
		static int personCount; // Static Member Variable must be declared in class with the keyword static
		int age;
		string name;

	public:
		/// Constructor
		Person(string name = "", int age = 0);

		/// Setters
		// Constant Parameter  - when const is in parameter list the function is prevented from modifying the parameter 'n'. The parameter is read-only
		void setAge(const int a);
		void setName(const string n);

		// Getters
		// Constant Member Functions - the function is prevented from modifying the object. None of the objects data members can be modified. Recommended for all getters
		static int getPersonCount();
		int getAge() const;
		string getName() const;
};
#endif