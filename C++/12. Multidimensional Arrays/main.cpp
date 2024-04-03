#include <iostream>
using namespace std;

typedef int intExams[2][2];
void getResults(int results[][3], int rows);
void getResults2(intExams results, int rows);

int main()
{
	// Two-Dimensional Arrays - one array for multiple sets of data (dataType nameOfVariable[#ofrows][#ofcolumns)
	int exams[4][3]; // 4 rows and 3 columns (imagine a table)
	exams[0][0] = 100; // First row First Column

	int exams2[2][3] = { {100, 90, 40}, {80, 70, 65} }; //  Can be initialized like this
	int exams3[2][3] = { 10, 90, 40, 80, 70, 65 }; // Or like this by omitting the iner curlybraces

	// Passing 2D Array to a function
	getResults(exams3, 2);

	// Using typedef with 2D Arrays
	intExams exams4 = { 1, 2, 3, 4 };
	getResults2(exams4, 2);

	return 0;
}

void getResults(int results[][3], int rows)
{
	cout << "  2D Array  " << endl << "===========" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << results[i][j] << " ";
		}
		cout << endl;
	}
	cout << "===========" << endl;
}

void getResults2(intExams results, int rows)
{
	cout << "  2D Array  " << endl << "===========" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << " " << results[i][j] << " ";
		}
		cout << endl;
	}
	cout << "===========" << endl;
}
