
#include "gameEngineHeaders/Spell.h"
#include "gameEngineHeaders/OffSpell.h"

#ifndef OFFSPELL_CPP
#define OFFSPELL_CPP

// OffSpell::OffSpell(string name, int lvl, int mana, int gold)
// 	: Spell(name, lvl, mana, gold) { 
// 	this->setDamage(this->getName());
// }	

OffSpell::OffSpell(string damMsg, int duration, int manaCost, int minLevel, string name, string damage)
	: Spell(name, duration, minLevel, manaCost) {
		this->damMsg = damMsg;
		this->damage = damage;
}

string OffSpell::getDamage() const{
	return this->damage;
}

string OffSpell::getDamMsg() const{
	return this->damMsg;
}
// void OffSpell::setDamage(string) {
	
//}

// int OffSpell::getDamage() const {
// 	return this->damage;
// }

// void OffSpell::castSpell(Character &player) {

// }

#endif