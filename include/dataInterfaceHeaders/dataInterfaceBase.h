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

#endif
