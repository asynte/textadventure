
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
		this->damageFormula = damage;
}

string OffSpell::getDamage() const{
	return this->damageFormula;
}

string OffSpell::getDamMsg() const{
	return this->damMsg;
}
// void OffSpell::setDamage(string) {
	
//}

// int OffSpell::getDamage() const {
// 	return this->damage;
// }

void OffSpell::castSpell(Character &player, NPC &target) {
	int damage = 0;
	if (this->getName() == "cause critical") {
		damage = rollD8(3) + player.getLevel() - 6;
	}
	else if (this->getName() == "cause light") {
		damage = rollD8(1) + player.getLevel()/3;
	}
	else if (this->getName() == "cause serious") {
		damage = rollD8(2) + player.getLevel()/2;
	}
	else if (this->getName() == "flamestrike") {
		damage = rollD8(6);
	}
	else if (this->getName() == "hezekiahs cure") {
		damage = rand() % (player.getLevel()/8 - player.getLevel()/16 - 1) + player.getLevel()/16 + 1;
	}
	else { 
		cout << "Spell does not exist." << endl;
		return;
	}
	cout << player.getName() + " casts " + this->getDamMsg() + " on " + target.getName() << endl;
	target.setHealth(max(target.getHealth() - damage, 0)); // NPC takes damage
	player.setMana(player.getMana() - this->getManaCost()); // subtract mana cost
}

#endif