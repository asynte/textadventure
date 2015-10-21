#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"

using namespace std;

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

	// return description of ROOM struct at specified index
	vector<string> roomDataInterface::getDescription (const int& index) {
		return roomVector[index].description;
	}

	// return id of ROOM struct at specifiedindex
	int roomDataInterface::getID (const int& index) {
		return roomVector[index].id;
	}

	// return name of ROOM struct at specified index
	string roomDataInterface::getName (const int& index) {
		return roomVector[index].name;
	}


	// DOOR roomDataInterface::getDoor (const int& index) {
	// 	return roomVector[index].door;
	// }

	// return description of DOOR struct at specified index
	vector<string> roomDataInterface::getDoorDescription (const int& roomIndex, const int& doorIndex) {
		return roomVector[roomIndex].door[doorIndex].description;
	}

	string roomDataInterface::getDoorDirection (const int& roomIndex, const int& doorIndex) {
		return roomVector[roomIndex].door[doorIndex].direction;
	}

	vector<string> roomDataInterface::getDoorKeyWord (const int& roomIndex, const int& doorIndex) {
		return roomVector[roomIndex].door[doorIndex].keyWord;
	}

	int roomDataInterface::getDoorTO (const int& roomIndex, const int& doorIndex) {
		return roomVector[roomIndex].door[doorIndex].to;
	}



	// return extended description of ROOM struct at specified index
	vector<string> roomDataInterface::getExtendedDescription (const int& roomIndex, const int& extendedIndex) {
		if (roomVector[roomIndex].extended.empty()) {
			return vector<string>();
		}

		else {
			return roomVector[roomIndex].extended[extendedIndex].description;
		}
	}

	// return keyword of ROOM struct at specified index
	vector<string> roomDataInterface::getExtendedKeyWord (const int& roomIndex, const int& extendedIndex) {
		
		if (roomVector[roomIndex].extended.empty()) {
			return vector<string>();
		}

		else {
			return roomVector[roomIndex].extended[extendedIndex].keyWord;
		}
	}





	///////////////////////////////////
	// 		  PRINT FUNCTIONS	     //
	///////////////////////////////////

	// print description of ROOM struct at specified index
	void roomDataInterface::printDescription (const int& index) {
		// for all strings at ROOM description vector
		cout << "Description\n";
		for (string s : roomVector[index].description){
			cout << "- " << s << "\n";
		}
	}

	// print id of ROOM struct at specified index
	void roomDataInterface::printID (const int& index) {
		cout << "ID: " << roomVector[index].id << "\n";
	}

	void roomDataInterface::printName (const int& index) {
		cout << "Name: " << roomVector[index].name << "\n";
	}




	void roomDataInterface::printDoorDescription (const int& roomIndex, const int& doorIndex) {
		// for all strings at DOOR description vector
		cout << "Door description\n";
		for (string s : roomVector[roomIndex].door[doorIndex].description){
			cout << "- " << s << "\n";
		}
	}

	// print direction of ROOM struct at specified index
	void roomDataInterface::printDoorDirection (const int& roomIndex, const int& doorIndex) {
		cout << "Door direction: " << roomVector[roomIndex].door[doorIndex].direction << "\n";
	}

	// print key word of ROOM struct at specified index
	void roomDataInterface::printDoorKeyWord (const int& roomIndex, const int& doorIndex) {
		// for all strings at ROOM keywords vector
		cout << "Door keywords\n";
		for (string s : roomVector[roomIndex].door[doorIndex].keyWord){
			cout << "- " << s << "\n";
		}
	}

	// print direction of ROOM struct at specified index
	void roomDataInterface::printDoorTO (const int& roomIndex, const int& doorIndex) {
		cout << "Door TO: " << roomVector[roomIndex].door[doorIndex].to << "\n";
	}

	// print extended description of ROOM struct at specified index
	void roomDataInterface::printExtendedDescription (const int& roomIndex, const int& extendedIndex) {
		// for all strings at ROOM long description vector
		cout << "Extended description\n";
		for (string s : roomVector[roomIndex].extended[extendedIndex].description){
			cout << "- " << s << "\n";
		}
	}

	// print keyword of ROOM struct at specified index
	void roomDataInterface::printExtendedKeyWord (const int& roomIndex, const int& extendedIndex) {
		cout << "Extended keywords\n";
		for (string s : roomVector[roomIndex].extended[extendedIndex].keyWord){
			cout << "- " << s << "\n";
		}	
	}

	// print elements of ROOM struct at specified index
	void roomDataInterface::printAtIndex (const int& index) {
		printDescription(index);

		for (int i = 0; i < roomVector[index].door.size(); i++) {
			printDoorDescription(index, i);
			printDoorDirection(index, i);
			printDoorKeyWord(index, i);
			printDoorTO(index, i);
		}


		for (int i = 0; i < roomVector[index].extended.size(); i++) {

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
		while (id != roomNode[i]["id"].as<int>()) {
			i++;
		}	

		if (i < roomNode.size()) {
			printAtIndex(i);
		}
	
	}

	// print all ROOM struct at roomVector
	void roomDataInterface::printAll () {

		// go through all ROOM nodes in ROOMS sequence
		for (int i = 0; i < roomNode.size(); i++) {
			printAtIndex(i);
		}		
	}

	///////////////////////////////////
	// 		  LOAD FUNCTIONS	     //
	///////////////////////////////////

	// push ROOM node to ROOM struct vector
	void roomDataInterface::push (const int& index) {

	vector<DOOR> doorVector;


	for (int i = 0; i < roomNode[index]["doors"].size(); i++){
		doorVector.push_back(DOOR{
			roomNode[index]["doors"][i]["desc"].as<vector<string>>(),
			roomNode[index]["doors"][i]["dir"].as<string>(),
			roomNode[index]["doors"][i]["keywords"].as<vector<string>>(),
			roomNode[index]["doors"][i]["to"].as<int>()
		});
	}

	vector<EXTENDED> extendedVector;

	for (int i = 0; i < roomNode[index]["extended_descriptions"].size(); i++){
		extendedVector.push_back(EXTENDED{
			roomNode[index]["extended_descriptions"][i]["desc"].as<vector<string>>(),
			roomNode[index]["extended_descriptions"][i]["keywords"].as<vector<string>>()
		});
	}


	roomVector.push_back(ROOM{
		roomNode[index]["desc"].as<vector<string>>(),
		doorVector,
		extendedVector,
		roomNode[index]["id"].as<int>(),
		roomNode[index]["name"].as<string>()

	});


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


	// push node with specified "id" into roomVector
	void roomDataInterface::loadFromID(const vector<int>& id) {

		// loop id.size() times
		for (int count = 0; count < id.size(); count++) {
		
			int i = 0;
			while (id[count] != roomNode[i]["id"].as<int>()) {
				i++;
			}	

			if (i < roomNode.size()) {
				// push current ROOM node to vector	
				push(i);
			}	
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



