
#include "gameEngineHeaders/Character.h"

#ifndef CHARACTER_CPP
#define CHARACTER_CPP

Character::Character(string name) {
    this->setName(name);
    this->setLevel(1);
    this->setHealth(CHAR_DEFAULTHEALTH);
    this->setAtk(CHAR_DEFAULTATK);
    this->setStr(CHAR_DEFAULTSTAT);
    this->setInt(CHAR_DEFAULTSTAT);
    this->setDex(CHAR_DEFAULTSTAT);
    this->setCha(CHAR_DEFAULTSTAT);
    this->currentLocation = CHAR_STARTLOCATION;
}

void Character::getStatus() { // print Character's stats
    cout << "\nName: " + this->getName();
    cout << "\nHealth: " + to_string(this->getHealth());
    cout << "\nLevel: " + to_string(this->getLevel());
    cout << "\nAttack: " + to_string(this->getAtk()) + "\n";
}

void Character::setHealth(int hp) {
    this->charHealth = hp;
}

int Character::getHealth() {
    return this->charHealth;
}

void Character::setExp(int exp) {
    this->experience = exp;
}

void Character::increaseExp(int expGained) {
    this->experience += expGained;
}

void Character::setLevel(int lvl) {
    this->charLevel = lvl;
}

int Character::getLevel() {
    return this->charLevel;
}

void Character::updateLevel() {
    int newLevel = 0;
    int expCounter = this->experience;
    while (expCounter > newLevel*100) { // each level requires level*100 exp (i.e. lvl 9 requires 900 exp)
        newLevel++; 
        expCounter -= newLevel*100;
    }
    this->setLevel(newLevel);
}

void Character::setAtk(int atk) {
    this->charAtk = atk;
}

int Character::getAtk() {
    return this->charAtk;
}

void Character::setStr(int str) {
    this->charStrength = str;
}

int Character::getStr() {
    return this->charStrength;
}
void Character::setInt(int intel) {
    this->charIntelligence = intel;
}

int Character::getInt() {
    return this->charIntelligence;
}

void Character::setDex(int dex) {
    this->charDexterity = dex;
}

int Character::getDex() {
    return this->charDexterity;
}

void Character::setCha(int chari) {
    this->charCharisma = chari;
}

int Character::getCha() {
    return this->charCharisma;
}

vector<Object> Character::getInventory() {
    return this->charInventory;
}

int Character::getLocation() {
    return this->currentLocation;
}

void Character::addToInventory(Object obj) {
    this->charInventory.push_back(obj);
}

// !! FIX LATER !!
/*void Character::removeFromInventory(Widget &w) {
    Widget widgetFound = find(this->charInventory.begin(), this->charInventory.end(), w); 
    if (widgetFound == w) { //found
        int widgetIndex = distance(this->charInventory.begin(), widgetFound); //index of found widget
        this->charInventory.erase(widgetIndex);
    } else { //not found
        cout << w.getName() + " is not in the inventory!";
    }
}*/

vector<Object> Character::getEquipment() {
    return this->charEquipment;
}

void Character::equip(Object item) {
    
}

void Character::interact(NPC npc) { // interact with NPC 
    cout << "\n" + npc.getDesc();
}

void Character::interact(Object obj) { // interact with Object
    this->addToInventory(obj);
    cout << "\n" + obj.getName() + " added to inventory";
    // need to remove Object from World??
}

void Character::examine(Object obj) { // examine Object
    cout << "\n" + obj.getLongDesc();
}

void Character::examine(Monster mon) { // examine Monster
    cout << "\n" + mon.getDesc();
}

void Character::interact(Monster mon) { // fight Monster
    mon.setHealth( mon.getHealth() - this->getAtk() ); // monster takes damage equal to character's atk
    if (mon.getHealth() > 0) { // monster is still alive
        cout << "\n" + mon.getName() + " takes " + to_string(this->getAtk()) + " damage and has " + to_string(mon.getHealth()) + " health remaining!";
        this->setHealth( this->getHealth() - mon.getAtk() ); // character takes damage equal to monster's atk
        cout << "\nYou take " + to_string(mon.getAtk()) + " damage and have " + to_string(this->getHealth()) + " health remaining!";
        if (this->getHealth() <= 0) { // player is dead
            cout << "\nYou have died.";
        }
    } else { // monster is dead
        cout << "\nYou have defeated " + mon.getName();
        // delete monster from World??
    }
}

void Character::move(World w, int roomId) {
    for (int i=0; i < w.getRoomsVector().size(); i++){ // find location of "roomId" by iterating through roomVector
        if (w.getRoomsVector()[i].getID()==roomId) {
            this->currentLocation = i;
        }
    }
    w.getNowRoomInformation(this->currentLocation);
}
#endif