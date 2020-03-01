#include "IntVector.h"
#include <iostream>
#include <stdexcept>

using namespace std;

IntVector::IntVector() : sz(0), cap(0) { data = NULL; }
IntVector::IntVector(unsigned size, int value) : sz(size), cap(size) {
	data = NULL;
	data = new int[sz];
	cout << "pointer: " << this->data << " was just created" << endl;
	for (unsigned i = 0; i < sz; i++) {
		data[i] = value;
	}
} 

IntVector::~IntVector() {
	cout << "POINTER: " << this->data << " was just deleted" << endl;
	delete [] data;
	data = NULL;
}

unsigned IntVector::size() const { return sz; }
unsigned IntVector::capacity() const { return cap; }

bool IntVector::empty() const {
	bool returnVal = true;
	if (sz > 0)
		returnVal = false;

	return returnVal;
}

const int& IntVector::at(unsigned index) const {
	if (index >= sz || index < 0)
		throw out_of_range("IntVector::at_range_check");
	else
		return data[index];
}

const int& IntVector::front() const {
	if (sz > 0)
		return data[0];
	else
		throw out_of_range("IntVector::at_range_check");
}

const int& IntVector::back() const {
	if (sz == 1)
                return data[0];
	else if (sz > 1)
		return data[sz - 1];
        else 
                throw out_of_range("IntVector::at_range_check");
}
