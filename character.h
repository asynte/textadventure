// Character Widget inheriting from Widget class
#include <iostream>
#include <vector>
#include <string>
#include "widget.h"

class character: public widget {

private:
	string characterName;
	long characterLevel;
	long characterHealth;
	vector <widget> characterInventory;

public:
	string use(){}

	// return character name
	string get_characterName() const{
		return characterName;
	}

	// return character level
	int get_characterLevel(){
		return characterLevel;
	}

	// return character health
	int get_characterHealth(){
		return characterHealth;
	}

}