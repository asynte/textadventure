#ifndef _USER_INTERFACE_H_
#define _USER_INTERFACE_H_

using namespace std;



#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <curses.h>
#include <unistd.h>
#include "pthread.h"
#include <typeinfo>
#include "assert.h"

#include "Commands.h"
#include "ObserverList.h"

void UserInterface_create(void);
void UserInterface_quit(void);
void UserInterface_exit(void);
pthread_t& UserInterface_getThreadId(void);

bool UserInterface_isActive(void);

void UserInterface_invalidInput(const string&);
void UserInterface_ignoreNext(void);

// added in GameEngineFunctions.h
// void UserInterface_addGameEngine(GameEngine g) ;
void UserInterface_addListener(Observer *obs);

void UserInterface_notifyListeners(const string &);
void UserInterface_notifyListeners(const vector<string> &);

//vector<string> UserInterface_getPossibleDirections(void);


//I/O functions
	//out to user
	void UserInterface_print(const string &value);
	void UserInterface_println(const string &value);
	void UserInterface_printServerMessage(const string &value);

	//get user input
	string UserInterface_getUserInput(void);
	
	//String Conversion
	string C2S(const char c);
	string I2S(const int i);

//template <typename T>
//ostream& operator<<(ostream& os, const T& x);
/*{
    //os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}*/


#endif
