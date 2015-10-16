#include "gameEngineHeaders/NPC.h"

#ifndef NPC_CPP
#define NPC_CPP

NPC::NPC(int id, string desc, vector<string> keywords, string longDesc, string shortDesc) {
	widgetId = id;
	npcDesc = desc;
	npcKeyWords = keywords;
	npcLongDesc = longDesc;
	widgetName = shortDesc;
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

#endif