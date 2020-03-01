#include <iostream>
#include <string>

using namespace std;


void flipString(string &s) {
	if (s.size() > 1) {
		char character = s.at(0);
		s = s.substr(1);
		flipString(s);
		s.push_back(character);
	}
}

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here


