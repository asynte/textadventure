#include "userAccountHeaders/Login.h"

#ifndef login_CPP
#define login_CPP

#include <stdio.h>
#include <string.h>


class InterfaceObserver : public Observer {
    public:
        InterfaceObserver() {}
        Login login;

        void notify(const string &userInput) {

        	//cout << "input: " << userInput << endl;

        	if(userInput == "register") {
        		login.UserAuth(1);
        	}

        	if(userInput == "login") {
        		login.UserAuth(2);
        	}
        }
        void notify(const vector<string> &userInput) {
        	//cout << "input: " << userInput.at(0) << endl;
            //do more stuff with the parsed strings
            //like call a function with arguements...
        }
};


void Login::init() {
	InterfaceObserver *observer = new InterfaceObserver();
	UserInterface_addListener(observer);
}

void Login::UserAuth(int choice){
	Login user1;

	if(choice == 1){
        user1.userRegister();
	}
    if(choice == 2){
        user1.Loggedin();
    }
}


 // User registration
void Login::userRegisterDo(){
	ofstream file;
	file.open("data/userdata.txt",fstream::app);
	if(file.is_open()){
		file<<"\n"<<username<< " " <<password;
		file.close();
			UserInterface_println("Enter Password:");
		UserInterface_println("Hi" + username);
		UserInterface_println("! You are registered now! Welcome!");
		UserAuth(0);
	}
	else{
			UserInterface_println("File Not Found");
	}
}

// Initialize user registration
void Login::userRegister(){
    
	UserInterface_println("Enter a new username:");
	username = UserInterface_getUserInput();
	ifstream fin;
	fin.open("data/userdata.txt");
	bool isFound=0;


	while(!fin.eof()){
		string temp = "";
		getline(fin,temp);
		for(int i=0;i<username.size();i++){
			if(temp[i]==username[i])
				isFound = 1;
				else{
				isFound =0;
				break;
				}
		}
	}
	if(isFound){
	UserInterface_println("Sorry Username already exist!");
	UserInterface_println("Please try a different one!");
	userRegister();
	}else{

	UserInterface_println("Please enter a new password:");
    password = UserInterface_getUserInput();
	userRegisterDo();	
	}
}


bool Login::Loggedin(){
	string userpass;
	UserInterface_println("Enter Username:");
	user = UserInterface_getUserInput();
	//user = UserInterface_getUserInput();
	//hide pass

    //char *pass; // password string pointer
    //pass = getpass("Enter Password: "); // get a password

	UserInterface_println("Enter Password:");
	pass = UserInterface_getUserInput();

	//search pattern	
	userpass = user+" "+pass;
	string line;
    ifstream usersFile;
    //system("ls");
    usersFile.open ("data/userdata.txt"); 
    //system("ls");
	bool found = false;

     	if(usersFile.is_open()) {
		while(getline(usersFile,line) && !found) {
			//match any strings
			if (line.compare(userpass) == 0) { 
		  	// if data found break loop
                  	found = true; 
              		}
          	}
	usersFile.close(); 
	if(found) {
		//link it to our game server
		UserInterface_println("Welcome to the game "+user);
		//cout << "Welcome to the game "<< user << '\n'; 
	}else {
		UserInterface_println("Incorrect Username and/or password !");
		Loggedin();
		return false;
		}
    }
    return true;
}
#endif