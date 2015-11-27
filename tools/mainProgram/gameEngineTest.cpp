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
int init(){
	roomDataInterface roomParser("data/smurf.yml");
	objDataInterface objParser("data/smurf.yml");
	npcDataInterface npcParser("data/smurf.yml");
}


int main() {


	objDataInterface objParser{"data/smurf.yml"};
	objParser.loadAll();
	//objParser.printAll();
	Character player("Dude",101);
	for (auto obj : objParser.getObjVector()) {
		cout << obj.getName() << endl;
		cout << obj.isWearable() << endl;
		if (obj.isWearable()) {
			cout << obj.getEquipArea() << endl;
		}
	}
	// Object axe();
	// axe.setEquipArea(Widget::WEAPON);
	// player.interact(axe);
	// player.equip(axe);
	// player.printStatus();
	// player.examine(axe);

	return 0;
}

