#ifndef NPC_CPP
#define NPC_CPP

#include "gameEngineHeaders/gameEngine.h"

NPC::NPC(int id, string desc, vector<string> keywords, string longDesc, string shortDesc) {
	widgetId = id;
	npcDesc = desc;
	npcKeyWords = keywords;
	npcLongDesc = longDesc;
	widgetName = shortDesc;
    this->setHealth(NPC_DEFAULTHEALTH);
    this->setAtk(NPC_DEFAULTATK);
}

string NPC::getLongDesc() {
	return npcLongDesc;
}

vector<string> NPC::getKeyWords() {
	return npcKeyWords;
}

string NPC::getDesc() {
	return npcDesc;
}

void NPC::setHealth(int hp) {
    this->npcHealth = hp;
}

int NPC::getHealth() {
    return this->npcHealth;
}

void NPC::setAtk(int atk) {
    this->npcAtk = atk;
}

int NPC::getAtk(){
    return this->npcAtk;
}

#endif