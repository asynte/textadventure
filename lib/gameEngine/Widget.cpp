#include "gameEngineHeaders/Widget.h"

#ifndef WIDGET_CPP
#define WIDGET_CPP

Widget::Widget() {}

void Widget::setName(string name) {
    this->widgetName = name;
}

string Widget::getName() {
    return widgetName;
}

int Widget::getId() {
    return widgetId;
}

#endif