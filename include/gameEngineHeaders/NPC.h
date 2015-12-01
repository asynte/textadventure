#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/Object.h"
class Widget;

class NPC : public Widget {

public:
    const int NPC_DEFAULTHEALTH = 20;
    const int NPC_DEFAULTATK = 3;
    const int NPC_DEFAULTSTAT = 2;
    map<int, const Object> npcEquipment; // maps equipmentArea to Object

    NPC();
    NPC(string);
    NPC(int, string, vector<string>, string, string);
    string getLongDesc() const;
        void setLongDesc(string);
    vector<string> getKeyWords() const;
    string getDesc() const;
    void setHealth(int);
    int getHealth() const;
    void setAtk(int);
    int getAtk() const;
    void updateStats();
    void equip(Object&);
    void showEquipment();

protected:
    string npcLongDesc;
    vector<string> npcKeyWords;
    string npcDesc;
    vector<Object> npcInventory;
    int npcHealth;
    int npcAtk;
    int npcStrength;
    int npcDexterity;
};

#endif