#include "IntList.h"
#include <iostream>

int main() {

	cout << "\nlist1 constructor called" << endl;
	IntList list1;
	cout << "pushfront 10" << endl;
	list1.push_front(10);
	cout << "pushfront 20" << endl;
	list1.push_front(20);
	cout << "pushfront 30" << endl;
	list1.push_front(30);
	cout << "list1: " << list1 << endl;
	cout << "pop" << endl;
	list1.pop_front();
	cout << "list1: " << list1 << endl;
	cout << "pop" << endl;
	list1.pop_front();
	cout << "list1: " << list1 << endl;
	cout << "pop" << endl;
	list1.pop_front();
	cout << "list1: " << list1 << endl;
	cout << "pushfront 100" << endl;
	list1.push_front(100);
	cout << "pushfront 200" << endl;
	list1.push_front(200);
	cout << "pushfront 300" << endl;
	list1.push_front(300);
	cout << "list1: " << list1 << endl;
	cout << endl;
	cout << "Calling list1 destructor..." << endl;

	IntList list2;
	cout << "called push_back on an empty list(5)" << endl;
	list2.push_back(5);
	cout << "called push_back on a list with 1 node(28)" << endl;
	list2.push_back(28);
	cout << "called push_back on a list with 2 nodes(0)" << endl;
	list2.push_back(0);
	cout << "list2: :" << list2 << endl;
	cout << "clear" << endl;
	list2.clear();
	cout << "list2: :" << list2 << endl;
	cout << "called clear" << endl;
	cout << "list2: :" << list2 << endl;
	list2.push_back(99);
	list2.push_back(0);
	list2.push_back(50);
	list2.push_back(2);
	cout << "list2: :" << list2 << endl;
	cout << "called selection_sort" << endl;
	list2.selection_sort();
	cout << "list2: :" << list2 << endl;
	list2.clear();
	cout << "selection_sort called on an empty list" << endl;
	list2.selection_sort();
	cout << "list2: :" << list2 << endl;
	cout << "insert_ordered(5) into an empty list" << endl;
	list2.insert_ordered(5);
	cout << "list2: :" << list2 << endl;
	cout << "insert ordered(0)" << endl;
	list2.insert_ordered(0);
	cout << "list2: :" << list2 << endl;
	cout << "insert ordered(100) " << endl;
	list2.insert_ordered(100);
	cout << "list2: :" << list2 << endl;
	cout << "insert ordered(100) " << endl;
	list2.insert_ordered(100);
	cout << "list2: :" << list2 << endl;
	cout << "insert ordered(100) " << endl;
	list2.insert_ordered(100);
	cout << "list2: :" << list2 << endl;
	cout << "insert ordered(0) " << endl;
	list2.insert_ordered(0);
	cout << "list2: :" << list2 << endl;
	cout << "remove duplicates" << endl;
	list2.remove_duplicates();
	cout << "list2: :" << list2 << endl;

	list2.clear();
	list2.push_back(-2);
	list2.push_back(-30);
	list2.push_back(-19);
	list2.push_back(-2);
	list2.push_back(0);
	list2.selection_sort();
	list2.insert_ordered(10);
	cout << "List 2: " << list2 << endl;




	return 0;

}
