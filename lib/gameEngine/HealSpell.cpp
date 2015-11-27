
#include "gameEngineHeaders/Spell.h"
#include "gameEngineHeaders/HealSpell.h"

#ifndef HEALSPELL_CPP
#define HEALSPELL_CPP

HealSpell::HealSpell(string name, int lvl, int mana, int gold)
	: Spell(name, lvl, mana, gold) { 
	int newHealAmount = (int)(pow(this->getSpellLevel(), 2) * Character::CHAR_DEFAULTHEALTH/2); // healAmount = spellLevel^2 * defaultHealth/2
	this->setHealAmount(newHealAmount);
}	

void HealSpell::setHealAmount(int heal) {
	this->healAmount = heal;
}

int HealSpell::getHealAmount() const {
	return this->healAmount;
}

void HealSpell::castSpell(Character &player) {
	int newHealth = player.getHealth() + this->healAmount;
	player.setHealth(newHealth);
	cout << player.getName() + " has been healed by " + to_string(this->healAmount);
}

#endif