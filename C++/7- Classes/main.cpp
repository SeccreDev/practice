#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structures - Programmer-defined data type that allows multiple variables to be grouped together
struct Student // struct name often begins with an uppercase letter.
{
	// Structure members/Fields - All public by default, they can be accessed without restrictions anywhere within the scope of the variable
	int studentID; // Cannot initialize members in the structure definition because no memory has been allocated yet
	short year;
	string name;
	float gpa;
};

int main()
{
	Student s1, s2;
	cout << "Input student id: ";
	cin >> s1.studentID;
	cin.ignore();
	cout << "Input student name: ";
	getline(cin, s1.name);

	s1.gpa = 4.0;
	s1.year = 2024;
	cout << "Student name: " << s1.name << endl;
	cout << "Student id: " << s1.studentID << endl;
	cout << "Student gpa: " << fixed << setprecision(1) << s1.gpa << endl;
	cout << "Student year: " << s1.year << endl;

	cout << "Input student id: ";
	cin >> s2.studentID;
	cin.ignore();
	cout << "Input student name: ";
	getline(cin, s2.name);

	s2.gpa = 3.0;
	s2.year = 2024;
	cout << "Student name: " << s2.name << endl;
	cout << "Student id: " << s2.studentID << endl;
	cout << "Student gpa: " << fixed << setprecision(1) << s2.gpa << endl;
	cout << "Student year: " << s2.year << endl;

	if (s1.gpa > s2.gpa)
	{
		cout << "First student has higher GPA\n";
	}
	else if (s1.gpa == s2.gpa)
	{
		cout << "Both students have the same GPA\n";
	}
	else
	{
		cout << "Second student has higher GPA\n";
	}
}