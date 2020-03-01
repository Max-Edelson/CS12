#include <iostream>
#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase() : itemName("none"), itemDescription("none"), itemPrice(0), itemQuantity(0) {}
ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity) {
	this->itemName = itemName;
	this->itemDescription = itemDescription;
	this->itemPrice = itemPrice;
	this->itemQuantity = itemQuantity;
}

void ItemToPurchase::SetName(string itemName) { this->itemName = itemName; }
void ItemToPurchase::SetDescription(string itemDescription) { this->itemDescription = itemDescription; }
void ItemToPurchase::SetPrice(int itemPrice) { this->itemPrice = itemPrice; }
void ItemToPurchase::SetQuantity(int itemQuantity) { this->itemQuantity = itemQuantity; }

int ItemToPurchase::GetPrice() const { return itemPrice; }
int ItemToPurchase::GetQuantity() const { return itemQuantity; }
string ItemToPurchase::GetDescription() const { return itemDescription; }
string ItemToPurchase::GetName() const { return itemName; }

void ItemToPurchase::PrintItemCost() const {
	cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << (itemQuantity * itemPrice) << endl;
}

void ItemToPurchase::PrintItemDescription() const {
	cout << itemName << ": " << itemDescription << endl;
}

bool ItemToPurchase::operator==(const ItemToPurchase item) const {
	bool returnVal = false;
	if (this->itemName == item.itemName)
		returnVal = true;
	return returnVal;
}
