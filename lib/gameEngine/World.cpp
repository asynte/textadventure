#ifndef WORLD_CPP
#define WORLD_CPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "gameEngineHeaders/World.h"
//#include "gameEngineHeaders/Character.h"
//#include "gameEngineHeaders/Widget.h"
#include "userInterfaceHeaders/UserInterface.h"
#include <unistd.h>



static void parseUserInput(const string &command, const string &arguement);


class InterfaceObserver : public Observer {
    public:
		InterfaceObserver()	{}

		void notify(const string &userInput) {
			//call functions with userInput as arguement

			parseUserInput(userInput, "");
		}
		void notify(const vector<string> &userInput) {
			string command = userInput.at(0);
			string arguement = userInput.at(1);

			parseUserInput(command, arguement);
		}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS IS ONLY THING I NEED TO EDIT
void parseUserInput(const string &command, const string &arguement) {
	if (command == "move") {
		UserInterface_println("entered the move command!");
		//Character::move(this, Door::getDirectionAsInt(arguement))
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

World::World(string name){
	this->name=name;
	initializeWorld(name);

	InterfaceObserver *observer = new InterfaceObserver();
	UserInterface_addListener(observer);
}
// void World::parseUserInput(const string &command, const string &arguement) {
// 	// if (userInput == "move") {
// 	// 	Character::move(this, Door::getDirectionAsInt(arguement))
// 	// }

// }


//function to replace the commented build() function, this is to call all of louie's yaml parsing
void World::initializeWorld(string name){
 	string fileName="data/"+name+".yml";
 	roomDataInterface room{fileName};
	room.loadAll();
	roomsVector=room.getRoomVector();


	
}

string World::getName(){
	return name;
}
// string World::getInformation(){
// 	return "a";
// }
void World::getInformation(){
	for(Room r:roomsVector){
		cout<<r.getName()<<endl;
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
			c.setLocation(i);
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
/*
//This function is equivalent to old function
//vector<string> getAllWorld(vector<string> vstring)
//Just renamed
vector<string> CreateWorld(vector<string> vstring){
	vector<string> filenames;

	InterfaceObserver *observer = new InterfaceObserver();

	for(int i=0;i<vstring.size();i++){
		string temp=getYAMLFileName(vstring[i]);
		if(temp.compare("")!=0){
			filenames.push_back(temp);
		}
	}

	UserInterface_addListener(observer);
	
	return filenames;
}
*/





#endif
