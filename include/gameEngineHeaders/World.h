using namespace std;

#ifndef WORLD_H
#define WORLD_H
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/NPC.h"

#include "dataInterfaceHeaders/dataInterfaceBase.h"
class World{
public:
	World();
	World(string name);
	//void build(string name);
	void initializeWorld(string name);
	string getName();
	vector<Room> getRoomsVector();
	Room getRoomFindById(int id);
	bool findRoomById(int );
private:
	vector<Room> roomsVector;
	vector <Object> objectVector;
	vector <NPC> npcVector;
	string name;
	int roomNowIndex;
	void addObjectToRoom(string fileName);
	void addNPCToRoom(string fileName);
	
};



#endif
