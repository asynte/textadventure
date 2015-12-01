#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/World.h"
#include "gameEngineHeaders/GameEngine.h"
#include "gameEngineHeaders/Spell.h"
#include "gameEngineHeaders/OffSpell.h"
#include "gameEngineHeaders/DefSpell.h"
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
void init(){
	// roomDataInterface roomParser("data/smurf.yml");
	// objDataInterface objParser("data/smurf.yml");
	// npcDataInterface npcParser("data/smurf.yml");
	spellDataInterface spellParser("data/spellstest.yml");
}

void testSpellShop() {
	Character player("Donald Trump", 3002);
	player.setLevel(99);
	SpellShop shop("Welcome to the Spell Shop", 10000);
	//cout << shop.getDescription() << endl;
	//cout << shop.getShopLocationID() << endl << endl;
	// shop.loadSpells();
	// shop.displaySpells();
	shop.shopMenu(player);
}

void testFight() {
	Character player("Kid with no arms", 3002);
    cout << "Current room ID: " + to_string(player.getLocation()) << endl;
    player.increaseExp(300);
    player.updateLevel();
    player.printStatus();
    Character player2("Downy", 3002);
    NPC smurf;
    smurf.setName("Smurfy Timmeh");
    smurf.setLongDesc("An orphan smurf with no friends.");
    player.examine(player2);
    player.examine(smurf);
    player.attack(smurf);
}

void testEquip() {
	Character player("Kid with no arms", 3002);
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
    player.updateStats();
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

void testNPCEquip() {
	NPC AI("Loser");
    Object sword(100, "Excalibur");
    sword.setWearable(true);
    sword.setEquipArea(Widget::WEAPON);
    AI.equip(sword);
    AI.showEquipment();
}

void testSpellCast() {
	npcDataInterface npcParser("data/smurf.yml");
	npcParser.loadAll();
	spellDataInterface spellParser("data/spellstest.yml");
	spellParser.loadAll();
	Character player("Killua", 101);
	player.setHealth(player.getHealth() - 30);
	player.printStatus();
	player.addDefSpell(spellParser.getDefVector().at(3));
	player.getDefSpells().at(0).castSpell(player);
	player.printStatus();
	player.addOffSpell(spellParser.getOffVector().at(0));
	NPC loser = npcParser.getNPCVector().at(0);
	cout << "Smurf health: " << loser.getHealth() << endl;
	player.getOffSpells().at(0).castSpell(player, loser);
	cout << "Smurf health: " << loser.getHealth() << endl;
}


int main() {
	//testSpellCast();
	// testNPCEquip();
 //    testSpellShop();
	return 0;
}

