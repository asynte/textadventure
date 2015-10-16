#include <iostream>
using namespace std;

#ifndef DOOR_H
#define DOOR_H

class Door{
public:
	Door();
	Door(string,string,string,int);
	string getDescription();
	int getDirectionAsInt();
	string getDirection();
	string getKeywords();
	int getToID();
	void getInformation();
	void setDescription(string);
	void setDirection(string);
	void setKeywords(string);
	void setToID(int);
private:
	string description;
	string direction;
	string keywords;
	int toID;
};


#endif