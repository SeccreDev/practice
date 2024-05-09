#include <iostream>
#include <string>
#ifndef COU_H
#define COU_H
using namespace std;

class CourseInfo
{
	private:
		string courseNumber;
		int numberOfCredits;
		char gradeEarned;

	public:
		// Constructor
		CourseInfo(string courseNumber = "", int numberOfCredits = 0, char gradeEarned = 0);

		// Accessor Methods
		string getCourseNumber() const;
		int getNumberOfCredits() const;
		char getGradeEarned() const;

		// Mutator Methods
		void setCourseNumber(string);
		void setNumberOfCredits(int);
		void setGradeEarned(char);
};
#endif
