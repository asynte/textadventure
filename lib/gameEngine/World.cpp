#ifndef WORLD_CPP
#define WORLD_CPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "gameEngineHeaders/World.h"
#include "yaml-cpp/yaml.h"
#include "userInterfaceHeaders/UserInterface.h"

class InterfaceObserver : public Observer {
    public:
		InterfaceObserver()	{}

		void notify(const string &userInput) {
			//call functions with userInput as arguement
			UserInterface_println(userInput);
		}
		void notify(const vector<string> &userInput) {
			//do more stuff with the parsed strings
			//like call a function with arguements...
		}
};

World::World(){
	name="";
}
World::World(string name){
	this->name=name;
	build(name);
}
/*
void World::build(string name){
	string fileName="./data/"+name+".yml";
	YAML::Node baseNode = YAML::LoadFile(fileName);

	// sets root node on ROOMS category
	YAML::Node charNode = baseNode["ROOMS"];
	// store each ROOM node on vector

	// go through all ROOM blocks on yaml file
	for (int i = 0; i < charNode.size(); i++) {
		YAML::Node descriptionNode=charNode[i]["desc"];
		string roomDescription;
		for(int j=0;j<descriptionNode.size();j++){
			roomDescription+=descriptionNode[j].as<string>()+" ";
		}
		vector <Door> doorsVector;
		YAML::Node doorsNode=charNode[i]["doors"];
		//get door information
		for(int j=0;j<doorsNode.size();j++){
			YAML::Node doorDescriptionNode=doorsNode[j]["desc"];
			string doorDescription;
			for(int k=0;k<doorDescriptionNode.size();k++){
				doorDescription+=doorDescriptionNode[k].as<string>()+" ";
			}


			string doorDirection=doorsNode[j]["dir"].as<string>();
			string doorKeywords;
			if(!doorsNode[j]["keywords"].IsSequence()){
				doorKeywords=doorsNode[j]["keywords"].as<string>();
			}else{
				doorKeywords="";
			}

			int doorToID=doorsNode[j]["to"].as<int>();
			//doorsVector.push_back(doorDescription,doorDirection,doorKeywords,doorToID);

			doorsVector.push_back(Door(doorDescription,doorDirection,doorKeywords,doorToID));
		}

		//get Room id;
		int roomID=charNode[i]["id"].as<int>();
		string roomName=charNode[i]["name"].as<string>();
		roomsVector.push_back(Room(roomDescription,doorsVector,roomName,roomID));
		
	}
}
*/
/*
void World::InitializeWorld(){
function to replace the commented build() function,
this is to call all of louie's yaml parsing
}
*/

string World::getName(){
	return name;
}
void World::getInformation(int currentLocation){
	UserInterface_println(getName());
	roomsVector[currentLocation].getInformation();
}
vector<Room> World:: getRoomsVector(){
	return roomsVector;
}
int World::willGoToRoom(int direction, int currentLocation){
	Room nowRoom=roomsVector[currentLocation];
	Door door;
	if(nowRoom.isRoomAvailable(direction)){
		door=nowRoom.getDoorWantToGo(direction);
	}
	door.getInformation();
	return door.getToID();
}
/*void World::goToRoom(int id){
	for(int i=0;i<roomsVector.size();i++){
		if(roomsVector[i].getID()==id){
			roomIndex=i;
		}
	}
	getNowRoomInformation();
}*/
void World::getNowRoomInformation(int currentLocation){
	roomsVector[currentLocation].getInformation();
}
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
