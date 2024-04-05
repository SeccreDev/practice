#include <iostream>
#include "Figure.h"
using namespace std;

int main()
{
	// Array of objects
	Figure figures[5];

	// Outputs each object 
	for (int i = 0; i < 5; i++)
	{
		cout << figures[i].getSide() << endl;
	}

	// Changes each object side member
	for (int i = 0; i < 5; i++)
	{
		figures[i] = Figure(i * 10);
	}

	// Outputs the new value for the side member
	for (int i = 0; i < 5; i++)
	{
		cout << figures[i].getSide() << endl;
	}

	// Initialization list for array of objects
	Figure figures2[4] = { 0, 1, 2, 3 };

	for (int i = 0; i < 4; i++)
	{
		cout << figures2[i].getSide() << endl;
	}

	Figure figures3[5] = { 1, 2, 3 }; // Default constructor is used for the remaining objects if initialization list is too short
	for (int i = 0; i < 5; i++)
	{
		cout << figures3[i].getSide() << endl;
	}

	// If an array object is initialized with a constructor that takes more than one argument the initialization
	// list must include a call to the constructor. Figures figures4[2] = {Figure(2, 5), Figure(4, 1)};

	// Array of structures
	struct Professor
	{
		int professorId;
		string name;
	};

	Professor spanish101[10];
	spanish101[0].professorId = 100;
	spanish101[0].name = "Virgil";
	cout << "Name: " << spanish101[0].name;
	cout << "ID: "  << spanish101[0].professorId << endl;
	return 0;

}