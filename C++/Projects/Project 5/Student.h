#include <iostream>
#include <vector>
#include <iomanip>
#include "CourseInf.h"
#ifndef STU_H
#define STU_H
using namespace std;

class Student : public CourseInfo
{
	private:
		string studentName;
		int idNumber, numberOfCourses;
		float gradePointAverage;
	 	vector <CourseInfo> courses;
	public:
		// Constructor
		Student(string studentName = "", int idNumber = 0, int numberOfCourses = 0, float gradePointAverage = 0.0);

		// Accessor Methods
		string getStudentName() const;
		int getIdNumber() const;
		int getNumberOfCourses() const;
		float getGradePointAverage() const;

		// Mutator Methods
		void setStudentName(string);
		void setIdNumber(int);
		void setNumberOfCourses(int);
		void setGradePointAverage(float);

		// Other Methods
		void courseDetails();
		void calculateGPA();
		void displayReport();
};
#endif
