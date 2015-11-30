#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <iostream>
#include "gameEngineHeaders/Widget.h"
class Widget;

class NPC : public Widget {

public:
    NPC();
    NPC(int, string, vector<string>, string, string);
    string getLongDesc() const;
        void setLongDesc(string);
    vector<string> getKeyWords() const;
    string getDesc() const;
    void setHealth(int);
    int getHealth() const;
    void setAtk(int);
    int getAtk() const;
    void setRoomID(int);
    int getRoomID()const;

protected:
    const int NPC_DEFAULTHEALTH = 20;
    const int NPC_DEFAULTATK = 3;
    string npcLongDesc;
    vector<string> npcKeyWords;
    string npcDesc;
    int npcHealth;
    int npcAtk;
    int roomID;
};

#endif