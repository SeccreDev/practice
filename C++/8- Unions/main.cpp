#include <iostream>
using namespace std;

/// Unions - similar to a struct but all members share a single memory location and only 1 member of the union can be used at a time
union WageInformation
{
	float hourlyRate;
	double annualSalary;
};

int main()
{
	WageInformation wI;
	wI.annualSalary = 29999.99;
	wI.hourlyRate = 7.99;

	cout << "Annual Salary: " << wI.annualSalary << endl;
	cout << "Hourly Rate: " << wI.hourlyRate << endl;

	return 0;
}
