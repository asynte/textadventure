#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

class CharacterProfile {

public:
    string username;
    string password;
    string user;
    string pass;
    int choice;
    
    void UserAuth(){
   	CharacterProfile user1;
    cout<<"\n\nHello there! Welcome to The Game!\n";
	cout<<"1:Register\n2:Login\nWhat do you want to do? ";cin>>choice;


    if(choice != 2 or choice!=1 ){
    	cout<<"There's no option "<<choice<<" at the moment sorry!"<<endl;
    }

	if(choice == 1){
        user1.userRegister();
	}
    if(choice == 2){
        user1.Loggedin();
    }

    }


    // User registration
    void userRegisterDo()
    {
	ofstream file;
	file.open("userdata.txt",fstream::app);
	file<<"\n"<<username<< " " <<password;
	file.close();
	cout<<"Hi "<<username<<"! You are registered now! Welcome!\n\n";
    }

    // Initialize user registration
    void userRegister(){
        cout << "\nEnter a new username:\n";
	cin >> username;
	ifstream fin;
	fin.open("userdata.txt");
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
	}else{
        	cout << "\nPlease enter a new password:\n";
        	cin >> password;
		userRegisterDo();	
		}
    	}

    bool Loggedin(){
	string userpass;
	cout<<"\nEnter Username: "; cin>>user;

	//hide pass
    char *pass; // password string pointer
    pass = getpass("Enter Password: "); // get a password

	//cout<<"Enter password: "; cin>>pass;
	//search pattern	
	userpass = user+" "+pass;
	string line;
       	ifstream usersFile;
        usersFile.open ("userdata.txt"); 
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
		return false;
		}
    }
}

};

