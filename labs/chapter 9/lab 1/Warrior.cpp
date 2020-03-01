#include <iostream>
#include "Warrior.h"

using namespace std;

Warrior::Warrior(string a, int h, int s, string all) : Character(WARRIOR, a, h, s), allegiance(all) { 
	health = h;
	attackStrength = s;
	type = WARRIOR;
	name = a;
}



void Warrior::attack(Character& other) {
	bool doAttack = true;


	if (other.getType() == 0) {
		Warrior &opp = dynamic_cast<Warrior &>(other);
	
		if (opp.allegiance == allegiance)
			doAttack = false;
	
	}

	if (doAttack) {
		double dama = (health / MAX_HEALTH) * attackStrength;
		other.damage((health / MAX_HEALTH) * attackStrength);
		cout << "Warrior " << name << " attacks " << other.getName() << " --- SLASH!!" << endl;
		cout << other.getName() << " takes " << dama << " damage." << endl;
	}
	else {
		cout << "Warrior " << name << " does not attack Warrior " << other.getName() << "." << endl;
		cout << "They share an allegiance with " << allegiance << "." << endl;
	}
}
