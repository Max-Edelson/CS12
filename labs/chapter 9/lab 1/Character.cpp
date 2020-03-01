#include "Character.h"
#include <iostream>
#include <string>

Character::Character(HeroType a, const string & b, double c, double d) : type(a), name(b), health(c), attackStrength(d) {}

HeroType Character::getType() const {
	return type;
}

const string & Character::getName() const {
	return name;
}

int Character::getHealth() const {
	return static_cast<int>(health);
}

void Character::setHealth(double h) {
	health = h;
}

void Character::damage(double d) {
	health -= d;
}

bool Character::isAlive() const {
	if (health > 0)
		return true;
	return false;
}
