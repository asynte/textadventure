#ifndef WORLD_CPP
#define WORLD_CPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "gameEngineHeaders/World.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Widget.h"
//#include "dataInterfaceHeaders/dataInterfaceBase.h"
using namespace std;


World::World(string name){
	this->name=name;
	roomNowIndex=0;
	initializeWorld(name);


}

void World::addCharacter(const Character &character) {
	characters.push_back(character);
}

Room World::getCurrentRoom(const Character &character) {
	//int currentRoomId = character.getLocation();
	int currentRoomId = 0;
	Room currentRoom = roomsVector[currentRoomId];

	return currentRoom;
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


void World::printRoomNames(){
	for(Room r:roomsVector){
		UserInterface_println(r.getName());
	}	
}

int World::getRoom(int roomID) {
	for (int i = 0; i < this->getRoomsVector().size(); i++) {
		if (this->getRoomsVector()[i].getID() == roomID) {
			return i;
		}
		else {
			return -1; //room not found
		}
	}
}

void World::moveCharacter(Character &player, string userCommand){

	int currentRoomIndex = this->getRoom(player.getLocation()); // get index of player's current room
	if (currentRoomIndex == -1) {
		cout << "Room does not exist!" << endl;
		return;
	}
	Room currentRoom = roomsVector[currentRoomIndex];
	int moveDirection = currentRoom.getDoorsList()[0].getDirectionAsInt(userCommand);
	if (currentRoom.isRoomAvailable(moveDirection)) {
	// above line checks whether the command to move is a movable direction
		this->setCharRoom(player, currentRoomIndex, moveDirection);
		cout << "You have moved to " + to_string(player.getLocation()) << endl;
	}
	else{
		cout<<"You cannot go in this direction because this direction does not exist"<<endl; 
	}

}

vector<Character> World::getCharacters() {
	return this->characters;
}

void World::setCharRoom(Character &c, int roomID, int moveDirection){
	for (auto currentDoor : roomsVector[roomID].getDoorsList()) {
		if (currentDoor.getDirectionAsInt(currentDoor.getDirection()) == moveDirection) {
			c.setLocation(currentDoor.getNextRoomID());
			return;
		}
	}
	// Maybe print out which room it just went into
}

void World::addRoom(Room room){
	roomsVector.push_back(room);
}






#endif

