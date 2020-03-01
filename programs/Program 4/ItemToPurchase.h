#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <iostream>

using namespace std;

class ItemToPurchase {

	private:
	string itemName;
	string itemDescription;
	int itemPrice;
	int itemQuantity;	

	public:
	void SetName(string);
	void SetDescription(string);
	void SetPrice(int);
	void SetQuantity(int);
	string GetName() const;
	string GetDescription() const;
	void PrintItemCost() const;
	void PrintItemDescription() const;
	int GetPrice() const;
	int GetQuantity() const;
	ItemToPurchase();
	ItemToPurchase(string, string, int, int);
	bool operator==(const ItemToPurchase) const;
};

#endif
