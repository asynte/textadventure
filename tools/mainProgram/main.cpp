#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/Monster.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/World.h"
#include "gameEngineHeaders/GameEngine.h"
#include "userAccountHeaders/Login.h"
#include "networkingHeaders/TCPClient.h"
#include "networkingHeaders/TCPDataflow.h"
#include "networkingHeaders/TCPServer.h"
#include "userInterfaceHeaders/Observer.h"
#include "userInterfaceHeaders/ObserverList.h"
#include "userInterfaceHeaders/Commands.h"
#include "userInterfaceHeaders/UserInterface.h"
#include "pthread.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


int main() {

	//Constructs object
	// cout<< " Nigger initiate" << endl;
	// roomDataInterface Hell{""};

	UserInterface_create();
	//roomDataInterfaceTest1();

	cout<< "NIGGGGGGG" << endl;
	roomDataInterface ROOM2("data/test.yml");

	cout << "more niggers" << endl;
	GameEngine *g = new GameEngine();
	UserInterface_addListener(g);

	pthread_join(UserInterface_getThreadId(), NULL);

	return 0;
}	
