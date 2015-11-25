
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
#include "gameEngineHeaders/Spell.h"
#include "gameEngineHeaders/HealSpell.h"

//class HealSpell;

using namespace std;

class Character : public Widget {
public:
    static const int CHAR_DEFAULTHEALTH = 100;
    static const int CHAR_DEFAULTMANA = 100;
    static const int CHAR_DEFAULTATK = 10;
    static const int CHAR_DEFAULTSTAT = 1;
    static const int CHAR_DEFAULTGOLD = 1000;
    static const int CHAR_STARTLOCATION = -1;

    map<int, const Object> charEquipment; // maps equipmentArea to Object
    
    Character();
    Character(string);
    void printStatus();
    void setHealth(int);
    int getHealth() const;
    void setMana(int);
    int getMana() const;
    void setGold(int);
    int getGold() const;
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
    // void addHealSpell(HealSpell);
    // vector<HealSpell> getHealSpells() const;
    void togglePVP();
    void updateStats();
    vector<Object> getInventory() const;
    void addToInventory(Object);
    void showInventory() const;
    void removeFromInventory(Object&);
    void equip(Object&);
    void unequip(Object);
    void setLocation(int);
    int getLocation() const;
    void interact(NPC);
    void interact(Object);
    void examine(Object);
    void examine(NPC);
    void examine(Character&);
    void attack(NPC);
    void attack(Character&);
    void battleSequence(NPC&);
    bool equals(const Character &);
    
protected:
    int charHealth;
    int charMana;
    int charGold;
    int experience;
    int charLevel;
    int charAtk;
    int charStrength;
    int charIntelligence;
    int charDexterity;
    int charCharisma;
    vector<Object> charInventory;
    vector<HealSpell> charHealSpells;
    int currentLocation;
    bool wantsToPVP;
};

#endif