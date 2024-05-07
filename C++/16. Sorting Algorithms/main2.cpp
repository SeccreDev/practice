#include <iostream>
#include <vector>
using namespace std;

class Person
{
	private:
		string name;
		int age;
	public:
		Person()
		{
			name = "";
			age = 0;
		}
		Person(string n, int a)
		{
			name = n;
			age = a;
		}
		
		string getName()
		{
			return name;
		}
		
		int getAge()
		{
			return age;
		}
};

void bubbleSort(vector<Person> &vector);
void swap(Person &a, Person &b);
void displayVector(vector<Person> vector);

int main()
{
	vector <Person> students;
	students.push_back(Person("Mary", 20));
	students.push_back(Person("Bob", 18));
	students.push_back(Person("Ann", 50));
	students.push_back(Person("Steven", 33));
	
	displayVector(students);
	bubbleSort(students);
	displayVector(students);
}

void bubbleSort(vector<Person> &vector)
{
	for(int maxElement = vector.size() - 1; maxElement > 0; maxElement--)
	{
		for(int index = 0; index < maxElement; index++ )
		{
			if (vector[index].getName() > vector[index + 1].getName())
			{
				swap(vector[index], vector[index + 1]);
			}
		}
	}
}

void swap(Person &a, Person &b)
{
	Person temp;
	temp = a;
	a = b;
	b = temp;
}

void displayVector(vector<Person> vector)
{
	cout << "The people in the vector are:\n";
	for(int i = 0; i < vector.size(); i++)
	{
		cout << vector[i].getName() << ": " 
			 << vector[i].getAge() << endl;
	}

}
