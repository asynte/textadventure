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

Login::Login() { }

Login::Login(bool temp) { 

	InterfaceObserver *observer = new InterfaceObserver();
	UserInterface_addListener(observer);
}

// void Login::init() {
// 	InterfaceObserver *observer = new InterfaceObserver();
// 	UserInterface_addListener(observer);
// }

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
		file<<"\n"<<"UserName:"<<username<< " " <<password;
		file.close();
		UserInterface_println("Hi " + username + "! You are registered now! Welcome!");
		UserAuth(0);
	}
	else{
		UserInterface_println("File Not Found");
	}
}

// Initialize user registration
void Login::userRegister(){
    
	int exitcon = 1;

	while (exitcon == 1){
		exitcon = 0;
		UserInterface_println("Enter a new username:");
		username = UserInterface_getUserInput();

		usernameTEMP = "UserName:"+username;


		ifstream fin;
		fin.open("data/userdata.txt");
		bool isFound=0;


		if(fin.is_open()){
			string candidate;

			while(fin >>candidate){
				if(usernameTEMP == candidate){
					UserInterface_println("Sorry Username already exist!");
					UserInterface_println("Please try again!");
					exitcon = 1;
				}
			}
		}

	}
	string pass1;
	string pass2;
	bool out = 1;

	while(out){
		UserInterface_println("Please enter a new password:");
    	pass1 = UserInterface_getUserInput();

		UserInterface_println("Please enter re-enter your new password:");
	    pass2 = UserInterface_getUserInput();

    	if(pass1==pass2){
    		password = pass1;
    		out = 0;
    		userRegisterDo();
  	  	}

    	if(pass1!=pass2){
    		UserInterface_println("Password does not match!");
    	}
	}

}



bool Login::Loggedin(){
	string userpass;
	UserInterface_println("Enter Username:");
	user = UserInterface_getUserInput();
	usernameTEMP2 = "UserName:"+user;
	//user = UserInterface_getUserInput();
	//hide pass

    //char *pass; // password string pointer
    //pass = getpass("Enter Password: "); // get a password

	UserInterface_println("Enter Password:");
	pass = UserInterface_getUserInput();

	//search pattern	
	userpass = usernameTEMP2+" "+pass;
	string line;
    ifstream usersFile;
    usersFile.open ("data/userdata.txt"); 

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