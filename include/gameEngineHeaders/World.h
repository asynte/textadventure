#include "Room.h"
#include "Door.h"
using namespace std;

#ifndef WORLD_H
#define WORLD_H

class World{
public:
	World();
	World(string name);
	void build(string name);
	vector<Room> getRoomsVector();
	string getName();
	void setRoomIndex(int roomIndex);
	void addRoom(Room room);
	void getInformation(int currentLocation);
	int willGoToRoom(int direction, int currentLocation);
	void goToRoom(int roomID);
	void getNowRoomInformation(int currentLocation);
private:
	vector<Room> roomsVector;
	string name;
};



#endif