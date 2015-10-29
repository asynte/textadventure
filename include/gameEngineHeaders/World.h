using namespace std;

#ifndef WORLD_H
#define WORLD_H
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Door.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"
class World{
public:
	World();
	World(string name);
	//void build(string name);
	void initializeWorld(string name);
	vector<Room> getRoomsVector();
	string getName();
	void setRoomIndex(int roomIndex);
	void addRoom(Room room);
	void getInformation();
	int willGoToRoom(int direction, int currentLocation);
	void goToRoom(int roomID);
	void getNowRoomInformation(int currentLocation);
private:
	vector<Room> roomsVector;
	string name;
};



#endif
