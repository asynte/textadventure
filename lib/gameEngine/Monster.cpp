
#include "gameEngineHeaders/Monster.h"

#ifndef MONSTER_CPP
#define MONSTER_CPP

Monster::Monster(string name) {
    this->setName(name);
    this->setHealth(MON_DEFAULTHEALTH);
    this->setAtk(MON_DEFAULTATK);
}

Monster::Monster(string name, int hp, int atk, string description) {
    this->setName(name);
    this->setHealth(hp);
    this->setAtk(atk);
    this->monDesc = description;
}

void Monster::setHealth(int hp) {
    this->monHealth = hp;
}

int Monster::getHealth() {
    return this->monHealth;
}

void Monster::setAtk(int atk) {
    this->monAtk = atk;
}

int Monster::getAtk(){
    return this->monAtk;
}

string Monster::getDesc() {
    return this->monDesc;
}

#endif