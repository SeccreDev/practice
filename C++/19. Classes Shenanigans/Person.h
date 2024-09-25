#include <iostream>
#include <string>
#include "Animal.h"
#ifndef PERSON_H
#define PERSON_H
using namespace std;

class Person
{
	private:
		// Static Member Variable - one instance of variable for the entire class (it is shared by all objects of the class).
		//                          can be initialized, used, before any class objects are created. Can be used to accumulate values from
		//                          a number of different objects, or to count the number of objects instantiated...
		static int personCount; // Static Member Variable must be declared in class with the keyword static
		int age;
		string name;


	public:
		/// Constructor
		// this Pointer - can be used to access members that may be hidden by parameters with the same name
		Person(string name = "", int age = 0)
		{
			this->name = name; // using ->
			(*this).age = age; // using * and . operators
			personCount++;
		}

		/// Setters
		// Constant Parameter  - when const is in parameter list the function is prevented from modifying the parameter. The parameter is read-only
		void setAge(const int &a);
		void setName(const string &n);

		// Getters
		// Constant Member Functions - the function is prevented from modifying the object. None of the objects data members can be modified. Recommended for all getters
		int getAge() const;
		string getName() const;
		
		// Static Member Functions - declared by prefixing the prototype with the keyword static before the function return data type
		static int getPersonCount();
		static void incrementPersonCount();

		// Friend function - a function that is not a member of a class, but has access to private members of the class. Declared by prefixing the prototype
		//                   with the keyword friend before the functions data return type. A friend function can be a stand-alone or a member function of another
		//                   class, in either case, the functions definition will not be preceded by the keyword friend. Friend functions is recommnended for functions
		//                   that must have access to private members
		friend void setMembers(Person &p, int age, string name);// Stand-alone Friend Function

		// Using Animal class
		void setAnimal(Animal &d, int age, string name);
		void printAnimal(Animal d);
};
#endif
