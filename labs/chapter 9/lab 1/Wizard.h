#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "Character.h"
	
using namespace std;

class Wizard : public Character {

	private:
	int rank;

	public:
	Wizard(string, int, int, int);
	void attack(Character&) override;

};

#endif
