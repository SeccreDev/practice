#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

Product::Product()
{
	description = "";
	category = "";
	productID = 0;
	price = 0;
}
Product::Product(string d, string c, int id, double p)
{
	description = d;
	category = c;
	productID = id;
	price = p;	
}

string Product::getCategory()
{
	return category;
}

string Product::getDescription()
{
	return description;
}

int Product::getProductID()
{
	return productID;
}

double Product::getPrice()
{
	return price;
}
