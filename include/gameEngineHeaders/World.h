#ifndef WORLD_H
#define WORLD_H

#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Widget.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "userInterfaceHeaders/UserInterface.h"

using namespace std;


class World{

private:
	string name;
	vector <Room> roomsVector;
	vector <Character> charactersVector;
	
	// Creator functions
	void initializeWorld(string name);

public:
	World();
	World(string name);
	
	// Getters
	string getName();

	vector <Room> getRoomsVector();
	Room getRoom(string roomName);

	vector <Character> getCharactersVector();
	Character getCharacter(string characterName);

	// Setters

	// Creator & helper functions
	bool findRoom(string roomName);
	void addRoom(const Room &room);

	bool findCharacter(string characterName);
	void addCharacter(const Character &character);

	void goToRoom(int id, Character &c);

	// Print functions
	void printRoomNames();


	//int willGoToRoom(int direction, int currentLocation);
	//void goToRoom(int roomID);
	//void getNowRoomInformation(int currentLocation);
	// void parseUserInput(const string &command, const string& arguement);

};



#endif
