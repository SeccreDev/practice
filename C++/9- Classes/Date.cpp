#include <iostream>
#include "Date.h"
using namespace std;

void Date::printDate()
{
	cout << "The day: " << getDay() << endl;
	cout << "The month: " << getMonth() << endl;
	cout << "The year: " << getYear() << endl;
}