#ifndef OBJECT_CPP
#define OBJECT_CPP

#include "gameEngineHeaders/Object.h"

Object::Object(int id, string name) {
    widgetName = name;
    widgetId = id;
    wearable = false;
}

Object::Object(int id, vector<string> extra, vector<string> keywords, string longDesc, string shortDesc) {
    objExtra = extra;
    widgetId = id;
    objKeyWords = keywords;
    objLongDesc = longDesc;
    widgetName = shortDesc;
    wearable = false;
}

string Object::getLongDesc() {
    return objLongDesc;
}

vector<string> Object::getKeyWords() {
    return objKeyWords;
}

vector<string> Object::getExtra() {
    return objExtra;
}

void Object::setWearable(bool w) {
    this->wearable = w;
}

bool Object::isWearable() {
    return this->wearable;
}

void Object::setEquipArea(equipmentArea ea) {
    this->equippedOn = ea;
}

Widget::equipmentArea Object::getEquipArea() {
    return this->equippedOn;
}

#endif