#include "minFunc.h"
#include <iostream>

using namespace std;

const int* min(const int arr[], int arrSize) {
	
	if (arrSize > 0) {
		if (arrSize == 1)
			return arr;

		const int* p = min(arr + 1, arrSize - 1); 

		if (arr[0] <= *p)
			return arr;
		else
			return p;
	}

	const int* l = nullptr;
	
	return l;
}
