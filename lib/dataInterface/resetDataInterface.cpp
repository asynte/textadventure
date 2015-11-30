#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Reset.h"


using namespace std;

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

	// return action of RESET struct at specified index
	string resetDataInterface::getAction (const int& index) {
		return resetVector[index].getAction();
	}

	// return comment of RESET struct at specified index
	string resetDataInterface::getComment (const int& index) {
		return resetVector[index].getComment();
	}

	// return id of RESET struct at specifiedindex
	int resetDataInterface::getID (const int& index) {
		return resetVector[index].getId();
	}


	// return limit of RESET struct at specifiedindex
	int resetDataInterface::getLimit (const int& index) {
		return resetVector[index].getLimit();
	}


	// return room of RESET struct at specifiedindex
	int resetDataInterface::getRoom (const int& index) {
		return resetVector[index].getRoom();
	}


	// return slot of RESET struct at specifiedindex
	int resetDataInterface::getSlot (const int& index) {
		return resetVector[index].getSlot();
	}

	string resetDataInterface::getState (const int& index) {
		return resetVector[index].getState();
	}
	vector<Reset> resetDataInterface::getResetVector(){
		return resetVector;
	}


	///////////////////////////////////
	// 		  PRINT FUNCTIONS	     //
	///////////////////////////////////

	// print action of RESET struct at specified index
	void resetDataInterface::printAction (const int& index) {
		cout << "Action: " << resetVector[index].getAction() << "\n";
	}

	// print comment of RESET struct at specified index
	void resetDataInterface::printComment (const int& index) {
		cout << "Comment: " << resetVector[index].getComment() << "\n";
	}

	// print ID of RESET struct at specified index
	void resetDataInterface::printID (const int& index) {
		cout << "ID: " << resetVector[index].getId() << "\n";
	}

	// print limit of RESET struct at specified index
	void resetDataInterface::printLimit (const int& index) {
		cout << "Limit: " << resetVector[index].getLimit() << "\n";
	}

	// print room of RESET struct at specified index
	void resetDataInterface::printRoom (const int& index) {
		cout << "Room: " << resetVector[index].getRoom() << "\n";
	}

		// print slot of RESET struct at specified index
	void resetDataInterface::printSlot (const int& index) {
		cout << "Slot: " << resetVector[index].getSlot() << "\n";
	}

	void resetDataInterface::printState (const int& index) {
		if (getState(index) == "locked") {cout << "State: " << resetVector[index].getState() << "\n";}
	}

	// print elements of RESET struct at specified index
	void resetDataInterface::printAtIndex (const int& index) {
		printAction(index);
		printComment(index);	
		printID(index);
		printLimit(index);
		printRoom(index);
		printSlot(index);
		printState(index);
		cout << "\n";
	}

	// print elements of RESET struct at specified RESET ID
	void resetDataInterface::printAtID (const int& id) {

		// go through all RESET nodes in resetVector
		int i = 0;
		while (id != resetVector[i].getId()) {
			i++;
		}	

		if (i < resetVector.size()) {
			printAtIndex(i);
		}
	
	}

	// print all RESET struct at resetVector
	void resetDataInterface::printAll () {

		// go through all RESET nodes in RESETS sequence
		for (int i = 0; i < resetVector.size(); i++) {
			printAtIndex(i);
		}		
	}

	///////////////////////////////////
	// 		  LOAD FUNCTIONS	     //
	///////////////////////////////////

	// push RESET node to RESET struct vector
	void resetDataInterface::push (const int& index) {

		// RESET.action 	  = resetNode[i]["action"].as<string>()
		// RESET.comment 	  = resetNode[i]["comment"].as<string>()
		// RESET.id     	  = resetNode[i]["id"].as<int>()
		// RESET.limit    	  = resetNode[i]["limit"].as<int>()
		// RESET.room  	  = resetNode[i]["room"].as<int>()
		// RESET.slot  	  = resetNode[i]["slot"].as<int>()

		string comment = "";
		int limit = 0;
		int room = 0;
		int slot = 0;
		string state = "unlocked";

		if (resetNode[index]["comment"] != NULL) {
			comment = resetNode[index]["comment"].as<string>();
		}

		if (resetNode[index]["limit"] != NULL) {
			limit = resetNode[index]["limit"].as<int>();
		}

		if (resetNode[index]["room"] != NULL) {
			room = resetNode[index]["room"].as<int>();
		}

		if (resetNode[index]["slot"] != NULL) {
			slot = resetNode[index]["slot"].as<int>();
		}

		if (resetNode[index]["state"] != NULL) {
			state = resetNode[index]["state"].as<string>();
		}

		resetVector.push_back(Reset(
			resetNode[index]["action"].as<string>(), 
			comment, 
			resetNode[index]["id"].as<int>(),
			limit, 
			room,
			slot,
			state
		));
	}

	// push "count" amount of nodes into resetVector
	void resetDataInterface::load (const int& count) {

		// if count is greater than resetNode size
		if (count > resetNode.size()) {

			// cout error message and return from function
			cout << "Error: count cannot be greater than node size.\n";
			return;
		}

		// if count is valid number
		else if (count < resetNode.size()) {

			// loop "count" amount of times
			for (int i = 0; i < count; i++) {

				// push current RESET node to vector
				push(i);

			}
		}
	}

	// push node with specified "id" into resetVector
	void resetDataInterface::loadFromID(const int& id) {

		int i = 0;
		while (id != resetNode[i]["id"].as<int>()) {
			i++;
		}	

		if (i < resetNode.size()) {
			// push current RESET node to vector	
			push(i);
		}		
	}


	// push node with specified "id" into resetVector
	void resetDataInterface::loadFromID(const vector<int>& id) {

		// loop id.size() times
		for (int count = 0; count < id.size(); count++) {
			
			loadFromID(id[count]);
		}
	}


	// push all RESET nodes into resetVector
	void resetDataInterface::loadAll() {

		// go through all RESET nodes in RESET sequence
		for (int i = 0; i < resetNode.size(); i++) {

			// push current RESET node to vector
			push(i);
		}
	}