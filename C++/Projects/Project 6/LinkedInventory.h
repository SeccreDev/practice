#ifndef _LINKED_INVENTORY_
#define _LINKED_INVENTORY_
#include "Node.h"

class LinkedInventory
{
	private:
		Node *headPtr;

	public:
		// Constructor
		LinkedInventory(); // CORE METHOD

		// Destructor
		virtual ~LinkedInventory();

		// Methods
		bool insert(const string &nameOfItem, const string &description, const int &quantity, const int &price); // CORE METHOD	
		bool isEmpty() const; // CORE METHOD
		int getCurrentSize() const; // CORE METHOD
		bool remove(); // CORE METHOD
		int sellOneItem(const string &nameOfItem, const int &quantity); // STUB
		int sellAll(); // STUB
		void display() const; // CORE METHOD
		void clear(); // STUB


}; // End of LinkedInventory class
#endif
