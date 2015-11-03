#ifndef OBJECT_CPP
#define OBJECT_CPP

#include "gameEngineHeaders/Object.h"

Object::Object() {
    
}

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

string Object::getLongDesc() const {
    return objLongDesc;
}

void Object::setLongDesc(string longdesc) {
    this->objLongDesc = longdesc;
}

vector<string> Object::getKeyWords() const {
    return objKeyWords;
}

vector<string> Object::getExtra() const {
    return objExtra;
}

void Object::setWearable(bool w) {
    this->wearable = w;
}

bool Object::isWearable() const {
    return this->wearable;
}

void Object::setEquipArea(equipmentArea ea) {
    this->equippedOn = ea;
}

Widget::equipmentArea Object::getEquipArea() const {
    return this->equippedOn;
}

#endif