#include "SortedSet.h"
#include <iostream>

using namespace std;

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet& cpy) : IntList(cpy) {}

SortedSet::SortedSet(const IntList& cpy) : IntList(cpy) {

	this->selection_sort();
	this->remove_duplicates();
}

SortedSet::~SortedSet() {
	this->clear();
}

bool SortedSet::in(int data) {

	IntNode* temp = head;
	
	while (temp) {
		if (temp->data == data)
			return true;
		temp = temp->next;
	}
	return false;
}

SortedSet SortedSet::operator|(const SortedSet& b) {
	
	if (b.head) {
		IntNode* currA = this->head;
		IntNode* currB = b.head;

		SortedSet* n = new SortedSet();
		
		while (currA) {
			n->insert_ordered(currA->data);
			currA = currA->next;
		}

		while (currB) {
			n->insert_ordered(currB->data);
			currB = currB->next;
		}
		return *n;
	}
	return *this; 
}
SortedSet SortedSet::operator&(const SortedSet& b) {

	SortedSet* n = new SortedSet;

	if (b.head) {
		if (this->head && b.head) {	

			int aLength = 0;
			int bLength = 0;

			IntNode* currA = this->head;
			IntNode* currB = b.head;
			
			while (currA) {
				aLength++;
				currA = currA->next;
			}

			while (currB) {
				bLength++;
				currB = currB->next;
			}
			
			currA = this->head;
			currB = b.head;

			if (aLength >= bLength) {

				for (IntNode* i = currA; i != nullptr; i = i->next) {
					for (IntNode* j = currB; j != nullptr; j = j->next) {

					if (j->data == i->data)		
						n->insert_ordered(i->data);
					}
				}
			}
			else {
				for (IntNode* i = currB; i != nullptr; i = i->next) {
					for (IntNode* j = currA; j != nullptr; j = j->next) {

					if (j->data == i->data)
						n->insert_ordered(i->data);
					}
				}
			}
		}
	}
	return *n;
}

//mutators
void SortedSet::add(int data) {

	if (head) {
	
		IntNode* prev = head;
		IntNode* curr = head->next;

		if (curr == nullptr) {
			if (head->data > data) {
				IntNode* p = new IntNode(data);
				p->next = head;
				head = tail;
				head = p;
			}
			else if (head->data < data) {
				IntNode* p = new IntNode(data);
				head->next = p;
				p->next = nullptr;
				tail = p;
			}
		}
		else {
			
			while (curr->next != nullptr) {
				//cout << "called for data: " << data << endl;
				if (curr->data >= data)
					break;
				curr = curr->next;
				prev = prev->next;
			}
			
			if (curr->data == data) {}
			else if (head->data > data ) {
				IntNode* p = new IntNode(data);
				p->next = prev;
				head = p;
			}
			else if (curr->data > data && prev->data != data) {
				IntNode* p = new IntNode(data);
				p->next = prev->next;
				prev->next = p;
			}
			else if (curr->next == nullptr && prev->data != data) {
				IntNode* p = new IntNode(data);
                                p->next = curr->next;
                                curr->next = p;
				tail = p;	
				//cout << "check 6" << endl;
			}
		}
	}
	else {
		head = new IntNode(data);
		tail = head;
		head->next = nullptr;
	}	
}

void SortedSet::push_front(int data) {
	add(data);
}

void SortedSet::push_back(int data) {
	add(data);
}

void SortedSet::insert_ordered(int value) {
/*
        if (head == nullptr || head->data > value) {
		IntNode* p = new IntNode(value);
                p->next = head;
                head = p;
		
		if (p->next == nullptr)
			tail = p;
        }
        else {
                IntNode* curr = head;
		IntNode* p = new IntNode(value);

                while(curr->next != nullptr && curr->next->data <= value) {
                        curr = curr->next;
                }
			
		if (curr->next->data != value) {
			p->next = curr->next;
                	curr->next = p;
		}

		if (p->next == nullptr)
	                tail = p;
        }
*/

	add(value);
}

SortedSet SortedSet::operator|=(const SortedSet& b) {
	SortedSet temp = *this | b;
        *this = temp;
        return temp;
}

SortedSet SortedSet::operator&=(const SortedSet& b) {
	SortedSet temp = *this & b;
	*this = temp;
	return temp;
}





















