
using namespace std;

#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H


#include <iostream>
#include <vector>
#include "gameEngineHeaders/World.h"
#include "gameEngineHeaders/Character.h"
#include "userInterfaceHeaders/UserInterface.h"

class GameEngine : public Observer {
	public:
		GameEngine();

		void notify(const string &userInput) ;
		void notify(const vector<string> &userInput);

		vector<string> GameEngine_getPossibleDirections();
		vector<string> GameEngine_getPossibleKeywords();


	private:
		Character currentPlayer;
		World currentWorld;

		void processUserCommand(const string &command, const string &arguement);

};



#endif
