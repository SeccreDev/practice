#include <iostream>
#ifndef FIGURE_H
#define FIGURE_H
using namespace std;

class Figure
{
	private:
		int side;

	public:
		Figure(int s = 10)
		{
			side = s;
		}

		int getSide();
};

#endif