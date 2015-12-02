#include <string>
#include <vector>
#include "gameEngineHeaders/Spell.h"
#include "gameEngineHeaders/Character.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"

#ifndef SPELLSHOP_H
#define SPELLSHOP_H


using namespace std;

class SpellShop {

public:

	SpellShop(string description, int shopLocationID);

	string getDescription();
	int getShopLocationID();
	void cinClear();
	void shopMenu(Character &player);
	string toLower(string &str);
	
private:

	string shopDescription;
	int shopLocationID; //Location of the shop
	void loadSpells();
	void displaySpells();	
	void setSpellCost();
	bool buySpell(Character &player);
	void printMenu();
	vector <DefSpell> defShopVector;
	vector <OffSpell> offShopVector;



};

#endif