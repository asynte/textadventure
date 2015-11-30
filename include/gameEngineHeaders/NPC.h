#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <iostream>
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/Object.h"

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
    void addInventory(Object);
    void addEquipment(Object);
    vector<Object> getInventory();
    vector<Object> getEquipment();

protected:
    const int NPC_DEFAULTHEALTH = 20;
    const int NPC_DEFAULTATK = 3;
    string npcLongDesc;
    vector<string> npcKeyWords;
    vector<Object> inventory;
    vector<Object> equipment;
    string npcDesc;
    int npcHealth;
    int npcAtk;
    int roomID;
};

#endif