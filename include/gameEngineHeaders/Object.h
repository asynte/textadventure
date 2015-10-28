
#include <string>
#include <vector>
#include <iostream>
#include "Widget.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object : public Widget {

public:
	Object();
        Object(int, string);
	Object(int, vector<string>, vector<string>, string, string);
	string getLongDesc();
	vector<string> getKeyWords();
	vector<string> getExtra();
        void setWearable(bool);
	bool isWearable();
        void setEquipArea(equipmentArea);
        equipmentArea getEquipArea();

protected:
	string objLongDesc;
	vector<string> objKeyWords;
	vector<string> objExtra;
        bool wearable;
        equipmentArea equippedOn;
};

#endif
