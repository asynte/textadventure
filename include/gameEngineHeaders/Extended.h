
using namespace std;

#ifndef Extended_H
#define Extended_H
#include <iostream>
#include <vector>

class Extended{
public:
	Extended(string,vector<string>);
	string getDescription();
	vector<string> getKeyWord();
	void printInformation();

	// void setDescription(vector<string>);
	// void setKeyWord(vector<string>);

private:
	string description;
	vector<string> keyWord;
};


#endif