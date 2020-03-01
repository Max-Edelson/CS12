#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include "Character.h"

using namespace std;

class Warrior : public Character {

	private:
	string allegiance;
	
	public:
	Warrior(string, int, int, string);
	void attack(Character&) override;
};


#endif
