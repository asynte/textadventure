#include <string>
#include "gameEngineHeaders/Spell.h"

#ifndef DEFSPELL_H
#define DEFSPELL_H

using namespace std;

class DefSpell : public Spell {
public:
	DefSpell(int duration, string effect, string hitChar, string hitvict, int manaCost, int minLevel, string name);
	//void setHealAmount(int);
	//int getHealAmount() const;
	void castSpell(Character&);
	string getEffect() const;
	string getHitChar() const;
	string getHitVict() const;
	string getWearOff() const;

private:
	string effect;
	string hitChar;
	string hitVict;
	string wearOff;

	// int healAmount;

};

#endif