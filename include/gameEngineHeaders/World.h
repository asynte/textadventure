using namespace std;
#ifndef WORLD_H
#define WORLD_H


#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Widget.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "userInterfaceHeaders/UserInterface.h"
#include "gameEngineHeaders/Reset.h"

class World{

public:
	World();
	World(string name);
	//void build(string name);
	void initializeWorld(string name);
	string getName();
	vector<Character> getCharacters();
	vector<Room> getRoomsVector();
	vector<NPC> getNPCsVector();
	vector<Object> getObjectsVector();
	Room getRoomFindById(int id);
	bool findRoomById(int );
	void addRoom(Room room);
	void printRoomNames();
	int getRoom(int roomID);
	void moveCharacter(Character &player, string userCommand);
	void setCharRoom(Character &c, int roomID, int moveDirection);
	void addCharacter(const Character &character);
		Room getCurrentRoom(Character &player);

	vector<string> getAllDirections(Character &player); // Used for UserInterface
	vector<string> getAllKeywords(Character &player); // Used for UserInterface
private:
	vector<Room> roomsVector;
	vector <Object> objectVector;
	vector <NPC> npcVector;
	vector<Character> characters;
	vector <Reset> resetsVector;
	string name;
	int roomNowIndex;
	string getCharacterMoveDirection(Character &player, string userCommand);
	void addObjectToRoom();
	void addNPCToRoom();
	int findRoomIndex(int roomID);
	int findNPCIndex(int npcID);
	int findObjectIndex(int objectID);
};
#endif