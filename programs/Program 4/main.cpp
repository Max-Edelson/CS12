#include <iostream>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart& cart) {
	string userChoice = "\0";
	string itemName;
	string itemDescription;
	int itemQuantity;
	int itemPrice;
	ItemToPurchase newItem;
	bool notAnOption = false;
	
	/*cout << "MENU" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Remove item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output items' descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit" << endl << endl;
	cout << "Choose an option:" << endl;
	*/

	while (userChoice != "q") {
		if (!notAnOption) {
			cout << "MENU" << endl;
			cout << "a - Add item to cart" << endl;
			cout << "d - Remove item from cart" << endl;
			cout << "c - Change item quantity" << endl;
			cout << "i - Output items' descriptions" << endl;
			cout << "o - Output shopping cart" << endl;
			cout << "q - Quit" << endl << endl;
		}
		cout << "Choose an option:" << endl;		

		cin >> userChoice;
		if (userChoice == "a") {
			cout << endl << "ADD ITEM TO CART" << endl;
			string gettingbuffer = "\0";
			cin.get(gettingbuffer);
			cout << "Buffer: " << gettingbuffer << endl;
			cout << "Enter the item name:" << endl;
			getline(cin, itemName);
			cout << "Enter the item description:" << endl;
			getline(cin, itemDescription);
			cout << "Enter the item price:" << endl;
			cin >> itemPrice;
			cout << "Enter the item quantity:" << endl;
			cin >> itemQuantity;
			cout << endl;

			newItem.SetName(itemName);
			newItem.SetDescription(itemDescription);
			newItem.SetPrice(itemPrice);
			newItem.SetQuantity(itemQuantity);

			cart.AddItem(newItem);
		}	
		else if (userChoice == "d") {
			cout << endl << "REMOVE ITEM FROM CART" << endl;
			cout << "Enter name of item to remove:" << endl;
			cin.ignore(1);
			getline(cin, itemName);
			cart.RemoveItem(itemName);
			cout << endl;
		}
		else if (userChoice == "c") {
			cin.ignore(1);
			cout << "CHANGE ITEM QUANTITY" << endl;
			cout << "Enter the item name:" << endl;
			getline(cin, itemName);
			cout << "Enter the new quantity:" << endl;
			cin >> itemQuantity;

			itemDescription = cart.GetDescriptionOfItem(itemName);
			itemPrice = cart.GetPriceOfItem(itemName);

			newItem.SetName(itemName);
			newItem.SetDescription(itemDescription);
			newItem.SetPrice(itemPrice);
			newItem.SetQuantity(itemQuantity);

			cart.ModifyItem(newItem);
		}
		else if (userChoice == "i") {
			cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
                        cart.PrintDescriptions();
			//needed?
			cout << endl;
		}
		else if (userChoice == "o") {
			cout << "OUTPUT SHOPPING CART" << endl;
                        cart.PrintTotal();
		}
		else {
			notAnOption = true;
			cin.ignore(1);
		}
	}
}

int main() {
	string name;
	string date;

	cout << "Enter customer's name:" << endl;
	getline(cin, name);
	cout << "Enter today's date:" << endl;
	getline(cin, date);

	cout << endl << "Customer name: " << name << endl;
	cout << "Today's date: " << date << endl << endl;

	ShoppingCart cart(name, date);

	PrintMenu(cart);

	return 0;
}
