#include "gameEngineHeaders/Object.h"

#ifndef OBJECT_CPP
#define OBJECT_CPP

Object::Object(int id, string name) {
    widgetName = name;
    widgetId = id;
}

Object::Object(int id, vector<string> extra, vector<string> keywords, string longDesc, string shortDesc) {
	objExtra = extra;
	widgetId = id;
	objKeyWords = keywords;
	objLongDesc = longDesc;
	widgetName = shortDesc;
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

#endif