#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

//helper
bool IntList::exists(IntNode * node, int value) const {
	
	if (!node)
		return false;
	else if (node->data == value)
		return true;
	return exists(node->next, value);
}

//global
bool IntList::exists(int value) const {
	if (exists(head, value))
		return true;
	return false;
}

//helper
ostream & operator<<(ostream & out, IntNode * node) {

	if (node) {
		if (node->next == nullptr) {
			out << node->data;
                	out << node->next;
		}
		else {
			out << node->data << " ";
			out << node->next;
		}
	}
	return out;
}

//global
ostream & operator<<(ostream & out, const IntList&  list) {
	if (list.head)
		out << list.head;

	return out;
}
