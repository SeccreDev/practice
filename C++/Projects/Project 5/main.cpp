#include <iostream>
#include "CourseInf.h"
#include "Student.h"
using namespace std;

// Functions Prototypes
void studentInformation(string& studentName, int& idNumber);
void courseNumbers(int &numberOfCourses);

int main()
{
	const int SIZE = 2;
	Student students[SIZE];
	int idNumber;
	string name;
	
	for (int i = 0; i < SIZE; i++)
	{
		studentInformation(name, idNumber);
		int numberOfCourses = 0;
		courseNumbers(numberOfCourses);

		students[i].setStudentName(name);
		students[i].setIdNumber(idNumber);
		students[i].setNumberOfCourses(numberOfCourses);
		students[i].courseDetails();
		students[i].calculateGPA();
		students[i].displayReport();
	}
	return 0;
}

/// Functions Declarations
// Returns studentName and idNumber
void studentInformation(string& studentName, int& idNumber)
{
	// Inputs student name
	cout << "Student Name: ";
	getline(cin, studentName);

	// Gets and validates ID number with a while loop.
	int counter = 0;
	do
	{
		cout << "ID Number: ";
		cin >> idNumber;
		if ((idNumber >= 0) && (idNumber <= 9999))
			counter = 1;
		else
			cout << "Please provide a valid ID number" << endl;
	} while (counter == 0);
}

// Gets and validates numbers of courses with a while loop
void courseNumbers(int &numberOfCourses)
{
	while (numberOfCourses <= 0 || numberOfCourses > 5)
	{
		cout << "Number of Courses: ";
		cin >> numberOfCourses;
		if (numberOfCourses <= 0 || numberOfCourses > 5)
			cout << "Provide valid number of courses, the minimum number of courses is 1 and the maximum 5" << endl;
		else
			cin.ignore();
		continue;
	}
}

