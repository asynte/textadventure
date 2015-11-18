using namespace std;



#ifndef WORLD_H
#define WORLD_H


#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Widget.h"

#include "dataInterfaceHeaders/dataInterfaceBase.h"


class World{
	public:
		World();
		World(const World &from);
		World(string name);
		//void build(string name);
		void initializeWorld(string name);
		vector<Room> getRoomsVector();
		string getName();
		void setRoomIndex(int roomIndex);
		void addRoom(Room room);
		void printRoomNames();
		int willGoToRoom(int direction, int currentLocation);
		//void goToRoom(int roomID);
		void getNowRoomInformation(int currentLocation);
		int getRoom(int roomID);
		void moveCharacter(Character &player, string userCommand);
		void setCharRoom(Character &c, int roomID, int moveDirection);
		void addCharacter(const Character &character);
		vector<Character> getCharacters();

		// vector<string> 




	private:
		Room getCurrentRoom(const Character &character);
		vector<Room> roomsVector;
		vector<Character> characters;
		string name;
};

#include "userInterfaceHeaders/UserInterface.h"

#endif
