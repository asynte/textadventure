#include <string>
#include "gameEngineHeaders/Spell.h"

#ifndef OFFSPELL_H
#define OFFSPELL_H

using namespace std;

class OffSpell : public Spell {
public:
	//OffSpell(string name, int lvl, int mana, int gold);
	OffSpell(string damMsg, int duration, int manaCost, int minLevel, string name, string damage);
	// void setDamage(string);
	// int getDamage() const;
	// void castSpell(Character&);
	string getDamage() const;
	string getDamMsg() const;

private:
	string damage;
	string damMsg;
	string damageFormula; // Jason's part
};

#endif