
#ifndef CHARACTER_CPP
#define CHARACTER_CPP


#include "gameEngineHeaders/Character.h"

// Character::Character() {
// }


Character::Character() {
    this->setName("");
    this->setLevel(1);
    this->setHealth(CHAR_DEFAULTHEALTH);
    this->setMana(CHAR_DEFAULTMANA);
    this->setGold(CHAR_DEFAULTGOLD);
    this->setExp(0);
    this->setAtk(CHAR_DEFAULTATK);
    this->setStr(CHAR_DEFAULTSTAT);
    this->setInt(CHAR_DEFAULTSTAT);
    this->setDex(CHAR_DEFAULTSTAT);
    this->setCha(CHAR_DEFAULTSTAT);
    this->setPVP(false);
    this->setLocation(CHAR_STARTLOCATION);
}

Character::Character(string name) {
    this->setName(name);
    this->setLevel(1);
    this->setHealth(CHAR_DEFAULTHEALTH);
    this->setMana(CHAR_DEFAULTMANA);
    this->setGold(CHAR_DEFAULTGOLD);
    this->setExp(0);
    this->setAtk(CHAR_DEFAULTATK);
    this->setStr(CHAR_DEFAULTSTAT);
    this->setInt(CHAR_DEFAULTSTAT);
    this->setDex(CHAR_DEFAULTSTAT);
    this->setCha(CHAR_DEFAULTSTAT);
    this->setPVP(false);
    this->setLocation(CHAR_STARTLOCATION);
}

bool Character::equals(const Character &other) {
    return this->widgetName == other.widgetName
        && this->widgetId == other.widgetId
    ; 
}

void Character::printStatus() { // print Character's stats
    cout << "\nName: " + this->getName();
    cout << "\nHealth: " + to_string(this->getHealth());
    cout << "\nMana: " + to_string(this->getMana());
    cout << "\nLevel: " + to_string(this->getLevel());
    cout << "\nPVP: " + to_string(this->getPVP());
    cout << "\nEquipment: \n";
    for (auto wornItem : this->charEquipment) {
        cout << "\t" + wornItem.second.getName() << endl;
    }
}

void Character::setHealth(int hp) {
    this->charHealth = hp;
}

int Character::getHealth() const {
    return this->charHealth;
}

void Character::setMana(int mp) {
    this->charMana = mp;
}

int Character::getMana() const {
    return this->charMana;
}

void Character::setGold(int gold) {
    this->charGold = gold;
}

int Character::getGold() const {
    return this->charGold;
}

void Character::setExp(int exp) {
    this->experience = exp;
}

void Character::increaseExp(int expGained) { // coupled with updateLevel
    this->experience += expGained;
}

void Character::setLevel(int lvl) {
    this->charLevel = lvl;
}

int Character::getLevel() const {
    return this->charLevel;
}

void Character::updateLevel() {
    int newLevel = 1;
    int expCounter = this->experience;
    while (expCounter >= newLevel*100) { // each level requires (level-1)*100 exp (i.e. lvl 9 requires 800 exp)
        expCounter -= newLevel*100;
        newLevel++; 
    }
    this->setLevel(newLevel);
}

void Character::setAtk(int atk) {
    this->charAtk = atk;
}

int Character::getAtk() const {
    return this->charAtk;
}

void Character::setStr(int str) {
    this->charStrength = str;
}

int Character::getStr() const {
    return this->charStrength;
}
void Character::setInt(int intel) {
    this->charIntelligence = intel;
}

int Character::getInt() const {
    return this->charIntelligence;
}

void Character::setDex(int dex) {
    this->charDexterity = dex;
}

int Character::getDex() const {
    return this->charDexterity;
}

void Character::setCha(int chari) {
    this->charCharisma = chari;
}

int Character::getCha() const {
    return this->charCharisma;
}

vector<Object> Character::getInventory() const {
    return this->charInventory;
}
void Character::setLocation(int roomID){
    this->currentLocation = roomID;
}

int Character::getLocation() const {
    return this->currentLocation;
}

// void Character::addHealSpell(HealSpell sp) {
//     this->charHealSpells.push_back(sp);
//     cout << sp.getName() + " acquired!" << endl;
// }

// vector<HealSpell> Character::getHealSpells() const {
//     return this->charHealSpells;
// }

void Character::setPVP(bool b) {
    this->wantsToPVP = b;
}

bool Character::getPVP() const {
    return this->wantsToPVP;
}

void Character::togglePVP() {
    if (this->wantsToPVP) {
        this->wantsToPVP = false;
    } else {
        this->wantsToPVP = true;
    }

}

