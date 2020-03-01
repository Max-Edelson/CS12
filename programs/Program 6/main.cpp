#include "IntVector.h"
#include <iostream>

using namespace std;

int main() {
	//IntVector vector(3,0);
	//cout << "size: " << vector.size() << " capacity: " << vector.capacity() << endl;	
	
	//IntVector vector2(100, 99);
	//cout << "vector2 at 0: " << vector2.at(0) << endl;
	//cout << "vector2 at 30: " << vector2.at(30) << endl;
	//vector2.at(100);
	//vector2.at(-1);
	//cout << "vector 2 at index 4: " << vector2.at(3) << endl;

	//cout << "size of vector 2: " << vector2.size() << " capacity of vector 2: " << vector2.capacity() << endl;
	
	//IntVector vector3;

	//cout << "size of vector 3: " << vector3.size() << " capacity of vector 3: " << vector3.capacity() << endl;

	//cout << "is vector 2 empty: " << vector2.empty() << endl;
	//cout << "is vector 3 empty: " << vector3.empty() << endl;
	
	//cout << "first element in vector 2: " << vector2.front() << endl;
	//cout << "first element in vector 3: " << vector3.front() << endl;

	//cout << "last element in vector 2: " << vector2.back() << endl;
	//cout << "last element in vector 3: " << vector3.back() << endl;

	/*for (unsigned int i = 0 ; i < vector2.size(); i++) {
		cout << "i: " << i << " = " << vector2.at(i) << endl;
	}*/

	//vector2.insert(50,290);
	//vector2.insert(0,290);
	//vector2.insert(100,290);
	
	//vector2.erase(2);
	//vector2.erase(0);
	//vector2.erase(100);

	//vector2.push_back(6);
	//vector2.push_back(50);

	//vector2.pop_back();
	//vector2.pop_back(5);

	//vector2.clear();

	//vector2.resize(5);
	//vector2.resize(250,55);
	//vector2.resize(0);

	//vector2.reserve(250);
	//cout << vector2.capacity() << endl;
	//vector2.reserve(5);
	//cout << vector2.capacity() << endl;

	//vector2.assign(100, 5);
	//vector2.assign(250, 5);
	//vector2.assign(1, 5);
	//vector2.assign(0,5);

/*
	cout << "Cap: " << test.capacity() << endl;
	cout << "Size: " << test.size() << endl << endl;
	
	vector.push_back(5);

	cout << "Cap: " << test.capacity() << endl;
        cout << "Size: " << test.size() << endl << endl;
*/

	//IntVector vector(2, 848);

	//vector.insert(2, -220);
	//vector.insert(0, -220);
	//vector.push_back(5);
	//vector.insert(0,3);

	IntVector vector;
	//vector.resize(403);

	//vector.insert(0, 5);	
	//vector.insert(-1, 5);
	//vector.insert(1, 5);
	//vector.insert(0);
	//cout << vector.at(0) << endl;
	
	//IntVector vector5(5, 3);	

	//for (unsigned int i = 0; i < vector5.size(); i++) {
        //        cout << vector5.at(i) << endl;
        //}

	//cout << "size: " << vector5.size() << endl;
        //cout << "cap: " << vector5.capacity() << endl;

	//vector5.insert(2, 11);
	//vector5.insert(5, 11);
	//vector5.insert(0, 11);

	//IntVector newV(1, -104);
	//newV.insert(0, -221);

	IntVector newV(20);
	newV.resize(100);

	cout << "size: " << newV.size() << endl;
	cout << "cap: " << newV.capacity() << endl;

	for (unsigned int i = 0; i < newV.size(); i++) {
		//cout << newV.at(i) << endl;
	}

	//IntVector v(200);
	//v.resize(403);	
	//v.insert(203, 1);

	//cout << "size: " << v.size() << endl;
	//cout << "cap: " << v.capacity() << endl;


	/*for (unsigned int i = 0 ; i < vector2.size(); i++) {
		cout << "i: " << i << " = " << vector2.at(i) << endl;
        }*/

	return 0;
}
