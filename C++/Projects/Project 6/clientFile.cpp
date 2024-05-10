#include "LinkedInventory.h"

int main()
{
	LinkedInventory* newInventory = new LinkedInventory();
	int choice, quantity, price, itemSold, gold = 0;
	string item, description;
	bool removed;

	while (true)
	{
		cout << "Choose an option:\n"
			<< "1 - Insert an item to the inventory\n"
			<< "2 - Remove the last item\n"
			<< "3 - Sell an item\n"
			<< "4 - Sell all items\n"
			<< "5 - Display the inventory\n"
			<< "6 - Destroy all items\n"
			<< "7 - Display current size of the inventory\n"
			<< "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		// A menu for the user 
		switch (choice)
		{
			case 1:
				cout << "============================================\n";
				cout << "Name of the item: ";
				getline(cin, item);

				cout << "Description: ";
				getline(cin, description);

				cout << "Quantity: ";
				do
				{
					cin >> quantity;
					if (quantity <= 0 || quantity >= 99)
					{
						cout << "Please enter a valid number between 0 and 99: ";
					}
				} while (quantity <= 0 || quantity >= 99); // Pre-condition for quantity
				
				cout << "Gold value: ";
				do
				{
					cin >> price;
					if (price < 0)
					{
						cout << "You like debts don't you? Enter a valid number above 0!: ";
					}
				} while (price < 0); // Pre-condition for price
				newInventory->insert(item, description, quantity, price); // Inserts all the values passed by the user in a Node.
				cout << "Item successfully added!\n" << "============================================\n";
				break;
			
			case 2:
				cout << "============================================\n";
				removed = newInventory->remove();
				if (removed)
				{
					cout << "Successfully removed the last item!\n";
				}
				else
				{
					cout << "No items to remove...\n";
				}
				cout << "============================================\n";
				break;

			case 3:
				cout << "============================================\n";
				cout << "Enter the item you wish to sell: ";
				getline(cin, item);
				cout << "How many you wish to sell: ";
				do
				{
					cin >> quantity;
					if (quantity <= 0 || quantity >= 99)
					{
						cout << "Please enter a valid number 0 - 99: ";
					}
				} while (quantity <= 0 || quantity >= 99); // Pre-condition for quantity

				gold = newInventory->sellOneItem(item, quantity);
				if (gold == -1)
				{
					cout << "It appears that the item does not exist\n";
				}
				else
				{
					cout << "You gained: " << gold << " gold coins!\n";
				}
				cout << "============================================\n";
				break;

			case 4:
				cout << "============================================\n";
				gold = newInventory->sellAll();
				if (gold == -1)
				{
					cout << "It appears that the item does not exist\n";
				}
				else
				{
					cout << "You gained: " << gold << " gold coins!\n";
				}
				cout << "============================================\n";
				break;

			case 5:
				newInventory->display();
				break;

			case 6:
				cout << "============================================\n";
				newInventory->clear();
				cout << "Inventory cleared!\n";
				cout << "============================================\n";
				break;

			case 7:
				cout << "============================================\n";
				cout << "The number of items in the inventory is: " << newInventory->getCurrentSize() << endl;
				cout << "============================================\n";
				break;

			default:
				cout << "============================================\n";
				cout << "Not a valid choice, please try again\n";
				cout << "============================================\n";
		}
	}
	return 0;
}
