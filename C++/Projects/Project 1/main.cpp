#include <iostream>
#include <string>
using namespace std;

class Inventory
{
	private:
		int itemNumber;
		int quantity;
		double cost;

	public:
		Inventory()
		{
			itemNumber = 0;
			quantity = 0;
			cost = 0;
		}

		Inventory(int i, int q, double c)
		{
			setItemNumber(i);
			setQuantity(q);
			setCost(c);
		}

		void setItemNumber(int i)
		{
			itemNumber = i;
		}

		void setQuantity(int q)
		{
			quantity = q;
		}

		void setCost(double c)
		{
			cost = c;
		}

		int getItemNumber()
		{
			return itemNumber;
		}

		int getQuantity()
		{
			return quantity;
		}

		double getCost()
		{
			return cost;
		}

		double getTotalCost()
		{
			return cost * quantity;
		}
};

void printProduct(Inventory product);

int main()
{
	Inventory firstProduct;
	Inventory secondProduct(14, 2, 12.99);
	int userItemNumber, userQuantity;
	double userCost;

	do
	{
		cout << "Enter the item number of the product (positive value): ";
		cin >> userItemNumber;
	} while (userItemNumber < 0);

	do
	{
		cout << "Enter the quantity (positive value): ";
		cin >> userQuantity;
	} while (userQuantity < 0);

	do
	{
		cout << "Enter the cost (positive value): ";
		cin >> userCost;
	} while (userCost < 0);

	firstProduct.setItemNumber(userItemNumber);
	firstProduct.setQuantity(userQuantity);
	firstProduct.setCost(userCost);

	printProduct(firstProduct);
	printProduct(secondProduct);
}

void printProduct(Inventory product)
{
	cout << " ~~~~~~~~ PRODUCT ~~~~~~~~ \n";
	cout << "Product Number: " << product.getItemNumber() << endl;
	cout << "Quantity: " << product.getQuantity() << endl;
	cout << "Cost: " << product.getCost() << endl;
	cout << "--------------------------\n";
	cout << "Total: " << product.getTotalCost() << endl << endl;
}
