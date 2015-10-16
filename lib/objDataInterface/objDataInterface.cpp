#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/objDataInterface.h"

using namespace std;

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

	// return extra of OBJECT struct at specified index
	vector<string> objDataInterface::getExtra (const int& index) {
		return objVector[index].extra;
	}

	// return id of OBJECT struct at specifiedindex
	int objDataInterface::getID (const int& index) {
		return objVector[index].id;
	}

	// return keyword of OBJECT struct at specified index
	vector<string> objDataInterface::getKeyWord (const int& index) {
		return objVector[index].keyWord;
	}

	// return long description of OBJECT struct at specified index
	vector<string> objDataInterface::getLongDescription (const int& index) {
		return objVector[index].longDesc;
	}

	// return short description of OBJECT struct at specified index
	string objDataInterface::getShortDescription (const int& index) {
		return objVector[index].shortDesc;
	}


	///////////////////////////////////
	// 		  PRINT FUNCTIONS	     //
	///////////////////////////////////

	// print extra of OBJECT struct at specified index
	void objDataInterface::printExtra (const int& index) {
		// for all strings at object extra vector
		for (string s : objVector[index].extra){
			cout << s << "\n";
		}
	}

	// print id of OBJECT struct at specified index
	void objDataInterface::printID (const int& index) {
		cout << objVector[index].id << "\n";
	}

	// print key word of OBJECT struct at specified index
	void objDataInterface::printKeyWord (const int& index) {
		// for all strings at obj keywords vector
		for (string s : objVector[index].keyWord){
			cout << s << "\n";
		}
	}

	// print long description of OBJECT struct at specified index
	void objDataInterface::printLongDescription (const int& index) {
		// for all strings at obj long description vector
		for (string s : objVector[index].longDesc){
			cout << s << "\n";
		}
	}

	// print short description of OBJECT struct at specified index
	void objDataInterface::printShortDescription (const int& index) {
		cout << objVector[index].shortDesc << "\n";
	}

	// print elements of OBJECT struct at specified index
	void objDataInterface::printAtIndex (const int& index) {
		printExtra(index);
		printID(index);	
		printKeyWord(index);
		printLongDescription(index);
		printShortDescription(index);
	}

	// print elements of OBJECT struct at specified OBJECT ID
	void objDataInterface::printAtID (const int& id) {

		// go through all OBJECT nodes in objVector
		int i = 0;
		while (id != objNode[i]["id"].as<int>()) {
			i++;
		}	

		if (i < objNode.size()) {
			printAtIndex(i);
		}
	
	}

	// print all OBJECT struct at objVector
	void objDataInterface::printAll () {

		// go through all OBJECT nodes in OBJECTS sequence
		for (int i = 0; i < objNode.size(); i++) {
			printAtIndex(i);
		}		
	}

	///////////////////////////////////
	// 		  LOAD FUNCTIONS	     //
	///////////////////////////////////

	// push OBJECT node to OBJECT struct vector
	void objDataInterface::push (const int& index) {

		// OBJECT.extra = objNode[i]["extra"].as<vector<string>>()
		// OBJECT.id 		   = objNode[i]["id"].as<int>()
		// OBJECT.keyWord     = objNode[i]["keywords"].as<vector<string>>()
		// OBJECT.longDesc    = objNode[i]["longdesc"].as<vector<string>>()
		// OBJECT.shortDesc   = objNode[i]["shortdesc"].as<string>()

		objVector.push_back(OBJECT{
			objNode[index]["extra"].as<vector<string>>(), 
			objNode[index]["id"].as<int>(), 
			objNode[index]["keywords"].as<vector<string>>(),
			objNode[index]["longdesc"].as<vector<string>>(), 
			objNode[index]["shortdesc"].as<string>()
		});
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
		
			int i = 0;
			while (id[count] != objNode[i]["id"].as<int>()) {
				i++;
			}	

			if (i < objNode.size()) {
				// push current OBJECT node to vector	
				push(i);
			}	
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



