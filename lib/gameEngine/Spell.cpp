#include "gameEngineHeaders/Spell.h"

#ifndef SPELL_CPP
#define SPELL_CPP

Spell::Spell(string name, int duration, int lvl, int mana) {
	this->spellName = name;
	this->duration = duration;
	this->minLevel = lvl;
	this->manaCost = mana;

}

Spell::Spell(string name, int duration, int lvl, int mana, int gold) {
	this->spellName = name;
	this->duration = duration;
	this->minLevel = lvl;
	this->manaCost = mana;
	this->goldCost = gold;
}

void Spell::setName(string name) {
	this->spellName = name;
}

string Spell::getName() const {
	return this->spellName;
}

void Spell::setMinLevel(int lvl) {
	this->minLevel = lvl;
}

int Spell::getMinLevel() const {
	return this->minLevel;
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

int Spell::getDuration() const{
	return this->duration;
}
#endif