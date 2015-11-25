#include "gameEngineHeaders/Spell.h"

#ifndef SPELL_CPP
#define SPELL_CPP

Spell::Spell(string name, int lvl, int mana, int gold) {
	this->spellName = name;
	this->spellLevel = lvl;
	this->manaCost = mana;
	this->goldCost = gold;
}

void Spell::setName(string name) {
	this->spellName = name;
}

string Spell::getName() const {
	return this->spellName;
}

void Spell::setSpellLevel(int lvl) {
	this->spellLevel = lvl;
}

int Spell::getSpellLevel() const {
	return this->spellLevel;
}

void Spell::setManaCost(int mcost) {
	this->manaCost = mcost;
}

int Spell::getManaCost() const {
	return this->manaCost;
}

void Spell::setGoldCost(int gcost) {
	this->goldCost = gcost;
}

int Spell::getGoldCost() const {
	return this->goldCost;
}

#endif