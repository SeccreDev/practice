#include <iostream>
#include "CourseInf.h"

/// Implementation file for CourseInf
//Constructor
/*
	Method: CourseInfo
	Parameters: courseNumber - a string that represents a course number 
				numberOfCredits - a int that represents the number of credits of a course
				gradeEarned -- a char that represents the grade earned in the course
	Return: Set the passed variables
	Purpose: To set all of the fields of the class.
*/
CourseInfo::CourseInfo(string courseNumber, int numberOfCredits, char gradeEarned)
{
	this->courseNumber = courseNumber;
	this->numberOfCredits = numberOfCredits;
	this->gradeEarned = gradeEarned;
}
// Accessor Methods
/*
	Method: getCourseNumber()
	Parameters: Receives no parameters
	Return Values: returns the course number
	Purpose: Returns the courseNumber field
*/
string CourseInfo::getCourseNumber() const
{
	return courseNumber;
}
/*
	Method: getNumberOfCredits()
	Parameters: Receives no parameters
	Return Values: returns the number of credits of the course
	Purpose: Returns the numberOfCredits field
*/
int CourseInfo::getNumberOfCredits() const
{
	return numberOfCredits;
}
/*
	Method: getGradeEarned()
	Parameters: Receives no parameters
	Return Values: returns the grade earned for the course
	Purpose: Returns the gradeEarned field
*/
char CourseInfo::getGradeEarned() const
{
	return gradeEarned;
}
// Mutator Methods
/*
	Method: setCourseNumber(string courseNumber)
	Parameters: courseNumber - represents the number of the course
	Return Values: Set the passed variables
	Purpose: To set courseNumber field
*/
void CourseInfo::setCourseNumber(string courseNumber)
{
	this->courseNumber = courseNumber;
}
/*
	Method: setNumberOfCredits(int numberOfCredits)
	Parameters: numberOfCredits - represents the number of credit of the course 
	Return Values: Set the passed variables
	Purpose: To set the numberOfCredits field
*/
void CourseInfo::setNumberOfCredits(int numberOfCredits)
{
	this->numberOfCredits = numberOfCredits;
}
/*
	Method: setGradeEarned(char gradeEarned)
	Parameters: gradeEarned - represents the letter grade obtained for a course 
	Return Values: Set the passed variables
	Purpose: To set the setGradeEarned field
*/
void CourseInfo::setGradeEarned(char gradeEarned)
{
	this->gradeEarned = gradeEarned;
}
