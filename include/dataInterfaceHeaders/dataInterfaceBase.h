#ifndef DATA_INTERFACE_BASE_H
#define DATA_INTERFACE_BASE_H

#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"

using namespace std;

class dataInterfaceBase {
public:


	///////////////////////////////////
	// 		  PRINT FUNCTIONS        //
	///////////////////////////////////

	virtual void printAtIndex (const int& index) = 0;
	
	virtual void printAtID (const int& id) = 0;

	virtual void printAll () = 0;

	///////////////////////////////////
	// 		  LOAD FUNCTIONS         //
	///////////////////////////////////

	virtual void push (const int& index) = 0;

	virtual void load (const int& count) = 0;

	virtual void loadFromID (const vector<int>& id) = 0;

	virtual void loadFromID (const int& id) = 0;

	virtual void loadAll() = 0;

	// virtual void add
	// virtual void remove
	// virtual void loadAtIndex (const int& index) = 0;
	// virtual void load same node X times

};


class npcDataInterface : public dataInterfaceBase{
private: 

	struct NPC {
		vector<string> description;
		int id;
		vector<string> keyWord;
		vector<string> longDesc;
		string shortDesc;
	};

	// store each NPCS node on npcVector
	vector<NPC> npcVector;

	// node where root of yaml file will be set
	YAML::Node baseNode;

	// node where NPCS sequence of yaml file will be set
	YAML::Node npcNode;

public:

	// npc constructor
	npcDataInterface(const string& file)
	: baseNode(YAML::LoadFile(file)), npcNode(baseNode["NPCS"]){

	}

	// npc deconstructor
	~npcDataInterface() {}

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

 	// Pre-condition:
    //    0 <= index < npcNode.size()
    // Post-condition:
    //    Returns the description of NPC struct at specified index
	vector<string> getDescription (const int& index);

	// Pre-condition:
    //    0 <= index < npcNode.size()
    // Post-condition:
    //    Returns the id of NPC struct at specified index
	int getID (const int& index);

	// Pre-condition:
    //    0 <= index < npcNode.size()
    // Post-condition:
    //    Returns the key word of NPC struct at specified index
	vector<string> getKeyWord (const int& index);

	// Pre-condition:
    //    0 <= index < npcNode.size()
    // Post-condition:
    //    Returns the long description of NPC struct at specified index
	vector<string> getLongDescription (const int& index);

	// Pre-condition:
    //    0 <= index < npcNode.size()
    // Post-condition:
    //    Returns the short description of NPC struct at specified index
	string getShortDescription (const int& index);

	///////////////////////////////////
	// 		  PRINT FUNCTIONS        //
	///////////////////////////////////

	void printDescription(const int& index);

	void printID (const int& index);

	void printKeyWord (const int& index);

	void printShortDescription (const int& index);

	void printLongDescription (const int& index);

	virtual void printAtIndex (const int& index);

	virtual void printAtID (const int& id);

	virtual void printAll ();

	///////////////////////////////////
	// 		   LOAD FUNCTIONS        //
	///////////////////////////////////

	virtual void push (const int& index);

	virtual void load (const int& count);

	virtual void loadFromID (const int& id);

	virtual void loadFromID (const vector<int>& id);

	virtual void loadAll();

};


class objDataInterface : public dataInterfaceBase{
private: 

	struct EXTRA {
		vector<string> description;
		vector<string> keyWord;
	};
	struct OBJECT {
		vector<EXTRA> extra;
		int id;
		vector<string> keyWord;
		vector<string> longDesc;
		string shortDesc;

	};

	// store each OBJECTS node on objVector
	vector<OBJECT> objVector;

	// node where root of yaml file will be set
	YAML::Node baseNode;

	// node where OBJECTS sequence of yaml file will be set
	YAML::Node objNode;

public:

	// obj constructor
	objDataInterface(const string& file)
	: baseNode(YAML::LoadFile(file)), objNode(baseNode["OBJECTS"]){

	}

	// obj deconstructor
	~objDataInterface() {}

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

 	// Pre-condition:
    //    0 <= index < objNode.size()
    // Post-condition:
    //    Returns the extra of OBJECTS struct at specified index
	vector<string> getExtraDescription (const int& objIndex, const int& extraIndex);

	vector<string> getExtraKeyWord(const int& objIndex, const int& extraIndex);

	// Pre-condition:
    //    0 <= index < objNode.size()
    // Post-condition:
    //    Returns the id of OBJECTS struct at specified index
	int getID (const int& index);

	// Pre-condition:
    //    0 <= index < objNode.size()
    // Post-condition:
    //    Returns the key word of OBJECTS struct at specified index
	vector<string> getKeyWord (const int& index);

	// Pre-condition:
    //    0 <= index < objNode.size()
    // Post-condition:
    //    Returns the long description of OBJECTS struct at specified index
	vector<string> getLongDescription (const int& index);

