#include <iostream>
using namespace std;
#ifndef INHERITANCE_H
#define INHERITANCE_H

// Inheritance - is a way of creating a new class by starting with an existing class and adding new members.
//               The existing class is called the base class, parent class, or superclass.
//               The new class is called the derived class, child class, or subclass. It can extend the functionality of the Parent class
//               Inheritance models the 'is-a' relationship between classes

class Parent
{
	// Protected - members within the same class are like private members. Outside the class, they are accessible, but only in a class that is derived from it.
	//             members of a parent class can be accessed by a child class. They can be called-on by member functions, friend functions, and friend classes
	protected:
		int id;
// private: int something; // Private members of a class are never accessible from anywhere except from member functions of the same class

	public:
		string lepra = "working";
		Parent(int id = 0)
		{
			this->id = id;
		}

		void setId(int id)
		{
			this->id = id;
		}

		int getId() const
		{
			return id;
		}
};

// The child class inherits the data members and the member functions of the parent class; Parent class constructor executes first, followed by the child class's constructor.
// These inheritance can be private, public, and protected:
// private Inheritance: all public members of the parent class become private members of the child class & all protected members of the parent class become private
//                      members of the child class
// protected Inheritance: all public members of the parent class become protected members of the child class & all protected members of the parent class become protected
//                        members of the child class
// public Inheritance: all public members of the parent class become public members of the child class & all protected members of the parent class become protected
//                     members of the child class
class Child : public Parent
{
	private:
		string name;

	public:
		Child(int id = 0, string name = " "): Parent(id) // Passing argument to Parent Class Constructor.
		{
			this->name = name;
		}

		void setName(string name = 0)
		{
			this->name = name;
		}

		string getName() const
		{
			return this->name;
		}

		void test()
		{
			cout << this->id << endl; // Allowed because is a protected member of the Parent Class
			cout << this->lepra << endl; // Allowed because is a public member of the Parent Class
			//cout << something; // Not allowed because is a private member. Compiler error
		}

		// Overriding - Child class can override a member function of its Parent class by defining a child class member function with the same name & parameter list.
		//              Typically used to replace a function in Parent class with different actions in child class (not the same as overloading). To access the 
		//              overriden version of the function, use the scope resolution operator with the name of the parent class and the name of the function.
};
#endif

