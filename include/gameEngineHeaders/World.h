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

class World{

public:
	World();
	World(string name);
	//void build(string name);
	void initializeWorld(string name);
	string getName();
	vector<Character> getCharacters();
	vector<Room> getRoomsVector();
	Room getRoomFindById(int id);
	bool findRoomById(int );
	void addRoom(Room room);
	void printRoomNames();
	int getRoom(int roomID);
	void moveCharacter(Character &player, string userCommand);
	void setCharRoom(Character &c, int roomID, int moveDirection);
	void addCharacter(const Character &character);

	vector<string> getAllDirections(Character &player); // Used for UserInterface
	vector<string> getAllKeywords(); // Used for UserInterface
private:
	vector<Room> roomsVector;
	vector <Object> objectVector;
	vector <NPC> npcVector;
	vector<Character> characters;

	string name;
	int roomNowIndex;
	void addObjectToRoom(string fileName);
	void addNPCToRoom(string fileName);
	Room getCurrentRoom(Character &player);
	
};
#endif
