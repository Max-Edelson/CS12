#include <iostream>
#include <vector>

#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart {

	private:
	string customerName;
	string currentDate;
	vector<ItemToPurchase> cartItems;

	public:
	string GetCustomerName() const;
	string GetDate() const;
	void AddItem(const ItemToPurchase);
	void RemoveItem(const string);
	void ModifyItem(const ItemToPurchase);
	int GetNumItemsInCart() const;
	int GetCostOfCart() const;
	void PrintTotal() const;
	int GetPriceOfItem(string) const;
	void PrintDescriptions() const;	
	string GetDescriptionOfItem(string) const;
	ShoppingCart();
	ShoppingCart(string, string);
};
