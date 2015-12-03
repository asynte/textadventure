
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
	else if (this->getName() == "lightning breath") {
		damage = rand() % (player.getLevel()/8 - player.getLevel()/16 - 1) + player.getLevel()/16 + 1;
	}
	else { 
		cout << "Spell does not exist." << endl;
		return;
	}
	cout << player.getName() + " casts " + this->getDamMsg() + " on " + target.getName() << endl;
	target.setHealth(max(target.getHealth() - damage, 0)); // NPC takes damage
	player.setMana(player.getMana() - this->getManaCost()); // subtract mana cost
	if (target.getHealth() <= 0) { 
        cout << target.getName() + " takes " + to_string(damage) + " damage and has no health remaining!" << endl;
    } else { // keep fighting
        cout << target.getName() + " takes " + to_string(damage) + " damage and has " + to_string(target.getHealth()) + " health remaining!" << endl;
        player.setHealth( player.getCurrentHealth() - target.getAtk() ); // character takes damage equal to NPC's atk
        cout << "You take " + to_string(target.getAtk()) + " damage and have " + to_string(player.getCurrentHealth()) + " health remaining!" << endl;
    }
}

#endif