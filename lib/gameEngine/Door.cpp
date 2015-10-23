#ifndef DOOR_CPP
#define DOOR_CPP
#include "gameEngineHeaders/Door.h"
#include "userInterfaceHeaders/UserInterface.h"
//1 for North, 2 for South, 3 for West, 4 for East, 5 for Up, 6 for Down
Door::Door(){ 
	description="";
	direction="";
	keywords="";
	toID=0;
}
Door::Door(string description,string direction,string keywords,int toID) {
	this->description = description;
	this->direction = direction;
	this->keywords=keywords;
	this->toID=toID;
}
string Door::getDescription(){
	return description;
}
int Door::getDirectionAsInt(){
	if(direction.compare("south")==0){
		return 2;
	}else if(direction.compare("north")==0){
		return 1;
	}else if(direction.compare("up")==0){
		return 5;
	}else if(direction.compare("east")==0){
		return 4;
	}else if(direction.compare("west")==0){
		return 3;
	}else{
		return 6;
	}
}
string Door::getDirection(){
	return direction;
}
string Door::getKeywords(){
	return keywords;
}
int Door::getToID(){
	return toID;
}
void Door::getInformation(){
	if(getToID()!=0){

		UserInterface_println("You will go to Room: " + I2S(getToID()) );
		UserInterface_println("Its description: " + getDescription());
		UserInterface_println("Its direction: " + getDirection());
		UserInterface_println("Its keywords: " + getKeywords());
	}

}
void Door::setDescription(string description){
	this->description=description;
}
void Door::setDirection(string direction){
	this->direction=direction;
}
void Door::setKeywords(string keywords){
	this->keywords=keywords;
}
void Door::setToID(int toID){
	this->toID=toID;
}

#endif
