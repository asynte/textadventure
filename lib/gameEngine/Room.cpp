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
vector<string> Room::getObjectAllKeyWords(){
	vector<string> objectAllKeywords;
	objectAllKeywords.push_back("Objects keyword: ");
	for(Object o:objectList){
		vector<string> objectKeywords=o.getKeyWords();
		for(string s:objectKeywords){
			objectAllKeywords.push_back(s);
		}
	}
	return objectAllKeywords;
}
vector<string> Room::getNPCAllKeyWords(){
	vector<string> npcAllKeywords;
	npcAllKeywords.push_back("NPC keyword: ");
	for(NPC n:npcList){
		vector<string> npcKeywords=n.getKeyWords();
		for(string s:npcKeywords){
			npcAllKeywords.push_back(s);
		}
	}
	return npcAllKeywords;
}
vector<string> Room::getDoorAllKeywords(){
	vector<string> doorAllKeywords;
	doorAllKeywords.push_back("Door keyword: ");
	for(Door d:doorsList){
		vector<string> doorKeywords=d.getKeywords();
		for(string s:doorKeywords){
			doorAllKeywords.push_back(s);
		}
	}
	return doorAllKeywords;
}
vector<string>Room::getAllKeyWords(){
	vector<string> objectAllKeywords=getObjectAllKeyWords();
	vector<string> npcAllKeywords=getNPCAllKeyWords();
	vector<string> doorAllKeywords=getDoorAllKeywords();
	vector<string> allKeywords;
	for(string s:objectAllKeywords){
		allKeywords.push_back(s);
	}
	for(string s:npcAllKeywords){
		allKeywords.push_back(s);
	}
	for(string s:doorAllKeywords){
		allKeywords.push_back(s);
	}
	return allKeywords;
}
vector <Object> Room::getObjectAssociatedKeyword(string keyword){
	vector <Object> objectKey;
	for(int i=0;i<objectList.size();i++){
		vector <string> objKeyword=objectList.at(i).getKeyWords();

		for(string s:objKeyword){
			if(s==keyword){
				objectKey.push_back(objectList.at(i));
			}
		}
	}
	return objectKey;
}
vector <NPC> Room::getNPCAssociatedKeyword(string keyword){
	vector <NPC> NPCkey;
	for(int i=0;i<objectList.size();i++){
		vector <string> npcKeyword=npcList.at(i).getKeyWords();

		for(string s:npcKeyword){
			if(s==keyword){
				NPCkey.push_back(npcList.at(i));
			}
		}
	}
	return NPCkey;
}

vector <int>Room::lookAtExit(){
	vector <int> exits;
	for(Door d:doorsList){
		exits.push_back(d.getToID());
	}
	return exits;
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
