using namespace std;

#ifndef ROOM_H
#define ROOM_H


#include <iostream>
#include "Door.h"
#include "Widget.h"
#include <vector>
#include "Extended.h"

class Room{
public:
	Room();
	Room(string,vector<Door>,vector<Extended>,string,int);
	string getDescription();
	vector<Door> getDoorsList();
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
        //vector<Widget> widgetVector;
};

#endif
