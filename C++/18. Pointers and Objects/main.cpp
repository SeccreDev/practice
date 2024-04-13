#include <iostream>
#include <string>
#include "Figure.h"
using namespace std;

struct Student
{
	int studentID;
	string studentName;
};

int main()
{
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
	cout << "Sides: " << (figurePointer[1]).getSide() << endl; // Using ->
	cout << "Area: " << (figurePointer[1]).getArea() << endl; // Using . operators

	// Dynamic Memory and Structures - allocating dynamic structure variables using pointer
	Student* dynamicStudentPointer = new Student;
	dynamicStudentPointer->studentID = 20;
	dynamicStudentPointer->studentName = "Jose";
	cout << "Dynamic student id: " << dynamicStudentPointer->studentID << endl;
	cout << "Dynamic student name: " << dynamicStudentPointer->studentName << endl;
	delete dynamicStudentPointer;

	// Dynamic Memory and Objects - allocating dynamic object variable using pointers
	Figure *dynamicFigurePointer = new Figure(20, 80.50);
	cout << "Dynamic Figure Area: " << dynamicFigurePointer->getArea() << endl;
	cout << "Dynamic Figure Sides: " << dynamicFigurePointer->getSide() << endl;
	delete dynamicFigurePointer;


	return 0;
}