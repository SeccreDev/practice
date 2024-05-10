#include "LinkedInventory.h"

//// Implementation file for LinkedInventory.h
/// CORE Methods
// Constructor
/*
	Method: LinkedInventory();
	Parameters: none
	Return Values: none
	Purpose: To set the headPtr to null
*/
LinkedInventory::LinkedInventory()
{
	headPtr = NULL;
}

// Methods
/*
	Method: insert(const string &nameOfItem, const string &description, const int &quantity, const int &price)
	Parameters: nameOfItem - a string representing the name of an item, description - a string representing the description of the item
				quantity - a int representing the quantity of the item, price - an int representing the price of the item
	Return Values: Returns true to indicate a successful run
	Purpose: Creates a new node in the beginning of the LinkedInventory filled with passed values
*/
bool LinkedInventory::insert(const string &nameOfItem, const string &description, const int &quantity, const int &price)
{
	// Creating a new node which will be filled with the passed values
	Node *newNodePtr = new Node();
	newNodePtr->setItemName(nameOfItem);
	newNodePtr->setItemDescription(description);
	newNodePtr->setItemQuantity(quantity);
	newNodePtr->setItemPrice(price);

	// Sets the next pointer as the current headPtr
	newNodePtr->setNext(headPtr);

	// Sets the headPtr to point to the newNode
	headPtr = newNodePtr;

	return true;
}

/*
	Method: isEmpty()
	Parameters: None
	Return Values: Returns true to indicate that the LinkedInventory is empty, false if not
	Purpose: Indicates whether the LinkedInventory is empty or not.
*/
bool LinkedInventory::isEmpty() const
{
	return headPtr == NULL;
}

/*
	Method: getCurrentSize()
	Parameters: None
	Return Values: Returns an integer that represents the size of the LinkedInventory
	Purpose: Indicates the size of the LinkedInventory
*/
int LinkedInventory::getCurrentSize() const
{
	int counter = 0;
	Node *currentNode = headPtr;
	while (currentNode != NULL)
	{
		counter++;
		currentNode = currentNode->getNext();
	}
	return counter;
}

/*
	Method: remove()
	Parameters: None
	Return Values: Returns true to indicate that the last Node has been removed, false if there are no items to be removed
	Purpose: Deletes the last element of the list
*/
bool LinkedInventory::remove()
{
	Node* previousNode = headPtr;
	Node* currentNode = headPtr->getNext();

		// Check whether there is an item to be deleted
		while (!isEmpty())
		{
			if (previousNode->getNext() == NULL) // If the node points towards a NULL then...
			{
				delete previousNode; // Delete the node
				previousNode = NULL; // Get rid of dangling pointers
				headPtr = NULL;  // Let the previousNode be the new last node
				return true;
			}
			else if (currentNode->getNext() == NULL) // if the node points towards a NULL then...
			{
				delete currentNode; // Delete the node
				currentNode = NULL; // Get rid of dangling pointers
				previousNode->setNext(NULL); // Let the previousNode be the new last node
				return true;
			}
			else
			{
				// Update the previousNode and currentNode until the last node is found
				previousNode = previousNode->getNext(); 
				currentNode = currentNode->getNext(); 
			}
		}
		return false;
}

/*
	Method: display()
	Parameters: None
	Return Values: none
	Purpose: Display all the nodes with their respective items
*/
void LinkedInventory::display() const
{
	Node *currentNode = headPtr;
	cout << "================START=OF=INVENTORY============================" << endl;
	for (int i = 0; i < getCurrentSize(); i++)
	{
		cout << "------------------------------------------------------" << endl
			<< "Item name: " << currentNode->getItemName() << endl
			<< "Description: " << currentNode->getItemDescription() << endl
			<< "Quantity: " << currentNode->getItemQuantity() << endl
			<< "Price: " << currentNode->getItemPrice() << "$" << endl
			<< "------------------------------------------------------" << endl;
		currentNode = currentNode->getNext();
	}
	cout << "==================END=OF=INVENTORY============================\n";
}

/// Other Methods
/*
	Method: int sellOneItem(const string &nameOfItem, const int &quantity)
	Parameters: nameOfItem - a string representing the name of an item, 
				quantity - a int representing the quantity of the item
	Return Values: an int representing gold
	Purpose: The method removes the item from the inventory if all of it is sold, or updates the quantity if the not all items are sold. 
*/
int LinkedInventory::sellOneItem(const string& nameOfItem, const int& quantity)
{
	int gold = 0;
	int quantityLeft = 0;
	Node *previousNode = headPtr;
	Node *currentNode = headPtr->getNext();
	// Check whether the first item is the item we are searching for
	if (previousNode->getItemName() == nameOfItem)
	{
		quantityLeft = (previousNode->getItemQuantity() - quantity);
		if (quantityLeft > 0)
		{
			previousNode->setItemQuantity(quantityLeft);
			gold = (previousNode->getItemPrice() * quantity);
			return gold;
		}
		else
		{
			gold = (previousNode->getItemPrice() * previousNode->getItemQuantity());
			headPtr = previousNode->getNext();
			previousNode->setNext(NULL);
			delete previousNode;
			previousNode = NULL;
			return gold;
		}
	}
	else
	{
		while (currentNode != NULL)
		{
			if (currentNode->getItemName() == nameOfItem)
			{
				quantityLeft = (currentNode->getItemQuantity() - quantity);
				if (quantityLeft > 0)
				{
					currentNode->setItemQuantity(quantityLeft);
					gold = (currentNode->getItemPrice() * quantity);
					return gold;
				}
				else
				{
					gold = (currentNode->getItemPrice() * currentNode->getItemQuantity());
					previousNode->setNext(currentNode->getNext());
					currentNode->setNext(NULL);
					delete currentNode;
					currentNode = NULL;
					return gold;
				}

			}
			else
			{
				//Update the previousNode and currentNode until the last node is found
				previousNode = previousNode->getNext();
				currentNode = currentNode->getNext();
			}
		}
	}
	// Went through the LinkedInventory looking for the item
	return -1;
}

/*
	Method: int sellAll()
	Parameters: None
	Return Values: an int representing gold
	Purpose: The method sells all items and removes them from inventory.
*/
int LinkedInventory::sellAll()
{
	Node* currentNode = headPtr;
	int gold = 0;
	for (int i = 0; i < getCurrentSize(); i++)
	{
		gold += sellOneItem(currentNode->getItemName(), currentNode->getItemQuantity());
		currentNode = currentNode->getNext();
	}
	return gold;
}

/*
	Method: clear()
	Parameters: None
	Return Values: None
	Purpose: Delete all the allocated nodes
*/
void LinkedInventory::clear()
{
	while (!isEmpty())
	{
		remove();
	}
}
/*
	Method: ~LinkedInventory()
	Parameters: None
	Return Values: None
	Purpose: Deletes all the allocated nodes
*/
LinkedInventory::~LinkedInventory()
{
	clear();
}
