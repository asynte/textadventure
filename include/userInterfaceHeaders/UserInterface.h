#ifndef _USER_INTERFACE_H_
#define _USER_INTERFACE_H_

using namespace std;

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "pthread.h"
#include "assert.h"
#include "Commands.h"
#include "ObserverList.h"

void UserInterface_create(void);
void UserInterface_quit(void);
pthread_t& UserInterface_getThreadId(void);

bool UserInterface_isActive(void);

void UserInterface_invalidInput(const string&);
void UserInterface_ignoreNext(void);

void UserInterface_addListener(Observer *obs);
void UserInterface_notifyListeners(const string &);
void UserInterface_notifyListeners(const vector<string> &);

#endif
