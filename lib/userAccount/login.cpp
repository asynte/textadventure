#include "userAccountHeaders/Login.h"

#ifndef login_CPP
#define login_CPP


class InterfaceObserver : public Observer {
    public:
        InterfaceObserver() {}
        Login login;

        void notify(const string &userInput) {

        	//cout << "input: " << userInput << endl;


        	if(userInput == "login") {
        		login.UserAuth(1);
        	}
        	if(userInput == "register") {
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
	file.open("../data/userdata.txt",fstream::app);
	if(file.is_open()){
		file<<"\n"<<username<< " " <<password;
		file.close();
		cout<<"Hi "<<username<<"! You are registered now! Welcome!\n\n";
		UserAuth(0);
	}
	else{
		cout<< "File not found" <<endl;
	}
}

// Initialize user registration
void Login::userRegister(){
    cout << "\nEnter a new username:\n";
	cin >> username;
	//username = UserInterface_getUserInput();

	ifstream fin;
	fin.open("../data/userdata.txt");
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
		cout << "\nSorry Username already exist!\nPlease try a different one!\n";
		userRegister();
	}else{
        cout << "\nPlease enter a new password:\n";
        cin >> password;
        //password = UserInterface_getUserInput();
		userRegisterDo();	
		}
}


bool Login::Loggedin(){
	string userpass;
	cout<<"\nEnter Username: "; 
	cin>>user;
	//user = UserInterface_getUserInput();
	//hide pass
    char *pass; // password string pointer
    pass = getpass("Enter Password: "); // get a password

	//cout<<"Enter password: "; cin>>pass;
	//search pattern	
	userpass = user+" "+pass;
	string line;
    ifstream usersFile;
    usersFile.open ("../data/userdata.txt"); 
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
		cout << "Welcome to the game "<< user << '\n'; 
	}else {
		cout << "\nIncorrect Username and/or password !\n";
		Loggedin();
		return false;
		}
    }
    return true;
}
#endif