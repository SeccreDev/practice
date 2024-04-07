#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int array[], int lowest, int highest, int desiredValue);

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
	//                 divides that side into three sections and repeats all the process again until the desired value is found or no more elements to examine.
	//                 Binary search is more efficient than linear search as it performs at most log2Size comparisions; it only requires the array to be sorted.
	int numbers2[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int desiredValue = 10;
	int lowestValue = 0, highestValue = SIZE - 1, numberFound;

	numberFound = binarySearch(numbers2, lowestValue, highestValue, desiredValue);
	if (numberFound == -1)
	{
		cout << "The number is not on the list...\n";
	}
	else
	{
		cout << "The desired value was found on index: " << numberFound << endl;
	}

	// Searching an Array of Objects - When searching an array of objects the value being searched for is a member of an object, not the entire object. Not limited to arrays of integers.

	return 0;
}

int binarySearch(int array[], int lowest, int highest, int desiredValue)
{

	while (lowest <= highest)
	{
		int middleValue = (lowest + highest) / 2;
		if (array[middleValue] == desiredValue)
		{
			cout << "The number you are looking for is found! \n";
			return middleValue;
		}
		else if (array[middleValue] < desiredValue)
		{
			lowest = middleValue + 1;
		}
		else
		{
			highest = middleValue - 1;
		}
	}

	return -1;
}
