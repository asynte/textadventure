using namespace std;



#ifndef WORLD_H
#define WORLD_H


#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Widget.h"




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
		void printRoomNames();
		int willGoToRoom(int direction, int currentLocation);
		//void goToRoom(int roomID);
		void getNowRoomInformation(int currentLocation);
		// void parseUserInput(const string &command, const string& arguement);
		void goToRoom(int id, Character &c);

		void addCharacter(const Character &character);
		// vector<Character> get

		// vector<string> 




	private:
		Room getCurrentRoom(const Character &character);
		vector<Room> roomsVector;
		vector<Character> characters;
		string name;
};

#include "userInterfaceHeaders/UserInterface.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"

#endif
