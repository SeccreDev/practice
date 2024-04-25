#include <iostream>
using namespace std;
#ifndef INTVALUE_H
#define INTVALUE_H

class IntValue
{
	private:
		int value;

	public:
		IntValue(int x = 0)
		{
			value = x;
		}

		// Conversion Operators - Member functions that tell the compiler how to convert an object of the class type to a value of any other data type.
		//						  The conversion information provided by the conversion operators is automatically used by the compiler in assignments, initializations,
		//						  and parameter passing. Conversion operator must be a member function of the class you are converting from. The name of the operator is the
		//                        name of the type you are converting to. The operatoor does not specify a return type.
		operator int()
		{
			return value;
		}

};
#endif


