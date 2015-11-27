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
	}

	return -1;
}

Room World::getCurrentRoom(Character &player) {
	int currentRoomIndex = this->getRoom(player.getLocation()); // get index of player's current room

	cout << "index: " << currentRoomIndex << endl;

	if (currentRoomIndex == -1) {
		cout << "Room does not exist!" << endl;
		exit(0);
	}
	return roomsVector[currentRoomIndex];
}
string World::getCharacterMoveDirection(Character &player, string userCommand){
	if(userCommand=="left"){
		player.turnLeft();
		return player.getDirection();
	}else if(userCommand=="right"){
		player.turnRight();
		return player.getDirection();
	}else if(userCommand=="back"){
		player.turnBack();
		return player.getDirection();
	}else if(userCommand=="forward"){
		return player.getDirection();
	}
	return "Wrong command";
}

void World::moveCharacter(Character &player, string userCommand){
	int currentRoomIndex = this->getRoom(player.getLocation()); // get index of player's current room
	Room currentRoom = this->getCurrentRoom(player);

	string direction = getCharacterMoveDirection(player,userCommand);
	if(direction!="Wrong command"){
		int moveDirection = currentRoom.getDoorsList()[0].getDirectionAsInt(direction);
		if (currentRoom.isRoomAvailable(moveDirection)) {
		// above line checks whether the command to move is a movable direction

			currentRoom.removeCharacter(player);

			this->setCharRoom(player, currentRoomIndex, moveDirection);
			cout << "You have moved to " + to_string(player.getLocation()) << endl;
			this->getCurrentRoom(player).addCharacter(player);
		}
		else{
			cout<<"You cannot go in this direction because this direction does not exist"<<endl; 
		}
	}else{
		cout<<"Wrong dirction"<<endl;
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


vector<string> World::getAllDirections(Character &player) { // Used for UserInterface
	Room currentRoom = getCurrentRoom(player);
	return currentRoom.getAllDirections();
}
vector<string> World::getAllKeywords(Character &player) { // Used for UserInterface
	Room currentRoom = getCurrentRoom(player);
	return currentRoom.getAllKeyWords();
}




#endif

