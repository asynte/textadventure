#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Object.h"

using namespace std;

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

	// return extra of OBJECT struct at specified index
	/*vector<string> objDataInterface::getExtraDescription (const int& objIndex, const int& extraIndex) {
		if (objVector[objIndex].getExtra().empty()) {
			return vector<string>();
		}

		else {
			return objVector[objIndex].extra[extraIndex].description;
		}
	}*/

	vector<string> objDataInterface::getExtraKeyWord (const int& objIndex/*, const int& extraIndex*/) {
		if (objVector[objIndex].getExtra().empty()) {
			return vector<string>();
		}

		else {
			return objVector[objIndex].getExtra();
		}
	}

	// return id of OBJECT struct at specifiedindex
	int objDataInterface::getID (const int& index) {
		return objVector[index].getId();
	}

	// return keyword of OBJECT struct at specified index
	vector<string> objDataInterface::getKeyWord (const int& index) {
		return objVector[index].getKeyWords();
	}

	// return long description of OBJECT struct at specified index
	string objDataInterface::getLongDescription (const int& index) {
		return objVector[index].getLongDesc();
	}

	// return short description of OBJECT struct at specified index
	string objDataInterface::getShortDescription (const int& index) {
		return objVector[index].getName();
	}


	///////////////////////////////////
	// 		  PRINT FUNCTIONS	     //
	///////////////////////////////////

	// print extra of OBJECT struct at specified index
	/*void objDataInterface::printExtraDescription (const int& objIndex, const int& extraIndex) {
		// for all strings at ROOM long description vector
		cout << "Extra description\n";
		for (string s : objVector[objIndex].getExtra()[extraIndex].getDesc()){
			cout << "- " << s << "\n";
		}
	}*/

	// print extra of OBJECT struct at specified index
	void objDataInterface::printExtraKeyWord (const int& objIndex/*, const int& extraIndex*/) {
		// for all strings at ROOM long description vector
		cout << "Extra keywords\n";
		for (string s : objVector[objIndex].getExtra()){
			cout << "- " << s << "\n";
		}
	}

	// print id of OBJECT struct at specified index
	void objDataInterface::printID (const int& index) {
		cout << "ID: " << objVector[index].getId() << "\n";
	}

	// print key word of OBJECT struct at specified index
	void objDataInterface::printKeyWord (const int& index) {
		// for all strings at obj keywords vector
		cout << "Keywords\n";
		for (string s : objVector[index].getKeyWords()){
			cout << "- " << s << "\n";
		}
	}

	// print long description of OBJECT struct at specified index
	void objDataInterface::printLongDescription (const int& index) {
		// for all strings at obj long description vector
		cout << "Long Description: " + objVector[index].getLongDesc() << endl;
	}

	// print short description of OBJECT struct at specified index
	void objDataInterface::printShortDescription (const int& index) {
		cout << "Short description: " << objVector[index].getName() << "\n";
	}

	// print elements of OBJECT struct at specified index
	void objDataInterface::printAtIndex (const int& index) {
		
		/*for (int i = 0; i < objVector[index].extra.size(); i++) {

			printExtraDescription(index, i);
			printExtraKeyWord(index, i);
		}*/
			printExtraKeyWord(index);
		printID(index);	
		printKeyWord(index);
		printLongDescription(index);
		printShortDescription(index);
		cout << "\n";
	}

	// print elements of OBJECT struct at specified OBJECT ID
	void objDataInterface::printAtID (const int& id) {

		int i = 0;
		while (id != objVector[i].getId()) {
			i++;
		}	

		if (i < objVector.size()) {
			printAtIndex(i);
		}
	
	}

	// print all OBJECT struct at objVector
	void objDataInterface::printAll () {

		// go through all OBJECT nodes in objVector
		for (int i = 0; i < objVector.size(); i++) {
			printAtIndex(i);
		}		
	}

	///////////////////////////////////
	// 		  LOAD FUNCTIONS	     //
	///////////////////////////////////

	// push OBJECT node to OBJECT struct vector
	void objDataInterface::push (const int& index) {

		// OBJECT.extra
		// OBJECT.id 		   = objNode[i]["id"].as<int>()
		// OBJECT.keyWord     = objNode[i]["keywords"].as<vector<string>>()
		// OBJECT.longDesc    = objNode[i]["longdesc"].as<vector<string>>()
		// OBJECT.shortDesc   = objNode[i]["shortdesc"].as<string>()


		//vector<string> extraVector;
                YAML::Node longdescNode = objNode[index]["longdesc"];
                string longDescription;
            // concatenate entire long description
            for (int k = 0; k < longdescNode.size(); k++) {
                longDescription += longdescNode[k].as<string>() + " ";
            }

		/*for (int i = 0; i < objNode[index]["extra"].size(); i++){
			extraVector.push_back(
				objNode[index]["extra"].as<vector<string>>()
			);
		}*/

		objVector.push_back(Object(
			objNode[index]["id"].as<int>(), 
			objNode[index]["extra"].as<vector<string>>(), 
			objNode[index]["keywords"].as<vector<string>>(),
			longDescription, 
			objNode[index]["shortdesc"].as<string>()
		));
	}

	// push "count" amount of nodes into objVector
	void objDataInterface::load (const int& count) {

		// if count is greater than objNode size
		if (count > objNode.size()) {

			// cout error message and return from function
			cout << "Error: count cannot be greater than node size.\n";
			return;
		}

		// if count is valid number
		else if (count < objNode.size()) {

			// loop "count" amount of times
			for (int i = 0; i < count; i++) {

				// push current OBJECT node to vector
				push(i);

			}
		}
	}

	// push node with specified "id" into objVector
	void objDataInterface::loadFromID(const int& id) {

		int i = 0;
		while (id != objNode[i]["id"].as<int>()) {
			i++;
		}	

		if (i < objNode.size()) {
			// push current OBJECT node to vector	
			push(i);
		}		
	}


	// push node with specified "id" into objVector
	void objDataInterface::loadFromID(const vector<int>& id) {

		// loop id.size() times
		for (int count = 0; count < id.size(); count++) {
		
			loadFromID(id[count]);
		}
	}


	// push all OBJECT nodes into objVector
	void objDataInterface::loadAll() {

		// go through all OBJECT nodes in OBJECTS sequence
		for (int i = 0; i < objNode.size(); i++) {

			// push current OBJECT node to vector
			push(i);
		}
	}



