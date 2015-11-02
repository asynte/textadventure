#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Door.h"
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

void dataEmitterTest1() {
	dataEmitter emit{"example"};
	emit.emitNPC();
	emit.printToFile();

}

void testSwitch() {
	while (loop)
	{
		cout << "Command: ";
		cin >> i;
		switch(i) {
			case 1:
				cout << "\n";
				npcDataInterfaceTest1();
				break;
			case 2:
				cout << "\n";
				objDataInterfaceTest1();
				break;
			case 3:
				cout << "\n";
				roomDataInterfaceTest1();
				break;
			case 4:
				cout << "\n";
				resetDataInterfaceTest1();
				break;
			case 5:
				cout << "\n";
				npcDataInterfaceTest2();
				break;
			case 6:
				dataEmitterTest1();
				break;
			default:
				cout << "\nWrong numba, Psych!\n";
				break;
			case -1:
				loop = false;
				break;
		}
	}
}

int main() {

	//Constructs object
	// cout<< " Nigger initiate" << endl;
	// roomDataInterface Hell{""};

	UserInterface_create();
	//roomDataInterfaceTest1();
	cout<< "NIGGGGGGG" << endl;
	roomDataInterface ROOM2("data/test.yml");

	cout << "more niggers" << endl;
	GameEngine *g = new GameEngine(); // !!!BRYAN FIX PLEASE!!!! DYNAMIC CAST ERROR!!!! std::bad_cast
	UserInterface_addListener(g);

	pthread_join(UserInterface_getThreadId(), NULL);
	// testSwitch();
	//dataEmitterTest1();

	return 0;
}	