	// Pre-condition:
    //    0 <= index < objNode.size()
    // Post-condition:
    //    Returns the short description of OBJECTS struct at specified index
	string getShortDescription (const int& index);

	///////////////////////////////////
	// 		  PRINT FUNCTIONS        //
	///////////////////////////////////

	void printExtraDescription(const int& objIndex, const int& extraIndex);

	void printExtraKeyWord(const int& objIndex, const int& extraIndex);

	void printID (const int& index);

	void printKeyWord (const int& index);

	void printShortDescription (const int& index);

	void printLongDescription (const int& index);

	virtual void printAtIndex (const int& index);

	virtual void printAtID (const int& id);

	virtual void printAll ();

	///////////////////////////////////
	// 		   LOAD FUNCTIONS        //
	///////////////////////////////////

	virtual void push (const int& index);

	virtual void load (const int& count);

	virtual void loadFromID (const int& id);

	virtual void loadFromID (const vector<int>& id);

	virtual void loadAll();

};


class roomDataInterface : public dataInterfaceBase{
private: 

	struct DOOR {
		vector<string> description;
		string direction;
		vector<string> keyWord;
		int to;
	};

	struct EXTENDED {
		vector<string> description;
		vector<string> keyWord;
	};

	struct ROOM {
		vector<string> description;
		vector<DOOR> door;
		vector<EXTENDED> extended;
		int id;
		string name;
	};

	// store each node on vector
	vector<ROOM> roomVector;

	// node where root of yaml file will be set
	YAML::Node baseNode;

	// node where ROOMS sequence of yaml file will be set
	YAML::Node roomNode;

public:

	// room constructor
	roomDataInterface(const string& file)
	: baseNode(YAML::LoadFile(file)), roomNode(baseNode["ROOMS"]) {

	}

	// room deconstructor
	~roomDataInterface() {}

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

 	vector<string> getDescription (const int& index);

	int getID (const int& index);

	string getName (const int& index);


	vector<string> getDoorDescription (const int& roomIndex, const int& doorIndex);

	string getDoorDirection (const int& roomIndex, const int& doorIndex);

	vector<string> getDoorKeyWord (const int& roomIndex, const int& doorIndex);

	int getDoorTO (const int& roomIndex, const int& doorIndex);


	vector<string> getExtendedDescription (const int& roomIndex, const int& extendedIndex);
	
	vector<string> getExtendedKeyWord (const int& roomIndex, const int& extendedIndex);


	///////////////////////////////////
	// 		  PRINT FUNCTIONS        //
	///////////////////////////////////

	void printDescription(const int& index);
	
	void printID (const int& index);

	void printName (const int& index);


	void printDoorDescription(const int& roomIndex, const int& doorIndex);

	void printDoorDirection (const int& roomIndex, const int& doorIndex);

	void printDoorKeyWord (const int& roomIndex, const int& doorIndex);

	void printDoorTO (const int& roomIndex, const int& doorIndex);


	void printExtendedDescription(const int& roomIndex, const int& extendedIndex);

	void printExtendedKeyWord (const int& roomIndex, const int& extendedIndex);


	virtual void printAtIndex (const int& index);

	virtual void printAtID (const int& id);

	virtual void printAll ();

	///////////////////////////////////
	// 		   LOAD FUNCTIONS        //
	///////////////////////////////////

	virtual void push (const int& index);

	virtual void load (const int& count);

	virtual void loadFromID (const int& id);

	virtual void loadFromID (const vector<int>& id);

	virtual void loadAll();

};


class resetDataInterface : public dataInterfaceBase{
private: 

	struct RESET {
		string action;
		string comment;
		int id;
		int limit;
		int room;
		int slot;
	};

	// store each node on vector
	vector<RESET> resetVector;

	// node where root of yaml file will be set
	YAML::Node baseNode;

	// node where RESET sequence of yaml file will be set
	YAML::Node resetNode;

public:

	// reset constructor
	resetDataInterface(const string& file)
	: baseNode(YAML::LoadFile(file)), resetNode(baseNode["RESETS"]) {

	}

	// reset deconstructor
	~resetDataInterface() {}

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

 	string getAction (const int& index);

	string getComment (const int& index);

	int getID (const int& index);

	int getLimit (const int& index);

	int getRoom (const int& index);

	int getSlot (const int& index);

	///////////////////////////////////
	// 		  PRINT FUNCTIONS        //
	///////////////////////////////////

	void printAction(const int& index);
	
	void printComment (const int& index);

	void printID (const int& index);

	void printLimit (const int& index);
	
	void printRoom (const int& index);

	void printSlot (const int& index);

	virtual void printAtIndex (const int& index);

	virtual void printAtID (const int& id);

	virtual void printAll ();

	///////////////////////////////////
	// 		   LOAD FUNCTIONS        //
	///////////////////////////////////

	virtual void push (const int& index);

	virtual void load (const int& count);

	virtual void loadFromID (const int& id);

	virtual void loadFromID (const vector<int>& id);

	virtual void loadAll();

};

#endif
