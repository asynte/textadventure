#include "gameEngineHeaders/SpellShop.h"

#ifndef SPELLSHOP_CPP
#define SPELLSHOP_CPP

SpellShop::SpellShop(string description, int locationID){
	this->shopDescription = description;
	this->shopLocationID = locationID;
}

string SpellShop::getDescription(){
	return this->shopDescription;
}

int SpellShop::getShopLocationID(){
	return this->shopLocationID;
}


void SpellShop::loadSpells(){ //Private function to parse YAML file 
	spellDataInterface spellParser("data/spellstest.yml");
	spellParser.loadAllDefenseSpell();
	spellParser.loadAllOffenseSpell();
	defShopVector = spellParser.getDefVector();
	offShopVector = spellParser.getOffVector();
	setSpellCost();

}

void SpellShop::displaySpells(){ //Loop the vector and display spells

	for(int i = 0 ; i < defShopVector.size() ; i++ ){
		cout << "Spell Name: " << defShopVector.at(i).getName() << endl;
		cout << "Gold Cost: " << defShopVector.at(i).getGoldCost() << endl;
		cout << "Minimum Level: " << defShopVector.at(i).getMinLevel() << endl;
		cout << "Mana Cost: " << defShopVector.at(i).getManaCost() << endl;
		cout << "Spell Duration: " << defShopVector.at(i).getDuration() << endl << endl;
	}
	for(int i = 0 ; i < offShopVector.size() ; i++ ){
		cout << "Spell Name: " << offShopVector.at(i).getName() << endl;
		cout << "Gold Cost: " << offShopVector.at(i).getGoldCost() << endl;
		cout << "Minimum Level: " << offShopVector.at(i).getMinLevel() << endl;
		cout << "Mana Cost: " << offShopVector.at(i).getManaCost() << endl;
		cout << "Spell Duration: " << offShopVector.at(i).getDuration() << endl << endl;
	}

}

void SpellShop::setSpellCost(){

	for(int i = 0 ; i < defShopVector.size() ; i++ ){
		if (defShopVector.at(i).getName() == "cure critical"){
			defShopVector.at(i).setGoldCost(500);
		}
		else if (defShopVector.at(i).getName() == "cure light"){
			defShopVector.at(i).setGoldCost(500);
		}
		else if (defShopVector.at(i).getName() == "cure serious"){
			defShopVector.at(i).setGoldCost(500);
		}
		else if (defShopVector.at(i).getName() == "heal"){
			defShopVector.at(i).setGoldCost(1000);
		}
		else if (defShopVector.at(i).getName() == "hezekiahs cure"){
			defShopVector.at(i).setGoldCost(2000);
		}				
	}

	for(int i = 0 ; i < offShopVector.size() ; i++ ){
		if (offShopVector.at(i).getName() == "cause critical"){
			offShopVector.at(i).setGoldCost(800);
		}
		else if (offShopVector.at(i).getName() == "cause light"){
			offShopVector.at(i).setGoldCost(800);
		}
		else if (offShopVector.at(i).getName() == "cause serious"){
			offShopVector.at(i).setGoldCost(800);
		}
		else if (offShopVector.at(i).getName() == "flamestrike"){
			offShopVector.at(i).setGoldCost(2000);
		}
		else if (offShopVector.at(i).getName() == "lightning breath"){
			offShopVector.at(i).setGoldCost(5000);
		}				
	}
}

void SpellShop::buySpell(Character &player){
	cout<< "player level is : " << player.getLevel();
	// FINISH BUY SPELL
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// 	check minlevel 
	//	check gold
	// 	deduct gold
	// 	remove spell from vector
	// 	tell player it is bought
}

void SpellShop::printMenu(){
	cout << "What would you like to do?" << endl;
	cout << "Menu: " << endl;
	cout << "1. Show Spells" << endl;
	cout << "2. Buy Spells" << endl;
	cout << "3. Exit Shop" << endl;
}

void SpellShop::shopMenu(Character &player){
	loadSpells();
	cout << getDescription() << endl;
	printMenu();

	string choice;
	while(cin >> choice){
		if(choice == "3"){
			break;
		}
		else if(choice == "1"){
			cout<< "Available Spells:" << endl << endl;
			displaySpells();
			printMenu();
		}
		else if(choice == "2"){
			string spellchoice;
			cout << "What spell would you like to buy?" <<endl;
			int spellNumber = 1;
			for(int i = 0 ; i < defShopVector.size() ; i++ ){
				cout << spellNumber + i << ". ";
				cout << defShopVector.at(i).getName() << endl;
			}
			for(int i = 0 ; i < offShopVector.size() ; i++ ){
				spellNumber = 6;
				cout << spellNumber + i << ". ";
				cout << offShopVector.at(i).getName() << endl;
			}
			cin >> spellchoice;
			if(spellchoice == "1" || spellchoice == "2" || spellchoice == "3" || spellchoice == "4"
				 || spellchoice == "5" || spellchoice == "6" || spellchoice == "7" || spellchoice == "8"
				  || spellchoice == "9" || spellchoice == "10"){
				buySpell(player);
				// NOT DONE!!!!!!!!!!!!!!!!!!!!!!!!!
				// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



				printMenu();			
			}else{
				cin.clear();
				cout << "Incorrect input" << endl << endl;
				printMenu();
			}
		}
		else {
			cin.clear();
			cout << "Please enter the correct command." << endl << endl;
			printMenu();
		}
	}
}

#endif