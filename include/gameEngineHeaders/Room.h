using namespace std;

#ifndef ROOM_H
#define ROOM_H


#include <iostream>
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/NPC.h"
#include <vector>
#include "gameEngineHeaders/Extended.h"

class Room{
public:
	Room();
	Room(int);
	Room(string,vector<Door>,vector<Extended>,string,int);
	string getDescription();
	vector<Door> getDoorsList() const;
	vector<Extended> getExtended();
	Door getDoorWantToGo(int direction);
	string getName() const;
	int getID() const;
	void getInformation();
	bool isRoomAvailable(int direction);

	vector<string> getPossibleDirections();


private:
	string description;
	vector<Door> doorsList;
	vector<Extended> extendedList;
	int ID;
	string name;
    vector<Widget> widgetVector;
};

#endif
