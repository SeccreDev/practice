#include <iostream>
#include <string>
#ifndef COPY_H
#define COPY_H
using namespace std;

// Copy Constructor - a special constructor used when a newly created object is initialized to the data of another object of the same class.
//                    If the programmer does not define a copy constructor for the class then the compiler calls a default copy constructor which copies corresponding
//					  data from one object to another of the same class. Default copy constructor copies field-to-field values, using member-wise assignment.
class Copy
{
	private:
		float *floatPointer;

	public:
		Copy(int x = 0)
		{
			floatPointer = new float;
			*floatPointer = x; // Problem occur when object contain pointers to dynamic storage
		}

		~Copy()
		{
			delete floatPointer;
		}

};
#endif

