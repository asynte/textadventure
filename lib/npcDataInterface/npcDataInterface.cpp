#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/npcDataInterface.h"

using namespace std;

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

	// return description of NPC struct at specified index
	vector<string> npcDataInterface::getDescription (const int& index) {
		return npcVector[index].description;
	}

	// return id of NPC struct at specifiedindex
	int npcDataInterface::getID (const int& index) {
		return npcVector[index].id;
	}

	// return keyword of NPC struct at specified index
	vector<string> npcDataInterface::getKeyWord (const int& index) {
		return npcVector[index].keyWord;
	}

	// return long description of NPC struct at specified index
	vector<string> npcDataInterface::getLongDescription (const int& index) {
		return npcVector[index].longDesc;
	}

	// return short description of NPC struct at specified index
	string npcDataInterface::getShortDescription (const int& index) {
		return npcVector[index].shortDesc;
	}


	///////////////////////////////////
	// 		  PRINT FUNCTIONS	     //
	///////////////////////////////////

	// print description of NPC struct at specified index
	void npcDataInterface::printDescription (const int& index) {
		// for all strings at npc description vector
		for (string s : npcVector[index].description){
			cout << s << "\n";
		}
	}

	// print id of NPC struct at specified index
	void npcDataInterface::printID (const int& index) {
		cout << npcVector[index].id << "\n";
	}

	// print key word of NPC struct at specified index
	void npcDataInterface::printKeyWord (const int& index) {
		// for all strings at npc keywords vector
		for (string s : npcVector[index].keyWord){
			cout << s << "\n";
		}
	}

	// print long description of NPC struct at specified index
	void npcDataInterface::printLongDescription (const int& index) {
		// for all strings at npc long description vector
		for (string s : npcVector[index].longDesc){
			cout << s << "\n";
		}
	}

	// print short description of NPC struct at specified index
	void npcDataInterface::printShortDescription (const int& index) {
		cout << npcVector[index].shortDesc << "\n";
	}

	// print elements of NPC struct at specified index
	void npcDataInterface::printAtIndex (const int& index) {
		printDescription(index);
		printID(index);	
		printKeyWord(index);
		printLongDescription(index);
		printShortDescription(index);
	}

	// print elements of NPC struct at specified NPC ID
	void npcDataInterface::printAtID (const int& id) {

		// go through all NPC nodes in npcVector
		int i = 0;
		while (id != npcNode[i]["id"].as<int>()) {
			i++;
		}	

		if (i < npcNode.size()) {
			printAtIndex(i);
		}
	
	}

	// print all NPC struct at npcVector
	void npcDataInterface::printAll () {

		// go through all NPC nodes in NPCS sequence
		for (int i = 0; i < npcNode.size(); i++) {
			printAtIndex(i);
		}		
	}

	///////////////////////////////////
	// 		  LOAD FUNCTIONS	     //
	///////////////////////////////////

	// push NPC node to NPC struct vector
	void npcDataInterface::push (const int& index) {

		// NPC.description = npcNode[i]["description"].as<vector<string>>()
		// NPC.id 		   = npcNode[i]["id"].as<int>()
		// NPC.keyWord     = npcNode[i]["keywords"].as<vector<string>>()
		// NPC.longDesc    = npcNode[i]["longdesc"].as<vector<string>>()
		// NPC.shortDesc   = npcNode[i]["shortdesc"].as<string>()

		npcVector.push_back(NPC{
			npcNode[index]["description"].as<vector<string>>(), 
			npcNode[index]["id"].as<int>(), 
			npcNode[index]["keywords"].as<vector<string>>(),
			npcNode[index]["longdesc"].as<vector<string>>(), 
			npcNode[index]["shortdesc"].as<string>()
		});
	}

	// push "count" amount of nodes into npcVector
	void npcDataInterface::load (const int& count) {

		// if count is greater than npcNode size
		if (count > npcNode.size()) {

			// cout error message and return from function
			cout << "Error: count cannot be greater than node size.\n";
			return;
		}

		// if count is valid number
		else if (count < npcNode.size()) {

			// loop "count" amount of times
			for (int i = 0; i < count; i++) {

				// push current NPC node to vector
				push(i);

			}
		}
	}

	// push node with specified "id" into npcVector
	void npcDataInterface::loadFromID(const int& id) {

		int i = 0;
		while (id != npcNode[i]["id"].as<int>()) {
			i++;
		}	

		if (i < npcNode.size()) {
			// push current NPC node to vector	
			push(i);
		}		
	}


	// push node with specified "id" into npcVector
	void npcDataInterface::loadFromID(const vector<int>& id) {

		// loop id.size() times
		for (int count = 0; count < id.size(); count++) {
		
			int i = 0;
			while (id[count] != npcNode[i]["id"].as<int>()) {
				i++;
			}	

			if (i < npcNode.size()) {
				// push current NPC node to vector	
				push(i);
			}	
		}
	}


	// push all NPC nodes into npcVector
	void npcDataInterface::loadAll() {

		// go through all NPC nodes in NPC sequence
		for (int i = 0; i < npcNode.size(); i++) {

			// push current NPC node to vector
			push(i);
		}
	}



