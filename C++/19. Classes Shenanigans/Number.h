#include <iostream>
#ifndef NUMBER_H
#define NUMBER_H
using namespace std;


class Number
{
	private:
		int number;

	public:
		Number(int x = 0)
		{
			number = x;
		}

		// Operator Overloading - is a compile-time polymorphism. We can overload an operator '+' in a class like String so that we can concatenate two strings by just using +.
		//						  Operators such as =, +, <= and others, can be redefined for use with objects of a class. The name of the function for the overloaded operator is operator
		//                        followed by the operator symbol. Operators can be overloaded as instance member functions, or as friend functions.
		// Operator Overloading +
		Number operator+ (const Number &num)
		{
			return Number(this->number + num.number);
		}

		// Operator Overloading ==
		bool operator== (const Number& num)
		{
			if (this->number == num.number)
			{
				return true;
			}
			else
			{;
				return false;
			}
		}

		int getNumber() const
		{
			return number;
		}
};

class Number2
{
	private:
		int *p;

	public:
		Number2(const Number2& obj)
		{
			 p = new int;
			*p = *obj.p;
		}

		Number2(int x = 0)
		{
			p = new int;
			*p = x;
		}

		// Operator Overloading = - Overloading the assignment operator solves problems with object assignment when an object containts pointer to dynamic memory
		//							Assignment operator is most naturally overloaded as an instance member function. It needs to returna value of the assigned
		//                          object to allow cascaded assignments such as a = b = c
		Number2 operator=(Number2 number)
		{
			p = new int;
			*p = *number.p;
			return *this;
		};

		int getInt() const
		{
			return *p;
		}

		~Number2()
		{
			delete p;
		}
};
#endif

