
#include <string>
#include <vector>

#ifndef WIDGET_H
#define WIDGET_H

using namespace std;

class Widget {

public:
    enum equipmentArea { HEAD, ACCESSORY, TORSO, HANDS, LEGS, FEET, WEAPON, SHIELD };
    const static int NUMEQUIP = 8;
    
    Widget();
    Widget(int, vector<string>, string, string);
    void setName(string);
    string getName() const;
    int getId() const;

protected:
    string widgetName; // aka shortDesc
    int widgetId;
};

#endif
