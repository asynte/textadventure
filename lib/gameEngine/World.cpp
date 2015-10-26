#ifndef WORLD_CPP
#define WORLD_CPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "gameEngineHeaders/World.h"
#include "yaml-cpp/yaml.h"
#include "userInterfaceHeaders/UserInterface.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"
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
	initializeWorld(name);
}


//function to replace the commented build() function, this is to call all of louie's yaml parsing
void World::initializeWorld(string name){
 	string fileName="../data/"+name+".yml";
 	roomDataInterface room{fileName};
	room.loadAll();
	
}

string World::getName(){
	return name;
}
// void World::getInformation(int currentLocation){
// 	UserInterface_println(getName());
// 	roomsVector[currentLocation].getInformation();
// }
// vector<Room> World:: getRoomsVector(){
// 	return roomsVector;
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
/*void World::goToRoom(int id){
	for(int i=0;i<roomsVector.size();i++){
		if(roomsVector[i].getID()==id){
			roomIndex=i;
		}
	}
	getNowRoomInformation();
}*/
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
