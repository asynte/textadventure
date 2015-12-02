#include "gameEngineHeaders/SpellShop.h"

#ifndef SPELLSHOP_CPP
#define SPELLSHOP_CPP


SpellShop::SpellShop(string description, int locationID){
	this->shopDescription = description;
	this->shopLocationID = locationID;
	loadSpells();
}

string SpellShop::getDescription(){
	return this->shopDescription;
}

int SpellShop::getShopLocationID(){
	return this->shopLocationID;
}

void SpellShop::cinClear(){
	cin.clear();
}

void SpellShop::loadSpells(){ //Private function to parse YAML file 
	spellDataInterface spellParser("data/spellstest.yml");
	spellParser.loadAll();
	defShopVector = spellParser.getDefVector();
	offShopVector = spellParser.getOffVector();
	setSpellCost();

}

void SpellShop::displaySpells(){ //Loop the vector and display spells

	for(int i = 0 ; i < defShopVector.size() ; i++ ){
		cout << "Spell Name: " << defShopVector.at(i).getName() << endl;
		cout << "Gold Cost: " << defShopVector.at(i).getGoldCost() << endl;
		cout << "Minimum Level: " << defShopVector.at(i).getMinLevel() << endl;
		cout << "Mana Cost: " << defShopVector.at(i).getManaCost() << endl << endl;
		//cout << "Spell Duration: " << defShopVector.at(i).getDuration() << endl << endl;
	}
	for(int i = 0 ; i < offShopVector.size() ; i++ ){
		cout << "Spell Name: " << offShopVector.at(i).getName() << endl;
		cout << "Gold Cost: " << offShopVector.at(i).getGoldCost() << endl;
		cout << "Minimum Level: " << offShopVector.at(i).getMinLevel() << endl;
		cout << "Mana Cost: " << offShopVector.at(i).getManaCost() << endl << endl;
		//cout << "Spell Duration: " << offShopVector.at(i).getDuration() << endl << endl;
	}

}

void SpellShop::setSpellCost(){

	for(int i = 0 ; i < defShopVector.size() ; i++ ){
		if (defShopVector.at(i).getName() == "cure critical"){
			defShopVector.at(i).setGoldCost(10);
		}
		else if (defShopVector.at(i).getName() == "cure light"){
			defShopVector.at(i).setGoldCost(10);
		}
		else if (defShopVector.at(i).getName() == "cure serious"){
			defShopVector.at(i).setGoldCost(10);
		}
		else if (defShopVector.at(i).getName() == "heal"){
			defShopVector.at(i).setGoldCost(20);
		}
		else if (defShopVector.at(i).getName() == "hezekiahs cure"){
			defShopVector.at(i).setGoldCost(30);
		}				
	}

	for(int i = 0 ; i < offShopVector.size() ; i++ ){
		if (offShopVector.at(i).getName() == "cause critical"){
			offShopVector.at(i).setGoldCost(10);
		}
		else if (offShopVector.at(i).getName() == "cause light"){
			offShopVector.at(i).setGoldCost(10);
		}
		else if (offShopVector.at(i).getName() == "cause serious"){
			offShopVector.at(i).setGoldCost(10);
		}
		else if (offShopVector.at(i).getName() == "flamestrike"){
			offShopVector.at(i).setGoldCost(30);
		}
		else if (offShopVector.at(i).getName() == "lightning breath"){
			offShopVector.at(i).setGoldCost(20);
		}				
	}
}

void SpellShop::printMenu(){
	cout << "What would you like to do?" << endl;
	cout << "Menu: " << endl;
	cout << "1. Show Spells" << endl;
	cout << "2. Buy Spells" << endl;
	cout << "3. Exit Shop" << endl;
}

