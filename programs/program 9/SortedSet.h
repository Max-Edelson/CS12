#ifndef SORTEDSET_H
#define SORTEDSET_H

#include "IntList.h"
#include <iostream>

using namespace std;

class SortedSet : public IntList {

	public:
	SortedSet();
	SortedSet(const SortedSet &);
	SortedSet(const IntList &);
	~SortedSet();
	bool in(int data);
	SortedSet operator|(const SortedSet& b);
	SortedSet operator&(const SortedSet& b);
	
	//mutators
	void add(int data);
	void push_front(int data);
	void push_back(int data);
	void insert_ordered(int data);
	SortedSet operator|=(const SortedSet& b);
	SortedSet operator&=(const SortedSet& b);


};

#endif
