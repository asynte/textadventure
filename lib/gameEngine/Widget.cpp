#include "gameEngineHeaders/Widget.h"

#ifndef WIDGET_CPP
#define WIDGET_CPP

Widget::Widget() {}

void Widget::setName(string name) {
    this->widgetName = name;
}

string Widget::getName() const {
    return widgetName;
}

int Widget::getId() const {
    return widgetId;
}

#endif