string SpellShop::toLower(string &str){
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

bool SpellShop::buySpell(Character &player){
	//cout<< "player level is : " << player.getLevel() << endl;
	string spelltype;
	cout << "Type of Spell would you like to buy:" << endl;
	cout << "1. Offense \n2. Defense\n3. Exit" << endl;
	getline(cin, spelltype);
	if(spelltype == "1"){ //User chooses to buy offensive spell
		cinClear(); //Clear spelltype
		string spellchoice; //Spell the user chooses to buy
		cout << "What Offensive spell do you want to buy?" << endl;
		cout << "\nOffensive Spells:" << endl;
		for(int i = 0 ; i < offShopVector.size() ; i++ ){
			cout << offShopVector.at(i).getName() << "  (" << offShopVector.at(i).getGoldCost() << " Gold)" << endl;
		}
		cout << "Exit" << endl;
		getline(cin, spellchoice);
		toLower(spellchoice);
		//Exit
		if(spellchoice == "exit"){
			cout << "Returning to main menu" << endl;
			cinClear();
			return true;
		}
		//Check if spell is valid
		if(spellchoice != "cause critical" && spellchoice != "cause light"
			&& spellchoice != "cause serious" && spellchoice != "flamestrike" && spellchoice != "lightning breath"){
			cout << "Spell does not exist" << endl << endl;
			cinClear(); //clear spellchoice
			return true;
		}
		int spellIndex; // Used to find the specific spell
		for(int i = 0 ; i < offShopVector.size() ; i++ ){
			if(spellchoice == offShopVector.at(i).getName()){
				spellIndex = i;
				break;
			}
		}
		if(player.getLevel() < offShopVector.at(spellIndex).getMinLevel()){ //Check player level requirement
			cout << "You do not meet the level requirement!" << endl;
			cout << "Required level is: " << offShopVector.at(spellIndex).getMinLevel() << endl;
			cinClear(); //clear spellchoice
			return true;
		}
		if(player.getGold() < offShopVector.at(spellIndex).getGoldCost()){ //Check player has enough gold
			cout << "You don't have enough gold to buy this spell!" << endl;
			cout << "The spell costs " << offShopVector.at(spellIndex).getGoldCost() << endl;
			cout << "Amount of gold you have is " << player.getGold() << endl;
			cinClear();//clear spellchoice
			return true;
		}
		player.setGold(player.getGold() - offShopVector.at(spellIndex).getGoldCost());
		cout << "You have successfully bought " << spellchoice << endl;
		player.addOffSpell(offShopVector.at(spellIndex)); // Adding bought spell to player's spells
		offShopVector.erase(offShopVector.begin() + spellIndex); //Removing spell from vector because it's bought
		cout << "Amount of gold you have now is " << player.getGold() << endl;
		cinClear(); //clear spellchoice
		printMenu();
		return false;	
	}
	else if(spelltype == "2"){ //User chooses to buy defensive spell
		cinClear(); //Clear spelltype
		string spellchoice; //Spell the user chooses to buy
		cout << "What Defensive spell do you want to buy?" << endl;
		cout << "\nDefensive Spells:" << endl;
		for(int i = 0 ; i < defShopVector.size() ; i++ ){
			cout << defShopVector.at(i).getName() << "  (" << defShopVector.at(i).getGoldCost() << " Gold)" << endl;
		}
		cout << "Exit" << endl;
		getline(cin, spellchoice);
		toLower(spellchoice);
		//Exit
		if(spellchoice == "exit"){
			cout << "Returning to main menu" << endl;
			cinClear();
			return true;
		}
		//Check if spell is valid
		if(spellchoice != "cure critical" && spellchoice != "cure light" && spellchoice != "cure serious" 
			&& spellchoice != "heal" && spellchoice != "hezekiahs cure"){
			cout << "Spell does not exist" << endl << endl;
			cinClear(); //clear spellchoice
			return true;
		}
		int spellIndex; //Used to find the specific spell
		for(int i = 0 ; i < defShopVector.size() ; i++ ){
			if(spellchoice == defShopVector.at(i).getName()){
				spellIndex = i;
				break;
			}
		}
		if(player.getLevel() < defShopVector.at(spellIndex).getMinLevel()){ //Check player level requirement
			cout << "You do not meet the level requirement!" << endl;
			cout << "Required level is: " << defShopVector.at(spellIndex).getMinLevel() << endl;
			cinClear(); //clear spellchoice
			return true;
		}
		if(player.getGold() < defShopVector.at(spellIndex).getGoldCost()){ //Check player has enough gold
			cout << "You don't have enough gold to buy this spell!" << endl;
			cout << "The spell costs " << defShopVector.at(spellIndex).getGoldCost() << endl;
			cout << "Amount of gold you have is " << player.getGold() << endl;
			cinClear();//clear spellchoice
			return true;
		}
		player.setGold(player.getGold() - defShopVector.at(spellIndex).getGoldCost());
		cout << "You have successfully bought " << spellchoice << endl;
		player.addDefSpell(defShopVector.at(spellIndex)); // Adding bought spell to player's spells
		defShopVector.erase(defShopVector.begin() + spellIndex); //Removing spell from vector because it's bought
		cout << "Amount of gold you have now is " << player.getGold() << endl;
		cinClear(); //clear spellchoice
		printMenu();
		return false;
	}
	else if(spelltype == "3"){ //User chooses to exit
		cout << "Exiting Buy Spell" << endl;
		printMenu();
		cinClear();
		return false;
	}
	else{ //User has a typo or enters invalid input
		cout << "Incorrect Input" << endl;
		cinClear();
		return true;
	}
}

void SpellShop::shopMenu(Character &player){
	cout << getDescription() << endl;
	printMenu();
	string choice;
	cin.clear();
	while(getline(cin,choice)){
		if(choice == "3"){ //Exit Spell Shop
			break;
		}
		else if(choice == "1"){ //See Spells
			cout<< "Available Spells:" << endl << endl;
			displaySpells();
			cinClear();
			printMenu();
		}
		else if(choice == "2"){
			bool buyfail;
			do{
				buyfail = buySpell(player);
			}while(buyfail);
			cinClear();		
		}
		else if(choice.length() > 0){
			cout << "Please enter the correct command. " << endl << endl;
			cinClear();
			printMenu();
		}
	}
}
#endif