#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "yaml-cpp/yaml.h"
using namespace std;

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

	// return description of ROOM struct at specified index
	string roomDataInterface::getDescription (const int& index) {
		return roomVector[index].getDescription();
	}

	// return id of ROOM struct at specifiedindex
	int roomDataInterface::getID (const int& index) {
		return roomVector[index].getID();
	}

	// return name of ROOM struct at specified index
	string roomDataInterface::getName (const int& index) {
		return roomVector[index].getName();
	}
	vector <Room> roomDataInterface::getRoomVector(){
		return roomVector;
	}

	// DOOR roomDataInterface::getDoor (const int& index) {
	// 	return roomVector[index].door;
	// }

	// return description of DOOR struct at specified index
	string roomDataInterface::getDoorDescription (const int& roomIndex, const int& doorIndex) {
		Room room=roomVector[roomIndex];
		Door door=room.getDoorsList()[doorIndex];

		return door.getDescription();
	}

	string roomDataInterface::getDoorDirection (const int& roomIndex, const int& doorIndex) {
		Room room=roomVector[roomIndex];
		Door door=room.getDoorsList()[doorIndex];
		return door.getDirection();
	}

	vector<string> roomDataInterface::getDoorKeyWord (const int& roomIndex, const int& doorIndex) {
		Room room=roomVector[roomIndex];
		Door door=room.getDoorsList()[doorIndex];
		return door.getKeywords();
	}

	int roomDataInterface::getDoorTO (const int& roomIndex, const int& doorIndex) {
		Room room=roomVector[roomIndex];
		Door door=room.getDoorsList()[doorIndex];
		return door.getToID();
	}



	// return extended description of ROOM struct at specified index
	string roomDataInterface::getExtendedDescription (const int& roomIndex, const int& extendedIndex) {
		Room room=roomVector[roomIndex];
		
		if (room.getExtended().size()==0) {
			return NULL;
		}

		else {
			Extended extended=room.getExtended()[extendedIndex];
			return extended.getDescription();
		}
	}

	// return keyword of ROOM struct at specified index
	vector<string> roomDataInterface::getExtendedKeyWord (const int& roomIndex, const int& extendedIndex) {
		Room room=roomVector[roomIndex];
		Extended extended=room.getExtended()[extendedIndex];
		if (room.getExtended().size()==0 ){
			return vector<string>();
		}

		else {
			Extended extended=room.getExtended()[extendedIndex];
			return extended.getKeyWord();
		}
	}





	///////////////////////////////////
	// 		  PRINT FUNCTIONS	     //
	///////////////////////////////////

	// print description of ROOM struct at specified index
	void roomDataInterface::printDescription (const int& index) {
		Room room=roomVector[index];
		// for all strings at ROOM description vector
		cout << "Description\n";
		
		cout << "- " << room.getDescription() << "\n";
		
	}

	// print id of ROOM struct at specified index
	void roomDataInterface::printID (const int& index) {
		Room room=roomVector[index];

		cout << "ID: " << room.getID() << "\n";
	}

	void roomDataInterface::printName (const int& index) {
		Room room=roomVector[index];
		cout << "Name: " << room.getName() << "\n";
	}




	void roomDataInterface::printDoorDescription (const int& roomIndex, const int& doorIndex) {
		// for all strings at DOOR description vector
		cout << "Door description\n";
		Room room=roomVector[roomIndex];
		Door door=room.getDoorsList()[doorIndex];
		cout << "- " << door.getDescription() << "\n";

	}

	// print direction of ROOM struct at specified index
	void roomDataInterface::printDoorDirection (const int& roomIndex, const int& doorIndex) {
		Room room=roomVector[roomIndex];
		Door door=room.getDoorsList()[doorIndex];
		cout << "Door direction: " << door.getDirection() << "\n";
	}

	// print key word of ROOM struct at specified index
	void roomDataInterface::printDoorKeyWord (const int& roomIndex, const int& doorIndex) {
		// for all strings at ROOM keywords vector
		cout << "Door keywords\n";
		Room room=roomVector[roomIndex];
		Door door=room.getDoorsList()[doorIndex];
		for (string s : door.getKeywords()){
			cout << "- " << s << "\n";
		}
	}

	// print direction of ROOM struct at specified index
	void roomDataInterface::printDoorTO (const int& roomIndex, const int& doorIndex) {
		Room room=roomVector[roomIndex];
		Door door=room.getDoorsList()[doorIndex];
		cout << "Door TO: " << door.getToID() << "\n";
	}

	// print extended description of ROOM struct at specified index
	void roomDataInterface::printExtendedDescription (const int& roomIndex, const int& extendedIndex) {
		// for all strings at ROOM long description vector
		cout << "Extended description\n";
		Room room=roomVector[roomIndex];
		Extended extended=room.getExtended()[extendedIndex];
		
		cout << "- " << extended.getDescription() << "\n";
	}

	// print keyword of ROOM struct at specified index
	void roomDataInterface::printExtendedKeyWord (const int& roomIndex, const int& extendedIndex) {
		cout << "Extended keywords\n";
		Room room=roomVector[roomIndex];
		Extended extended=room.getExtended()[extendedIndex];
		for (string s : extended.getKeyWord()){
			cout << "- " << s << "\n";
		}	
	}

	// print elements of ROOM struct at specified index
	void roomDataInterface::printAtIndex (const int& index) {
		printDescription(index);
		Room room=roomVector[index];
		for (int i = 0; i < room.getDoorsList().size(); i++) {
			printDoorDescription(index, i);
			printDoorDirection(index, i);
			printDoorKeyWord(index, i);
			printDoorTO(index, i);
		}


		for (int i = 0; i < room.getExtended().size(); i++) {

			printExtendedDescription(index, i);
			printExtendedKeyWord(index, i);
		}


		printID(index);	
		printName(index);
		cout << "\n";
	}


	// print elements of ROOM struct at specified ROOM ID
	void roomDataInterface::printAtID (const int& id) {

		// go through all ROOM nodes in roomVector
		int i = 0;
		while (id != roomVector[i].getID()) {
			i++;
		}	

		if (i < roomVector.size()) {
			printAtIndex(i);
		}
	
	}

	// print all ROOM struct at roomVector
	void roomDataInterface::printAll () {

		// go through all ROOM nodes in ROOMS sequence
		for (int i = 0; i < roomVector.size(); i++) {
			printAtIndex(i);
		}		
	}

	///////////////////////////////////
	// 		  LOAD FUNCTIONS	     //
	///////////////////////////////////

	// push ROOM node to ROOM struct vector
	void roomDataInterface::push (const int& index) {

		vector<Door> doorVector;
		
		for (int i = 0; i < roomNode[index]["doors"].size(); i++){
			YAML::Node descriptionNode=roomNode[index]["desc"];
			string description;
			for(int j=0;j<descriptionNode.size();j++){
				description+=descriptionNode[j].as<string>()+" ";
			}
			doorVector.push_back(Door(
				description,
				roomNode[index]["doors"][i]["dir"].as<string>(),
				roomNode[index]["doors"][i]["keywords"].as<vector<string>>(),
				roomNode[index]["doors"][i]["to"].as<int>()
			));
		}

		vector<Extended> extendedVector;

		for (int i = 0; i < roomNode[index]["extended_descriptions"].size(); i++){
			YAML::Node descriptionNode=roomNode[index]["desc"];
			string description;
			for(int j=0;j<descriptionNode.size();j++){
				description+=descriptionNode[j].as<string>()+" ";
			}
			extendedVector.push_back(Extended(
				description,
				roomNode[index]["extended_descriptions"][i]["keywords"].as<vector<string>>()
			));
		}

		YAML::Node roomDescriptionNode=roomNode[index]["desc"];
		string roomDescription;
		for(int j=0;j<roomDescriptionNode.size();j++){
				roomDescription+=roomDescriptionNode[j].as<string>()+" ";
			}
		roomVector.push_back(Room(
			roomDescription,
			doorVector,
			extendedVector,
			roomNode[index]["name"].as<string>(),
			roomNode[index]["id"].as<int>()
			

		));
	}

	// push "count" amount of nodes into roomVector
	void roomDataInterface::load (const int& count) {

		// if count is greater than roomNode size
		if (count > roomNode.size()) {

			// cout error message and return from function
			cout << "Error: count cannot be greater than node size.\n";
			return;
		}

		// if count is valid number
		else if (count < roomNode.size()) {

			// loop "count" amount of times
			for (int i = 0; i < count; i++) {

				// push current ROOM node to vector
				push(i);

			}
		}
	}

	// push node with specified "id" into roomVector
	void roomDataInterface::loadFromID(const int& id) {


		int i = 0;
		while (id != roomNode[i]["id"].as<int>()) {
			i++;
		}	

		if (i < roomNode.size()) {
			// push current ROOM node to vector	
			push(i);
		}		
	}


	// push node with specified "ids" into roomVector
	void roomDataInterface::loadFromID(const vector<int>& id) {

		// loop id.size() times
		for (int count = 0; count < id.size(); count++) {
		
			loadFromID(id[count]);
		}
	}


	// push all ROOM nodes into roomVector
	void roomDataInterface::loadAll() {

		// go through all ROOM nodes in ROOM sequence
		for (int i = 0; i < roomNode.size(); i++) {

			// push current ROOM node to vector
			push(i);
		}
	}