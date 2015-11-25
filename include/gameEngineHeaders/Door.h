
using namespace std;

#ifndef DOOR_H
#define DOOR_H


#include <iostream>
#include <vector>



class Door{
	public:
		Door(string,string,vector<string>,int);
		string getDescription();
		int getDirectionAsInt(const string &str);

		string getDirection();
		vector<string> getKeywords();
		int getNextRoomID();
		void getInformation();
		void setDescription(string);
		void setDirection(string);
		void setKeywords(vector<string>);
		void setToID(int);
	private:
		string description;
		string direction;
		vector<string> keywords;
		int toID;
};


#endif
