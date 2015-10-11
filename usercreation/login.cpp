#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool Loggedin(){
	string userpass,user,pass;
	cout<<"Enter username: "; cin>>user;
	cout<<"Enter password: "; cin>>pass;
	//search pattern	
	userpass = user+" "+pass;
        int offset; 
        string line;
        ifstream usersFile;
        usersFile.open ("userdata.txt"); 
	bool found = false;
     	if(usersFile.is_open()) {
		while(getline(usersFile,line) && !found) {
		//match strings
			if (line.compare(userpass) == 0) { 
		  	// if data found break loop
                  	found = true; 
              		}
          	}
	//close the file
	usersFile.close(); 
	if(found) {
		cout << "Welcome "<< user << '\n';
		//link it to our game server 
	}
	else {
		cout << "\nIncorrect Username and/or password !\n";
		return false;
	}
      }
}


int main()
{
	int choice;
	cout<<"1.register\n2:login\nWhat do you want to do? ";cin>>choice;


	if(choice == 1){
		string username,password;
		cout<<"Select username: "; cin>>username;
		cout<<"Select a password: "; cin>>password;
		ofstream file;
		file.open("userdata.txt",fstream::app);
		file<<"\n"<<username<< " " <<password;
		file.close();
		cout<<"You are registered! Welcome!\n\n";
		main();
	}
	else if(choice == 2){
		bool status = Loggedin();
		if(!status){
			cout<<"Please try again!\n"<<endl;
			main();
		}
	}
	return 0;
}
