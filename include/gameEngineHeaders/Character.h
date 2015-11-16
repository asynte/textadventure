
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <regex>
#include <stdlib.h>
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/Room.h"

using namespace std;

class Character : public Widget {
public:
    const int CHAR_DEFAULTHEALTH = 100;
    const int CHAR_DEFAULTATK = 10;
    const int CHAR_DEFAULTSTAT = 1;
    const int CHAR_STARTLOCATION = -1;

    map<int, const Object> charEquipment; // maps equipmentArea to Object
    
    Character(string);
    void printStatus();
    void setHealth(int);
    int getHealth() const;
    void setExp(int);
    void increaseExp(int);
    int getExp() const;
    void setLevel(int);
    int getLevel() const;
    void updateLevel();
    void setAtk(int);
    int getAtk() const;
    void setStr(int);
    int getStr() const;
    void setInt(int);
    int getInt() const;
    void setDex(int);
    int getDex() const;
    void setCha(int);
    int getCha() const;
    void setPVP(bool);
    bool getPVP() const;
    void togglePVP();
    vector<Object> getInventory() const;
    void addToInventory(Object);
    void showInventory() const;
    void removeFromInventory(Object&);
    void equip(Object&);
    void unequip(Object);
    void setLocation(int);
    int getCurrentLocation() const;
    void interact(NPC);
    void interact(Object);
    void examine(Object);
    void examine(NPC);
    void examine(Character&);
    void attack(NPC);
    void attack(Character&);
    void battleSequence(NPC&);
    
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
    int currentLocation;
    bool wantsToPVP;
};

#endif
