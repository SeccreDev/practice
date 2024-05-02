#ifndef CLASSTEMP_H
#define CLASSTEMP_H

// Class template - can be used whenever we need several classes that only differs in the type of some of their data members, or in the type of the parameters of ther member functions
template <class T>
class ClassTemp
{
	public:
		T add(T x, T y)
		{
			return x + y;
		}
};
#endif


