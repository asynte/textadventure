#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <algorithm>
#include <vector>
#include <map>
#include "UserInterface.h"

void Commands_initiate(void);

vector<string> Commands_getMatches(const string &input, int n);

bool Commands_isValidToken(const string &token);

void Commands_callFunction(const string &funcName);
void Commands_callFunction(const string &funcName, const string &funcArgs);
void Commands_callFunction(const string &funcName, const vector<string> &funcArgs);

#endif
