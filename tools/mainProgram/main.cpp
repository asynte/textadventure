#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/Monster.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/World.h"
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

void npcDataInterfaceTest1() {
	npcDataInterface npc{"midgaard.yml"};
	npc.loadAll();
	npc.printAll();
}

void objDataInterfaceTest1() {
	objDataInterface object{"midgaard.yml"};
	object.loadAll();
	object.printAll();
}

void roomDataInterfaceTest1() {
	roomDataInterface room{"midgaard.yml"};
	room.loadAll();
	room.printAll();
}

void resetDataInterfaceTest1() {
	resetDataInterface reset{"midgaard.yml"};
	reset.loadAll();
	reset.printAll();
}

void roomDataInterfaceTest2() {

	roomDataInterface ROOM2{"midgaard.yml"};

	ROOM2.loadFromID(3120);


	// assign valuables from ROOM struct
	vector<string> a = ROOM2.getDescription(0);

	int b = ROOM2.getID(0);

	string c = ROOM2.getName(0);

	vector<string> d = ROOM2.getDoorDescription(0, 0);

	string e = ROOM2.getDoorDirection(0, 0);

	vector<string> j = ROOM2.getDoorKeyWord(0, 0);

	int f = ROOM2.getDoorTO(0, 0);

	vector<string> g = ROOM2.getExtendedDescription(0, 0);

	vector<string> h = ROOM2.getExtendedKeyWord(0, 0);


	// output variable values to terminal
	for (string s: a){
		cout << s << "\n";
	}

	for (string s: d){
		cout << s << "\n";
	}

	cout << e << "\n";

	for (string s: j){
		cout << s << "\n";
	}	

	for (string s: g){
		cout << s << "\n";
	}	

	for (string s: h){
		cout << s << "\n";
	}	

	cout << f << "\n";

	cout << b << "\n" << c << "\n\n";

}


int main() {

	npcDataInterfaceTest1();
	objDataInterfaceTest1();
	roomDataInterfaceTest1();
	resetDataInterfaceTest1();

	return 0;
}	
