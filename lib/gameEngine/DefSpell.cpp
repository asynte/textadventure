
#include "gameEngineHeaders/Spell.h"
#include "gameEngineHeaders/DefSpell.h"

#ifndef DEFSPELL_CPP
#define DEFSPELL_CPP

// DefSpell::DefSpell(string name, int duration, int lvl, int mana, int gold)
// 	: Spell(name, duration, lvl, mana, gold) { 
	
// }
DefSpell::DefSpell(int duration, string effect, string hitChar, string hitVict, int manaCost, int minLevel, string name)
	: Spell(name, duration, minLevel, manaCost) {
		this->effect = effect;
		this->hitChar = hitChar;
		this->hitVict = hitVict;
}

string DefSpell::getEffect() const{
	return this->effect;
}

string DefSpell::getHitChar() const{
	return this->hitChar;
}

string DefSpell::getHitVict() const{
	return this->hitVict;
}

string DefSpell::getWearOff() const{
	return this->wearOff;
}
// void DefSpell::setHealAmount(int heal) {
// 	this->healAmount = heal;
// }

// int DefSpell::getHealAmount() const {
// 	return this->healAmount;
// }

void DefSpell::castSpell(Character &player) {
	int healAmount = 0;
	if (this->getName() == "cure critical") {
		healAmount = rollD8(3) + player.getLevel() - 6;
	}
	else if (this->getName() == "cure light") {
		healAmount = rollD8(1) + player.getLevel()/3;
	}
	else if (this->getName() == "cure serious") {
		healAmount = rollD8(2) + player.getLevel()/2;
	}
	else if (this->getName() == "heal") {
		healAmount = 100;
	}
	else if (this->getName() == "hezekiahs cure") {
		healAmount = 5 * (player.getLevel()/3);
	}
	else { 
		cout << "Spell does not exist." << endl;
		return;
	}
	//cout << this->getHitChar() << endl;
	cout << this->getHitVict() << endl;
	player.setHealth(min(player.getHealth(), player.getCurrentHealth()+healAmount)); // spell casting
	cout << "You heal " << healAmount << " health." << endl;
	player.setMana(player.getMana() - this->getManaCost()); // subtract mana cost
}

#endif
