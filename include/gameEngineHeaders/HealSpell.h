#include <cmath>
#include "gameEngineHeaders/Spell.h"

#ifndef HEALSPELL_H
#define HEALSPELL_H

using namespace std;

class HealSpell : public Spell {
public:
	HealSpell(string, int, int, int);
	void setHealAmount(int);
	int getHealAmount() const;
	void castSpell(Character&);
private:
	int healAmount;
};

#endif