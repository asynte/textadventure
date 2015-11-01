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
	Object(int, vector<string>, vector<string>, string, string);
        void setLongDesc(string);
	string getLongDesc() const;
	vector<string> getKeyWords() const;
	vector<string> getExtra() const;
        void setWearable(bool);
	bool isWearable() const;
        void setEquipArea(equipmentArea);
        equipmentArea getEquipArea() const;

protected:
	string objLongDesc;
	vector<string> objKeyWords;
	vector<string> objExtra;
        bool wearable;
        equipmentArea equippedOn;
};

#endif
