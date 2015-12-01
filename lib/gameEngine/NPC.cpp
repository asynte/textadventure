#ifndef NPC_CPP
#define NPC_CPP

#include "gameEngineHeaders/NPC.h"

NPC::NPC() {
    this->setHealth(NPC_DEFAULTHEALTH);
    this->setAtk(NPC_DEFAULTATK);
}

NPC::NPC(string name) {
    this->setHealth(NPC_DEFAULTHEALTH);
    this->setAtk(NPC_DEFAULTATK);
    this->widgetName = name;
}

NPC::NPC(int id, string desc, vector<string> keywords, string longDesc, string shortDesc) {
	widgetId = id;
	npcDesc = desc;
	npcKeyWords = keywords;
	npcLongDesc = longDesc;
	widgetName = shortDesc;
    this->setHealth(NPC_DEFAULTHEALTH);
    this->setAtk(NPC_DEFAULTATK);
    roomID=-1;

}
void NPC::setRoomID(int roomID){
    this->roomID=roomID;
}
int NPC::getRoomID()const{
    return roomID;
}
string NPC::getLongDesc() const {
	return npcLongDesc;
}

void NPC::setLongDesc(string longdesc) {
    this->npcLongDesc = longdesc;
}

vector<string> NPC::getKeyWords() const {
	return npcKeyWords;
}

string NPC::getDesc() const {
	return npcDesc;
}

void NPC::setHealth(int hp) {
    this->npcHealth = hp;
}

int NPC::getHealth() const {
    return this->npcHealth;
}

void NPC::setAtk(int atk) {
    this->npcAtk = atk;
}

int NPC::getAtk() const {
    return this->npcAtk;
}

void NPC::addInventory(Object o){
    inventory.push_back(o);
}

vector<Object> NPC::getInventory(){
    return inventory;
}

void NPC::updateStats() {
    map<int, const Object>::iterator it;
    // set default values
    this->npcStrength = NPC_DEFAULTSTAT;
    this->npcDexterity = NPC_DEFAULTSTAT;
    for (it = this->npcEquipment.begin(); it != this->npcEquipment.end(); it++) {
        if (it->first == 16 || it->first == 17) { //weapon
            this->npcStrength += (it->second.getName()).length();
        }
        else if (it->first == 11) { //shield
            this->npcDexterity += (it->second.getName()).length();
        }
    }
    this->npcAtk = NPC_DEFAULTSTAT + this->npcStrength;
    this->npcHealth = NPC_DEFAULTSTAT + this->npcDexterity;
}

void NPC::equip(Object &item) {
    if (item.isWearable()) {
        this->npcEquipment.insert( {item.getEquipArea(), item} );
        this->updateStats();
    } 
    else {
        cout << "Item not wearable!" << endl;
    }
}

void NPC::showEquipment() {
    cout << "Equipment: " << endl;
    for (auto wornItem : this->npcEquipment) {
        cout << "\t" << wornItem.second.getId() << ": " << wornItem.second.getName() << endl;
    }
}

#endif