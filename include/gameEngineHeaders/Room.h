using namespace std;

#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/NPC.h"

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
	string getName();
	int getID();
	void getInformation();
	bool isRoomAvailable(int direction);
	void addObject(const Object& o);
	void addNPC(const NPC& npc);
	vector <Object> getObjectList();
	vector <NPC> getNPCList();
private:
	string description;
	vector<Door> doorsList;
	vector<Extended> extendedList;
	vector<Object>objectList;
	vector<NPC>npcList;
	int ID;
	string name;
};

#endif
