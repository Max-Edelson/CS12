#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

double interpolation(double flightAngle, const vector<double>& angles, const vector<double>& coefficients) {
	double returnValue;

	for (unsigned int i = 0; i < angles.size(); i++) {
		if (flightAngle == angles.at(i))
			returnValue = coefficients.at(i);
	}
	
	for (unsigned int i = 0; i < angles.size() - 1; i++) {
		if (flightAngle > angles.at(i) && flightAngle < angles.at(i + 1)) {
			double test1 = (flightAngle - angles.at(i))/(angles.at(i + 1) - angles.at(i));
			double test2 = coefficients.at(i + 1) - coefficients.at(i);
			returnValue = coefficients.at(i) + test1 * test2;//+ ((flightAngle - angles.at(i))/(angles.at(i + 1) - angles.at(i)))(coefficients.at(i + 1) - coefficients.at(i));
		}
	}
	return returnValue;
}

bool isOrdered(const vector<double>& angles) {
	bool returnVal = true;
	
	//for (unsigned int i = 0; i < angles.size() - 2; i++) {
		//if (angles.at(i + 1) < angles.at(i))
			//returnStatement = false;	
	//}

	for (unsigned int i = 1; i < angles.size(); i++) {
		if (angles.at(i) < angles.at(i - 1))
			returnVal = false;
		else {}
	}

	return returnVal;
}

void reorder(vector<double>& angles, vector<double>& coefficients) {
	double temp;
	
	cout << "Before ordered" << endl;
	for (unsigned int i = 0; i < angles.size(); i++) {
		cout << "angle: " << angles.at(i) << "       coefficient: " << coefficients.at(i) << endl;
	}
	if (angles.size() == 0) {}
	else {
		for (unsigned int i = 0; i < angles.size() - 1; i++) {
			for (unsigned int j = i + 1; j < angles.size(); j++) {
				if (angles.at(i) > angles.at(j)) {
					temp = angles.at(i);
					angles.at(i) = angles.at(j);
					angles.at(j) = temp;	

					temp = coefficients.at(i);
					coefficients.at(i) = coefficients.at(j);
					coefficients.at(j) = temp;
				}
			}
		} 
	}
	cout << "After ordered" << endl;
        for (unsigned int i = 0; i < angles.size(); i++) {
                cout << "angle: " << angles.at(i) << "       coefficient: " << coefficients.at(i) << endl;
        }
}

void addDataToVectors(vector<double>& targetVector, string text) {
	double currDouble;	

        istringstream inSS (text);
        inSS >> currDouble;
        targetVector.push_back(currDouble);
}

void readData(const string& fileName, vector<double>& angles, vector<double>& coefficients) {
	string text;
	//char delim = ' ';
	ifstream inFS;
	vector<string> angleStrings;
	vector<string> coefficientStrings;


	inFS.open(fileName);
        if (!inFS.is_open()) {
                cout << "Error opening " << fileName << endl;
		exit(EXIT_FAILURE);	
	}
	
	while (getline(inFS, text, ' ')) {
			//cout << "Text: " << text << endl;
                        addDataToVectors(angles, text);
                        getline(inFS, text, '\n');
			//cout << "Text: " << getline(inFS, text, ' ') << endl;
                        addDataToVectors(coefficients, text);
	}

	 /*while (!inFS.eof() && inFS.good()) {
                if (getline(inFS, text, ' ')) {
                        //cout << "Text: " << text << endl;
                        addDataToVectors(angles, text);
                        getline(inFS, text, '\n');
                        //cout << "Text: " << getline(inFS, text, ' ') << endl;
                        addDataToVectors(coefficients, text);
                }
        }	
	*/
	

	/*
	for (unsigned int i = 0; i < angleStrings.size() - 1; i++) {
		inSS.clear();
		text = angleStrings.at(i);
		inSS.str(text);
		inSS >> currDouble;
		angles.push_back(currDouble);
		text = coefficientStrings.at(i);
		inSS.clear();
		inSS.str(text);
                inSS >> currDouble;
                coefficients.push_back(currDouble);
	}
	*/

	inFS.close();
}

bool isWithinBounds(double userAngle, const vector<double>& angles) {
	bool returnVal = false;

	if (userAngle > angles.at(0) && userAngle < angles.at(angles.size() - 1))
		returnVal = true;
	else if (userAngle == angles.at(0) || userAngle == angles.at(angles.size() - 1))
		returnVal = true;

	return returnVal;
}

int main(int argc, char* argv[]) {
	double userAngle;
	double computedLift;
	int counter = 0;
	string userAnswer;
	vector<double> angles;
	vector<double> coefficients;
	bool done = false;

	if (argc != 2) {
		cout << "Expecting two arguments." << endl;
		return 1;
	} 
	
	readData(argv[1], angles, coefficients);

	if (angles.size() == 0)
		exit(EXIT_FAILURE);

	if (!isOrdered(angles))
		reorder(angles, coefficients);
	
	while (!done && counter < 1) {
		cout << "Please enter a flight-path angle(double): ";
		cin >> userAngle;	

	
		if (!isWithinBounds(userAngle, angles)) {
			cout << "That angle is not within bounds" << endl;
		}
		else {
			computedLift = interpolation(userAngle, angles, coefficients);
			cout << "The coefficient of lift is " << computedLift << endl;
		}
	
		cout << "If you would like to find another coefficient of lift, please type Yes, otherwise, type No: ";
		cin >> userAnswer;
		
		if (userAnswer == "No")
			done = true;
		else if (userAnswer == "Yes") {}
		else
			counter++;
	}


	return 0;
}
