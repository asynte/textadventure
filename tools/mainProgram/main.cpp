#include "dataInterfaceHeaders/dataInterfaceBase.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/World.h"
#include "gameEngineHeaders/GameEngine.h"
#include "gameEngineHeaders/Spell.h"
#include "gameEngineHeaders/OffSpell.h"
#include "gameEngineHeaders/DefSpell.h"
#include "gameEngineHeaders/SpellShop.h"
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
string input;
string inputKeyWords(){
   string keywords;
   cout<<"input keywords: ";
   cin>>keywords;
   return keywords;
}
int init(){
	roomDataInterface roomParser("data/midgaard.yml");
	objDataInterface objParser("data/midgaard.yml");
	npcDataInterface npcParser("data/midgaard.yml");
	resetDataInterface resetParser("data/midgaard.yml");
   spellDataInterface spellParser("data/spellstest.yml");
}
string convertToLower(string input){
   string result;
   for(int i=0;i<input.length();i++){
      result+=tolower(input[i]);
   }
   return result;
}
void testSpellShop(Character player) {
   player.setLevel(99);
   SpellShop shop("Welcome to the Spell Shop", 10000);
   shop.shopMenu(player);
}

void showPlayerInformation(Character player){

   player.printStatus();
}

void moveLocation(Character &player, World &world){
   string input;
   cout<<"Which direction you want to move."<<endl;
   cout<<" Left, right, forward, back, up,down or exit"<<endl;
   
   while(true){
      cin>>input;
      input=convertToLower(input);
      if(input=="left" || input=="right" || input=="forward" || input=="back"||input=="up"||input=="down"){
         world.moveCharacter(player,input);
         break;
      }else if(input=="exit"){
         break;
      }else{
         cout<<"Please input Left, right, forward, back, up,down or exit"<<endl;
      }
   }

}
void attackNPC(Character &player,Room &room){
   cout << "Current room ID: " + to_string(player.getLocation()) << endl;
   player.increaseExp(300);
   player.updateLevel();
   player.printStatus();
   int index=0;
   if(room.getNPCList.size()==1){
      index=0;
   }else{
      cout<<"Who you want to attack"<<endl;
      for(NPC n:room.getNPCList()){
         cout<<n.getName()<<endl;
      }
      string name;
      cin>>name;
      for(int i=0; i<room.getNPCList().size();i++){
         if(room.getNPCList().at(i).getName()==name){
            index=i;
            break;
         }
      }
      
   }
   if(index<room.getNPCList().size()){
         player.examine(room.getNPCList().at(index));
         player.attack(room.getNPCList().at(index));
   }else{
      cout<<"the name of npc does not exist!!!!!"<<endl;
   }
}
void printAllkeywordInRoom(Room room){
   vector<string> keyword=room.getAllKeyWords();
   for(string s:keyword){
      cout<<s<<" ";
   }
   cout<<endl;
}

void printAllObjectNameKeyword(Room room){
   string keyword=inputKeyWords();
   cout<<"Keyword: "<<keyword<<" associated object name:"<<endl;
   vector<Object> objects=room.getObjectAssociatedKeyword(keyword);
   for(Object o:objects){
      cout<<o.getName()<<endl;
   }
   if(objects.size()==0){
      cout<<"Sorry, there is no keyword "<<keyword<<" in this room Object."<<endl;
   }
}
void printAllNPCNameKeyword(Room room){
   string keyword=inputKeyWords();
   cout<<"Keyword: "<<keyword<<" associated npc name:"<<endl;
   vector<NPC> NPCs=room.getNPCAssociatedKeyword(keyword);
   for(NPC npc:NPCs){
      cout<<npc.getName()<<endl;
   }
   if(NPCs.size()==0){
      cout<<"Sorry, there is no keyword "<<keyword<<" in this room NPC."<<endl;
   }
}

void turnDirection(Character &player){
   string input;
   cout<<"Which direction you want to turn."<<endl;
   cout<<" Left, right, back or exit"<<endl;
   cin>>input;
   input=convertToLower(input);
   while(true){
      if(input=="left" || input=="right" || input=="back"){
         player.turn(input);
         break;
      }else if(input=="exit"){
         break;
      }else{
         cout<<"Please input Left, right, back or exit"<<endl;
      }
   }
}

string playerName(){
   string input;
   cout<<"Please input your name"<<endl;
   cin>>input;
   return input; 
}
string chooseWorld(){
   string input;
   while(true){
      cout<<"Input the choice."<<endl;
      cout<<"1.go to exist world"<<endl;
      cout<<"2.create a new world"<<endl;
      cin>>input;
      if(input=="1" || input=="2"){
         break;
      }
   }
   if(input=="1"){
      cout<<"which world you want to go. midgaard or smurf"<<endl;
      while(true){
         cin>>input;
         input=convertToLower(input);
         if(input=="midgaard" || input=="smurf"){
            return input;
         }else{
            cout<<"Please input midgaard or smurf"<<endl;
         }
      }
   }else{

      //Sonny's , you should return your world name
   }
}

void mainMenu(){
   cout<<"\n\n\nYou can choose below action"<<endl;
   cout<<"1.Shop"<<endl;
   cout<<"2.My information."<<endl;
   cout<<"3.Move"<<endl;
   cout<<"4.Turn"<<endl;
   cout<<"5.Look At my inventory"<<endl;
   cout<<"6.Look at all keyword  in this room"<<endl;
   cout<<"7.Search keyword of object in this room"<<endl;
   cout<<"8.Search keyword of NPC in this room"<<endl;
   cout<<"9.Attack Npc"<<endl;
   cout<<"10.Exit"<<endl;
   cout<<"\n\n";
}

int main() {
   string playName=playerName();
   string worldName=chooseWorld();
   World world(worldName);
   Character player(playName, world.getRoomsVector().at(0).getID());
   // World world("midgaard");
   // Character player("gfd", 3001);
   while(true){
      Room room=world.getCurrentRoom(player);
      mainMenu();
      cin>>input;
      if(input=="1"){
         testSpellShop(player);
      }else if(input=="2"){
         showPlayerInformation(player);
      }else if(input=="3"){
         moveLocation(player,world);
      }else if(input=="4"){
         turnDirection(player);
      }else if(input=="5"){
         player.showInventory();
      }else if(input=="6"){
         printAllkeywordInRoom(room);
      }else if(input=="7"){
         printAllObjectNameKeyword(room);
      }else if(input=="8"){
         printAllNPCNameKeyword(room);
      }else if(input=="9"){
         attackNPC(player,room);
      }else if(input=="10"){
         break;
      }

   }


	return 0;
}

