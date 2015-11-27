#include <string>
#include "gameEngineHeaders/Character.h"

#ifndef SPELL_H
#define SPELL_H

class Character;

using namespace std;

class Spell {
public:
	Spell(string, int, int, int);
	void setName(string);
	string getName() const;
	void setSpellLevel(int);
	int getSpellLevel() const;
	void setManaCost(int);
	int getManaCost() const;
	void setGoldCost(int);
	int getGoldCost() const;

private:
	string spellName;
	int spellLevel;
	int manaCost;
	int goldCost;
};

#endif