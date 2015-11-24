#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/World.h"
#include "gameEngineHeaders/GameEngine.h"
#include "gameEngineHeaders/HealSpell.h"
#include "userAccountHeaders/Login.h"
#include "networkingHeaders/TCPClient.h"
#include "networkingHeaders/TCPDataflow.h"
#include "networkingHeaders/TCPServer.h"
#include "userInterfaceHeaders/Observer.h"
#include "userInterfaceHeaders/ObserverList.h"
#include "userInterfaceHeaders/Commands.h"
#include "userInterfaceHeaders/UserInterface.h"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

void testFight() {
	Character player("Kid with no arms");
    cout << "Current room ID: " + to_string(player.getLocation()) << endl;
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
	Character player("Kid with no arms");
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
    cout << "Char attack: " + to_string(player.getAtk()) << endl;
    player.examine(sword);
    player.showInventory();
    player.printStatus();
    player.unequip(sword);
    player.printStatus();
    player.removeFromInventory(rock);
    player.removeFromInventory(sword);
    player.showInventory();
}

void testSpells() {
    Character player("Kilgrave");
    player.printStatus();
    HealSpell weakHeal("Weak Heal Spell", 1, 20, 50);
    player.addHealSpell(weakHeal);
    (player.getHealSpells()[0]).castSpell(player);
    player.printStatus();
}

int main() {

    /////////////////////////////////////////////////////////////////////////////////////////////////////

	// UserInterface_create();
	// cout<< "NIGGGGGGG" << endl;
	// roomDataInterface ROOM2("data/test.yml");

	// cout << "more niggers" << endl;
	// GameEngine *g = new GameEngine(); // !!!BRYAN FIX PLEASE!!!! DYNAMIC CAST ERROR!!!! std::bad_cast
	// UserInterface_addListener(g);

	// pthread_join(UserInterface_getThreadId(), NULL);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // GameEngine *g = new GameEngine(); // !!!BRYAN FIX PLEASE!!!! DYNAMIC CAST ERROR!!!! std::bad_cast
    // UserInterface_addListener(g);

    // roomDataInterface ROOM2("data/midgaard.yml");

    // World sfu("midgaard");
   
    // Character player("Akame");
    // player.setLocation(3001);
    // string direction;
    // cout<<"Enter direction: " << endl;
    // cin >> direction;
    // sfu.moveCharacter(player, direction);

    // ROOM2.printAll();
    // objDataInterface objParser("data/midgaard.yml");
    // objParser.loadAll();
    // objParser.printAll();
    // npcDataInterface npcParser("data/midgaard.yml");
    // npcParser.loadAll();
    // npcParser.printAll();

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    // testFight();
    // testEquip();
    testSpells();

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    
	return 0;
}	
