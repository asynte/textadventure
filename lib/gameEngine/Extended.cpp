#ifndef EXTENDED_CPP
#define EXTENDED_CPP
#include "gameEngineHeaders/Extended.h"

Extended::Extended(string description ,vector<string> keyWord){
	this->description=description;
	this->keyWord=keyWord;
}
string Extended::getDescription(){
	return description;
}
vector<string>Extended::getKeyWord(){
	return keyWord;
}
// void Extended::setDescription(vector<string> description){
// 	this->description;
// }
// void Extended::setKeyWord(vector<string> keyWord){
// 	this->keyWord;

// }
void Extended::printInformation(){
	cout<<"description:"<<endl;
	
	cout<<description<<endl;
	
	cout<<"Keyword:"<<endl;
	for(string s:keyWord){
		cout<<s<<endl;
	}
}

#endif