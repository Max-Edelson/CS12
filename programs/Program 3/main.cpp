#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Date {

 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();
   Date(unsigned int, unsigned int, unsigned int);
   Date(const string &month, unsigned int day, unsigned int year);
	

	/*Date(unsigned int month, unsigned int day, unsigned int year) {

		if (month < 1 ) {
			this->month = 1;
		} 
		else if (month > 12) {
			this->month = 12;
		}
		else { 
			this->month = month;
		}

		if (day > 31) {
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				day = 31;
			}
			else if (month == 2) {
				day = 28;
			}	
			else {
				day = 30;
			}
		}
		else if (day < 1) {
			day = 1;
		}
		else {
			this-> day = day;
		}
			
		this->year = year;		
	}*/	

   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
	void printNumeric() const {
		cout << month << "/" << day << "/" << year;
	}


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(unsigned int month, unsigned int day, unsigned int year) {
	bool invalid = false;
	this->day = day;

	if (month < 1 ) {
	        this->month = 1;
		invalid = true;
        }
        else if (month > 12) {
                this->month = 12;
		invalid = true;
        }
        else {
                this->month = month;
        }

        if (this->day >= 31) {
                if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
			if (this->day > 31)
				invalid = true;
      		        this->day = 31;
		}
                else if (this->month == 2) {}
                else {
                        this->day = 30;
			invalid = true;
                }
        }
        else if (this->day < 1) {
		invalid = true;
                this->day = 1;
        }
        else {
                this->day = day;
        }

	if (this->month == 2) {
		if (this->day == 28) {
			if (isLeap(year)) {
				this->day = 29;
				cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << year << "." << endl;
			}
		}
		else if (this->day == 29) {
			if (!isLeap(year)) {
				this->day = 28;
				cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << year << "." << endl;
			} 
		}
		else if (this->day > 29) {
			invalid = true;

			if (isLeap(year))
				this->day = 29;
			else
				this->day = 28;
		}
	}
	
	if (year != 0)
		this->year = year;
	else 
		this->year = 2000;

	if (invalid) {
		cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
	}
}

Date::Date(const string &m, unsigned day, unsigned year) {
	//transform(month.begin(), month.end(), month.begin(), ::tolower);
        bool invalidMonth = false;
	bool invalidDate = false;
        
        locale loc;
	monthName = m;

        for (unsigned int i = 0; i < monthName.length(); i++) {
		if (!islower(monthName[i], loc)) {
			//let = monthName[i];
			//tolower(let);
	        	monthName[i] = tolower(monthName[i]);
			//monthName.at(i) = let;
		}
        }
	this->day = day;
	
        if (monthName == "january")
                month = 1;
        else if (monthName == "february")
                month = 2;
        else if (monthName == "march")
                month = 3;
        else if (monthName == "april")
                month = 4;
        else if (monthName == "may")
                month = 5;
        else if (monthName == "june")
                month = 6;
        else if (monthName == "july")
                month = 7;
        else if (monthName == "august")
                month = 8;
        else if (monthName == "september")
                month = 9;
        else if (monthName == "october")
                month = 10;
        else if (monthName == "november")
                month = 11;
        else if (monthName == "december")
                month = 12;
        else {
                invalidMonth = true;
		month = 1;
	}
	
        if (!invalidMonth) {
                if (this->day >= 31) {
			if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
				if (this->day > 31)
					invalidDate = true;
                		this->day = 31;
                        }
                        else if (this->month == 2) {}
                        else {
                                this->day = 30;
				invalidDate = true;
                        }
                }
                else if (day <= 1) {
			invalidDate = true;
                        this->day = 1;
                }
                else {
                        this->day = day;
                }
                this->year = year;
          }
          else {
                this->day = 1;
                this->year = 2000;
          }

	if (year == 0) {
                this->year = 2000;
		invalidDate = true;
        }

	if (this->month == 2) {
                if (this->day > 28) {
                        if (isLeap(year)) {
				if (this->day == 29) {}
				else {
                                	this->day = 29;
					invalidDate = true;
				}
			}
                        else {
                                this->day = 28;
				invalidDate = true;
			}
                }
        }

	if (invalidMonth) {
                cout << "Invalid month name: the Date was set to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
        }
	
	if (invalidDate)
		cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
}


// Implement the Date member functions here

unsigned Date::number(const string &mn) const {
	unsigned int returnVal;

	if (mn == "january")	
               returnVal = 1;
	else if (mn == "february") 
               returnVal = 2;
	else if (mn == "march")
               returnVal = 3;
	else if (mn == "april")
               returnVal = 4;
	else if (mn == "may")
               returnVal = 5;
	else if (mn == "june")
               returnVal = 6;
	else if (mn == "july")
               returnVal = 7;
	else if (mn == "august")
               returnVal = 8;
	else if (mn == "september")
               returnVal = 9;
	else if (mn == "october")
               returnVal = 10;
	else if (mn == "november")
               returnVal = 11;
	else if (mn == "december")
               returnVal = 12;
	else {
	        cout << "invalid month" << endl;
		returnVal = 9999999;
	}

	return returnVal;
}

string Date::name(unsigned m) const {
	string returnVal;

	switch(m) {
		case 1:
			returnVal = "January";
			break;
		case 2:
                        returnVal = "February";
                        break;
		case 3:
                        returnVal = "March";
                        break;
		case 4:
                        returnVal = "April";
                        break;
		case 5:
                        returnVal = "May";
                        break;
		case 6:
                        returnVal = "June";
                        break;
		case 7:
                        returnVal = "July";
                        break;
		case 8:
                        returnVal = "August";
                        break;
		case 9:
                        returnVal = "September";
                        break;
		case 10:
                        returnVal = "October";
                        break;
		case 11:
                        returnVal = "November";
                        break;
		case 12:
                        returnVal = "December";
                        break;
		default:
			returnVal = "Invalid Month";
			break;
	}

	return returnVal;
}

void Date::printAlpha() const  {
	string tempMonth = name(month);
	//tempMonth.at(0) = char(tempMonth.at(0)-32);
	
	cout << tempMonth << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const {
	bool returnVal = false;

	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 100 == 0))
		returnVal = true;

	return returnVal;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
	bool isLeapYear = isLeap(y);
	unsigned int returnVal;
	
	if (isLeapYear && m == 2) {
		returnVal = 29;
	}	
	else if (!isLeapYear && m == 2) {
		returnVal = 28;
	}
	else {
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        	        returnVal = 31;
                }
                else {
                        returnVal = 30;
                }
	}

	return returnVal;
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

//I changed that
//Date getDate();

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}


int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

