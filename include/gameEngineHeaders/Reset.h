using namespace std;

#ifndef RESET_H
#define RESET_H


#include <iostream>
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/NPC.h"
#include <vector>
#include "gameEngineHeaders/Extended.h"

class Reset{
public:
	Reset(string, string,int,int,int,int,string);
	string getAction();
	string getComment();
	int getId();
	int getLimit();
	int getRoom();
	int getSlot();
	string getState();

private:
	string action;
	string comment;
	int id;
	int limit;
	int room;
	int slot;
	string state;
};
