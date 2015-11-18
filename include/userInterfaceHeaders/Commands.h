#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <algorithm>
#include <vector>
#include <map>
#include "UserInterface.h"

#define DYNAMIC_MOVE_COMMAND 0
#define DYNAMIC_LOOK_COMMAND 1

void Commands_initiate(void);

vector<string> Commands_getMatches(const string &input, int n, bool hasDynamicArguements, int type);

bool Commands_isValidToken(const string &token);
bool Commands_hasDynamicArguements(const string &token);

void Commands_callFunction(const string &funcName);
void Commands_callFunction(const string &funcName, const string &funcArgs);
void Commands_callFunction(const string &funcName, const vector<string> &funcArgs);

void Commands_callError(const string &funcName, const string &funcArgs);
#endif
