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



World::World(string name){
	this->name=name;
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

// void World::parseUserInput(const string &command, const string &arguement) {
// 	// if (userInput == "move") {
// 	// 	Character::move(this, Door::getDirectionAsInt(arguement))
// 	// }

// }


//function to replace the commented build() function, this is to call all of louie's yaml parsing
void World::initializeWorld(string name){
 	string fileName="data/"+name+".yml";

 	cout<<"cunt";
 	roomDataInterface room(fileName);

	room.loadAll();
	roomsVector=room.getRoomVector();


	
}

string World::getName(){
	return name;
}

void World::printRoomNames(){
	for(Room r:roomsVector){
		// cout<<r.getName()<<endl;
		UserInterface_println(r.getName());
	}	
}

vector<Room> World:: getRoomsVector(){
	return roomsVector;
}


// int World::willGoToRoom(int direction, int currentLocation){
// 	Room nowRoom=roomsVector[currentLocation];

// 	if(nowRoom.isRoomAvailable(direction)){
// 		Door door = nowRoom.getDoorWantToGo(direction);
// 		door.getInformation();
// 		return door.getToID();
// 	}

// 	UserInterface_println("ERROR! Invalid move direction");
// 	return -1;
// }

// int World::willGoToRoom(int direction, int currentLocation){
// 	Room nowRoom=roomsVector[currentLocation];
// 	Door door;
// 	if(nowRoom.isRoomAvailable(direction)){
// 		door=nowRoom.getDoorWantToGo(direction);
// 	}
// 	door.getInformation();
// 	return door.getToID();
// }

void World::goToRoom(int id, Character &c){
	for(int i=0;i<roomsVector.size();i++){
		if(roomsVector[i].getID()==id){
			c.setLocation(id);
		}
	}
	// Maybe print out which room it just went into
}

// void World::goToRoom(int id){
// 	if (id == -1) {
// 		return;
// 	}

// 	for(int i=0; i < roomsVector.size(); ++i){
// 		if(roomsVector[i].getID()==id){
// 			//Character::move(this, i);
// 			return;
// 		}
// 	}
// }

// int World::convertDirectionString(const string &direction){
// 	door.getDirectionAsInt(direct);
// }
// void World::getNowRoomInformation(int currentLocation){
// 	roomsVector[currentLocation].getInformation();
// }
void World::addRoom(Room room){
	//can not do
}






#endif
