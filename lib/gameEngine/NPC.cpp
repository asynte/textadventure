#ifndef NPC_CPP
#define NPC_CPP

#include "gameEngineHeaders/NPC.h"

NPC::NPC() {
    this->setHealth(NPC_DEFAULTHEALTH);
    this->setAtk(NPC_DEFAULTATK);
}

NPC::NPC(int id, string desc, vector<string> keywords, string longDesc, string shortDesc) {
	widgetId = id;
	npcDesc = desc;
	npcKeyWords = keywords;
	npcLongDesc = longDesc;
	widgetName = shortDesc;
    this->setHealth(NPC_DEFAULTHEALTH);
    this->setAtk(NPC_DEFAULTATK);
    roomID=0;

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

#endif