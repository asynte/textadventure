#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>
#include <iostream>
#include "gameEngineHeaders/Widget.h"
class Widget;

class Object : public Widget {

public:
	Object();
        Object(int, string);
	Object(int, string, vector<string>, vector<string>, string, string);
        void setLongDesc(string);
	string getLongDesc() const;
	vector<string> getKeyWords() const;
	vector<string> getExtraKeyWords() const;
	string getExtraDesc() const;
        void setWearable(bool);
	bool isWearable() const;
        void setEquipArea(equipmentArea);
        equipmentArea getEquipArea() const;
    void setRoomID(int);
    int getRoomID()const;
protected:
	string objLongDesc;
	vector<string> objKeyWords;
	string objExtraDesc;
	vector<string> objExtraKeyWords;
        bool wearable;
        equipmentArea equippedOn;
        int objStats;
    int roomID;

};

#endif