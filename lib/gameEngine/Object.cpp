#ifndef OBJECT_CPP
#define OBJECT_CPP

#include "gameEngineHeaders/Object.h"

Object::Object() {
    
}

Object::Object(int id, string name) { // for testing use only
    widgetName = name;
    widgetId = id;
    wearable = false;
    roomID=-1;
}

Object::Object(int id, vector<string> keywords){ //testing
    widgetId = id;
    objKeyWords = keywords;
    wearable = false;
    equippedOn = Widget::ERROR;
}

Object::Object(int id, string extraDesc, vector<string> extraKeywords, vector<string> keywords, string longDesc, string shortDesc) {
    objExtraDesc = extraDesc;
    objExtraKeyWords = extraKeywords;
    widgetId = id;
    objKeyWords = keywords;
    objLongDesc = longDesc;
    widgetName = shortDesc;
    wearable = false;
    objStats = this->widgetName.length();
    roomID=-1;
    slot=-1;
    equippedOn = Widget::ERROR;
}
void Object::setRoomID(int roomID){
    this->roomID=roomID;
}

int Object::getRoomID()const{
    return roomID;

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

vector<string> Object::getExtraKeyWords() const {
    return objExtraKeyWords;
}

string Object::getExtraDesc() const {
    return objExtraDesc;
}

void Object::setWearable(bool w) {
    this->wearable = w;
}

bool Object::isWearable() {
    // for(int i = 0; i < this->objKeyWords.size(); i++){
    //     if(this->objKeyWords[i] == "axe" || this->objKeyWords[i] == "wand"){
    //         this->setEquipArea(Widget::WEAPON);
    //         return true;
    //     } 
    //     else if(this->objKeyWords[i] == "glasses" || this->objKeyWords[i] == "necklace"){
    //         this->setEquipArea(Widget::ACCESSORY);
    //         return true;
    //     } 
    //     else if(this->objKeyWords[i] == "hat"){
    //         this->setEquipArea(Widget::HEAD);
    //         return true;
    //     }
    // }
    // return false;
    return this->wearable;
}

void Object::setEquipArea(equipmentArea ea) {
    this->equippedOn = ea;
}

Widget::equipmentArea Object::getEquipArea() const {
    return this->equippedOn;
}
void Object::setSlot(int slot) {
    this->slot = slot;
    this->equippedOn = (Widget::equipmentArea)slot;
}
int Object::getSlot()const{
    return slot;
}

#endif