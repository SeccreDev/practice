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

	// Constructor - special function that can be a member of a structure, automatically invoked when a structure variable is created. Used to initialize data members.
	Student(int SID = 0, short Y = 0, string N = "0", float GPA = 0)
	{
		studentID = SID;
		year = Y;
		name = N;
		gpa = GPA;
	}
};

/*
* Nested Structures
  struct PersonInfo
  {
	string name, address, city;
  };

  struct Student
  {
	int studentID;
	PersonInfo pData;
	short year;
	double gpa;
  };
*/

// A function that takes Student as a parameter
void showData(const Student& s);

// Returning a structure from a function
Student getStudentData();

int main()
{
	/*Student s1, s2;
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
	}*/

	// We can also initialize structure by using a constructor or a list
	// Initializing structure with list
	Student s3 = {404, 2012, "Andres", 2.40 + 1.20};

	// Initializing data with a constructor
	Student s4 = Student(1234, 2003, "Julio", 1.40 + 2.40);

	// Passing a structure parameter
	showData(s3); // Passing a structure by value is slow, passing by reference allows the function to modify the data in the structure but if we use a const it will deny it
	showData(s4);

	/* Members of nested structures
	   Student s5;
	   s5.pData.name = "Juan";
	   s5.pData.city = "Madrid";
	   s5.studentID = 102;
	*/

	// Calling Student getStudentData();
	Student s5 = getStudentData();
	showData(s5);
}

void showData(const Student &s)
{
	cout << "Student name: " << s.name << endl;
	cout << "Student id: " << s.studentID << endl;
	cout << "Student gpa: " << fixed << setprecision(1) << s.gpa << endl;
	cout << "Student year: " << s.year << endl;
}

Student getStudentData()
{
	Student s1;
	cout << "Input studentID: ";
	cin >> s1.studentID;
	cout << "Input year: ";
	cin >> s1.year;
	cin.ignore();
	cout << "Input student name: ";
	getline(cin, s1.name);
	cout << "Input student gpa: ";
	cin >> s1.gpa;
	return s1;
}
