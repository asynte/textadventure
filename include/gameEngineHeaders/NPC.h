
#include <string>
#include <vector>
#include <iostream>
#include "Widget.h"

#ifndef NPC_H
#define NPC_H

class NPC : public Widget {

public:
	NPC(int, string, vector<string>, string, string);
	string getLongDesc();
	vector<string> getKeyWords();
	string getDesc();
	//void interact();

protected:
	string npcLongDesc;
	vector<string> npcKeyWords;
	string npcDesc;
};

#endif
