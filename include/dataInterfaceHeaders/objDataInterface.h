#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceBase.h"

using namespace std;

class objDataInterface : public dataInterfaceBase{
private: 

	struct OBJECT {
		vector<string> extra;
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
	vector<string> getExtra (const int& index);

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

	void printExtra(const int& index);

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

