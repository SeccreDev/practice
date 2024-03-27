#include <iostream>
#include "Date.cpp" // import the Date class
using namespace std;

void showData(Date d);
void showData2(Date &d);
void showData3(const Date &d);
Date initializeDate();

int main()
{
	/// Object - are the instance of a class. Objects are defined just like other variables using the name of the class as the data type.
	// Creating an object using the default constructor with no argument list
	Date activity; 

	// Creating an object using a constructor with an argument list (because this constructor has parameters).
	Date activity2(10, 10, 10);

	// Member functions are accessed using the dot operator
	activity.printDate(); 
	activity2.printDate();

	// Passing objects as argument to functions by value. The function will create a local copy and the original object in calling environment is unaffected by actions inside the function. Can slow down a program and waste space
	showData(activity);
	
	// Passing objects by reference, the function can use the 'set' functions to modify the object. Speeds up program, but allows the functions to modify data in the parameter
	showData2(activity);
	
	// Passing objects by reference but protecting parameter data that should not be changed using a const reference parameter
	showData3(activity);
	
	// Returning object from a function
	Date activity3 = initializeDate();
	showData3(activity3);

}

void showData(Date d)
{
	cout << "The day: " << d.getDay() << endl;
	cout << "The month: " << d.getMonth() << endl;
	cout << "The year: " << d.getYear() << endl;
}

void showData2(Date &d)
{
	d.setDay(2);
	d.setMonth(2);
	d.setYear(1999);
	cout << "The day: " << d.getDay() << endl;
	cout << "The month: " << d.getMonth() << endl;
	cout << "The year: " << d.getYear() << endl;
}

void showData3(const Date& d)
{
	//d.setDay(2); // Not allowed
	cout << "The day: " << d.getDay() << endl;
	cout << "The month: " << d.getMonth() << endl;
	cout << "The year: " << d.getYear() << endl;
}

Date initializeDate()
{
	Date d;
	d.setDay(20);
	d.setMonth(12);
	d.setYear(900);
	return d;
}
