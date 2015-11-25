#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/NPC.h"

using namespace std;

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

	// return description of NPC struct at specified index
	string npcDataInterface::getDescription (const int& index) {
		return npcVector[index].getDesc();
	}

	// return id of NPC struct at specifiedindex
	int npcDataInterface::getID (const int& index) {
		return npcVector[index].getId();
	}

	// return keyword of NPC struct at specified index
	vector<string> npcDataInterface::getKeyWord (const int& index) {
		return npcVector[index].getKeyWords();
	}

	// return long description of NPC struct at specified index
	string npcDataInterface::getLongDescription (const int& index) {
		return npcVector[index].getLongDesc();
	}

	// return short description of NPC struct at specified index
	string npcDataInterface::getShortDescription (const int& index) {
		return npcVector[index].getName();

	}
	vector<NPC> npcDataInterface::getNPCVector(){
		return npcVector;
	}


	///////////////////////////////////
	// 		  PRINT FUNCTIONS	     //
	///////////////////////////////////

	// print description of NPC struct at specified index
	void npcDataInterface::printDescription (const int& index) {
		// for all strings at npc description vector
		cout << "Description: " + npcVector[index].getDesc() << endl;
	}

	// print id of NPC struct at specified index
	void npcDataInterface::printID (const int& index) {
		cout << "ID: " + npcVector[index].getId() << "\n";
	}

	// print key word of NPC struct at specified index
	void npcDataInterface::printKeyWord (const int& index) {
		// for all strings at npc keywords vector
		cout << "Keywords\n";
		for (string s : npcVector[index].getKeyWords()){
			cout << "- " << s << "\n";
		}
	}

	// print long description of NPC struct at specified index
	void npcDataInterface::printLongDescription (const int& index) {
		// for all strings at npc long description vector

		cout << "Long Description: " + npcVector[index].getLongDesc() << endl;
	}

	// print short description of NPC struct at specified index
	void npcDataInterface::printShortDescription (const int& index) {

		cout << "Short description: " << npcVector[index].getName() << "\n";
	}

	// print elements of NPC struct at specified index
	void npcDataInterface::printAtIndex (const int& index) {
		printDescription(index);
		printID(index);	
		printKeyWord(index);
		printLongDescription(index);
		printShortDescription(index);
		cout << "\n";
	}

	// print elements of NPC struct at specified NPC ID
	void npcDataInterface::printAtID (const int& id) {

		// go through all NPC nodes in npcVector
		int i = 0;
		while (id != npcVector[i].getId()) {
			i++;
		}	

		if (i < npcVector.size()) {
			printAtIndex(i);
		}
	
	}

	// print all NPC struct at npcVector
	void npcDataInterface::printAll () {

		// go through all NPC nodes in NPCS sequence
		for (int i = 0; i < npcVector.size(); i++) {
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
            
            YAML::Node descNode = npcNode[index]["description"];
            string description;
            // concatenate entire description
            for (int j = 0; j < descNode.size(); j++) {
                description += descNode[j].as<string>() + " ";
            }
            YAML::Node longdescNode = npcNode[index]["longdesc"];
            string longDescription;
            // concatenate entire long description
            for (int k = 0; k < longdescNode.size(); k++) {
                longDescription += longdescNode[k].as<string>() + " ";
            }
            
		npcVector.push_back(NPC(
			npcNode[index]["id"].as<int>(), 
                                description,
			npcNode[index]["keywords"].as<vector<string>>(),
			longDescription, 
			npcNode[index]["shortdesc"].as<string>()
		));
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


		// std::find_if (npcNode.begin(), npcNode.end(), [](YAML::Node n) { return id == n["id"].as<int>(); });
		int i = 0;
		while (id != npcNode[i]["id"].as<int>()) {
			i++;
		}	

		YAML::Node::iterator it = std::find_if (npcNode.begin(), npcNode.end(), [&id](YAML::Node n) { return id == n["id"].as<int>(); });

		if (it == npcNode.end()){
			std::cout << "Error: Index out of bounds\n";
		}

		else {
			int i = std::distance(npcNode.begin(), it);
			push (i);
		}
	}


	// push node with specified "id" into npcVector
	void npcDataInterface::loadFromID(const vector<int>& id) {


		// loop id.size() times
		for (int count = 0; count < id.size(); count++) {
		
			loadFromID(id[count]);
		}
	}

	// push all NPC nodes into npcVector
	void npcDataInterface::loadAll() {

		// go through all NPC nodes in NPC sequence
		for (int index = 0; index < npcNode.size(); index++) {

			// push current NPC node to vector
			push(index);
		}
	}
