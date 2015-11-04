#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/World.h"
#include "userAccountHeaders/Login.h"
#include "networkingHeaders/TCPClient.h"
#include "networkingHeaders/TCPDataflow.h"
#include "networkingHeaders/TCPServer.h"
#include "userInterfaceHeaders/Observer.h"
#include "userInterfaceHeaders/ObserverList.h"
#include "userInterfaceHeaders/Commands.h"
#include "userInterfaceHeaders/UserInterface.h"
#include "pthread.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
int init(){
	roomDataInterface roomParser("data/midgaard.yml");
	objDataInterface objParser("data/midgaard.yml");
	npcDataInterface npcParser("data/midgaard.yml");

}
void printObjectkeywordInRoom(Room room){
	vector<string> keyword=room.getObjectAllKeyWords();
	for(string s:keyword){
		cout<<s<<" ";
	}
}
void printNPCkeywordInRoom(Room room){
	vector<string> keyword=room.getNPCAllKeyWords();
	for(string s:keyword){
		cout<<s<<" ";
	}
}
void printAllkeywordInRoom(Room room){
	vector<string> keyword=room.getAllKeyWords();
	for(string s:keyword){
		cout<<s<<" ";
	}
	cout<<endl;
}
void printAllObjectNameKeyword(Room room,string keyword){
	cout<<"Keyword: "<<keyword<<" associated object name:"<<endl;
	vector<Object> objects=room.getObjectAssociatedKeyword(keyword);
	for(Object o:objects){
		cout<<o.getName()<<endl;
	}
	if(objects.size()==0){
		cout<<"Sorry, there is no keyword "<<keyword<<" in this room Object."<<endl;
	}
}
void printAllNPCNameKeyword(Room room,string keyword){
	cout<<"Keyword: "<<keyword<<" associated object name:"<<endl;
	vector<NPC> NPCs=room.getNPCAssociatedKeyword(keyword);
	for(NPC npc:NPCs){
		cout<<npc.getName()<<endl;
	}
	if(NPCs.size()==0){
		cout<<"Sorry, there is no keyword "<<keyword<<" in this room NPC."<<endl;
	}
}
void printAllExitDoor(Room room){
	vector <int> exits=room.lookAtExit();
	cout<<"Room "<<room.getID() <<" Exit: ";
	for(int i:exits){
		cout<<i<<" ";
	}
	cout<<endl;
}

int main() {


	World world("midgaard");
	int roomrightID=3001;
	int roomfalseID=3000;//no room id is 3000
	if(world.findRoomById(roomrightID)){
		Room room=world.getRoomFindById(3001);
		printObjectkeywordInRoom(room);
		printNPCkeywordInRoom(room);
		printAllkeywordInRoom(room);
		printAllObjectNameKeyword(room,"b");
		printAllObjectNameKeyword(room,"bottle");
		printAllNPCNameKeyword(room,"baker");
		printAllExitDoor(room);

	}
	if(!world.findRoomById(roomfalseID)){
		cout<<"Sorry cannot find room"<<endl;
	}

	
	return 0;
}	
