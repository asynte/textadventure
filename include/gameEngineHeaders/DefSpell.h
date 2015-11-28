#include <string>
#include "gameEngineHeaders/Spell.h"

#ifndef DEFSPELL_H
#define DEFSPELL_H

using namespace std;

class DefSpell : public Spell {
public:
	DefSpell(string, int, int, int);
	void setHealAmount(int);
	int getHealAmount() const;
	void castSpell(Character&);
private:
	int healAmount;
	string hitChar;
	string hitVict;
};

#endif