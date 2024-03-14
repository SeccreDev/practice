#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

// Declare variables
const double PI = 3.1415;

// Function Protypes
void getRadius(double &r);
double calculateCircumference(double r = 5);
double calculateArea(double r = 5);
void displayCircleSpecs(double r, double c, double a, bool saveToFile = false);
void saveCircleSpecs(double r, double c, double a); // NOT IDEAL NAME, BUT SHOWS HOW TO USE OVERLOAD


int main()
{
	double 	radius,
		   	circumference,
		   	area;
	string myFile = "file.txt";
	getRadius(radius);
	circumference = calculateCircumference(radius);
	area = calculateArea(radius);
	displayCircleSpecs(radius, circumference, area, true);

	//saveCircleSpecs(radius, circumference, area);
	return 0;
}
// Function Declarations

/*
	Function: void getRadius(double &r)
	Parameters: Receives the radius variable, which needs to be set
	Return Values: Although, this function does not return a value, it sets the passed radius variable
	Purpose: To set the variable radius to a value chosen by user	
*/
void getRadius(double &r)
{
	cout << "Please enter the radius of your circle: ";
	cin >> r;
	return;
}


/*
	Function: double calculateCircumference(double r)
	Parameters: radius r
	Return Value: circumference
	Purpose: Given a radius, this function calculates the circumference by using the formula 2*PI*radius	
*/
double calculateCircumference(double r)
{
	return 2 * r * PI;
}

/*
	Function: double calculateArea(double r)
	Parameters: radius r
	Return Value: Area
	Purpose: Given a radius, this function calculates the area by using the formula PI*radius*radius
*/
double calculateArea(double r)
{
	return PI * r * r;
}

/*
	Function: void displayCircleSpecs(double r, double c, double a)
	Parameters: radius r, circumference c, area a
	Return Value: none
	Purpose: Given circle measuraments, this function displays the radius, circumference and area of a given circle
*/
void displayCircleSpecs(double r, double c, double a, bool saveToFile)
{
	if (saveToFile)
		saveCircleSpecs(r, c, a);
	else
	{
		cout 	<< "The provided circle had the following measuraments:\n" 
				<< "Radius: " << r << endl
				<< "Area: " << fixed << setprecision(2) << a << endl
				<< "Circumference: "  << fixed << setprecision(2) << c << endl
				<<"\n /**** !!!THANKS FOR USING OUR CIRCLE SPECS PROGRAM!!! ****\\";
	}
}
/*
	Function: void saveCircleSpecs(double r, double c, double a, string filename)
	Parameters: radius r, circumference c, area a, string filename
	Return Value: none
	Purpose: Given circle measuraments, this function SAVES to a file the radius, circumference and area of a given circle
*/
void saveCircleSpecs(double r, double c, double a)
{
	/*
	ofstream outputFile; 	// Declare the output stream file
	outputFile.open(f); 	//open the file
	ORRRRR DO IT IN ONE LINE
	*/
	ofstream outputFile("myFile.txt");
	outputFile 	<< "The provided circle had the following measuraments:\n" 
				<< "Radius: " << r << endl
				<< "Area: " << fixed << setprecision(2) << a << endl
				<< "Circumference: "  << fixed << setprecision(2) << c << endl
				<<"\n /**** !!!THANKS FOR USING OUR CIRCLE SPECS PROGRAM!!! ****\\";
	outputFile.close(); // close the file once you are done
}
