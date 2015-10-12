#include <iostream>
#include <fstream>
#include <string>
#include "CharacterProfile.h"

using namespace std;
// Main program
int main() {
    	int choice;
    	CharacterProfile user1;
    	ifstream usersFile("userdata.txt");
	cout<<"\n\nHi there! Welcome to The Game!\n";
	cout<<"1:Register\n2:Login\nWhat do you want to do? ";cin>>choice;
	if(choice == 1){
        	user1.userRegister();
	}
        	else{
            	user1.Loggedin();
            	}
}
