/*
	Alan Montero Colon
	Purpose: Book Company Project - print out information for an order of books
*/
#include <iostream>
#include <fstream>
using namespace std;

// Global constant variables
const float bookPrice = 10.99;
const float shippingPrice = 2.99;

// Function Prototypes
void bookInfo(int &bookO, int &bookStock, float &specialC);
int calculateBookToShip(int bookO, int bookStock);
int calculateBackOrder(int bookO, int bookStock);
float calculateBookPrice(int bookRTS);
float calculateTotalShipping(float specialC);
float calculateTotalPrice(float totalSP, float bookP);
void saveToFile(int bookO, int bookStock, int bookRTS, int bO, float bookP, float totalSP, float total);

int main()
{
	float specialCharges,
		bookPrice,
		totalShippingPrice,
		totalPrice;

	int bookOrdered,
		bookInStock,
		bookReadyToShip,
		backOrder;

	cout << "Hello, this program will print out information for an order of books" << endl;

	bookInfo(bookOrdered, bookInStock, specialCharges);
	bookReadyToShip = calculateBookToShip(bookOrdered, bookInStock);
	backOrder = calculateBackOrder(bookOrdered, bookInStock);
	bookPrice = calculateBookPrice(bookReadyToShip);
	totalShippingPrice = calculateTotalShipping(specialCharges);
	totalPrice = calculateTotalPrice(totalShippingPrice, bookPrice);
	saveToFile(bookOrdered, bookInStock, bookReadyToShip, backOrder, bookPrice, totalShippingPrice, totalPrice);

	return 0;
}

// Function Declarations

/*
	Function: void bookInfo(int &bookO, int &bookStock, float &specialC)
	Parameters: Receives the bookO, bookStock and specialC variables
	Return Values: Set the passed variables
	Purpose: To set the variables bookO, bookStock and specialC to a value chosen by the user
*/
void bookInfo(int& bookO, int& bookStock, float& specialC)
{
	cout << "Books ordered: ";
	do
	{
		cin >> bookO;
		if (bookO <= 0)
			cout << "Please reenter the number of books ordered: ";
	} while (bookO <= 0);

	cout << "Books in stock: ";
	do
	{
		cin >> bookStock;
		if (bookStock < 0)
			cout << "Please reenter the number of books in stock: ";
	} while (bookStock < 0);

	cout << "Enter any special shipping charges: ";
	do
	{
		cin >> specialC;
		if (specialC < 0 || specialC > 100)
			cout << "Please enter a valid charge: ";
	} while (specialC < 0 || specialC > 100);
}

/*
	Function: int calculateBookToShip(int bookO, int bookStock )
	Parameters: Receives bookO and bookStock
	Return Values: bookReadyToShip
	Purpose: Given the bookO and bookStock, this function evaluates the number of books ready to ship from current stock
*/
int calculateBookToShip(int bookO, int bookStock)
{
	if (bookO <= bookStock)
		return bookO;
	else
		return bookStock;
}

/*
	Function: int calculateBackOrder(int bookO, int bookStock)
	Parameters: Receives bookO and bookStock
	Return Values: backOrder
	Purpose: Calculates backorder by applying (bookO - bookStock)
*/
int calculateBackOrder(int bookO, int bookStock)
{
	if (bookO > bookStock)
		return bookO - bookStock;
}

/*
	Function: float calculateBookPrice(int bookRTS)
	Parameters: Receives bookReadyToShip
	Return Values: bookPrice
	Purpose: Calculates the price of the books ready for shipment
*/
float calculateBookPrice(int bookRTS)
{
	return bookRTS * bookPrice;
}

/*
	Function: float calculateTotalShipping(float specialC)
	Parameters: Receives specialC
	Return Values: totalShippingPrice
	Purpose: Calculates the total shipping price by applying (specialC + shippingPrice)
*/
float calculateTotalShipping(float specialC)
{
	return specialC + shippingPrice;
}

/*
	Function: float calculateTotalPrice(float totalSP, float bookP)
	Parameters: Receives totalShippingPrice and bookP
	Return Values: totalPrice
	Purpose: Calculates the total price by applying (totalShippingPrice + bookPrice)
*/
float calculateTotalPrice(float totalSP, float bookP)
{
	return totalSP + bookP;
}

/*
	Function: void saveToFile(int bookO, int bookStock, int bookRTS, int bO, float bookP, float totalSP, float total)
	Parameters: Receives bookOrdered, bookStock, bookReadyToShip, bookO, bookPrice, totalShippingPrice and totalPrice
	Return Values: None
	Purpose: Outputs to a file all the information regarding the order of books
*/
void saveToFile(int bookO, int bookStock, int bookRTS, int bO, float bookP, float totalSP, float total)
{
	ofstream outputFile("Receipt Books.txt");
	outputFile << "Book Company Order" << endl
		<< "================================================" << endl
		<< "Books ordered: " << bookO << endl
		<< "Books in stock: " << bookStock << endl
		<< "Books ready for shipment: " << bookRTS << endl;

	if (bookO > bookStock)
	{
		outputFile << "Books Backorder: " << bO << endl;
	}
	outputFile << "Books price: $" << bookP << endl;


	if (bookRTS != 0)
	{
		outputFile << "Total shipping price: $" << totalSP << endl
			<< "Total price: $" << total << endl;
	}
	else if (bookRTS == 0)
	{
		outputFile << "Total shipping price: $" << 0 << endl
			<< "Total price: $" << 0 << endl;
	}

	outputFile << "================================================";
	outputFile.close();
	cout << "----------------------------------" << endl
		<< "The Information Has Been Printed" << endl
		<< "Thank You For Using This Program!" << endl << endl;
}

