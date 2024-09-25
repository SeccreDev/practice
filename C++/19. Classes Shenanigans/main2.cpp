#include <iostream>
using namespace std;

class Square
{
	private: 
		double side;
		double *randomPointer;
	
	public:
		Square() // No arg-constructor
		{
			side = 0;
			randomPointer = NULL;	
		}	
		Square(double s) // Constructor with one argument (initializes the side)
		{
			side = s;
			randomPointer = new double;
		}
		void setSide(double s)
		{
			side = s;
		}
		double getSide()
		{
			return side;
		}
		double getArea()
		{
			return side * side;
		}
		double getPerimeter()
		{
			return side * 4;
		}
		
		// DESTRUCTOR METHOD -- Has the purpose of freeing up allocated memory.
		// It is created by placing a ~ followed by the class name:   ~Square()
		~Square()
		{
			cout << "The destructor was called! EXTERMINATE!\n";
			delete randomPointer;
			randomPointer = nullptr;
		}
};

int main()
{
	Square myBox(5);
	Square *sqPointer = new Square(10);
	cout << "The area of my box is: " << myBox.getArea() << endl;
	cout << "Edward has a box with the area of: " << sqPointer->getArea() << endl;
	delete sqPointer;
	sqPointer = nullptr;
	
	return 0;
}
