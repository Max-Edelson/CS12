#include "IntVector.h"
#include <iostream>

using namespace std;

int main() {
	IntVector vector(3,0);
	cout << "size: " << vector.size() << " capacity: " << vector.capacity() << endl;	
	
	IntVector vector2(100, 99);
	cout << "vector2 at 0: " << vector2.at(0) << endl;
	cout << "vector2 at 30: " << vector2.at(30) << endl;
	//vector2.at(100);
	//vector2.at(-1);
	cout << "vector 2 at index 4: " << vector2.at(3) << endl;

	cout << "size of vector 2: " << vector2.size() << " capacity of vector 2: " << vector2.capacity() << endl;
	
	IntVector vector3;

	cout << "size of vector 3: " << vector3.size() << " capacity of vector 3: " << vector3.capacity() << endl;

	cout << "is vector 2 empty: " << vector2.empty() << endl;
	cout << "is vector 3 empty: " << vector3.empty() << endl;
	
	cout << "first element in vector 2: " << vector2.front() << endl;
	//cout << "first element in vector 3: " << vector3.front() << endl;

	cout << "last element in vector 2: " << vector2.back() << endl;
	//cout << "last element in vector 3: " << vector3.back() << endl;

	return 0;
}
