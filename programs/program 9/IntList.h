#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>

using namespace std;

struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};

class IntList {
 protected:
        IntNode *head;
        IntNode *tail;
 public:
        IntList();
        ~IntList();
        IntList(const IntList &cpy);
        void push_front(int);
        void pop_front();
        bool empty() const;
        void push_back(int value);
        void selection_sort();
        void insert_ordered(int value);
        void remove_duplicates();
        void clear();
        const int & front() const;
        const int & back() const;
        IntList & operator=(const IntList &rhs);
        friend ostream & operator<<(ostream &, const IntList &);
};


#endif
