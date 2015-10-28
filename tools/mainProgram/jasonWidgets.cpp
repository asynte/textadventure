#include "dataInterfaceHeaders/npcDataInterface.h"
#include "dataInterfaceHeaders/objDataInterface.h"
#include "gameEngineHeaders/gameEngine.h"
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
#include <dirent.h>

using namespace std;

double goToOtherRoom();
string getYAMLFileName(string file);
vector<string> getAllWorld(vector<string> vstring);
//Jason Parse
void parseYamlAndPrint();

//1 to go North, 2 to go South, 3 to go West, 4 to go East, 5 to go Up, 6 to go Down
int main()
{	
    cout << "Success\n";
    return 0;
}
double goToOtherRoom(){
	double doorInput;
	cout<<"Where do you want to go? Please type 1 to go North, 2 to go South, 3 to go West, 4 to go East, 5 to go Up, 6 to go Down"<<endl;
	cin>>doorInput;
	while(cin.fail()||!(doorInput==1 || doorInput==2 ||doorInput==3 ||doorInput==4 || doorInput==5 || doorInput==6)){
		cin.clear();
		cin.ignore(256, '\n');

		cout<<"Please type 1 to go North, 2 to go South, 3 to go West, 4 to go East, 5 to go Up, 6 to go Down"<<endl;
		cin>>doorInput;

	}
	return doorInput;
}
vector<string> getAllWorld(vector<string> vstring){
	vector<string> filenames;

	for(int i=0;i<vstring.size();i++){
		string temp=getYAMLFileName(vstring[i]);
		if(temp.compare("")!=0){
			filenames.push_back(temp);
		}
	}
	return filenames;
}
string getYAMLFileName(string file){
	string substring;
	if(file[file.length()-3]=='y' &&file[file.length()-2]=='m'&&file[file.length()-1]=='l'){
		for(int i=0;i<file.length();i++){
			if(file[i]!='.'){
				substring+=file[i];
			}else{
				break;
			}
		}
	}
	return substring;
	
}
// Jason's Parsing
void parseYamlAndPrint() {
    // loads yaml file
    YAML::Node baseNode = YAML::LoadFile("testyaml.yml");
    YAML::Node npcNode = baseNode["NPCS"];
    vector<NPC> npcVector;

    // go through all NPC blocks on yaml file
    for (int i = 0; i < npcNode.size(); i++) {
            YAML::Node descNode = npcNode[i]["description"];
            string description;
            // concatenate entire description
            for (int j = 0; j < descNode.size(); j++) {
                description += descNode[j].as<string>() + " ";
            }
            YAML::Node longdescNode = npcNode[i]["longdesc"];
            string longDescription;
            // concatenate entire long description
            for (int k = 0; k < longdescNode.size(); k++) {
                longDescription += longdescNode[k].as<string>() + " ";
            }
            NPC tempNPC( npcNode[i]["id"].as<int>(), description, npcNode[i]["keywords"].as<vector<string>>(),
                    longDescription, npcNode[i]["shortdesc"].as<string>() );
            npcVector.push_back(tempNPC);
    }

    YAML::Node objNode = baseNode["OBJECTS"];
    vector<Object> objVector;

    // go through all Object blocks on yaml file
    for (int i = 0; i < objNode.size(); i++) {
            YAML::Node longdescNode = objNode[i]["longdesc"];
            string longDescription;
            // concatenate entire long description
            for (int k = 0; k < longdescNode.size(); k++) {
                longDescription += longdescNode[k].as<string>() + " ";
            }
            Object tempObj( objNode[i]["id"].as<int>(), objNode[i]["extra"].as<vector<string>>(), objNode[i]["keywords"].as<vector<string>>(),
                    longDescription, objNode[i]["shortdesc"].as<string>() );
            objVector.push_back(tempObj);
            
    }
    
    //print npcs and objects
    for (int i = 0; i < npcVector.size(); i++) {
            // print description
            cout << "description: " + npcVector[i].getDesc() << "\n";
            // print NPC id
            cout << "id: " + to_string(npcVector[i].getId()) << "\n";
            // for each string in keyWords vector
            cout << "keywords: ";
            for (string s : npcVector[i].getKeyWords()) {
                    cout << s << " ";
            }
            // print NPC LongDesc
            cout << "\nlongdesc: " + npcVector[i].getLongDesc() << "\n";
            // print NPC name
            cout << "shortdesc: " + npcVector[i].getName() << "\n\n";
    }

    for (int i = 0; i < objVector.size(); i++) {
            // print Object id
            cout << "id: " + to_string(objVector[i].getId()) << "\n";
            // for each string in keyWords vector
            cout << "keywords: ";
            for (string s : objVector[i].getKeyWords()) {
                    cout << s << " ";
            }
            // print Object LongDesc
            cout << "\nlongdesc: " + objVector[i].getLongDesc() << "\n";
            // print Object name
            cout << "shortdesc: " + objVector[i].getName() << "\n\n";
    }
}