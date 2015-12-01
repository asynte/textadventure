#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"

using namespace std;

	///////////////////////////////////
	// 		  PRINT FUNCTIONS	     //
	///////////////////////////////////

	void spellDataInterface::printDefDuration (const int& index) {
		cout << "Duration: " << defSpellVector[index].getDuration() << "\n";
	}

	void spellDataInterface::printEffect (const int& index) {
		cout << "Effect: " << defSpellVector[index].getEffect() << "\n";
	}

	void spellDataInterface::printHitChar (const int& index) {
		cout << "HitChar: " << defSpellVector[index].getHitChar() << "\n";
	}

	void spellDataInterface::printHitVict (const int& index) {
		cout << "HitVict: " << defSpellVector[index].getHitVict() << "\n";
	}

	void spellDataInterface::printDefMana (const int& index) {
		cout << "Mana: " << defSpellVector[index].getManaCost() << "\n";
	}

	void spellDataInterface::printDefMinLevel (const int& index) {
		cout << "MinLevel: " << defSpellVector[index].getMinLevel() << "\n";
	}

	void spellDataInterface::printDefName (const int& index) {
		cout << "Name: " << defSpellVector[index].getName() << "\n";
	}


	void spellDataInterface::printDamMsg (const int& index) {
		cout << "DmgMsg: " << offSpellVector[index].getDamMsg() << "\n";
	}

	void spellDataInterface::printOffDuration (const int& index) {
		cout << "Duration: " << offSpellVector[index].getDuration() << "\n";
	}

	void spellDataInterface::printOffMana (const int& index) {
		cout << "Mana: " << offSpellVector[index].getManaCost() << "\n";
	}

	void spellDataInterface::printOffMinLevel (const int& index) {
		cout << "MinLevel: " << offSpellVector[index].getMinLevel() << "\n";
	}

	void spellDataInterface::printOffName (const int& index) {
		cout << "Name: " << offSpellVector[index].getName() << "\n";
	}

	void spellDataInterface::printDamage (const int& index) {
		cout << "Damage: " << offSpellVector[index].getDamage() << "\n";
	}

	void spellDataInterface::printAtIndexDefense (const int& index) {
		//printDefDuration(index);
		printEffect(index);	
		printHitChar(index);
		printHitVict(index);
		printDefMana(index);
		printDefMinLevel(index);
		printDefName(index);
		cout << "\n";
	}

	void spellDataInterface::printAtIndexOffense (const int& index) {
		printDamMsg(index);
		//printOffDuration(index);	
		printOffMana(index);
		printOffMinLevel(index);
		printOffName(index);
		printDamage(index);
		cout << "\n";
	}
	void spellDataInterface::printAll () {

		for (int i = 0; i < defSpellVector.size(); i++) {
			printAtIndexDefense(i);
		}	

		for (int i = 0; i < offSpellVector.size(); i++) {
			printAtIndexOffense(i);
		}		
	}

	///////////////////////////////////
	// 		  LOAD FUNCTIONS	     //
	///////////////////////////////////

	void spellDataInterface::pushDef (const int& index) {

		// for the five  defense spells
		if (defenseNode[index]["Name"].as<string>() == "cure critical" ||
			defenseNode[index]["Name"].as<string>() == "cure serious" ||
			defenseNode[index]["Name"].as<string>() == "heal" ||
			defenseNode[index]["Name"].as<string>() == "hezekiahs cure" ||
			defenseNode[index]["Name"].as<string>() == "cure light") {
			
			string effect = defenseNode[index]["Effect"].as<string>();
			string eff = effect.substr(7, effect.length()-11);

			// change DeFSPELL to Spell class constructor
			defSpellVector.push_back(DefSpell{
				defenseNode[index]["Duration"].as<int>(),
				eff,
				defenseNode[index]["Hitchar"].as<string>(),
				defenseNode[index]["Hitvict"].as<string>(),
				defenseNode[index]["Mana"].as<int>(),
				defenseNode[index]["Minlevel"].as<int>(),
				defenseNode[index]["Name"].as<string>()
			});	
		}
		
	}

	void spellDataInterface::pushOff (const int& index) {

		// for the five offense spells
		if (offenseNode[index]["Name"].as<string>() == "cause critical" ||
			offenseNode[index]["Name"].as<string>() == "cause serious" ||
			offenseNode[index]["Name"].as<string>() == "cause light" ||
			offenseNode[index]["Name"].as<string>() == "lightning breath" ||
			offenseNode[index]["Name"].as<string>() == "flamestrike") {

			// change OFFSPELL to Spell class constructor
			offSpellVector.push_back(OffSpell{
					offenseNode[index]["Dammsg"].as<string>(),
					offenseNode[index]["Duration"].as<int>(),
					offenseNode[index]["Mana"].as<int>(),
					offenseNode[index]["Minlevel"].as<int>(),
					offenseNode[index]["Name"].as<string>(),
					offenseNode[index]["Damage"].as<string>()
			});
		}
	}

	void spellDataInterface::loadAllDefenseSpell() {

		for (int i = 0; i < defenseNode.size(); i++) {
			pushDef(i);
		}
	}

	void spellDataInterface::loadAllOffenseSpell() {

		for (int i = 0; i < offenseNode.size(); i++) {

			pushOff(i);
		}
	}

	void spellDataInterface::loadAll() {
		loadAllDefenseSpell();
		loadAllOffenseSpell();
	}

	///////////////////////////////////
	// 		  GET FUNCTIONS	         //
	///////////////////////////////////

	vector <DefSpell> spellDataInterface::getDefVector(){
		return defSpellVector;
	}

	vector <OffSpell> spellDataInterface::getOffVector(){
		return offSpellVector;
	}