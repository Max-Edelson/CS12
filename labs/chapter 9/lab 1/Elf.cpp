#include <iostream>
#include "Elf.h"

using namespace std;

Elf::Elf(string n, int h, int d, string f) : Character(ELF, n, h, d), family(f) { 
	//Character(ELF, n, h, d);
	name = n;
	health = h;
	attackStrength = d;
	type = ELF;
}

void Elf::attack(Character& other) { 
	bool doAttack = true;

	
	if (other.getType() == 1) {
		Elf &opp = dynamic_cast<Elf &>(other);

		if (opp.family == this->family)
			doAttack = false;
	}
	
	double dam = (health / MAX_HEALTH) * attackStrength;

	if (doAttack) {
		other.damage(dam);
		cout << "Elf " << name << " shoots an arrow at " << other.getName() << " --- TWANG!!" << endl;
		cout << other.getName() << " takes " << dam << " damage." << endl;
	}
	else {
		cout << "Elf " << name << " does not attack Elf " << other.getName() << "." << endl;
		cout << "They are both members of the " << family << " family." << endl; 
	}
}
