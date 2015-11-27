#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"

using namespace std;

	
	///////////////////////////////////
	// 		  LOAD FUNCTIONS	     //
	///////////////////////////////////

	void spellDataInterface::pushDef (const int& index) {

		// for cure light spell
		if (defenseNode[index]["Name"].as<string>() == "cure light") {
			string wearOff = defenseNode[index]["Wearoff"].as<string>();
			
			// change DEFSPELL to Spell class constructor
			defSpellVector.push_back(DEFSPELL{
				defenseNode[index]["Duration"].as<int>(),
				defenseNode[index]["Effect"].as<string>(),
				defenseNode[index]["Hitchar"].as<string>(),
				defenseNode[index]["Hitvict"].as<string>(),
				defenseNode[index]["Mana"].as<int>(),
				defenseNode[index]["Minlevel"].as<int>(),
				defenseNode[index]["Name"].as<string>(),
				wearOff
			});	

		}

		// for the four other defense spells
		if (defenseNode[index]["Name"].as<string>() == "cure critical" ||
			defenseNode[index]["Name"].as<string>() == "cure serious" ||
			defenseNode[index]["Name"].as<string>() == "heal" ||
			defenseNode[index]["Name"].as<string>() == "hezekiahs cure") {
			string wearOff = "";
			
			// change DeFSPELL to Spell class constructor
			defSpellVector.push_back(DEFSPELL{
				defenseNode[index]["Duration"].as<int>(),
				defenseNode[index]["Effect"].as<string>(),
				defenseNode[index]["Hitchar"].as<string>(),
				defenseNode[index]["Hitvict"].as<string>(),
				defenseNode[index]["Mana"].as<int>(),
				defenseNode[index]["Minlevel"].as<int>(),
				defenseNode[index]["Name"].as<string>(),
				wearOff
			});	
		}
		
	}

	void spellDataInterface::pushOff (const int& index) {

		// for the five offense spells
		if (offenseNode[index]["Name"].as<string>() == "cause critical" ||
			offenseNode[index]["Name"].as<string>() == "cause serious" ||
			offenseNode[index]["Name"].as<string>() == "cause serious" ||
			offenseNode[index]["Name"].as<string>() == "lightning breath" ||
			offenseNode[index]["Name"].as<string>() == "flamestrike") {

			// change OFFSPELL to Spell class constructor
			offSpellVector.push_back(OFFSPELL{
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
