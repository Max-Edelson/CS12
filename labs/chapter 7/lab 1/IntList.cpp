#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList() : head(NULL), tail(NULL) {}

IntList::~IntList() {
	while (head) {
		IntNode* temp = head->next;
		delete head;
		head = temp;
	}
	tail = head;
}

void IntList::push_front(int value) {
	IntNode* n = new IntNode(value);
	n->next = head;
	head = n;
	
	if (head->next == NULL) {
		tail = head;
	}
	else if (head->next->next == NULL) {
		tail = head->next;
	}	
}

void IntList::pop_front() {
	if (head != NULL) {
		IntNode* n = head->next;
		delete head;
		head = n;	
	}
}

bool IntList::empty() const {
	bool returnVal = false;

	if (head == NULL)
		returnVal = true;

	return returnVal;
}

const int& IntList::front() const {
	return head->data;
}

const int& IntList::back() const {
	return tail->data;
}

ostream& operator<<(ostream& ostreamVal, const IntList& list) {
	IntNode* curr = list.head;
	while (curr) {
		if (curr == list.head)
			ostreamVal << curr->data;
		else 
			ostreamVal << ' ' << curr->data;
		
		curr = curr->next;
	}
	
	return ostreamVal;
}
