#ifndef ROOM_CPP
#define ROOM_CPP
#include "gameEngineHeaders/Room.h"
#include "userInterfaceHeaders/UserInterface.h"

Room::Room(){
	description = "";
	//this->extended_descriptions = extended_descriptions;
	ID=0;
	name="";
}
Room::Room(string description,vector<Door> doorsList,vector<Extended> extendedList,string name,int ID) {
	this->description = description;
	this->doorsList=doorsList;
	this->extendedList = extendedList;
	this->name=name;
	this->ID=ID;
}
string Room::getDescription(){
	return description;
}
vector<Door> Room::getDoorsList(){
	return doorsList;
}
vector<Extended> Room::getExtended(){
	return extendedList;
}
string Room::getName(){
	return name;
}
int Room::getID(){
	return ID;
}
void Room::addObject(const Object& o){
	(this->objectList).push_back(o);
}

vector<Object> Room::getObjectList(){

	return this->objectList;
}
void Room::addNPC(const NPC& npc){
	(this->npcList).push_back(npc);
}
vector<NPC> Room::getNPCList(){

	return this->npcList;
}
bool Room::isRoomAvailable(int direction){
	for(int i=0;i<doorsList.size();i++){
		if(doorsList[i].getDirectionAsInt()==direction){
			return true;
		}
	}
	
	return false;
}
Door Room::getDoorWantToGo(int direction){
	for(int i=0;i<doorsList.size();i++){
		if(doorsList[i].getDirectionAsInt()==direction){
			return doorsList[i];
		}
	}
}
#endif
