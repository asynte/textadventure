
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
class Widget;
class NPC;
class Object;


using namespace std;

class Character : public Widget {
public:
    const int CHAR_DEFAULTHEALTH = 100;
    const int CHAR_DEFAULTATK = 10;
    const int CHAR_DEFAULTSTAT = 1;
    const int CHAR_STARTLOCATION = 0;
    map<int, Object> charEquipment;
    
    Character(string);
    void printStatus();
    void setHealth(int);
    int getHealth();
    void setExp(int);
    void increaseExp(int);
    int getExp();
    void setLevel(int);
    int getLevel();
    void updateLevel();
    void setAtk(int);
    int getAtk();
    void setStr(int);
    int getStr();
    void setInt(int);
    int getInt();
    void setDex(int);
    int getDex();
    void setCha(int);
    int getCha();
    void setPVP(bool);
    bool getPVP();
    void togglePVP();
    vector<Object> getInventory();
    void addToInventory(Object);
    //void removeFromInventory(Object);
    Object** getEquipment();
    void equip(Object&);
    void unequip(Object);
    void setLocation(int);
    int getLocation();
    void interact(NPC);
    void interact(Object);
    void examine(Object);
    void examine(NPC);
    void attack(NPC);
    void attack(Character&);
    //void move(World, int);
    
protected:
    int charHealth;
    int experience;
    int charLevel;
    int charAtk;
    int charStrength;
    int charIntelligence;
    int charDexterity;
    int charCharisma;
    vector<Object> charInventory;
    //add vector for skills?
    int currentLocation;
    bool wantsToPVP;
};

#endif
