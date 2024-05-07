#include <iostream>
using namespace std;

struct StructWithPointer
{
	int *somePointer;
	int size;
};

int main()
{
	StructWithPointer theStruct;
	int number = 25;
	theStruct.size = 5;
	theStruct.somePointer = &number;
	
	cout << "The contents of somePointer is: " << *(theStruct.somePointer) << endl;
	
	StructWithPointer *structP = new StructWithPointer;
	structP->somePointer = &number;
	cout << "The contents of somePointer within structP is: " << *(structP->somePointer) << endl;
	cout << "Now with pointer notation:\n";
	cout << "The contents of somePointer within structP is: " << *((*structP).somePointer) << endl;
	return 0;
}
