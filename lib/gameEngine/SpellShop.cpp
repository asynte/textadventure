#include "gameEngineHeaders/SpellShop.h"
#include "gameEngineHeaders/Spell.h"
#include "include/dataInterfaceBase.h"

#ifndef SPELLSHOP_CPP
#define SPELLSHOP_CPP

SpellShop::SpellShop(string description, int locationID, ){
	this->shopDescription = description;
	this->shopLocationID = locationID;
}

string SpellShop::getDescription() const{
	return this->shopDescription;
}

int SpellShop::getShopLocationID() const{
	return this->shopLocationID;
}

void SpellShop::loadSpells(){ //Private function to parse YAML file 
//for Testing purposes this does showspell as well
	spellDataInterface spellParser("data/spellstest.yml");
	spellParser.loadAllDefenseSpell();
	spellParser.loadAllOffenseSpell();
	spellParser.printAll();

}

// void SpellShop::showSpells(){ //Loop the vector and display spells

// }