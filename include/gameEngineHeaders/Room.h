using namespace std;



#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <iostream>
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Extended.h"

class Room{
public:

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

	void addObject(const Object& o);
	void addNPC(const NPC& npc);
	void addCharacter(const Character& player);
	void removeCharacter(const Character& player);
	vector <Object> getObjectList();
	vector <NPC> getNPCList();
	vector <Character> getCharacterList();
	vector<string> getObjectAllKeyWords();
	vector<string> getNPCAllKeyWords();
	vector<string> getDoorAllKeywords();
	//vector<string> getCharacterAllKeyWords();
	vector<string> getAllKeyWords();
	vector <Object> getObjectAssociatedKeyword(string keyword);
	vector <NPC> getNPCAssociatedKeyword(string keyword);
	//vector <int>lookAtExit();
	vector<string> getAllDirections(); // Used for UserInterface

	//void test(Character c);
private:
	string description;
	vector<Door> doorsList;
	vector<Extended> extendedList;
	vector<Object>objectList;
	vector<NPC>npcList;
	vector<Character> characterList;

	int ID;
	string name;

    vector<Widget> widgetVector;

};

#endif
