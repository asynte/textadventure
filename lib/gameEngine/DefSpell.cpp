
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

// void DefSpell::castSpell(Character &player) {
// 	int newHealth = player.getHealth() + this->healAmount;
// 	player.setHealth(newHealth);
// 	cout << player.getName() + " has been healed by " + to_string(this->healAmount);
// }

#endif
