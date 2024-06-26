#include <iostream>
using namespace std;

int main()
{
	// Data type declaration and variable definition
	enum Tree { ASH, ELM, OAK } tree1, tree2, tree3;

	// Assigning an int value to an enum variable
	tree1 = static_cast<Tree>(1); // Assigns ELM

	// Assigning the value of an enum variable to an int
	tree2 = ELM;
	int theTree = tree2; // Assigns 1
	int thatTree = OAK; // Assigns 2

	// Assign the result of a computation to an enum variable
	tree3 = static_cast<Tree>(tree2 + 1); // Assigns OAK

	// Using enumerators in a switch statement
	switch (tree1)
	{
		case ASH:
			cout << "ASH" << endl;
			break;
		case ELM:
			cout << "ELM" << endl;
			break;
		case OAK:
			cout << "OAK" << endl;
			break;
	}

	// Using enumerators for loop control
	for (Tree tree4 = ASH; tree4 <= OAK; tree4 = static_cast<Tree>(tree4 + 1))
	{
		cout << tree4 << endl;
	}

	// Enumerated values cannot be reused in different enumerated data types that are in the same scope. A strongly typed enum (called enum class) allows you to do this
	enum class Street { RUSH, OAK, STATE };

	// Enumeratos can be used in multiple enumerated data types, references must include the name of the strongly typed enum followed by ::
	Street street = Street::OAK;

	// Strongly typed enumerators are stored as ints by default, to choose a different integer data type, it must be indicated after the enum name and before the enumarator list:
	enum class Flower : char {DAISY, ORCHID};

	// To retrieve the integer value associated with a strongly-typed enumerator, cast it to an int
	int value = static_cast<int>(Flower::ORCHID);

	return 0;
}