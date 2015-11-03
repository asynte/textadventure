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


int main() {
	// roomParser.loadAll();
npcDataInterface npcParser("data/test.yml");
npcParser.loadAll();
npcParser.printAll();

	//World world("midgaard");
	//world.getInformation();
	// vector <Room> rooms=world.getRoomsVector();
	// for(int i=0;i<rooms.size();i++){
	// 	cout<<"room id: "<<rooms.at(i).getID()<<endl;
	// 	vector<Object> object=rooms.at(i).getObjectList();
	// 	cout<<"Object: "<<endl;
	// 	for(Object o:object){
	// 		cout<<o.getName()<<endl;
	// 	}
	// 	cout<<"NPC:"<<endl;
	// 	vector<NPC> npc=rooms.at(i).getNPCList();
	// 	for(NPC n:npc){
	// 		cout<<n.getName()<<endl;
	// 	}
	// }
	return 0;
}	
