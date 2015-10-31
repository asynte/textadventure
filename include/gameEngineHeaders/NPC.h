#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <iostream>
#include "gameEngineHeaders/Widget.h"
class Widget;

class NPC : public Widget {

public:
	NPC(int, string, vector<string>, string, string);
	string getLongDesc();
	vector<string> getKeyWords();
	string getDesc();
	void setHealth(int);
    int getHealth();
    void setAtk(int);
    int getAtk();

protected:
    const int NPC_DEFAULTHEALTH = 20;
    const int NPC_DEFAULTATK = 3;
	string npcLongDesc;
	vector<string> npcKeyWords;
	string npcDesc;
	int npcHealth;
	int npcAtk;
};

#endif
