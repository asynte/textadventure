#include <string>
#include "gameEngineHeaders/Spell.h"

#ifndef OFFSPELL_H
#define OFFSPELL_H

using namespace std;

class OffSpell : public Spell {
public:
	OffSpell(string, int, int, int);
	void setDamage(string);
	int getDamage() const;
	void castSpell(Character&);
private:
	int damage;
	string damMsg;
	string damageFormula;
};

#endif