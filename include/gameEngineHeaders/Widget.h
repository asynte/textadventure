
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"

#ifndef WIDGET_H
#define WIDGET_H

using namespace std;

class Widget {

public:
    Widget();
    Widget(int, vector<string>, string, string);
    void setName(string);
    string getName();
    int getId();
    //virtual void interact() = 0; // function to interact with object, pure virtual

protected:
    string widgetName; // aka shortDesc
    int widgetId;
};

#endif
