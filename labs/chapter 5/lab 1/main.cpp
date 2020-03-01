//include any standard libraries needed
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize) {
	
	double sum = 0;
	double mean = 0;

	for (int i = 0; i < arraySize; i ++) {
		sum += array[i];
	}
	
	mean = sum/arraySize;

	return mean;	
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index) {
	
	for (int i = index; i + 1 < arraySize; i++) {
		array[i] = array[i + 1];	
	}

	arraySize--;
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize) {
	
	for (int i = 0; i < arraySize; i++) {
		if (i == 0)
			cout << array[i];
		else
			cout << ", " << array[i];
	}
	cout << endl;
}


int ARR_CAP = 100;

int main(int argc, char *argv[]) {
	ifstream inFS;
	double currDouble = 0;
	int indexToRemove = '\0';
	int counter = 0;

   // verify file name provided on command line
	if (argc == 2) {
		inFS.open(argv[1]);

		if (inFS.is_open()) {
 			/*do {
				inFS >> currDouble;
				if (inFS.good())
					vector.push_back(currDouble);
			} while (!inFS.eof()); */
			
			double array[ARR_CAP];
			
			while (inFS >> currDouble) {
				array[counter] = currDouble;
				counter++;
			}

			cout << "Mean: " << mean(array, counter) << endl << endl;
			
			cout << "Enter index of value to be removed (0 to " << counter - 1 << "):  ";
                        cin >> indexToRemove;
                        cout << endl << endl;

			cout << "Before removing value: ";
			display(array, counter);
			cout << endl << endl;

			remove(array, counter, indexToRemove);
			cout << "After removing value: ";
			display(array, counter);
			cout << endl << endl;

			cout << "Mean: " << mean(array, counter) << endl;
		}	
	}


   // open file and verify it opened

   // Declare an array of doubles of size ARR_CAP.

    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.

    
   // Call the mean function passing it this array and output the 
   // value returned.
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.

	
   // Call the display function to output the array.

   
   // Call the remove function to remove the value at the index
   // provided by the user.
  
    
   // Call the display function again to output the array
   // with the value removed.

   
   // Call the mean function again to get the new mean

   
	return 0;
}
