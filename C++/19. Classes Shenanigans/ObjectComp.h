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
		Rectangle(int l = 0, int w = 0)
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
		Rectangle size; // Book is a composed object

	public:
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

