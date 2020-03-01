#ifndef ELF_H
#define ELF_H

#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

class Elf : public Character {

	private: 
	string family;
	
	public:
	Elf(string, int, int, string);
	//string getAllegiance() const;
	void attack(Character&) override;	

};

#endif
