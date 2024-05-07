#include<iostream>
#include<string>
using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H
class Product
{
	private:
		string description;
		string category;
		int productID;
		double price;
		
	public:
		Product();
		Product(string d, string c, int id, double p);
		string getDescription();
		string getCategory();
		int getProductID();
		double getPrice();		
};
#endif
