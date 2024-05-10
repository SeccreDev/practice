#include <iostream>
#include "Node.h"

int main()
{
	Node myInventory;
	Node myInventory2("Potato", "Can be eaten", 70, 2);
	Node myInventory3("Banana", "Looks rotten", 1, 2, &myInventory2);
	// Look at contents of myInventory
	cout << "myInventory item is : " << myInventory.getItemName() << endl
		<< "myInventory item description is : " << myInventory.getItemDescription() << endl
		<< "myInventory item quantity is : " << myInventory.getItemQuantity() << endl
		<< "myInventory item price is : " << myInventory.getItemPrice() << "$" << endl
		<< "myInventory points to : " << myInventory.getNext() << endl
		<< "------------------END-OF-INVENTORY--------------------------" << endl << endl;

	// Look at contents of myInventory2
	cout << "myInventory item is : " << myInventory2.getItemName() << endl
		<< "myInventory item description is : " << myInventory2.getItemDescription() << endl
		<< "myInventory item quantity is : " << myInventory2.getItemQuantity() << endl
		<< "myInventory item price is : " << myInventory2.getItemPrice() << "$" << endl
		<< "myInventory points to : " << myInventory2.getNext() << endl
		<< "------------------END-OF-INVENTORY--------------------------" << endl << endl;

	// Look at contents of myInventory3
	cout << "myInventory item is : " << myInventory3.getItemName() << endl
		<< "myInventory item description is : " << myInventory3.getItemDescription() << endl
		<< "myInventory item quantity is : " << myInventory3.getItemQuantity() << endl
		<< "myInventory item price is : " << myInventory3.getItemPrice() << "$" << endl
		<< "myInventory points to : " << myInventory3.getNext() << endl
		<< "------------------END-OF-INVENTORY--------------------------" << endl << endl;

	return 0;
}
