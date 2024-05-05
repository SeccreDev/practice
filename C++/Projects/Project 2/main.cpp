/*
	Alan Montero Colon
	Purpose: Book Company Project - print out information for an order of books
*/
#include <iostream>
#include <fstream>
using namespace std;

// Global constant variables
const float comicPrice = 9.99;
const float shippingPrice = 3.99;

// Function Prototypes
void comicBookInfo(int &comicO, int &comicStock, float &specialC);
int calculateComicToShip(int comicO, int comicStock);
int calculateBackOrder(int comicO, int comicStock);
float calculateComicsPrice(int comicRTS);
float calculateTotalShipping(float specialC);
float calculateTotalPrice(float totalSP, float comicP);
void saveToFile(int comicO, int comicStock, int comicRTS, int bO, float comicP, float totalSP, float total);

int main()
{	
	float specialCharges,
		  comicsPrice,
		  totalShippingPrice,
		  totalPrice;

	int comicsOrdered,
		comicsInStock,
		comicReadyToShip,
		backOrder;

	cout << "Hello, this program will print out information for an order of comics" << endl;

	comicBookInfo(comicsOrdered, comicsInStock, specialCharges);
	comicReadyToShip = calculateComicToShip(comicsOrdered, comicsInStock);
	backOrder = calculateBackOrder(comicsOrdered, comicsInStock);
	comicsPrice = calculateComicsPrice(comicReadyToShip);
	totalShippingPrice = calculateTotalShipping(specialCharges);
	totalPrice = calculateTotalPrice(totalShippingPrice, comicsPrice);
	saveToFile(comicsOrdered, comicsInStock, comicReadyToShip, backOrder, comicsPrice, totalShippingPrice, totalPrice);

	return 0;
}

// Function Declarations

/*
	Function: void comicBookInfo(int &comicO, int &comicStock, float &specialC)
	Parameters: Receives the comicsOrdered, comicsInStock and specialCharges variables
	Return Values: Set the passed variables
	Purpose: To set the variables comicsOrdered, comicsInStock and specialCharges to a value chosen by the user
*/
void comicBookInfo(int &comicO, int &comicStock, float &specialC)
{
	cout << "Comic books ordered: ";
	do 
	{
		cin >> comicO;
		if (comicO <= 0)
			cout << "Please reenter the number of comic books ordered: ";
	} while (comicO <= 0);

	cout << "Comic books in stock: ";
	do
	{
		cin >> comicStock;
		if (comicStock < 0)
			cout << "Please reenter the number of comic books in stock: ";
	} while (comicStock < 0);

	cout << "Enter any special shipping charges: ";
	do
	{
		cin >> specialC;
		if (specialC < 0 || specialC > 100)
			cout << "Please enter a valid charge: ";
	} while (specialC < 0 || specialC > 100);
}

/*
	Function: int calculateComicToShip(int comicO, int comicStock)
	Parameters: Receives comicsOrdered and comicsInStock
	Return Values: comicReadyToShip
	Purpose: Given the comicsOrdered and comicsInStock, this function evaluates the number of comic books ready to ship from current stock
*/
int calculateComicToShip(int comicO, int comicStock)
{
	if (comicO <= comicStock)
		return comicO;
	else
		return comicStock;
}

/*
	Function: int calculateBackOrder(int comicO, int comicStock)
	Parameters: Receives comicsOrdered and comicsInStock
	Return Values: backOrder
	Purpose: Calculates backorder by applying (comicsOrdered - comicsInStock)
*/
int calculateBackOrder(int comicO, int comicStock)
{
	if (comicO > comicStock)
		return comicO - comicStock;
}

/*
	Function: float calculateComicsPrice(int comicRTS)
	Parameters: Receives comicReadyToShip
	Return Values: comicsPrice
	Purpose: Calculates the price of the comic books ready for shipment
*/
float calculateComicsPrice(int comicRTS)
{
	return comicRTS * comicPrice;
}

/*
	Function: float calculateTotalShipping(float specialC)
	Parameters: Receives specialCharges 
	Return Values: totalShippingPrice
	Purpose: Calculates the total shipping price by applying (specialCharges + shippingPrice)
*/
float calculateTotalShipping(float specialC)
{
	return specialC + shippingPrice;
}

/*
	Function: float calculateTotalPrice(float totalSP, float comicP)
	Parameters: Receives totalShippingPrice and comicsPrice
	Return Values: totalPrice
	Purpose: Calculates the total price by applying (totalShippingPrice + comicsPrice)
*/
float calculateTotalPrice(float totalSP, float comicP)
{
	return totalSP  + comicP;
}

/*
	Function: void saveToFile(int comicO, int comicStock, int comicRTS, int bO, float comicP, float totalSP, float total)
	Parameters: Receives comicsOrdered, comicsInStock, comicReadyToShip, backOrder, comicsPrice, totalShippingPrice and totalPrice
	Return Values: None
	Purpose: Outputs to a file all the information regarding the order of comic books
*/
void saveToFile(int comicO, int comicStock, int comicRTS, int bO, float comicP, float totalSP, float total)
{
	ofstream outputFile("Receipt Comics.txt");
	outputFile << "Amazing Comic Book Company Order" << endl
			   << "================================================" << endl
		       << "Comics ordered: " << comicO << endl
		       << "Comics in stock: " << comicStock << endl
		       << "Comics ready for shipment: " << comicRTS << endl;

	if (comicO > comicStock)
	{
		outputFile << "Comics Backorder: " << bO << endl;
	}
	outputFile << "Comics price: $" << comicP << endl;


	if (comicRTS != 0)
	{
		outputFile << "Total shipping price: $" << totalSP << endl
			       << "Total price: $" << total << endl;
	} 
	else if (comicRTS == 0)
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

