
#include "gameEngineHeaders/Spell.h"
#include "gameEngineHeaders/DefSpell.h"

#ifndef DEFSPELL_CPP
#define DEFSPELL_CPP

DefSpell::DefSpell(string name, int lvl, int mana, int gold)
	: Spell(name, lvl, mana, gold) { 
	
}	

void DefSpell::setHealAmount(int heal) {
	this->healAmount = heal;
}

int DefSpell::getHealAmount() const {
	return this->healAmount;
}

void DefSpell::castSpell(Character &player) {
	int newHealth = player.getHealth() + this->healAmount;
	player.setHealth(newHealth);
	cout << player.getName() + " has been healed by " + to_string(this->healAmount);
}

#endif