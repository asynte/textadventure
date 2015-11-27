#ifndef DOOR_CPP
#define DOOR_CPP


#include "gameEngineHeaders/Door.h"
#include "userInterfaceHeaders/UserInterface.h"

//1 for North, 2 for South, 3 for West, 4 for East, 5 for Up, 6 for Down
Door::Door(string description,string direction,vector<string> keywords,int toID) {
	this->description = description;
	this->direction = direction;
	this->keywords.reserve(keywords.size());
	copy(keywords.begin(),keywords.end(),back_inserter(this->keywords));
	this->toID=toID;
}

string Door::getDescription(){
	return description;
}

int Door::getDirectionAsInt(const string &str){
	if(str == "south"){
		return 2;
	}
	else if(str == "north"){
		return 0;
	}
	else if(str == "up"){
		return 5;
	}
	else if(str == "east"){
		return 3;
	}
	else if(str == "west"){
		return 1;
	}
	else if(str == "down"){
		return 6;
	}
	else{
		return 0;
		//zero means direction not found
	}
}


string Door::getDirection(){
	return direction;
}
vector<string> Door::getKeywords(){
	return keywords;
}
int Door::getNextRoomID(){
	return toID;
}
void Door::getInformation(){
	// if(getToID()!=0){

	// 	UserInterface_println("You will go to Room: " + I2S(getToID()) );
	// 	UserInterface_println("Its description: " + getDescription());
	// 	UserInterface_println("Its direction: " + getDirection());
	// 	UserInterface_println("Its keywords: " + getKeywords());
	// }

}
void Door::setDescription(string description){
	this->description=description;
}
void Door::setDirection(string direction){
	this->direction=direction;
}
void Door::setKeywords(vector<string> keywords){
	this->keywords=keywords;
}
void Door::setToID(int toID){
	this->toID=toID;
}

#endif
