#include <iostream>
using namespace std;

typedef int intExams[2][2];
void getResults(int results[][3], int rows); // When using 2D arrays specify size of all but the first dimension
void getResults2(intExams results, int rows);
void getRectSolid(short solid[][3][5], int rows); // When using 2D or more dimensions arrays specify size of all but the first dimension

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

	// Arrays with three or more dimensions
	short rectSolid[2][3][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
								11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
								21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
	double timeGrid[3][4][3][4]; // 4D array, can be used for x-coordinate, y-coordinate, z-coordinate, time

	getRectSolid(rectSolid, 2);


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

void getRectSolid(short solid[][3][5], int rows)
{
	cout << "  3D Array  " << endl << "===========" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				printf("test[%d][%d][%d] = %d\n", i, j, k, solid[i][j][k]);
			}
			cout << endl;
		}
	}
	cout << "===========" << endl;

}
