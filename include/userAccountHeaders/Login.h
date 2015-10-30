#ifndef _LOGIN_H_
#define _LOGIN_H_

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "userInterfaceHeaders/UserInterface.h"
using namespace std;

class Login{

public:
    string usernameTEMP;
    string usernameTEMP2;
    string username;
    string password;
    string user;
    string pass;
    int choice;
    void UserAuth(int);
    void userRegisterDo();
    void userRegister();
    bool Loggedin();
    void init();
};

#endif 

