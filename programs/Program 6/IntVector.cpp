#include "IntVector.h"
#include <iostream>
#include <stdexcept>

using namespace std;

IntVector::IntVector() : sz(0), cap(0) { data = NULL; }
IntVector::IntVector(unsigned size, int value) : sz(size), cap(size) {
	data = NULL;
	data = new int[sz];
	//cout << "pointer: " << this->data << " was just created" << endl;
	for (unsigned i = 0; i < sz; i++) {
		data[i] = value;
		//cout << data[i] << endl;
	}
} 

IntVector::~IntVector() {
	//cout << "POINTER: " << this->data << " was just deleted" << endl;
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

int& IntVector::at(unsigned index) {
        if (index >= sz || index < 0) {
		//cout << "size: " << sz << " cap: " << cap << " index: " << index << endl;
                throw out_of_range("IntVector::at_range_check");
	}
        else
                return data[index];
}

void IntVector::clear() {
	sz = 0;
}

void IntVector::resize(unsigned size, int value) {
	if (size < sz) {
		sz = size;
	}
	else if (size > sz && size <= cap) {
		for (unsigned int i = sz; i < size; i++) {
			data[i] = value;
		}
		sz = size;
	}
	else if (size > cap) {
		
		int originalSize = sz;

		while (cap < size) {
			if ((cap + (size - cap)) <= (cap * 2)) {
				expand();
			}
			else {
				
				expand(size - cap);
			}
		}
		
		sz = size;

		for (unsigned int i = originalSize; i < sz; i++) {
			data[i] = value;
		}
	}

}

void IntVector::reserve(unsigned n) {
	if (cap == 0) {
		cap = n;
	}
	else if (n > cap) {
		expand(n - cap);
	}
}

void IntVector::assign(unsigned n, int value) {
	if (cap == 0) {
		resize(n, value);
	}
	else if (n <= cap) {
		sz = n;
		for (unsigned int i = 0; i < n; i++) {
			data[i] = value;
		}
	}
	else {
		if ((cap * 2) >= (cap + (n - cap))) {
			expand();
		}
		else {
			expand(n - cap);
		}
		sz = n;
		
		for (unsigned int i = 0; i < sz; i++) {
			data[i] = value;
		}
	}
}

void IntVector::push_back(int value) {
	if (cap == 0) {
		expand();
		sz++;
		data[0] = value;
	}
	else {
		if (sz + 1 > cap) {
			expand();
		}
		
		data[sz] = value;
		sz++;

	}
}

void IntVector::pop_back() {
	sz--;
}

void IntVector::expand() {
        if (cap > 0) {
                cap *= 2;

                int* temp = new int[cap];
                for (unsigned int i = 0; i < sz; i++) {
                        temp[i] = data[i];
                }

                delete [] data;

                data = temp;
		
		/*for (unsigned int i = 0; i < sz; i++) {
			cout << "data at i: " << data[i] << endl;
		}*/
        }
	else if (cap == 0) {
		data = NULL;
		data = new int[1];
		cap = 1;
	}
}

void IntVector::expand(unsigned amount) {
        if (cap > 0) {
                cap += amount;

                int* temp = new int[cap];
                for (unsigned int i = 0 ; i < sz; i++) {
                        temp[i] = data[i];
                }

                delete [] data;

                data = temp;
        }
	else if (cap == 0) {
                data = NULL;
                data = new int[amount];
                cap = amount;
        }
}

void IntVector::insert(unsigned index, int value) {

	if (index > sz) {
		throw out_of_range("IntVector::insert_range_check");
	}
		
	if (sz + 1 > cap) {
		expand();
		//cout << "expanded line 201" << endl;
	}

	if (index == sz) {
		//cout << "data at index = value" << endl;
		data[index] = value;
	}
	else if (index == 0 && cap == 1) {
		data[0] = value;
	}
	else if (index == 0 && cap > 1) {
		for (unsigned int i = sz - 1; i < cap; i--) {
			//cout << "i: " << i << endl;

			data[i + 1] = data[i];

			if (i == index) {
				//cout << "i: index" << endl;
				data[i] = value;
			}
		} 
	}
	else {
		//cout << "else statement" << endl;
		for (unsigned int i = sz - 1; i >= index; i--) {
			//cout << "i: " << i << " index: " << index << endl;

			data[i + 1] = data[i];
			if (i == index) {
				data[i] = value;
				//cout << "Inserted something at i: " << i << endl;
			}
		}
	}

	sz++;
}

void IntVector::erase(unsigned index) {
	if (sz == 0)
		throw out_of_range("IntVector::erase_range_check");
	else if (index > sz - 1)
		throw out_of_range("IntVector::erase_range_check");
	else {
		for (unsigned int i = index ; i < sz; i++) {
			data[i] = data[i + 1];
		}
		sz--;
	}
}

const int& IntVector::front() const {
	if (sz > 0)
		return data[0];
	else
		throw out_of_range("IntVector::at_range_check");
}

int& IntVector::front() {
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

int& IntVector::back() {
        if (sz == 1)
                return data[0];
        else if (sz > 1)
                return data[sz - 1];
        else
                throw out_of_range("IntVector::at_range_check");
}

