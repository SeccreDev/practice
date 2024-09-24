#include <iostream>
#include <string>
#include "Figure.h"
using namespace std;

struct Student
{
	int studentID = 0;
	string studentName= "NULL";
};

// Function Prototypes
void changeStudent(Student* pointer);
void changeFigure(Figure *pointer);

int main()
{
	// Early binding - happens at compile time and objects cannot be altered at run-time. Most of the time early binding and automatic memory management are sufficient.
	//                 other times its not: Polymorphism and access of an object outside of the function/method that creates it.
	// Late binding - happens at run-time. Memory allocated using new must be deallocated using delete. Failure to do so results in memory leaks (more dangerous in loops).
	//                Functions that allocate storage should be the function that de-allocates it, and a class that needs dynamically allocate storage should invoke new in its constructor and delete in its destructor
	Student s1 = { 100, "Alan" };
	Figure square[4];
	
	// Pointer to structures
	Student *studentPointer = &s1;
	(*studentPointer).studentID = 200; // Need to use () when using * and . operators
	cout << (*studentPointer).studentID << endl;
	studentPointer->studentID = 300;  // Or using the form pointer->member;
	cout << studentPointer->studentID << endl;

	// Pointer to object
	Figure *figurePointer = square;
	cout << "Sides: " << (*figurePointer).getSide() << endl; // Using * and . operators
	cout << "Area: " << figurePointer->getArea() << endl; // Using ->
	figurePointer->setSide(4); // Using ->
	(*figurePointer).setArea(40.50); // Using * and . operators
	cout << "Sides: " << figurePointer->getSide() << endl; // Using ->
	cout << "Area: " << (*figurePointer).getArea() << endl; // Using . operators
	
	// Using () and * operators to access 2nd element and so forth
	(figurePointer[1]).setSide(4);
	(figurePointer[1]).setArea(200.25);
	cout << "Sides: " << (figurePointer[1]).getSide() << endl; // Using . operators
	cout << "Area: " << (figurePointer[1]).getArea() << endl; // Using . operators

	// Dynamic Memory and Structures - allocating dynamic structure variables using pointer
	Student* dynamicStudentPointer = new Student;
	dynamicStudentPointer->studentID = 20;
	dynamicStudentPointer->studentName = "Jose";
	cout << "Dynamic student id: " << dynamicStudentPointer->studentID << endl;
	cout << "Dynamic student name: " << dynamicStudentPointer->studentName << endl;
	delete dynamicStudentPointer;

	// Passing a structure pointer as parameter
	Student *dynamicStudentPointer2 = new Student;
	changeStudent(dynamicStudentPointer2);
	cout << "Dynamic Student Area: " << dynamicStudentPointer2->studentID << endl;
	cout << "Dynamic Student Sides: " << dynamicStudentPointer2->studentName << endl;
	delete dynamicStudentPointer2;

	// Dynamic Memory and Objects - allocating dynamic object variable using pointers
	Figure *dynamicFigurePointer = new Figure(20, 80.50);
	cout << "Dynamic Figure Area: " << dynamicFigurePointer->getArea() << endl;
	cout << "Dynamic Figure Sides: " << dynamicFigurePointer->getSide() << endl;
	delete dynamicFigurePointer;

	// Passing an object pointer as parameter
	Figure* dynamicFigurePointer2 = new Figure(4, 70);
	changeFigure(dynamicFigurePointer2);
	cout << "Dynamic Figure Sides: " << dynamicFigurePointer2->getSide() << endl;
	cout << "Dynamic Figure Area: " << dynamicFigurePointer2->getArea() << endl;
	delete dynamicFigurePointer2;

	// Dangling Pointer - is a pointer which points to unallocated (already freed) memory area.
	float *ptr = new float; // Memory dynamically allocated
	float *ptr2 = ptr; // Pointer to the dynamically memory area
	delete ptr; // Memory unallocated, but ptr2 still points to it.

	// Avoid Dangling Pointers - set pointer variables to NULL when you no longer need them (test whether a pointer variable contains NULL before using it).
	//                           set all aliases that reference a deleted object to NULL when object is deleted
	ptr2 = NULL; // Setting to NULL to avoid the dangling pointer

	// Program Memory:
	//                - run-time stack
	//		  - free storage (heap): Memory dynamically allocated
	//		  - static storage: static variables definitions
	//		  - code storage: global definitions

	return 0;
}

void changeStudent(Student* pointer)
{
	int id;
	string name;
	cout << "Input the id of the student: ";
	cin >> id;
	cout << "Input the name of the student: ";
	cin.get();
	getline(cin, name);
	pointer->studentID = id;
	pointer->studentName = name;
}

void changeFigure(Figure* pointer)
{
	float area, sides;
	cout << "Input the amount of sides: ";
	cin >> sides;
	cout << "Input the desired area: ";
	cin >> area;
	pointer->setSide(sides); 
	pointer->setArea(area);
}
