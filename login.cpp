#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool Loggedin(){
	string user,pass, un,pw;
	cout<<"Enter user: "; cin>>user;
	cout<<"Enter pass: "; cin>>pass;

	ifstream read("userdata.txt");
	getline(read,un);
	getline(read,pw);

	if(un == user && pw == pass){
		return true;
	}
	else{
		return false;
	}
}

int main()
{
	int choice;
	cout<<"1.register\n2:login\nWhat do you want to do? ";cin>>choice;


	if(choice == 1){
		string username,password;
		cout<<"select user: "; cin>>username;
		cout<<"select a pass:"; cin>>password;
		ofstream file;

		file.open("userdata.txt");
		file<<username<<endl
			<<password;
		file.close();
		cout<<"You are registered! Welcome!\n\n";
		main();
	}
	else if(choice == 2){
		bool status = Loggedin();
		if(!status){
			cout<<"cant login!\n"<<endl;
			main();

		}
		else{
			cout<<"successfully log in!\n"<<endl;
//link it to server
		}
	}
	return 0;
}
