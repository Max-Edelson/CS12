#include <iostream>
#include <string>
#include "Wizard.h"

using namespace std;

Wizard::Wizard(string n, int h, int a, int r) : Character(WIZARD, n, h, a), rank(r) {
	name = n;
	health = h;
	attackStrength = a;
	type = WIZARD;
}

void Wizard::attack(Character& other) {

	if (other.getType() == 2) {
		Wizard &opp = dynamic_cast<Wizard &>(other);
		//cout << "Rank: " << rank << " other rank: " << opp.rank << " ad: " << attackStrength << endl;
		double attackRank = static_cast<double>(rank);
		double defendRank = static_cast<double>(opp.rank);
		double rankRatio = attackRank / defendRank;
		//cout << "rankRatio: " << rankRatio << endl;
		double wizDam = attackStrength * rankRatio;
		//cout << "widDam: " << wizDam << endl;
		opp.damage(wizDam);
		cout << "Wizard " << name << " attacks " << other.getName() << " --- POOF!!" << endl;
		cout << other.getName() << " takes " << wizDam << " damage." << endl;
	}
	else {
		other.damage(attackStrength);
		cout << "Wizard " << name << " attacks " << other.getName() << " --- POOF!!" << endl;
                cout << other.getName() << " takes " << attackStrength << " damage." << endl;
	}
}
