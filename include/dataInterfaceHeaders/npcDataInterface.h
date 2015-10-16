#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceBase.h"

using namespace std;

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

