#include <iostream>
using namespace std;

void bubbleSort(int array[], int size);
void displayArray(int array[], int size);
void selectionSort(int array[], int size);

int main()
{
	// Sorting - arrange values into an order (alphabetical, descending, ascending)
	// Bubble Sort Algorithm - compares first two element and exchange them if they are out of order then it move to the next element and does the same
	//                         until the end of the array. It repeats this process for the whole array again until a pass through it is made with no exchanges.
	//                         Bubble sort is easy to understand and implement but inefficient for large arrays
	const int SIZE = 10;
	int numbers[SIZE] = {9, 3, 2, 1, 76, 2, 1, 8, 19, 0};
	bubbleSort(numbers, SIZE);
	displayArray(numbers, SIZE);

	// Selection Sort - It locate the smallest element in the array and exchange it with the element in position 0. Then locates the next smallest element and exchanges it with the
	//                  element in position 1. It continues to do this until all elements are in order.
	//                  Selection Sort is more efficient than Bubble Sort but is considered harder to understand and implement
	int numbers2[SIZE] = { 9, 3, 2, 1, 76, 2, 1, 8, 19, 0 };
	selectionSort(numbers2, SIZE);
	displayArray(numbers2, SIZE);

	// Sorting an Array of Objects - The key field determines how the object will be ordered, when exchanging the contents of array elements entire objects must be exchanged,
	//								 not just the key fields in the object

	return 0;
}

void bubbleSort(int array[], int size)
{
	bool wasSwapped;
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
	cout << endl;
}

void selectionSort(int array[], int size)
{
	int minValue;
	for (int i = 0; i < size - 1; i++)
	{
		minValue = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[minValue])
			{
				minValue = j;
			}
		}
		if (minValue != i)
		{
			swap(array[minValue], array[i]);
		}
	}
}