void Character::updateStats() {
    map<int, const Object>::iterator it;
    // set default values
    this->charStrength = CHAR_DEFAULTSTAT;
    this->charDexterity = CHAR_DEFAULTSTAT;
    this->charCharisma = CHAR_DEFAULTSTAT;
    this->charIntelligence = CHAR_DEFAULTSTAT;
    for (it = this->charEquipment.begin(); it != this->charEquipment.end(); it++) {
        if (it->first == 5) { //weapon
            this->charStrength += (it->second.getName()).length();
        }
        else if (it->first == 6) { //shield
            this->charDexterity += (it->second.getName()).length();
        }
    }
    this->charAtk = CHAR_DEFAULTATK + this->charStrength;
    this->charHealth = CHAR_DEFAULTHEALTH + this->charDexterity;
    this->charMana = CHAR_DEFAULTMANA + this->charIntelligence;
}

void Character::addToInventory(Object obj) {
    this->charInventory.push_back(obj);
}

void Character::showInventory() const {
    cout << "Inventory: " << endl;
    for (auto item : this->getInventory()) {
        cout << "\t" + item.getName() << endl;
    }
}

// !! FIX LATER !!
void Character::removeFromInventory(Object &obj) {
    vector<Object>::iterator it;
    for (it = this->charInventory.begin(); it != this->charInventory.end();) { // find and remove object
        int currentId = (*it).getId();
        if (currentId == obj.getId()) {
            this->charInventory.erase(it);
            cout << obj.getName() + " has been removed from inventory." << endl;
            return;
        }
        else
        {
            it++;
        }
    }
    cout << obj.getName() + " is not in the inventory!" << endl; // not found
}

void Character::equip(Object &item) {
    if (item.isWearable()) {
        int areaIsEquipped = this->charEquipment.count(item.getEquipArea()); // search if item's equipArea is occupied
        if (areaIsEquipped == 0) { // nothing equipped in this area
            this->charEquipment.insert( {item.getEquipArea(), item} );
            cout << item.getName() + " has been equipped." << endl;
            this->removeFromInventory(item); 
            this->updateStats();
        } else { // something equipped in this area
            cout << this->charEquipment[areaIsEquipped].getName() + " is already equipped! Please unequip first." << endl;
        }
    } else { // not wearable
        cout << "This item is not wearable!" << endl;
    }
}

void Character::unequip(Object item) {
    int itemEquipped = this->charEquipment.count(item.getEquipArea());
    if (itemEquipped == 1) {
        this->addToInventory(item);
        this->charEquipment.erase(item.getEquipArea());
        cout << item.getName() + " has been unequipped." << endl;
    } else {
        cout << item.getName() + " is already unequipped. " << endl;
    }
}

void Character::interact(NPC npc) { // interact with NPC 
    cout << npc.getDesc() << endl;
}

void Character::interact(Object obj) { // interact with Object
    this->addToInventory(obj);
    cout << obj.getName() + " has been added to inventory." << endl;
    // need to remove Object from World??
}

void Character::examine(Object obj) { // examine Object
    cout << obj.getLongDesc() << endl;
}

void Character::examine(NPC npc) { // examine NPC
    cout << npc.getLongDesc() << endl;
}

void Character::examine(Character &c) { // examine other character
    c.printStatus();
}

void Character::attack(NPC npc) { // fight NPC
    int round = 1;
    while (this->getHealth() > 0 && npc.getHealth() > 0) {
        string userCmd;
        cout << "Round " + to_string(round) << endl;
        cout << "What would you like to do? \n\tFight\tFlee" << endl;
        cin >> userCmd;
        //if ( regex_search(userCmd, regex("Fight*", regex_constants::basic)) ) { //fight
        if (userCmd == "Fight") {
            this->battleSequence(npc);
            round++;
        //} else if ( regex_search(userCmd, regex("Flee*", regex_constants::basic)) ) { //flee
        } else if (userCmd == "Flee") {
            int fleeChance = (rand()*10)%4;
            if (fleeChance > 0) { // flee success, 75%
                cout << "You have fled the battle. Coward!" << endl;
                break;
            } else { // flee failed, 25%
                cout << "Fleeing failed!" << endl;
                this->battleSequence(npc);
            }
        } else {
            cout << "Incorrect command entered!" << endl;
        }
    }
    // battle results
    if (npc.getHealth() <= 0) { // NPC is dead
        cout << "\nYou have defeated " + npc.getName() << endl; 
    } else if (this->getHealth() <= 0) { // player is dead
        cout << "\nYou have died." << endl;
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

void Character::battleSequence(NPC &npc) {
    npc.setHealth( npc.getHealth() - this->getAtk() ); // NPC takes damage equal to character's atk
    if (npc.getHealth() <= 0) { 
        cout << npc.getName() + " takes " + to_string(this->getAtk()) + " damage and has no health remaining!" << endl;
    } else { // keep fighting
        cout << npc.getName() + " takes " + to_string(this->getAtk()) + " damage and has " + to_string(npc.getHealth()) + " health remaining!" << endl;
        this->setHealth( this->getHealth() - npc.getAtk() ); // character takes damage equal to NPC's atk
        cout << "You take " + to_string(npc.getAtk()) + " damage and have " + to_string(this->getHealth()) + " health remaining!" << endl;
    }
}

#endif