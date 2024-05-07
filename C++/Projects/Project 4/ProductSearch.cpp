/*
	Purpose: Product Search 
*/
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
using namespace std;

void swap(Product &a, Product &b);
void selectionSortByID(vector<Product> &v);
void selectionByPriceAsc(vector<Product> &v);
void selectionByPriceDesc(vector<Product> &v);
int binarySearch(vector<Product> &v, int id);
void displayInfo(Product p);
void displaySearchResults(vector<Product> &v, char sort, string cat, double p);
void getUserCharacter(char &ch);
void getUserCategory(string &c);
void userPriceLimit(double &pL);
void validateUserId(int &userId);

int main()
{
  // Declaring and Initializing a vector with some products
	vector <Product> products;
	products.push_back(Product("Sony a10 Camera", "cameras", 1001, 1998.99));
	products.push_back(Product("Canon EOS M50", "cameras", 5023, 604.99));
	products.push_back(Product("Canon PowerShot SX420", "cameras", 2341, 199.00));
	products.push_back(Product("Kids Camera", "cameras", 1587, 38.99));
	products.push_back(Product("Kodak PIXPRO", "cameras", 9231, 76.99));
	products.push_back(Product("Tea Tree Special Shampoo", "beauty", 3322, 30.18));
	products.push_back(Product("CND Essentials Nail & Cuticle Oil", "beauty", 7892, 8.50));
	products.push_back(Product("Philips Nerelco Multigroom", "beauty", 9802, 19.95));
	products.push_back(Product("35 Color Eyeshadow Palette", "beauty", 1278, 9.98));
	products.push_back(Product("Oreos Snack Stacks", "food", 2052, 8.55));
	products.push_back(Product("KIND Bars", "food", 6890, 14.22));
	products.push_back(Product("Viva Natural Coconut Oil", "food", 4768, 13.29));
	products.push_back(Product("Nike's Running Shorts", "sports", 8912, 20.99));
	products.push_back(Product("All Purpose dumbbells", "sports", 1942, 36.99));
	products.push_back(Product("Acer Aspire Laptop", "computers", 7823, 352.99));

	// Variables
	bool infinite = true;
	int userMenuChoice, 
		userChosenId,
		position;
	char userSortedChoice;
	string userCategory;
	double priceLimit;

	cout <<     "           Hi, welcome to the store!         " << endl;
	while (infinite == true)
	{
		cout << "|-------------------------------------------|" << endl
			 << "|                   MENU                    |" << endl
			 << "|===========================================|" << endl
			 << "|1) Search for product by ID                |" << endl
		     << "|2) Search by category and price            | " << endl
		 	 << "|___________________________________________|" << endl << endl
			 << "Choose an option (1 or 2): ";
		cin >> userMenuChoice;
		switch (userMenuChoice)
		{
			case 1: validateUserId(userChosenId);
					position = binarySearch(products, userChosenId);
					if (position == -1)
					{
						cout << "Product Not Found" << endl << endl;
					}
					else
					{
						displayInfo(products[position]);
					}
					break;
			
			case 2: getUserCharacter(userSortedChoice);
					getUserCategory(userCategory);
					userPriceLimit(priceLimit);
					displaySearchResults(products, userSortedChoice, userCategory, priceLimit);
					break;

			default: cout << "Invalid option, restarting the program..." << endl << endl << endl;
					 break;
		}
	}
	return 0;
}

/*
	Function: swap
	Parameters: a -- a product object, b -- a product object
	Return: Does not return a value
	Purpose: This function exhanges the the values of parameters a and b.
*/
void swap(Product &a, Product &b)
{
	Product z = a;
	a = b;
	b = z;
}

/*
	Function: selectionSortByID
	Parameters: v -- vector of products
	Return: Does not return a value
	Purpose: This function sorts the a vector of products in ascending order
			 based on the productID. THis must be done utilizing the selection sort
			 algorithm
*/
void selectionSortByID(vector<Product> &v)
{
	int minIndex, minValue;
	for (int start = 0; start < v.size(); start++)
	{
		minIndex = start;
		minValue = v[start].getProductID();
		for (int index = start + 1; index < v.size(); index++)
		{
			if (v[index].getProductID() < minValue)
			{
				minValue = v[index].getProductID();
				minIndex = index;
			}
		}
		swap(v[minIndex], v[start]);
	}
}

