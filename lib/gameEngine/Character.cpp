
#ifndef CHARACTER_CPP
#define CHARACTER_CPP

#include "gameEngineHeaders/Character.h"

Character::Character(string name) {
    this->setName(name);
    this->setLevel(1);
    this->setHealth(CHAR_DEFAULTHEALTH);
    this->setAtk(CHAR_DEFAULTATK);
    this->setStr(CHAR_DEFAULTSTAT);
    this->setInt(CHAR_DEFAULTSTAT);
    this->setDex(CHAR_DEFAULTSTAT);
    this->setCha(CHAR_DEFAULTSTAT);
    //this->charEquipment = { nullptr }; // set equipment to nothing
    this->setPVP(false);
    this->currentLocation = CHAR_STARTLOCATION;
}

void Character::printStatus() { // print Character's stats
    cout << "\nName: " + this->getName();
    cout << "\nHealth: " + to_string(this->getHealth());
    cout << "\nLevel: " + to_string(this->getLevel());
    cout << "\nEquipment: ";
    for (int wornItem=0; wornItem < this->charEquipment.size(); wornItem++) {
        cout << "\n\t" + this->charEquipment[wornItem].getName();
    }
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

void Character::setLocation(int location) {
    this->currentLocation = location;
}

int Character::getLocation() {
    return this->currentLocation;
}

void Character::setPVP(bool b) {
    this->wantsToPVP = b;
}

bool Character::getPVP() {
    return this->wantsToPVP;
}

void Character::togglePVP() {
    if (this->wantsToPVP) {
        this->wantsToPVP = false;
    } else {
        this->wantsToPVP = true;
    }
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

/*Object** Character::getEquipment() {
    return this->charEquipment;
}*/

void Character::equip(Object &item) {
    if (item.isWearable()) {
        int areaIsEquipped = this->charEquipment.count(item.getEquipArea()); // search if item's equipArea is occupied
        if (areaIsEquipped == 0) { // nothing equipped in this area
            this->charEquipment[areaIsEquipped] = item;
        } else { // something equipped in this area
            cout << this->charEquipment[areaIsEquipped].getName() + " is already equipped! Please unequip first.";
        }
    } else { // not wearable
        cout << "This item is not wearable!";
    }
}

void Character::unequip(Object item) {
    this->getEquipment()[item.getEquipArea()] = nullptr;
}

void Character::interact(NPC npc) { // interact with NPC 
    
}

void Character::interact(Object obj) { // interact with Object
    this->addToInventory(obj);
    cout << "\n" + obj.getName() + " added to inventory";
    // need to remove Object from World??
}

void Character::examine(Object obj) { // examine Object
    cout << "\n" + obj.getLongDesc();
}

void Character::examine(NPC npc) { // examine NPC
    cout << "\n" + npc.getDesc();
}

void Character::attack(NPC npc) { // fight NPC
    int round = 0;
    while (this->getHealth() > 0 || npc.getHealth() > 0) {
        cout << "Round " + to_string(round) << endl;
        npc.setHealth( npc.getHealth() - this->getAtk() ); // NPC takes damage equal to character's atk
        if (npc.getHealth() <= 0) { // NPC is dead
            cout << "\nYou have defeated " + npc.getName();
        } else { // keep fighting
            cout << "\n" + npc.getName() + " takes " + to_string(this->getAtk()) + " damage and has " + to_string(npc.getHealth()) + " health remaining!";
            this->setHealth( this->getHealth() - npc.getAtk() ); // character takes damage equal to NPC's atk
            cout << "\nYou take " + to_string(npc.getAtk()) + " damage and have " + to_string(this->getHealth()) + " health remaining!";
            if (this->getHealth() <= 0) { // player is dead
                cout << "\nYou have died.";
            }        
        }
        round++;
    }
}
// !!! UNFINISHED !!! FUCK PVP FUNCTION
void Character::attack(Character &c) { // fight NPC
    int round = 0;
    while (this->getHealth() > 0 || c.getHealth() > 0) { // both chararacters alive
        cout << "Round " + to_string(round) << endl;
        c.setHealth( c.getHealth() - this->getAtk() ); // c takes damage equal to character's atk
        if (c.getHealth() <= 0) { // c is dead
            cout << "\nYou have defeated " + c.getName();
        } else { // keep fighting
            cout << "\n" + c.getName() + " takes " + to_string(this->getAtk()) + " damage and has " + to_string(c.getHealth()) + " health remaining!";
            this->setHealth( this->getHealth() - c.getAtk() ); // character takes damage equal to c's atk
            cout << "\nYou take " + to_string(c.getAtk()) + " damage and have " + to_string(this->getHealth()) + " health remaining!";
            if (this->getHealth() <= 0) { // player is dead
                cout << "\nYou have died.";
            }        
        }
        round++;
    }
}

/*void Character::move(World w, int roomId) {
    for (int i=0; i < w.getRoomsVector().size(); i++){ // find location of "roomId" by iterating through roomVector
        if (w.getRoomsVector()[i].getID()==roomId) {
            this->currentLocation = i;
        }
    }
    w.getNowRoomInformation(this->currentLocation);
}*/
#endif