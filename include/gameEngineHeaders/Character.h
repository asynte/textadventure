
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Widget.h"
#include "Object.h"
#include "NPC.h"
#include "Monster.h"
#include "World.h"

#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character : public Widget {
public:
    const int CHAR_DEFAULTHEALTH = 100;
    const int CHAR_DEFAULTATK = 10;
    const int CHAR_DEFAULTSTAT = 1;
    const int CHAR_STARTLOCATION = 0;
    
    Character(string);
    void getStatus();
    void setHealth(int);
    int getHealth();
    void setExp();
    void increaseExp();
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
    vector<Widget> getInventory();
    void addToInventory(Object);
    //void removeFromInventory(Widget&);
    int getLocation();
    void interact(NPC);
    void interact(Object);
    void examine(Object);
    void examine(Monster);
    void interact(Monster);
    void move(World, int);
    
protected:
    int charHealth;
    int experience;
    int charLevel;
    int charAtk;
    int charStrength;
    int charIntelligence;
    int charDexterity;
    int charCharisma;
    vector<Widget> charInventory;
    int currentLocation;
};

#endif
