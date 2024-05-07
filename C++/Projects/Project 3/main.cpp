/*
	Purpose: Structure Project ~ Display student structure. 
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
	string name;
	int idNumber;
	short testScore1, testScore2, testScore3;
	float average;
	char grade;
};

// Function Prototypes
Student createStudent();
void calculateAverage(Student &s);
char calculateGrade(float s);
void passedOrFailed(char g);
void displayStudent(const Student &s);

int main()
{
	Student student1 = createStudent();
	calculateAverage(student1);
	student1.grade = calculateGrade(student1.average);
	displayStudent(student1);
	return 0;
}

//Function Declarations
/*
	Function: Student createStudent()
	Parameters: None
	Return Values: Returns a structure 
	Purpose: Creates and returns a structure with name, ID number and test scores 
*/
Student createStudent()
{
	Student s;
	cout << "Name: ";
	getline(cin, s.name);
	cout << "ID Number: ";
	cin >> s.idNumber;
	do
	{
		cout << "First test score: ";
		cin >> s.testScore1;
	} while (s.testScore1 < 0 || s.testScore1 > 100);
	do
	{
		cout << "Second test score: ";
		cin >> s.testScore2;
	} while (s.testScore2 < 0 || s.testScore2 > 100);
	do
	{
		cout << "Third test score: ";
		cin >> s.testScore3;
	} while (s.testScore3 < 0 || s.testScore3 > 100);
	cout << "================================================================\n";
	return s;
}

/*
	Function: calculateAverage(Student &s)
	Parameters: Passes the student1 structure
	Return Values: Returns average
	Purpose: To calculate the average of the test scores
*/
void calculateAverage(Student &s)
{
	s.average = ((s.testScore1 + s.testScore2 + s.testScore3) / 3.0);
}

/*
	Function: calculateGrade(float s)
	Parameters: Passes the average value
	Return Values: Returns grade
	Purpose: To calculate the letter grade based on the average score
*/
char calculateGrade(float s)
{
	if (s >= 90)
		return 'A';
	else if (s >= 80)
		return 'B';
	else if (s >= 70)
		return 'C';
	else if (s >= 60)
		return 'D';
	else
		return 'F';
}

/*
	Function: passedOrFailed(char g)
	Parameters: Passes the letter grade
	Return Values: None
	Purpose: Displays a message that tells the user if the passed or not
*/
void passedOrFailed(char g)
{
	if (g == 'A' || g == 'B' || g == 'C')
		cout << "You Passed!" << endl;
	else
		cout << "You Failed..." << endl;
}

/*
	Function: displayStudent(const Student &s)
	Parameters: Passes the student1 structure
	Return Values: None
	Purpose: Displays student name, ID number, test scores, test average and final grade
*/
void displayStudent(const Student &s)
{
	cout << "Name of the student: " << s.name << endl
		<< "Student ID Number: " << s.idNumber << endl
		<< "Test Scores: \n"
		<< "1st Test: " << s.testScore1 << endl
		<< "2nd Test: " << s.testScore2 << endl
		<< "3rd Test: " << s.testScore3 << endl
		<< "Test Average: " << fixed << setprecision(2) << s.average << endl
		<< "Final Grade: " << s.grade << endl;
	passedOrFailed(s.grade);
}