/*
	Function: selectionByPriceAsc
	Parameters: v -- vector of products
	Return: Does not return a value
	Purpose: This function sorts the a vector of products in ascending order
			 based on the price. This must be done utilizing the selection sort
			 algorithm
*/
void selectionByPriceAsc(vector<Product> &v)
{
	int minIndex;
	double minValue;
	for (int start = 0; start < v.size(); start++)
	{
		minIndex = start;
		minValue = v[start].getPrice();
		for (int index = start + 1; index < v.size(); index++)
		{
			if (v[index].getPrice() < minValue)
			{
				minValue = v[index].getPrice();
				minIndex = index;
			}
		}
		swap(v[minIndex], v[start]);
	}
}

/*
	Function: selectionByPriceDesc
	Parameters: v -- vector of products
	Return: Does not return a value
	Purpose: This function sorts the a vector of products in descending order
			 based on the price. This must be done utilizing the selection sort
			 algorithm
*/
void selectionByPriceDesc(vector<Product> &v)
{
	int maxIndex;
	double maxValue;
	for (int start = 0; start < v.size(); start++)
	{
		maxIndex = start;
		maxValue = v[start].getPrice();
		for (int index = start + 1; index < v.size(); index++)
		{
			if (v[index].getPrice() > maxValue)
			{
				maxValue = v[index].getPrice();
				maxIndex = index;
			}
		}
		swap(v[maxIndex], v[start]);
	}
}

/*
	Function: binarySearch
	Parameters: v -- vector of products, id -- search key
	Return: The index of the matching product, or -1 if no match is found
	Purpose: This function returns the index of the first matched product based on the
			 search key. If no product is found with the corresponding productID,
			 this function returns -1. This function utilizes the binary search algorithm.
*/
int binarySearch(vector<Product> &v, int id)
{
	selectionSortByID(v);
	int first = 0;
	int middle;
	int last = v.size();
	int position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (v[middle].getProductID() == id)
		{
			found = true;
			position = middle;
		}
		else if (v[middle].getProductID() > id)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

/*
	Function: displayInfo
	Parameters: p
	Return: no return value
	Purpose: This function displays all product information for p (description, category,id, price)
*/
void displayInfo(Product p)
{
	cout << "=============================================" << endl
		 << "Description: " << p.getDescription() << endl
	 	 << "Category: " << p.getCategory() << endl
		 << "Id: " << p.getProductID() << endl
		 << "Price: " << p.getPrice() << endl << endl;
}

/*
	Function: displaySearchResults
	Parameters: v -- vector of products
				sort -- a character representing A - Ascending or D - Descending
				cat -- the category to be searched on
				p -- the price limit for the search
	Return: no return value
	Purpose: This function sorts the vector by price in ascending order if the sort
			 paramameter is A or in descending order if the sort paremeter is D.
			 The function then finds all products in the searched category (cat) that
			 are less then the price limit (p).
			 The function displays the product information for all matches.
			 In case no matches are found, this function displays: "No matching products were found"
			 This function is based on a linear search algorithm, but contains 2 search keys.
*/
void displaySearchResults(vector<Product> &v, char sort, string cat, double p)
{
	if (sort == 'A')
		selectionByPriceAsc(v);
	else if (sort == 'D')
		selectionByPriceDesc(v);
	
	bool found = false;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getCategory() == cat)
		{
			if (p > v[i].getPrice())
			{
				displayInfo(v[i]);
				found = true;
			}
		}
		
	}

	if (found == false)
		cout << "No matching products were found " << endl << endl;
}

/*
	Function: getUserCharacter
	Parameters: ch - a character 
	Return: Does not return a value
	Purpose: This function sets the variable passed by a character chosen by the user
*/
void getUserCharacter(char &ch)
{
		cout << "Sort the products based on their price. Enter 'A' for an ascending order, else enter 'D' for a descending order: " << endl;
		cin >> ch;
		ch = toupper(ch);
		cin.ignore();
}

/*
	Function: getUserCategory
	Parameters: c - a string 
	Return: Does not return a value
	Purpose: This function sets the variable passed by a string chosen by the user
*/
void getUserCategory(string &c)
{
	cout << "Enter the category: ";
	getline(cin, c);
}

/*
	Function:  userPriceLimit
	Parameters: priceLimit -- a double 
	Return: Does not return a value
	Purpose: This function sets the variable passed by a value chosen by the user
*/
void userPriceLimit(double &pL)
{
	cout << "Price limit: ";
	cin >> pL;
	cout << endl;
}

/*
	Function: validateUserId
	Parameters: userId -- an int
	Return: Does not return a value
	Purpose: This function sets the variable passed by a value chosen by the user
*/
void validateUserId(int &userId)
{
	do
	{
		cout << "Choose an ID number between 1000 and 9999: ";
		cin >> userId;
	} while (userId > 9999 || userId < 1000);
}
