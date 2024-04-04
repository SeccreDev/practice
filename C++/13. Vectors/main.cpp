#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> intVec;
void showData(vector <int> data);
void showData2(intVec data);
void showData3(intVec &data);

int main()
{
	// Vectors - Holds set of elements like an array but is more flexible as it can grow or shrink as needed. 
	vector <int> examScores;
	vector  <double> area;

	// Can use [] to access elements but only if the vector has a predefined size or if its filled prior to using []
	vector <float> exam(10); // Size of the vector is enclosed in parentheses not brackets

	// typedef with vectors
	intVec values; // Declaring a vector of integers; has 0 elements
	intVec values2(50); // Declaring a vector with initial size of 30 elements
	intVec values3(10, 0); // Declaring a vector with initial size of 10 elements and all elements initialize to 0
	intVec values4(values3); // Declaring a vector initialized to size and contents of vector values 3

	// Passing a vector by value
	showData(values3);
	showData2(values4);

	// Passing a vector by reference - vectors are not passed by reference like arrays. We have to use the & operator
	showData3(values4);

	// Growing vector size by adding element
	values4.push_back(100); // Add a element holding 100
	cout << values4.size() << endl; // determines the number of elements in the vector (now has 11 elements)

	// Remove element from vector
	values4.pop_back();
	cout << values4.size() << endl; // number of elements in the vector should be 10 now

	// Remove all contents of the vector
	values4.clear();
	cout << values4.size() << endl; // number of elements in the vector should be 0 now

	// Determines if a vector is empty
	cout << values4.empty(); // Should return 1 (which is true)


	return 0;
}

void showData(vector<int> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << "Vector(" << i << ") has the value of: " << data[i] << endl;
	}
}

void showData2(intVec data)
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << "Vector(" << i << ") has the value of: " << data[i] << endl;
	}
}

void showData3(intVec &data)
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << "Vector(" << i << ") has the value of: " << data[i] << endl;
	}
}
