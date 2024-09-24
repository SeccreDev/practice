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

	// Struct pointer needs to be dereferenced to show the content
	cout << "The contents of somePointer is: " << *(theStruct.somePointer) << endl;

	// Creating a dynamically structure 
	StructWithPointer *structP = new StructWithPointer;
	structP->somePointer = &number;
	cout << "The contents of somePointer within structP is: " << *(structP->somePointer) << endl;
	cout << "Now with pointer notation:\n";
	cout << "The contents of somePointer within structP is: " << *((*structP).somePointer) << endl;
	return 0;
}
