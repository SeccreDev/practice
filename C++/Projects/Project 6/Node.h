#ifndef _NODE_
#define _NODE_
#include <iostream>
#include <string>
using namespace std;

class Node
{
	private:
		string itemName;
		string itemDescription;
		int itemQuantity;
		int itemPrice;
		Node *next; // address of the next Node
	public:
		// Default Constructor
		Node();
		
		// Constructors with parameters 
		Node(const string &nameOfItem, const string &description, const int &quantity, const int &price);
		Node(const string &nameOfItem, const string &description, const int &quantity, const int &price, Node *nextNodePtr);

		// Setter Methods
		void setItemName(const string &nameOfItem);
		void setItemDescription(const string &description);
		void setItemQuantity(const int &quantity);
		void setItemPrice(const int &price);
		void setNext(Node *nextNodePtr);

		// Getter Methods
		string getItemName() const;
		string getItemDescription() const;
		int getItemQuantity() const;
		int getItemPrice() const;
		Node *getNext() const;

}; // End of Node class
#endif
