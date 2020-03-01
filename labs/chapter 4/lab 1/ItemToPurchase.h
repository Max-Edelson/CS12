#include <iostream>

using namespace std;

class ItemToPurchase {

	private:
	string itemName;
	int itemPrice;
	int itemQuantity;	

	public:
	void SetName(string);
	void SetPrice(int);
	void SetQuantity(int);
	string GetName() const;
	int GetPrice() const;
	int GetQuantity() const;
	ItemToPurchase();
};
