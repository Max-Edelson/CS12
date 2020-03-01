#include <iostream>
#include <vector>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

using namespace std;

ShoppingCart::ShoppingCart() : customerName("none"), currentDate("January 1, 2016") { vector<ItemToPurchase> cartItems; }
ShoppingCart::ShoppingCart(string customerName, string currentDate) { 
	this->customerName = customerName;
	this->currentDate = currentDate;
	vector<ItemToPurchase> cartItems;
}

string ShoppingCart::GetCustomerName() const { return customerName; }
string ShoppingCart::GetDate() const { return currentDate; }

void ShoppingCart::AddItem(ItemToPurchase item) {
	cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string item) {
	bool found = false;

	for (unsigned int i = 0; i < cartItems.size(); i++) {
		if (cartItems.at(i).GetName() == item && cartItems.size() > 0) {
			//ItemToPurchase first = cartItems.at(i);
			cartItems.at(i) = cartItems.at(cartItems.size() - 1);
			cartItems.pop_back();	
			found = true;
		}	
	}
	
	if (!found)
		cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::ModifyItem(const ItemToPurchase item) {
	bool found = false;

	for (unsigned int i = 0; i < cartItems.size(); i++) {
		if (cartItems.at(i) == item) {
			if (item.GetName() != "none" && item.GetPrice() != 0 && item.GetDescription() != "none") {
				cartItems.at(i).SetDescription(item.GetDescription());
				cartItems.at(i).SetQuantity(item.GetQuantity());
				cartItems.at(i).SetPrice(item.GetPrice());
			}
			found = true;
		}
	}

	if (!found)
		cout << "Item not found in cart. Nothing modified." << endl << endl;
}

string ShoppingCart::GetDescriptionOfItem(string item) const {
	string description = "none";          
                                
        for (unsigned int i = 0; i < cartItems.size(); i++) {
                if (cartItems.at(i).GetName() == item)
                        description = cartItems.at(i).GetDescription();
        }                       
                        
        return description;  
}

int ShoppingCart::GetPriceOfItem(string item) const {
	int price = 0;

	for (unsigned int i = 0; i < cartItems.size(); i++) {
		if (cartItems.at(i).GetName() == item)
			price = cartItems.at(i).GetPrice();	
	}

	return price;
}

int ShoppingCart::GetNumItemsInCart() const {
	int quantity = 0;

	for (unsigned int i = 0; i < cartItems.size(); i++ ){
		quantity += cartItems.at(i).GetQuantity();	
	}

	return quantity; 
}

int ShoppingCart::GetCostOfCart() const {
	int cost = 0;

	for (unsigned int i = 0; i < cartItems.size(); i++ ) {
		cost += (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
	}

	return cost;
}

void ShoppingCart::PrintTotal() const {
	cout << customerName << "'s Shopping Cart - " << currentDate << endl;
	if (cartItems.size() > 0)
		cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
	else {
		cout << "Number of Items: 0" << endl << endl;
	}

	if (cartItems.size() > 0) { 
		for (unsigned int i = 0; i < cartItems.size(); i++) {
			cartItems.at(i).PrintItemCost();
		}

		cout << endl << "Total: $" << ShoppingCart::GetCostOfCart() << endl << endl;
	}
	else {
		cout << "SHOPPING CART IS EMPTY" << endl << endl;
		cout << "Total: $0" << endl;
		cout << endl;
	}
}

void ShoppingCart::PrintDescriptions() const {
	cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
	cout << "Item Descriptions" << endl;

	for (unsigned int i = 0; i < cartItems.size(); i++) {
		cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
	} 
}
