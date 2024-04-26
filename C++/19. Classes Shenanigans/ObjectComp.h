#include <iostream>
using namespace std;
#ifndef OBJECTCOMP_H
#define OBJECTCOMP_H

class Rectangle
{
	private:
		float length;
		float width;

	public:
		Rectangle(float l = 0, float w = 0)
		{
			length = l;
			width = w;
		}

		void setDimensions(int l = 0, int w = 0)
		{
			length = l;
			width = w;
		}

		float getArea()
		{
			return length * width;
		}
};

// Object Composition - when an object of a class is a member variable of an object of another. Often used to design complex objects whose members are simpler objects
class Book
{
	private:
		int pages;
		// Class aggregation - object of one class owns an object of another class
		Rectangle size; // Book is a composed object.

	public:
		// Member Initialization List - Used in constructors for classes involved in aggregation. Allows constructor for enclosing class to pass arguments to
		//                              the constructor of the enclosed class. Can be used to simplify the coding of constructors.
		// Aggregation Relationship through pointers (not implemented here) - is represented as an object of one class containing pointers to objects of another class. The contained objects are said to 
		//                           be part of the containing object, but they can exist independently of the containing object.
		Book(int p, float l, float w): size(l, w)
		{
			this->pages = p;
			
		}

		void setPages(int p)
		{
			pages = p;
		}

		float totalCost()
		{
			return pages * size.getArea();
		}
};
#endif

