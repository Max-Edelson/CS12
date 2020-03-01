#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList() : head(NULL), tail(NULL) {}

//do I need the following marked out code?
IntList::IntList(const IntList &cpy) {

	cout << "copy constructor called" << endl;

	if (cpy.head) {
		head = new IntNode(cpy.head->data);
		IntNode* currNode = head;
		IntNode* currCpy = cpy.head->next;

		while (currCpy != nullptr) {
			
			currNode->next = new IntNode(currCpy->data);
			currNode = currNode->next;
			currCpy = currCpy->next;
		}

		tail = currNode;
	}
	else {
		head = nullptr;
		tail = head;
	}
}

IntList::~IntList() {
        while (head) {
                IntNode* temp = head->next;
                delete head;
                head = temp;
        }
        tail = head;
}

IntList& IntList::operator=(const IntList &rhs) {
	
	if (this != &rhs) {
		
		if (head) {
			clear();
		}
		IntNode* o = rhs.head;

		while (o != nullptr) {
			if (head == nullptr) {
				head = new IntNode(o->data);
			}	
			else {
				push_back(o->data);
			}	
			o = o->next;
		}
	}

	return *this;
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

void IntList::push_back(int value) {
	if (head != NULL) {
		IntNode* p = new IntNode(value);
		p->data = value;
		
		IntNode* last = head;

		while (last->next) {
			last = last->next;
		}

		last->next = p;
		tail = p;
	}
	else {
		IntNode* p = new IntNode(value);
		head = p;
		tail = p;
	}
}

void IntList::clear() {
	while (head) {
		IntNode* next = head->next;
		delete head;
		head = next;	
	}
	tail = head;
}

void IntList::selection_sort() {
	if (head) {
		for (IntNode* i = head; i != NULL; i = i->next) {
			IntNode* min = i;
			for (IntNode* j = i->next; j != NULL; j = j->next) {
				if (j->data < min->data)
					min = j;	
			}
			int temp = i->data;
			i->data = min->data;
			min->data = temp;
		}
	}
}

void IntList::insert_ordered(int value) {
	IntNode* p = new IntNode(value);	

	//make sure tail is set at the end
	if (head == nullptr || head->data > value) {
		p->next = head;
		head = p;
		
		if (p->next == nullptr)
			tail = p;
	}	
	else {
		IntNode* curr = head;
		
		while(curr->next != nullptr && curr->next->data < value) {
			curr = curr->next;
		}

		p->next = curr->next;
		curr->next = p;	
	}

	if (p->next == nullptr)
		tail = p;
}

//0, 10, 20, 40, 50, 80

//60

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

void IntList::remove_duplicates() {

	for (IntNode* i = head; i != NULL; i = i->next) {
		for (IntNode* j = i->next; j !=NULL; j = j->next) {
			IntNode* current = i;
			
			while (current->next != j)
				current = current->next;
		
			if (j->data == i->data) {
				current->next = j->next;
				if (j == tail)
					tail = current;
				
				IntNode* temp = j;	
				delete temp;		
			}
		}
	}
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
