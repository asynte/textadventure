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
	//Room();
	Room(string,vector<Door>,vector<Extended>,string,int);
	string getDescription();
	vector<Door> getDoorsList();
	vector<Extended> getExtended();
	Door getDoorWantToGo(int direction);
	string getName();
	int getID();
	void getInformation();
        // vector<Widget> getWidgetVector();
        // void setWidgetVector(int, Widget);
	bool isRoomAvailable(int direction);
private:
	string description;
	vector<Door> doorsList;
	vector<Extended> extendedList;
	int ID;
	string name;
        //vector<Widget> widgetVector;
};

#endif
