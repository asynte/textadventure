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
#include "userInterfaceHeaders/GameEngineFunctions.h"
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

void testFight() {
	Character player("Retard");
    player.increaseExp(300);
    player.updateLevel();
    player.printStatus();
    Character player2("Downy");
    NPC smurf;
    smurf.setName("Smurfy Timmeh");
    smurf.setLongDesc("An orphan smurf with no friends.");
    player.examine(player2);
    player.examine(smurf);
    player.attack(smurf);
}

void testEquip() {
	Character player("Retard");
    player.increaseExp(300);
    player.updateLevel();
    player.printStatus();
    player.togglePVP();
    Object rock(69, "shiny rock");
    Object sword(100, "Excalibur");
    sword.setLongDesc("A legendary sword.");
    sword.setWearable(true);
    sword.setEquipArea(Widget::WEAPON);
    player.interact(sword);
    player.interact(rock);
    player.equip(sword);
    player.examine(sword);
    player.showInventory();
    player.printStatus();
    player.unequip(sword);
    player.printStatus();
    player.removeFromInventory(rock);
    player.removeFromInventory(sword);
    player.showInventory();
}
/*void testSwitch() {
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
}*/

int main() {
	UserInterface_create();

	roomDataInterface ROOM2("data/test.yml");

	GameEngine *g = new GameEngine();
	g->addWorld(World("test"));

	g->addCharacter(Character("herp"));
	g->addCharacter(Character("derp"));


	UserInterface_addGameEngine(g);

	pthread_join(UserInterface_getThreadId(), NULL);

	return 0;
}	
