#include "gameEngineHeaders/Room.h"

#ifndef ROOM_CPP
#define ROOM_CPP

Room::Room(){
	description = "";
	//this->extended_descriptions = extended_descriptions;
	ID=0;
	name="";
}
Room::Room(string description,vector<Door> doorsList,string name,int ID) {
	this->description = description;
	this->doorsList=doorsList;
	//this->extended_descriptions = extended_descriptions;
	this->name=name;
	this->ID=ID;
}
string Room::getDescription(){
	return description;
}
vector<Door> Room::getDoorsList(){
	return doorsList;
}
string Room::getName(){
	return name;
}
int Room::getID(){
	return ID;
}
void Room::getInformation(){
	cout<<"You are in Room "<<getID()<<endl;
	cout<<"Its name is "<<getName()<<endl;
	cout<<"Description: "<<getDescription()<<endl;
	if(doorsList.size()==1){
		cout<<"There is "<<doorsList.size()<<" door"<<endl;
	}else if(doorsList.size()>1){
		cout<<"There are "<<doorsList.size()<<" doors"<<endl;
	}
	
	cout<<"Direction: ";
	for(int i=0;i<doorsList.size();i++){
		cout<<doorsList[i].getDirection()<<" ";

	}
	cout<<endl<<endl<<endl; 
}
vector<Widget> Room::getWidgetVector() {
    return this->widgetVector;
}

void Room::setWidgetVector(int widgetIndex, Widget wid) {
    this->widgetVector[widgetIndex] = wid;
}
bool Room::isRoomAvailable(int direction){
	for(int i=0;i<doorsList.size();i++){
		if(doorsList[i].getDirectionAsInt()==direction){
			return true;
		}
	}
	cout<<"You cannot go in this direction because this direction does not exist"<<endl;
	return false;
}
Door Room::getDoorWantToGo(int direction){
	for(int i=0;i<doorsList.size();i++){
		if(doorsList[i].getDirectionAsInt()==direction){
			return doorsList[i];
		}
	}
}
#endif