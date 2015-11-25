
// using namespace std;

// #ifndef GAME_ENGINE_CPP
// #define GAME_ENGINE_CPP


// #include "gameEngineHeaders/GameEngine.h"





// void GameEngine::notify(const string &userInput) {
// 	processUserCommand(userInput, "");
// }

// void GameEngine::notify(const vector<string> &userInput) {
// 	string command = userInput.at(0);
// 	string arguement = userInput.at(1);

// 	processUserCommand(command, arguement);
// }

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// // THIS IS ONLY THING I NEED TO EDIT
// void GameEngine::processUserCommand(const string &command, const string &arguement) {

// 	// string usrcmd;
// 	// int temp = arguement.copy(usrcmd, arguement.length());
// 	UserInterface_println("command: " + command + " arguement:" + arguement);

// 	if (command == "move" && arguement.length() > 0) {
// 	//if (command == "move") {
// 		UserInterface_println("entered the move command!");

// 		// Room currentRoom = currentPlayer.getLocation();
// 		//int directionId = 
// 		//int directionId = Door_getDirectionAsInt(arguement);

// 		// int directionId = 0;
// 		// int newRoomId = 3002;

// 		//currentWorld.printRoomNames();

// 		// UserInterface_println("currentRoom pre: " + I2S(currentRoom.getID()));

// 		//string test = I2S()

// 		// currentWorld.goToRoom(newRoomId, currentPlayer);

// 		//parseMoveCommand(arguement);
// 		//UserInterface_println("currentRoom post: " + I2S(currentPlayer.getCurrentRoom().getID()));
// 	}

// }
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// vector<string> GameEngine::GameEngine_getPossibleDirections() {
// 	return currentWorld.getAllDirections(currentPlayer);
// }
// vector<string> GameEngine::GameEngine_getPossibleKeywords() {
// 	return currentWorld.getAllDirections(currentPlayer);
// }


// // 	Room currentRoom = currentPlayer.getCurrentRoom();
	


// // 	// vector<string> dir = currentRoom.getPossibleDirections();

// // 	// for(int i = 0; dir.size() > i; ++i) {
// // 	// 		UserInterface_println(dir.at(i) );
// // 	// }


// // 	// 	UserInterface_println("room direction count: " + I2S(dir.size()));

// // 	// vector<string> dir;

// // 	// dir.push_back("derp");

// // 	// return dir;

// // 	return currentRoom.getPossibleDirections();
// // }

// GameEngine::GameEngine()  : 
// 	currentPlayer(Character("Retard")), 
// 	currentWorld(World("test")) 
// 	{
// 		currentWorld.printRoomNames();
// 	}


// #endif
