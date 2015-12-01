#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/World.h"
#include "gameEngineHeaders/GameEngine.h"
#include "gameEngineHeaders/Reset.h"

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
	resetDataInterface resetParser("data/midgaard.yml");

}


int main() {

	World sfu("midgaard");
   	vector <NPC> npcVector=sfu.getNPCsVector();
   	for(int i=0;i<npcVector.size();i++){
   		if(npcVector.at(i).getId()==3011){
   			cout<<npcVector.at(i).getRoomID()<<endl;
            vector<Object> equip=npcVector.at(i).getEquipment();
            cout<<"Equipment id"<<endl;
            for(int i=0;i<equip.size();i++){
               cout<<equip.at(i).getId()<<endl;
            }
   		}
   	}
   	vector <Object> objectVector=sfu.getObjectsVector();
   	for(int i=0;i<objectVector.size();i++){
   		if(objectVector.at(i).getId()==3139){
   			cout<<objectVector.at(i).getRoomID()<<endl;
   		}
   	}
    // Character player("Akame",3001);

	   //  string direction;
	   //  cout<<"Enter direction: " << endl;
	   //  cin >> direction;
	   //  sfu.moveCharacter(player, direction);


	return 0;
}

