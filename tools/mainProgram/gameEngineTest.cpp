#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/World.h"
#include "gameEngineHeaders/GameEngine.h"
#include "gameEngineHeaders/SpellShop.h"
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
	// roomDataInterface roomParser("data/smurf.yml");
	// objDataInterface objParser("data/smurf.yml");
	// npcDataInterface npcParser("data/smurf.yml");
	spellDataInterface spellParser("data/spellstest.yml");
}


int main() {

	Character player("Donald Trump", 3002);
	player.setLevel(99);
	SpellShop shop("Welcome to the Spell Shop", 10000);
	//cout << shop.getDescription() << endl;
	//cout << shop.getShopLocationID() << endl << endl;
	// shop.loadSpells();
	// shop.displaySpells();
	shop.shopMenu(player);

	return 0;
}

