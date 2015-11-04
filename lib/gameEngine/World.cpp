#ifndef WORLD_CPP
#define WORLD_CPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "gameEngineHeaders/World.h"
// class InterfaceObserver : public Observer {
//     public:
// 		InterfaceObserver()	{}

// 		void notify(const string &userInput) {
// 			//call functions with userInput as arguement
// 			UserInterface_println(userInput);
// 		}
// 		void notify(const vector<string> &userInput) {
// 			//do more stuff with the parsed strings
// 			//like call a function with arguements...
// 		}
// };
World::World(string name){
	this->name=name;
	roomNowIndex=0;
	initializeWorld(name);
}


//function to replace the commented build() function, this is to call all of louie's yaml parsing
void World::initializeWorld(string name){
 	string fileName="data/"+name+".yml";
 	roomDataInterface room{fileName};
	room.loadAll();
	roomsVector=room.getRoomVector();
	addObjectToRoom(fileName);
	addNPCToRoom(fileName);
}

string World::getName(){
	return name;
}
vector<Room> World:: getRoomsVector(){
	return roomsVector;
}
Room World::getRoomFindById(int id){
		return roomsVector.at(roomNowIndex);
}



bool World::findRoomById(int roomId){
	for(int i=0;i<roomsVector.size();i++){
		if(roomsVector.at(i).getID()==roomId){
			roomNowIndex=i;
			return true;
		}
	}
	return false;
}


void World::addObjectToRoom(string fileName){
	objDataInterface object(fileName);
	object.loadAll();
	objectVector=object.getObjVector();
	for(int i=0;i<objectVector.size();i++){
		int id=objectVector.at(i).getId();
		for(int j=0;j<roomsVector.size();j++){
			int roomId=roomsVector.at(j).getID();
			if(roomId==id){
				roomsVector.at(j).addObject(objectVector.at(i));
			}
		}
	}
}
void World::addNPCToRoom(string fileName){
	npcDataInterface npc(fileName);
	npc.loadAll();
	npcVector=npc.getNPCVector();
	for(int i=0;i<npcVector.size();i++){
		int id=npcVector.at(i).getId();
		for(int j=0;j<roomsVector.size();j++){
			int roomId=roomsVector.at(j).getID();
			if(roomId==id){
				roomsVector.at(j).addNPC(npcVector.at(i));
			}
		}
	}
}
#endif