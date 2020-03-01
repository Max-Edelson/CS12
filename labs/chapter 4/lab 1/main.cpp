#include <iostream>
#include "ItemToPurchase.h"

int main() {

	ItemToPurchase item1;
	ItemToPurchase item2;
	string currName;
	int currPrice;
	int currQuantity;

	cout << "Item 1" << endl;
	cout << "Enter the item name:" << endl;
	getline(cin, currName);
	cout << "Enter the item price:" << endl;
	cin >> currPrice;
	cout << "Enter the item quantity:" << endl;
	cin >> currQuantity;
	item1.SetName(currName);
	item1.SetPrice(currPrice);
	item1.SetQuantity(currQuantity);

	cout << endl;
	cin.ignore();
	
	cout << "Item 2" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, currName);
        cout << "Enter the item price:" << endl;
        cin >> currPrice;
        cout << "Enter the item quantity:" << endl;
        cin >> currQuantity;
        item2.SetName(currName);
        item2.SetPrice(currPrice);
        item2.SetQuantity(currQuantity);	
	
	cout << endl;
	cout << "TOTAL COST" << endl;
	cout << item1.GetName() << ' ' << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << (item1.GetQuantity() * item1.GetPrice()) << endl;
	cout << item2.GetName() << ' ' <<  item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << (item2.GetQuantity() * item2.GetPrice()) << endl << endl;
	cout << "Total: $" << ((item1.GetQuantity() * item1.GetPrice()) + (item2.GetQuantity() * item2.GetPrice())) << endl;

	return 0;
}
