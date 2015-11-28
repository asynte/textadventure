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
	void setMinLevel(int);
	int getMinLevel() const;
	void setManaCost(int);
	int getManaCost() const;
	void setGoldCost(int);
	int getGoldCost() const;

private:
	string spellName;
	int manaCost;
	int goldCost;
	int minLevel;
};

#endif