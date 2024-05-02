#ifndef CLASSTEMP_H
#define CLASSTEMP_H

// Class template - can be used whenever we need several classes that only differs in the type of some of their data members, or in the type of the parameters of ther member functions.
// Templates can be combined with inheritance. You can derive: -Non template classes from a template class: instantiate the base class template and then inherit from it
//															   -Template class from a template class.
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


