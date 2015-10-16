
#include <string>
#include <vector>
#include "Widget.h"

#ifndef MONSTER_H
#define MONSTER_H

using namespace std;

class Monster : public Widget {
public:
    const int MON_DEFAULTHEALTH = 20;
    const int MON_DEFAULTATK = 3;
    
    Monster(string);
    Monster(string, int, int, string);
    void setHealth(int);
    int getHealth();
    void setAtk(int);
    int getAtk();
    string getDesc();
    
protected:
    int monHealth;
    int monAtk;
    string monDesc;
};

#endif
