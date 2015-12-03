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

void testSpellShop(Character &player, int currentLocation) {
   player.setLevel(99);
   SpellShop shop("Welcome to the Spell Shop", currentLocation);
   shop.shopMenu(player);
}

void showPlayerInformation(Character player){

   player.printStatus();
}

void moveLocation(Character &player, World &world){
   string input;
   cout<<"Which direction you want to move?"<<endl;
   cout<<"left, right, forward, back, up, down or exit"<<endl;
   
   while(true){
      cin>>input;
      input=convertToLower(input);
      if(input=="left" || input=="right" || input=="forward" || input=="back"||input=="up"||input=="down"){
         world.moveCharacter(player,input);
         break;
      }else if(input=="exit"){
         break;
      }else{
         cout<<"Please input left, right, forward, back, up, down or exit"<<endl;
      }
   }

}

void attackNPC(Character &player,Room &room){
   cout << "Current room ID: " + to_string(player.getLocation()) << endl;
   player.increaseExp(300);
   player.updateLevel();
   player.printStatus();
   int index=0;
   string name;
   if(room.getNPCList().size()==1){
      index=0;
   }else if(room.getNPCList().size()>1){
      cout<<"Who you want to attack?"<<endl;
      for(NPC n:room.getNPCList()){
         cout<<n.getName()<<endl;
      }
      cin>>name;
      for(int i=0; i<room.getNPCList().size();i++){
         if(room.getNPCList().at(i).getName()==name){
            index=i;
            break;
         }
      }
      
   }else{
      cout<<"There is no NPC"<<endl;
   }
   if(index<room.getNPCList().size()){
         player.examine(room.getNPCList().at(index));
         player.attack(room.getNPCList().at(index));
   }
}

void examineNPC(Character &player,Room &room){
   cout << "Current room ID: " + to_string(player.getLocation()) << endl;
   int index=0;
   string name;
   if(room.getNPCList().size()==1){
      index=0;
   }else if(room.getNPCList().size()>1){
      cout<<"Who you want to examine?"<<endl;
      for(NPC n:room.getNPCList()){
         cout<<n.getName()<<endl;
      }
      cin>>name;
      for(int i=0; i<room.getNPCList().size();i++){
         if(room.getNPCList().at(i).getName()==name){
            index=i;
            break;
         }
      }
      
   }else{
      cout<<"There are no NPCs"<<endl;
   }
   if(index<room.getNPCList().size()){
         player.examine(room.getNPCList().at(index));
         player.interact(room.getNPCList().at(index));
   }
}

void pickupObject(Character &player, Room &room) {
   int index=0;
   string name;
   if(room.getObjectList().size()==1){
      index=0;
   }else if(room.getObjectList().size()>1){
      cout<<"What do you want to pick up?"<<endl;
      for(auto n:room.getObjectList()){
         cout<<n.getName()<<endl;
      }
      cin>>name;
      for(int i=0; i<room.getObjectList().size();i++){
         if(room.getObjectList().at(i).getName()==name){
            index=i;
            break;
         }
      }
      
   }else{
      cout<<"There are no objects."<<endl;
   }
   if(index<room.getObjectList().size()){
         player.interact(room.getObjectList().at(index));
   }
}

void equipItem(Character &player) {
   player.showInventory();
   cout << "What do you want to equip?" << endl;
   string item1;
   string item2;
   cin >> item1;
   cin >> item2;
   string item = item1 + " " + item2;
   for (auto thing : player.getInventory()) {
      if (thing.getName() == item) {
         player.equip(thing);
      }
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
      cout<<"Sorry, there is no Object " << keyword << " in this room"<<endl;
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
      cout<<"Sorry, there is no NPC " << keyword << " in this room"<<endl;
   }
}

void turnDirection(Character &player){
   string input;
   cout<<"Which direction you want to face?"<<endl;
   cout<<"left, right, back or exit"<<endl;
   cin>>input;
   input=convertToLower(input);
   while(true){
      if(input=="left" || input=="right" || input=="back"){
         player.turn(input);
         break;
      }else if(input=="exit"){
         break;
      }else{
         cout<<"Please input left, right, back or exit"<<endl;
      }
   }
}

string playerName(){
   string input;
   cout<<"Enter character name:"<<endl;
   cin>>input;
   return input; 
}

string worldCreation(){

   string worldName;
   cout << "Welcome to World Creation!" << endl;
   cout << "Please enter your world name: " << endl;
   
   cin >> worldName;
   dataEmitter emit{worldName};
   cin.clear();

   emit.startEmittingToYamlFile(worldName);

   return worldName;
}

string chooseWorld(){
   string input = "";
   while(true){
      cout<<"What would you like to do?"<<endl;
      cout<<"1. Go to an existing world"<<endl;
      cout<<"2. Create a new world"<<endl;
      cin>>input;
      
      if(input=="1" || input=="2"){
         break;
      }
   }
   if(input=="1"){
      cout<<"What world do you want to play in? \nPossible options are: midgaard or smurf"<<endl;
      while(true){
         cin >> input;
         input = convertToLower(input);
         if(input == "midgaard" || input == "smurf"){
            break;
         }
         else{
            cout << "Please input midgaard or smurf" <<endl;
         }
      }
   }
   else if(input == "2"){
      input = worldCreation();
      cin.clear();
   }
   return input;
}

void mainMenu(){
   cout<<"\n\nChoose an action:"<<endl;
   cout<<"1. Spell Shop"<<endl;
   cout<<"2. Player Information"<<endl;
   cout<<"3. Move"<<endl;
   cout<<"4. Turn"<<endl;
   cout<<"5. Check Inventory"<<endl;
   cout<<"6. Examine Room"<<endl;
   cout<<"7. Search Objects"<<endl;
   cout<<"8. Search NPC"<<endl;
   cout<<"9. Attack NPC"<<endl;
   cout<<"10. Pick up Object"<<endl;
   cout<<"11. Examine NPC"<<endl;
   cout<<"12. Equip Object"<<endl;
   cout<<"13. Exit Game"<<endl;
   cout<<"\n\n";
}

int main() {

   string playName = playerName();
   string worldName = chooseWorld();
   World world(worldName);
   while(world.getRoomsVector().size() == 0){
      string worldName = chooseWorld();
   }
   Character player(playName, world.getRoomsVector().at(0).getID());
   
   // World world("midgaard");
   // Character player("gfd", 3001);
   while(true){
      Room room=world.getCurrentRoom(player);
         mainMenu();
         cin>>input;
         if(input=="1"){
         	 cin.clear();
            testSpellShop(player, world.getRoomsVector().at(0).getID());
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
         }else if (input=="10"){
            pickupObject(player, room);
         }else if (input=="11"){
            examineNPC(player,room);
         }else if (input=="12"){
            equipItem(player);
         }else if(input=="13"){
            break;
         }else{
            cout<<"Incorrect Input, Please enter a number between 1 and 13"<<endl;
         }
   }

   

	return 0;
}

