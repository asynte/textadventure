#include <iostream>
#include "Door.h"
#include "Widget.h"
using namespace std;

#ifndef ROOM_H
#define ROOM_H

class Room{
public:
	Room();
	Room(string,vector<Door>,string,int);
	string getDescription();
	vector<Door> getDoorsList();
	Door getDoorWantToGo(int direction);
	string getName();
	int getID();
	void getInformation();
        vector<Widget> getWidgetVector();
        void setWidgetVector(int, Widget);
	bool isRoomAvailable(int direction);
private:
	string description;
	vector<Door> doorsList;
	//string extended_descriptions;
	int ID;
	string name;
        vector<Widget> widgetVector;
};

#endif
