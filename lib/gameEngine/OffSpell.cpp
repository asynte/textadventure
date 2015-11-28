
#include "gameEngineHeaders/Spell.h"
#include "gameEngineHeaders/OffSpell.h"

#ifndef OFFSPELL_CPP
#define OFFSPELL_CPP

OffSpell::OffSpell(string name, int lvl, int mana, int gold)
	: Spell(name, lvl, mana, gold) { 
	this->setDamage(this->getName());
}	

void OffSpell::setDamage(string) {
	
}

int OffSpell::getDamage() const {
	return this->damage;
}

void OffSpell::castSpell(Character &player) {

}

#endif