#include <string>
#include "gameEngineHeaders/Spell.h"

#ifndef SPELLSHOP_H
#define SPELLSHOP_H

using namespace std;

class SpellShop {
public:
	SpellShop(string description, int shopLocationID);


private:
	string shopDescription = "Welcome to the Spell Shop";
	int shopLocationID; //Location of the shop
};