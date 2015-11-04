#ifndef WORLD_CPP
#define WORLD_CPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "gameEngineHeaders/World.h"


World::World(){
	cout << " Midgaard World Created" << endl;
	this -> name = "midgaard";
	initializeWorld(name);
}

World::World(string name){
	this -> name = name;
	initializeWorld(name);
}


////////////////////////////////////////
//	Getter functions


string World::getName(){
	return name;
}

vector <Room> World::getRoomsVector(){
	return roomsVector;
}

Room World::getRoom(string roomName){
	for (Room r:roomsVector){
		if (r.getName() == roomName){
			return r;		
		}		
	}	
	//return r;
}

vector <Character> World::getCharactersVector(){
	return charactersVector;
}

Character World::getCharacter(string characterName){
	for (Character c:charactersVector){
		if (c.getName() == characterName){
			return c;
		}
	}
}


////////////////////////////////////////
//	Setter Functions


////////////////////////////////////////
//	Creator & helper functions


//function to replace the commented build() function, this is to call all of louie's yaml parsing
void World::initializeWorld(string name){
 	string fileName = "data/" + name + ".yml";

 	roomDataInterface roomInterface(fileName);
	roomInterface.loadAll();
	roomsVector = roomInterface.getRoomVector();
}

bool World::findRoom(string roomName){
	for (Room r:roomsVector){
		if (r.getName() == roomName){
			return true;		
		}		
	}
	return false;
}

void World::addRoom(const Room &room){
	roomsVector.push_back(room);
}

bool World::findCharacter(string characterName){
	for (Character c:charactersVector){
		if (c.getName() == characterName){
			return true;		
		}		
	}
	return false;
}

void World::addCharacter(const Character &character) {
	charactersVector.push_back(character);
}

void World::goToRoom(int id, Character &c){
	for(int i=0; i < roomsVector.size(); i++){
		if(roomsVector[i].getID() == id){
			c.setLocation(roomsVector[i]);
		}
	}
	// Maybe print out which room it just went into
}


//////////////////////////////////////
// 	Print functions

void World::printRoomNames(){
	for(Room r:roomsVector){
		UserInterface_println(r.getName());
	}	
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

// int World::convertDirectionString(const string &direction){
// 	door.getDirectionAsInt(direct);
// }
// void World::getNowRoomInformation(int currentLocation){
// 	roomsVector[currentLocation].getInformation();
// }


#endif
