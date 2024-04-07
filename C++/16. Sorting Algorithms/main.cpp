#include <iostream>
using namespace std;

void bubbleSort(int array[], int size);
void displayArray(int array[], int size);

int main()
{
	// Sorting - arrange values into an order (alphabetical, descending, ascending)
	// Bubble Sort Algorithm - compares first two element and exchange them if they are out of order then it move to the next element and does the same
	//                         until the end of the array. It repeats this process for the whole array again until a pass through it is made with no exchanges.
	const int SIZE = 10;
	int numbers[SIZE] = {9, 3, 2, 1, 76, 2, 1, 8, 19, 0};
	bubbleSort(numbers, SIZE);
	displayArray(numbers, SIZE);

	return 0;
}

void bubbleSort(int array[], int size)
{
	bool wasSwapped = false;
	for (int i = 0; i < size - 1; i++)
	{
		wasSwapped = false;
		for (int j = 0 ; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				wasSwapped = true;
			}
		}
		if(wasSwapped == false)
		{
			break;
		}
	}
}

void displayArray(int array[], int size)
{
	cout << "Sorted array elements: ";
	for (int i = 0; i < size; i++)
	{
		cout << " " << array[i] << " ";
	}
}
