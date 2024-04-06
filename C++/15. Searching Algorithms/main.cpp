#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// Search - locate a specific item in a list (array, vector, linked list, ...) of data
	// Linear Search - Algorithm that searches for a value by analyzing a list from the beginning until it finds the desired value. Rather slow since
	//                 on average it searches half of the list IF the value is found within the list. If not it searches the whole list.
	//                 (In this case it searches the whole list to find every index were that value is found)
	const int SIZE = 10;
	int numbers[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 6, 10 };
	int searchNumber = 6;
	vector <int> foundOn;
	bool isFound = false;
	for (int index = 0; index < SIZE; index++)
	{
		if (numbers[index] == searchNumber)
		{
			isFound = true;
			foundOn.push_back(index);
		}
		else
		{
			cout << "The desired element wasn't found in the index: " << index << endl;
		}
	}

	if (isFound)
	{
		for (int i = 0; i < foundOn.size(); i++)
		{
			cout << "The desired value was found on: " << foundOn[i] << endl;
		}
	}
	else
	{
		cout << "The desired element was not found.";
	}

	// Binary Search - Algorithm that searches for a value by dividing a sorted array into three sections: middle element, left side of middle element, and right side of middle element.
	//                 Analyzes if the middle element is the desired value, if not it uses only one half of the array (left or right depending if the desired value is lower or higher) and
	//                 divides that side into three sections and repeats all the process again until the desired value is found or no more elements to examine

}
