#include "Node.h"

/// Implementation file for Node.h
// Constructor 
/*
	Method: Node()
	Parameters: none
	Return Values: none
	Purpose: To set the node to nothing and set the next pointer to null
*/
Node::Node()
{
	next = NULL;
}

/*
	Method: Node(const string &nameOfItem, const string &description, const int &quantity, const int &price)
	Parameters: nameOfItem - a string representing the name of an item, description - a string representing the description of the item
				quantity - a int representing the quantity of the item, price - an int representing the price of the item
	Return Values: none
	Purpose: Initializes itemName, itemDescription, itemQuantity, itemPrice to passed values and set the next pointer to null
*/
Node::Node(const string &nameOfItem, const string &description, const int &quantity, const int &price)
{
	itemName = nameOfItem;
	itemDescription = description;
	itemQuantity = quantity;
	itemPrice = price;
	next = NULL;
}

/*
	Method: Node(const string &nameOfItem, const string &description, const int &quantity, const int &price, Node *nextNodePtr)
	Parameters: nameOfItem - a string representing the name of an item, description - a string representing the description of the item
				quantity - a int representing the quantity of the item, price - an int representing the price of the item
				nextNodePtr - a Node pointer to the address of another Node.
	Return Values: none
	Purpose: Initializes itemName, itemDescription, itemQuantity, itemPrice to passed values and set the next pointer to nextNodePtr
*/
Node::Node(const string &nameOfItem, const string &description, const int &quantity, const int &price, Node *nextNodePtr)
{
	itemName = nameOfItem;
	itemDescription = description;
	itemQuantity = quantity;
	itemPrice = price;
	next = nextNodePtr;
}

// Setter Methods
/*
	Method: setItemName(const string &nameOfItem)
	Parameters: nameOfItem - a string representing the name of the item
	Return Values: none
	Purpose: initializes the itemName field to passed value
*/
void Node::setItemName(const string &nameOfItem)
{
	itemName = nameOfItem;
}

/*
	Method: setItemDescription(const string &description)
	Parameters: description - a string representing the description of the item
	Return Values: none
	Purpose: initializes the itemDescription field to passed value
*/
void Node::setItemDescription(const string &description)
{
	itemDescription = description;
}

/*
	Method: setItemQuantity(const int &quantity)
	Parameters: quantity - a int representing the quantity of the item
	Return Values: none
	Purpose: initializes the itemQuantity field to passed value
*/
void Node::setItemQuantity(const int &quantity)
{
	itemQuantity = quantity;
}

/*
	Method: setItemPrice(const int &price);
	Parameters: price - an int representing the price of the item
	Return Values: none
	Purpose: initializes the itemPrice field to passed value
*/
void Node::setItemPrice(const int &price)
{
	itemPrice = price;
}

/*
	Method: setNext(Node *nextNodePtr);
	Parameters: nextNodePtr - a Node pointer to the address of another Node.
	Return Values: none
	Purpose: set the next pointer to the passed value of nextNodePtr
*/
void Node::setNext(Node *nextNodePtr)
{
	next = nextNodePtr;
}

// Getter Methods
/*
	Method: getItemName()
	Parameters: none
	Return Values: a string, representing the name of the item
	Purpose: returns the itemName field
*/
string Node::getItemName() const
{
	return itemName;
}

/*
	Method: getItemDescription()
	Parameters: none
	Return Values: a string, representing the description of the item
	Purpose: returns the itemDescription field
*/
string Node::getItemDescription() const
{
	return itemDescription;
}

/*
	Method: getItemQuantity()
	Parameters: none
	Return Values: a int, representing the quantity of the item
	Purpose: returns the itemQuantity field
*/
int Node::getItemQuantity() const
{
	return itemQuantity;
}

/*
	Method: getItemPrice()
	Parameters: none
	Return Values: a int, representing the price of the item
	Purpose: returns the itemPrice field
*/
int Node::getItemPrice() const
{
	return itemPrice;
}

/*
	Method: *getNext()
	Parameters: none
	Return Values: an address, representing the address of the next Node
	Purpose: returns the *next field
*/
Node* Node::getNext() const
{
	return next;
}

