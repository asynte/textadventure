#ifndef ROOM_CPP
#define ROOM_CPP


#include <algorithm>
#include "gameEngineHeaders/Room.h"


Room::Room(int ID) {
	this->ID = ID;
}

Room::Room(string description,vector<Door> doorsList,vector<Extended> extendedList,string name,int ID) {
	this->description = description;
	this->doorsList=doorsList;
	this->extendedList = extendedList;
	this->name=name;
	this->ID=ID;
}
vector<string> Room::getObjectAllKeyWords(){
	vector<string> objectAllKeywords;
	objectAllKeywords.push_back("\nObjects keyword: ");
	for(Object o:objectList){
		vector<string> objectKeywords=o.getKeyWords();
		for(string s:objectKeywords){
			objectAllKeywords.push_back(s);
		}
	}
	return objectAllKeywords;
}
vector<string> Room::getNPCAllKeyWords(){
	vector<string> npcAllKeywords;
	npcAllKeywords.push_back("\nNPC keyword: ");
	for(NPC n:npcList){
		vector<string> npcKeywords=n.getKeyWords();
		for(string s:npcKeywords){
			npcAllKeywords.push_back(s);
		}
	}
	return npcAllKeywords;
}
vector<string> Room::getDoorAllKeywords(){
	vector<string> doorAllKeywords;
	doorAllKeywords.push_back("\nDoor keyword: ");
	for(Door d:doorsList){
		vector<string> doorKeywords=d.getKeywords();
		for(string s:doorKeywords){
			doorAllKeywords.push_back(s);
		}
	}
	return doorAllKeywords;
}
//Character not in room, did not test
// vector<string> Room::getCharacterAllKeyWords(){
// 	vector<string> characterAllKeywords;
// 	characterAllKeywords.push_back("\nCharacter keyword: ");
// 	for(Character c:characterList){
// 		vector<string> chararcterKeywords=c.getKeyWords();
// 		for(string s:chararcterKeywords){
// 			characterAllKeywords.push_back(s);
// 		}
// 	}
// 	return characterAllKeywords;
// }
vector<string>Room::getAllKeyWords(){
	vector<string> objectAllKeywords=getObjectAllKeyWords();
	vector<string> npcAllKeywords=getNPCAllKeyWords();
	vector<string> doorAllKeywords=getDoorAllKeywords();
	//vector<string> characterAllKeywords=getCharacterAllKeyWords();
	vector<string> allKeywords;
	for(string s:objectAllKeywords){
		allKeywords.push_back(s);
	}
	for(string s:npcAllKeywords){
		allKeywords.push_back(s);
	}
	for(string s:doorAllKeywords){
		allKeywords.push_back(s);
	}
	// for(string s:characterAllKeywords){
	// 	allKeywords.push_back(s);
	// }
	return allKeywords;
}
vector <Object> Room::getObjectAssociatedKeyword(string keyword){
	cout<<"keyword:"<<keyword<<endl;
	vector <Object> objectKey;
	for(int i=0;i<objectList.size();i++){
		vector <string> objKeyword=objectList.at(i).getKeyWords();

		for(string s:objKeyword){
			if(s.compare(keyword)==0){
				objectKey.push_back(objectList.at(i));
			}
		}
	}
	return objectKey;
}
vector <NPC> Room::getNPCAssociatedKeyword(string keyword){
	vector <NPC> NPCkey;
	for(int i=0;i<npcList.size();i++){
		vector <string> npcKeyword=npcList.at(i).getKeyWords();

		for(string s:npcKeyword){
			if(s.compare(keyword)==0){
				NPCkey.push_back(npcList.at(i));
			}
		}
	}
	return NPCkey;
}


// vector <int>Room::lookAtExit(){
// 	vector <int> exits;
// 	for(Door d:doorsList){
// 		exits.push_back(d.getToID());
// 	}
// 	return exits;
// }
string Room::getDescription(){
	return description;
}
vector<Door> Room::getDoorsList() const {
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
void Room::addObject(const Object& o){
	(this->objectList).push_back(o);
}

vector<Object> Room::getObjectList(){

	return this->objectList;
}

void Room::addCharacter(const Character &player) {
	(this->characterList).push_back(player);
}
vector<Character> Room::getCharacterList(){
	return this->characterList;
}
void Room::removeCharacter(const Character& player) {
	for(auto itr = characterList.begin(); itr != characterList.end(); ++itr) {
		if((*itr).equals(player)) {
			characterList.erase(itr);
		}
	}
	//characterList.erase(remove(characterList.begin(), characterList.end(), player), characterList.end());
}

void Room::addNPC(const NPC& npc){
	(this->npcList).push_back(npc);
}
vector<NPC> Room::getNPCList(){

	return this->npcList;
}
bool Room::isRoomAvailable(int direction){
	for(int i=0;i<doorsList.size();i++){
 		if(doorsList[i].getDirectionAsInt(doorsList[i].getDirection()) == direction){
 			return true;
 		}
 	}
 	//cout<<"You cannot go in this direction because this direction does not exist"<<endl;
 	//UserInterface_println("You cannot go in this direction because this direction does not exist");
 	return false;

}


vector<string> Room::getAllDirections() {  // Used for UserInterface
	vector<string> directions;

	for(int i=0;i<doorsList.size();i++){
		Door door = doorsList[i];
		string direction = door.getDirection();

		// if ( find(directions.begin(), directions.end(), direction) != directions.end() ) {

		//cout << "adding: " << direction;

		directions.push_back(direction);
		// }
	}

	return directions;
}



#endif
