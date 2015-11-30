#ifndef DATA_INTERFACE_BASE_H
#define DATA_INTERFACE_BASE_H

#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "../gameEngineHeaders/Room.h"
#include "../gameEngineHeaders/Door.h"
#include "../gameEngineHeaders/Extended.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/DefSpell.h"
#include "gameEngineHeaders/OffSpell.h"

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

	string getDescription (const int& index);
	vector <NPC> getNPCVector();
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

	string getLongDescription (const int& index);

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

	// store each OBJECTS node on objVector
	vector<Object> objVector;

	// node where root of yaml file will be set
	YAML::Node baseNode;

	// node where OBJECTS sequence of yaml file will be set
	YAML::Node objNode;

	struct EXTRA {
		vector<string> extraDescriptionVector;
		vector<string> extraKeyWordsVector;
	};

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

	string getExtraDescription (const int& objIndex);

	vector<string> getExtraKeyWord(const int& objIndex);
	vector<Object> getObjVector();
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

	string getLongDescription (const int& index);

	// Pre-condition:
    //    0 <= index < objNode.size()
    // Post-condition:
    //    Returns the short description of OBJECTS struct at specified index
	string getShortDescription (const int& index);

	///////////////////////////////////
	// 		  PRINT FUNCTIONS        //
	///////////////////////////////////


	void printExtraDescription(const int& objIndex);

	void printExtraKeyWord(const int& objIndex);

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
	// store each node on vector
	vector<Room> roomVector;

	// node where root of yaml file will be set
	YAML::Node baseNode;

	// node where ROOMS sequence of yaml file will be set
	YAML::Node roomNode;

public:

	// room constructor
	roomDataInterface();
	roomDataInterface(const string& file)
	: baseNode(YAML::LoadFile(file)) {
		cout << "file loaded" << endl;
		roomNode = baseNode["ROOMS"];
	}

	// room deconstructor
	~roomDataInterface() {}

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

 	string getDescription (const int& index);

	int getID (const int& index);

	string getName (const int& index);
	vector <Room> getRoomVector();

	string getDoorDescription (const int& roomIndex, const int& doorIndex);

	string getDoorDirection (const int& roomIndex, const int& doorIndex);

	vector<string> getDoorKeyWord (const int& roomIndex, const int& doorIndex);

	int getDoorTO (const int& roomIndex, const int& doorIndex);


	string getExtendedDescription (const int& roomIndex, const int& extendedIndex);
	
	vector<string> getExtendedKeyWord (const int& roomIndex, const int& extendedIndex);

	int getRoomSize ();

	int getDoorSize (const int& index);

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

	void printAction (const int& index);
	
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


class dataEmitter {
private: 

	vector<string> area;
	vector<string> npcs;
	vector<string> objects;
	vector<string> resets;
	vector<string> rooms;

	string yamlFileName;

	ofstream outFile;

	YAML::Emitter emitter;
public:

	dataEmitter(const string& file)
	: yamlFileName(file  + ".yml") {

		std::ifstream inFile(yamlFileName);

		if (inFile.peek() == std::ifstream::traits_type::eof()) {
			// area.push_back("AREA:\n");
			// npcs.push_back("NPCS:\n");
			// objects.push_back("OBJECTS:\n");
			// resets.push_back("RESETS:\n");
			// rooms.push_back("ROOMS:\n");

		}

		else {
			string line;
			int count = 0;

			while (getline (inFile, line)) {

				if (line == "NPCS:") {
					count = 1;
				}	

				if (line == "OBJECTS:") {
					count = 2;
				}

				if (count == 0) {
					area.push_back(line + "\n");
				}
		

				if (count == 1) {
					npcs.push_back(line + "\n");
				}

				if (count == 2) {
					objects.push_back(line + "\n");
				}
			}
		}

		outFile.open(yamlFileName);

	}

	~dataEmitter() {
		outFile.close();
	}

	virtual void searchLine (const string& s);

	virtual void printToFile ();

	virtual void emitArea ();

	virtual void emitNPC ();


};


class spellDataInterface{
private: 

	// struct DEFSPELL {
	// 	int duration;
	// 	string effect;
	// 	string hitChar;
	// 	string hitVict;
	// 	int mana;
	// 	int minLevel;
	// 	string name;
	// 	string wearOff;
	// };

	// struct OFFSPELL {
	// 	string damMsg;
	// 	int duration;
	// 	int mana;
	// 	int minLevel;
	// 	string name;
	// 	string damage;
	// };

	// store each node on vector
	vector <DefSpell> defSpellVector;
	vector <OffSpell> offSpellVector;

	// node where root of yaml file will be set
	YAML::Node baseNode;

	// node where SPELL sequence of yaml file will be set
	YAML::Node offenseNode, defenseNode;

public:

	// spell constructor
	spellDataInterface(const string& file)
	: baseNode(YAML::LoadFile(file)), defenseNode(baseNode["defense"]), offenseNode(baseNode["offense"]){

	}

	// spell deconstructor
	~spellDataInterface() {}


	virtual void printDefDuration(const int& index);
	virtual void printEffect(const int& index);
	virtual void printHitChar(const int& index);
	virtual void printHitVict(const int& index);
	virtual void printDefMana(const int& index);
	virtual void printDefMinLevel(const int& index);
	virtual void printDefName(const int& index);

	virtual void printDamMsg(const int& index);
	virtual void printOffDuration(const int& index);
	virtual void printOffMana(const int& index);
	virtual void printOffMinLevel(const int& index);
	virtual void printOffName(const int& index);
	virtual void printDamage(const int& index);

	virtual void printAtIndexDefense(const int& index);
	virtual void printAtIndexOffense(const int& index);
	virtual void printAll();

	///////////////////////////////////
	// 		   LOAD FUNCTIONS        //
	///////////////////////////////////

	virtual void pushDef (const int& index);
	virtual void pushOff (const int& index);

	virtual void loadAllDefenseSpell();
	virtual void loadAllOffenseSpell();
	virtual void loadAll();

	///////////////////////////////////
	// 		   GET FUNCTIONS         //
	///////////////////////////////////

	vector <DefSpell> getDefVector();
	vector <OffSpell> getOffVector();
};

#endif