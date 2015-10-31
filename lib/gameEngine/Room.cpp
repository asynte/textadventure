#ifndef ROOM_CPP
#define ROOM_CPP


#include <algorithm>
#include "gameEngineHeaders/Room.h"
#include "userInterfaceHeaders/UserInterface.h"

// Room::Room(){
// 	description = "";
// 	//this->extended_descriptions = extended_descriptions;
// 	ID=0;
// 	name="";
// }
Room::Room() {

}

Room::Room(string description,vector<Door> doorsList,vector<Extended> extendedList,string name,int ID) {
	this->description = description;
	this->doorsList=doorsList;
	this->extendedList = extendedList;
	this->name=name;
	this->ID=ID;
}
string Room::getDescription(){
	return description;
}
vector<Door> Room::getDoorsList(){
	return doorsList;
}
vector<Extended> Room::getExtended(){
	return extendedList;
}
string Room::getName() const{
	return name;
}
int Room::getID() const{
	return ID;
}
void Room::getInformation(){
	// UserInterface_println("You are in Room " + I2S(getID()) );
	// UserInterface_println("Its name is " + getName());
	// UserInterface_println("Description: " + getDescription());
	// if(doorsList.size()==1){
	// 	UserInterface_println("There is " + I2S(doorsList.size()) + " door");
	// }else if(doorsList.size()>1){
	// 	UserInterface_println("There are " + I2S(doorsList.size()) + " doors");
	// }
	
	// UserInterface_println("Direction: ");
	// for(int i=0;i<doorsList.size();i++){
	// 	UserInterface_println(doorsList[i].getDirection()+" ");

	// }
	// UserInterface_println(" ");
	// UserInterface_println(" ");
	// UserInterface_println(" ");
}
// vector<Widget> Room::getWidgetVector() {
//     return this->widgetVector;
// }

// void Room::setWidgetVector(int widgetIndex, Widget wid) {
//     this->widgetVector[widgetIndex] = wid;
// }
bool Room::isRoomAvailable(int direction){
	for(int i=0;i<doorsList.size();i++){
		if(doorsList[i].getDirectionAsInt()==direction){
			return true;
		}
	}
	cout<<"You cannot go in this direction because this direction does not exist"<<endl;
	//UserInterface_println("You cannot go in this direction because this direction does not exist");
	return false;
}


Door Room::getDoorWantToGo(int direction){
	for(int i=0;i<doorsList.size();i++){
		if(doorsList[i].getDirectionAsInt()==direction){
			return doorsList[i];
		}
	}
}

vector<string> Room::getPossibleDirections() {
	vector<string> directions;

	for(int i=0;i<doorsList.size();i++){
		Door door = doorsList[i];
		string direction = door.getDirection();

		// if ( find(directions.begin(), directions.end(), direction) != directions.end() ) {

		cout << "adding: " << direction;

			directions.push_back(direction);
		// }
	}

	return directions;
}


// bool Room::isRoomAvailable(int direction){
// 	for(int i=0;i<doorsList.size();i++){
// 		if(doorsList[i].getDirectionAsInt()==direction){
// 			return true;
// 		}
// 	}
// 	cout<<"You cannot go in this direction because this direction does not exist"<<endl;
// 	return false;
// }
#endif
