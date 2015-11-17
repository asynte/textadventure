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

// bool World::doesRoomExist(int roomID) {
// 	for (auto currentRoom : roomsVector) {
// 		if (roomID == currentRoom.getID()) {
// 			return true;
// 		}
// 	}
// 	return false;
// }

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
	roomsVector.push_back(room);
}






#endif
