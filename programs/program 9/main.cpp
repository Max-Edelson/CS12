#include "IntList.h"
#include "SortedSet.h"

#include <iostream>

using namespace std;

int main() {

	SortedSet set1 = SortedSet();
	set1.add(-70);
	set1.add(-27);
	set1.add(-39);
	set1.add(13);
	set1.add(110);
	set1.add(85);
	set1.add(110);
	cout << "Set1: " << set1 << endl;	

	SortedSet set2 = SortedSet();

	//SortedSet set3 = set1 & set2;
	//SortedSet set3 = set1 &= set2;
	//SortedSet set3 = set1 | set2;
	//SortedSet set3 = set1 |= set2;

	//cout << "Set3: " << set3 << endl;
	//cout << "Set1: " << set1 << endl;

	/*
	cout << "Set1: " << set1 << endl;
	//set1.add(175);
	set1.push_front(175);
	cout << "175 push front" << endl;
	//set1.add(50);
	set1.push_front(50);
	cout << "50 added" << endl;
	//set1.add(50);
	set1.push_back(50);
        cout << "50 added" << endl;

	cout << "list: " << set1 << endl;
*/
/*
	set1.add(500);
	cout << "500 added" << endl;
	set1.add(0);
	cout << "Set1: " << set1 << endl;

	IntList list1 = IntList();
	cout << "Set 3: " << list1 << endl;
	list1.push_back(175);
	list1.push_back(200);
	list1.push_back(50);

	SortedSet set2 = SortedSet(set1);

	cout << "set 2: " << set2 << endl;

	SortedSet set3 = SortedSet(list1);

	cout << "Set 3: " << list1 << endl;
*/	
	return 0;
}
