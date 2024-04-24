#include <iostream>
#ifndef COPY_H
#define COPY_H
using namespace std;

// This class will use a Default Copy Constructor as it does not have one define
class BadCopy
{
	private:
		float *floatPointer;

	public:
		BadCopy(float x = 0)
		{
			floatPointer = new float;
			*floatPointer = x; // Problem occur when object contain pointers to dynamic storage
		}

		~BadCopy()
		{
			delete floatPointer;
		}

};

// This class will use the Copy Constructor define by the programmer
class GoodCopy
{
private:
	float *floatPointer;

public:
	// Programmer-Defined Copy Constructor - Takes one parameter: an object of the same class by reference. The copy constructor uses the data in the object passed as
	//                                       as parameter to initialize the object being created. Reference parameter should be const to avoid corruption. This copy constructor
	//                                       will avoid problems caused by memory sharing. 
	// 1- Should allocate separate memory to hold new object's dynamic member data.
	// 2- Should make new object's pointer point to this memory
	// 3- Should copy the data, not the pointer, from the original object to the new object
	GoodCopy(const GoodCopy &obj)
	{
		floatPointer = new float;
		*floatPointer = *obj.floatPointer;
	}

	GoodCopy(float x = 0)
	{
		floatPointer = new float;
		*floatPointer = x; 
	}

	~GoodCopy()
	{
		delete floatPointer;
	}

};
#endif
