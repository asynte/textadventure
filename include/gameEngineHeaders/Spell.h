#include <string>
#include "gameEngineHeaders/Character.h"

#include <stdlib.h>
#include <algorithm> 

#ifndef SPELL_H
#define SPELL_H

class Character;

using namespace std;

class Spell {
public:
	Spell(string name, int duration, int lvl, int mana);
	Spell(string name, int duration, int lvl, int mana, int gold);
	void setName(string);
	string getName() const;
	void setMinLevel(int);
	int getMinLevel() const;
	void setManaCost(int);
	int getManaCost() const;
	void setGoldCost(int);
	int getGoldCost() const;
	int getDuration() const;	
	int rollD8(int);

private:
	string spellName;
	int duration;
	int manaCost;
	int goldCost;
	int minLevel;
};

#endif