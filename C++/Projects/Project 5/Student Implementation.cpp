#include <iostream>
#include "Student.h"
/// Implementation file for Student
/// Methods
//Constructor
/*
	Method: Student(string studentName, int idNumber, int numberOfCourses, float gradePointAverage)
	Parameters: studentName - a string that represents the name of a student
				idNumber - an int that represents the ID number of the student 
				numberOfCourse - an int that represents the how many courses the student is taking 
				gradePointAverage - a float that represents the GPA of the student
	Return: Set the passed variables
	Purpose: To set all of the fields of the class.
*/
Student::Student(string studentName, int idNumber, int numberOfCourses, float gradePointAverage)
{
	this->studentName = studentName;
	this->idNumber = idNumber;
	this->numberOfCourses = numberOfCourses;
	this->gradePointAverage = gradePointAverage;
}

// Accessor Methods
/*
	Method: getStudentName()
	Parameters: Receives no parameters
	Return Values: returns student's name
	Purpose: Returns the studentName field
*/
string Student::getStudentName() const
{
	return studentName;
}
/*
	Method: getIdNumber()
	Parameters: Receives no parameters
	Return Values: returns the ID number of the student
	Purpose: Returns the idNumber field
*/
int Student::getIdNumber() const
{
	return idNumber;
}
/*
	Method: getNumberOfCourses()
	Parameters: Receives no parameters
	Return Values: returns the number of courses the student is taking 
	Purpose: Returns the numberOfCourses field
*/
int Student::getNumberOfCourses() const
{
	return numberOfCourses;
}
/*
	Method: getGradePointAverage()
	Parameters: Receives no parameters
	Return Values: returns the GPA of the student
	Purpose: Returns the gradePointAverage field
*/
float Student::getGradePointAverage() const
{
	return gradePointAverage;
}

// Mutator Methods
/*
	Method: setStudentName(string studentName)
	Parameters: studentName - represents the name of the student
	Return Values: Set the passed variables
	Purpose: To set the studentName field
*/
void Student::setStudentName(string studentName) 
{
	this->studentName = studentName;
}
/*
	Method: setIdNumber(int idNumber)
	Parameters: idNumber - represents the ID of the student
	Return Values: Set the passed variables
	Purpose: To set the idNumber field
*/
void Student::setIdNumber(int idNumber)
{
	this->idNumber = idNumber;
}
/*
	Method: setNumberOfCourses(int numberOfCourses)
	Parameters: numberOfCourses - represents the number of courses the student is taking
	Return Values: Set the passed variables
	Purpose: To set the numberOfCourses field
*/
void Student::setNumberOfCourses(int numberOfCourses)
{
	this->numberOfCourses = numberOfCourses;
}
/*
	Method: setGradePointAverage(float gradePointAverage)
	Parameters: gradePointAverage - represents the GPA of the student
	Return Values: Set the passed variables
	Purpose: To set the gradePointAverage field
*/
void Student::setGradePointAverage(float gradePointAverage)
{
	this->gradePointAverage = gradePointAverage;
}

// Other methods
/*
	Method: courseDetails()
	Parameters: Receives no parameters
	Return Values: None
	Purpose: Add new elements to the vector <CourseInfo> courses depending on how many courses were taken by the student
*/
void Student::courseDetails()
{
	string courseNumber;
	int courseCredit;
	char gradeEarned;

	for (int i = 0; i < getNumberOfCourses(); i++)
	{
		cout << "Please enter the course number: ";
		getline(cin, courseNumber);
		
		do
		{
			cout << "Please enter number of credits for the course: ";
			cin >> courseCredit;
			if (courseCredit <= 0 || courseCredit > 5)
				cout << "Provide valid number of credit, the minimum number of credit is 1 and the maximum 5" << endl;
			else
				cin.ignore();
			continue;
		} while (courseCredit <= 0 || courseCredit > 5);

		int counter = 0;
		do
		{
			cout << "Please enter letter grade received in the course: ";
			cin >> gradeEarned;
			gradeEarned = static_cast<char>(toupper(gradeEarned));

			
			if (gradeEarned == 'A')
			{
				counter = 1;
			}
			else if (gradeEarned == 'B')
			{
				counter = 1;
			}
			else if (gradeEarned == 'C')
			{
				counter = 1;
			}
			else if (gradeEarned == 'D')
			{
				counter = 1;
			}
			else if (gradeEarned == 'F')
			{
				counter = 1;
			}
			else
				cout << "Provide a valid grade, should be letter A or B or C or D or F" << endl;
		} while (counter == 0);
		cin.ignore();
		courses.push_back(CourseInfo(courseNumber, courseCredit, gradeEarned));
	}
}
/*
	Method: calculateGPA()
	Parameters: Receives no parameters
	Return Values: None
	Purpose: Calculates the gpa by getting the total value of grades and diving it by the total amount of credits
*/
void Student::calculateGPA()
{
	const int A = 4, B = 3, C = 2, D = 1, F = 0;
	int totalGrades = 0, totalCredits = 0;
	float gradePoint;
		for (int i = 0; i < getNumberOfCourses(); i++)
		{
			totalCredits += courses[i].getNumberOfCredits();
			switch (courses[i].getGradeEarned())
			{
				case 'A': 
					totalGrades += A * courses[i].getNumberOfCredits();
					break;
				case 'B':
					totalGrades += B * courses[i].getNumberOfCredits();
					break;
				case 'C':
					totalGrades += C * courses[i].getNumberOfCredits();
					break;
				case 'D':
					totalGrades += D * courses[i].getNumberOfCredits();
					break;
				case 'F':
					totalGrades += F * courses[i].getNumberOfCredits();
					break;
				default:
					cout << "You shouldn't be able to see this..." << endl;
					break;
			}
	    }
		gradePoint = static_cast<float>(totalGrades) / totalCredits;
		setGradePointAverage(gradePoint);
}
/*
	Method: displayReport()
	Parameters: Receives no parameters
	Return Values: None
	Purpose: Show the GPA report of the student
*/
void Student::displayReport()
{
	cout << "===================================================" << endl
		 << "            GPA REPORT FOR THIS SEMESTER           " << endl
		 << "===================================================" << endl 
		 << "Name: " << getStudentName() << endl
		 << "ID: " << getIdNumber() << endl
		 << "Number of courses: " << getNumberOfCourses() << endl
		 << "---------------------------------------------------" << endl
		 << "                      Courses                      " << endl
		 << "---------------------------------------------------" << endl
		 << "Number                Credits                Grade " << endl;                                                          

	for (int i = 0; i < getNumberOfCourses(); i++)
	{
		cout << left << setw(25) << courses[i].getCourseNumber()
			 << right << courses[i].getNumberOfCredits()
			 << setw(22) << courses[i].getGradeEarned() << endl;
	}
	cout << "---------------------------------------------------" << endl
		 << "GPA: " << setprecision(3) << getGradePointAverage() << endl
		 << "===================================================" << endl << endl;
}
