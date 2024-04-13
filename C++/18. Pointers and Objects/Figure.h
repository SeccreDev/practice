#include <iostream>
#ifndef FIGURE_H
#define FIGURE_H
using namespace std;

class Figure
{
	private:
		int sides;
		float area;

	public:
		Figure(int s = 0, float a = 0)
		{
			sides = s;
			area = a;
		}

		// Getters
		int getSide()
		{
			return sides;
		}

		float getArea()
		{
			return area;
		}

		// Setters
		void setSide(int s)
		{
			sides = s;
		}

		void setArea(float a)
		{
			area = a;
		}

};
#endif
