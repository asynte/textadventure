
#include <string>
#include <vector>

#ifndef WIDGET_H
#define WIDGET_H

using namespace std;

class Widget {

public:
    enum equipmentArea { ERROR = 99, MISC = 0, ACCESSORY = 1, NECK = 3, TORSO = 4, CHEST = 5, HEAD = 6, LEGS = 7, FEET = 8, HANDS = 9, ARMS = 10, SHIELD = 11, BACK = 12, BELT = 13, WEAPON = 16 , WEAPON2 = 17};
    const static int NUMEQUIP = 18;
    
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
