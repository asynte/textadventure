#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"

using namespace std;



void cinClear(){
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



void dataEmitter::searchLine (const string& phrase) {
	// string line;z
	// size_t pos;
	// while (getline(outFile, line)) {
	// 	pos = line.find(phrase);


	// }
}

void dataEmitter::printToFile () {	

	for (string s : area) {
		outFile << s;
	}

	for (string s : npcs) {
		outFile << s;
	}

	for (string s : objects) {
		outFile << s;
	}

	for (string s : resets) {
		outFile << s;
	}

	for (string s : rooms) {
		outFile << s;
	}
}

void dataEmitter::emitArea () {

	emitter << YAML::BeginMap;
	emitter << YAML::Key << "AREA";
	emitter << YAML::BeginMap;
	emitter << YAML::Key << "name";
	emitter << YAML::Value << "AreaName";
	emitter << YAML::EndMap;
	emitter << YAML::EndMap;
}


void dataEmitter::emitNPC () {

	// TEST CODE


	emitter << YAML::BeginMap;

	// AREA BEGIN
	emitter << YAML::Key << "AREA";
	emitter << YAML::BeginMap;

	// 	AREA name
	emitter << YAML::Key << "name";
	emitter << YAML::Value << "AreaName";

	emitter << YAML::EndMap;

	// AREA END


	// NPCS BEGIN
	emitter << YAML::Key << "NPCS";
	emitter << YAML::BeginSeq;
	emitter << YAML::BeginMap;

	// 	NPC description
	emitter << YAML::Key << "description";
	emitter << YAML::Value << YAML::BeginSeq 
	<< "The wizard looks old and senile, and yet he looks like a very powerful"
	<< "wizard. He is equipped with fine clothing, and is wearing many fine"
	<< YAML::EndSeq;

	// 	NPC id
	emitter << YAML::Key << "id";
	emitter << YAML::Value << "3000";

	// 	NPC keywords
	emitter << YAML::Key << "keywords";
	emitter << YAML::Value << YAML::BeginSeq << "wizard" << YAML::EndSeq;

	// 	NPC longDescription
	emitter << YAML::Key << "longdesc";
	
	// 	NPC shortDescription
	emitter << YAML::Value << YAML::BeginSeq << "A wizard walks around behind the counter, talking to himself." << YAML::EndSeq;
	emitter << YAML::Key << "shortdesc";
	emitter << YAML::Value << "the wizard";
	
	emitter << YAML::EndMap;
	emitter << YAML::EndSeq;

	// NPCS END


	// OBJECTS BEGIN
	emitter << YAML::Key << "OBJECTS";
	emitter << YAML::BeginSeq;
	emitter << YAML::BeginMap;
	
	// 	OBJECTS extra
	emitter << YAML::Key << "extra";
	
	emitter << YAML::BeginSeq;
	emitter << YAML::BeginMap;

	// 	OBJECTS extra desc
	emitter << YAML::Key << "desc";
	emitter << YAML::Value << YAML::BeginSeq << "It is quite heavy.  The blade is made of some metal that you can't even" << YAML::EndSeq;
	
	// 	OBJECTS extra keywords
	emitter << YAML::Key << "keywords";
	emitter << YAML::Value << YAML::BeginSeq << "axe" << YAML::EndSeq;
	
	emitter << YAML::EndMap;
	emitter << YAML::EndSeq;


	// 	OBJECTS id
	emitter << YAML::Key << "id";
	emitter << YAML::Value << "3000";

	// 	OBJECTS keywords
	emitter << YAML::Key << "keywords";
	emitter << YAML::Value << YAML::BeginSeq << "axe" << YAML::EndSeq;

	// 	OBJECTS long description
	emitter << YAML::Key << "longdesc";
	emitter << YAML::Value << YAML::BeginSeq << "A wizard walks around behind the counter, talking to himself." << YAML::EndSeq;
	
	// 	OBJECTS short description
	emitter << YAML::Key << "shortdesc";
	emitter << YAML::Value << "the wizard";

	emitter << YAML::EndMap;
	emitter << YAML::EndSeq;

	// OBJECTS END

	// RESETS BEGIN
	emitter << YAML::Key << "RESETS";

	emitter << YAML::BeginSeq;
	emitter << YAML::BeginMap;

	// 	RESETS action
	emitter << YAML::Key << "action";
	emitter << YAML::Value << "npc";

	// 	RESETS comment
	emitter << YAML::Key << "comment";
	emitter << YAML::Value << "The executioner";

	// 	RESETS id
	emitter << YAML::Key << "id";
	emitter << YAML::Value << "3011";

	// 	RESETS limit
	emitter << YAML::Key << "limit";
	emitter << YAML::Value << "1";

	// 	RESETS room
	emitter << YAML::Key << "room";
	emitter << YAML::Value << "3001";

	emitter << YAML::EndMap;
	emitter << YAML::EndSeq;

	// RESETS END


	// ROOMS BEGIN
	emitter << YAML::Key << "ROOMS";

	emitter << YAML::BeginSeq;
	emitter << YAML::BeginMap;

	// 	RESETS description
	emitter << YAML::Key << "desc";
	emitter << YAML::Value << YAML::BeginSeq << "It is quite heavy.  The blade is made of some metal that you can't even" << YAML::EndSeq;

	// 	RESETS door1
	emitter << YAML::Key << "doors";

	emitter << YAML::BeginSeq;
	emitter << YAML::BeginMap;

	// 	RESETS door1 description
	emitter << YAML::Key << "desc";
	emitter << YAML::Value << YAML::BeginSeq << "It is quite heavy.  The blade is made of some metal that you can't even" << YAML::EndSeq;

	// 	RESETS door1 direction
	emitter << YAML::Key << "dir";
	emitter << YAML::Value << "north";

	// 	RESETS door1 keywords
	emitter << YAML::Key << "keywords";
	emitter << YAML::Value << "[]";
	
	// 	RESETS door1 to	
	emitter << YAML::Key << "to";
	emitter << YAML::Value << "3054";

	emitter << YAML::EndMap;

	emitter << YAML::BeginMap;

	// 	RESETS door2 description	
	emitter << YAML::Key << "desc";
	emitter << YAML::Value << YAML::BeginSeq << "You see the temple" << YAML::EndSeq;

	// 	RESETS door2 direction
	emitter << YAML::Key << "dir";
	emitter << YAML::Value << "north";

	// 	RESETS door2 keywords
	emitter << YAML::Key << "keywords";
	emitter << YAML::Value << "[]";
	
	// 	RESETS door2 TO
	emitter << YAML::Key << "to";
	emitter << YAML::Value << "3057";
	

	emitter << YAML::EndMap;
	emitter << YAML::EndSeq;

	// 	RESETS extended 
	emitter << YAML::Key << "extended_descriptions";
	emitter << YAML::BeginSeq;
	emitter << YAML::BeginMap;

	// 	RESETS extended description
	emitter << YAML::Key << "desc";
	emitter << YAML::Value << YAML::BeginSeq << "You see the temple" << YAML::EndSeq;

	// 	RESETS extended keywords
	emitter << YAML::Key << "keywords";
	emitter << YAML::Value << YAML::BeginSeq << "Plaque" << YAML::EndSeq;

	emitter << YAML::EndMap;
	emitter << YAML::EndSeq;

	// 	RESETS ID
	emitter << YAML::Key << "id";
	emitter << YAML::Value << "3001";

	// 	RESETS name
	emitter << YAML::Key << "name";
	emitter << YAML::Value << "Temple of Gardgard";

	// RESETS END
	emitter << YAML::EndMap;

	outFile << emitter.c_str();
}
