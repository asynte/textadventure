
#include <fstream>
#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "dataInterfaceHeaders/dataInterfaceBase.h"

using namespace std;


void cinIgnore() {
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
}

template<typename T>
	T const get () {
		T result;
		std::cin >> result;
		return result;
}

template<typename T>
T const getLine () {
	T result;
	std::getline(std::cin, result);
	return result;
}

void const dataEmitter::getLineWhile () {
	string result;
	while (std::getline(std::cin, result)) {
		if (result == "-1") {
			break;
		}

		emitter << result;
	}
}


void dataEmitter::emitMapValue () {
	emitter << YAML::Value << getLine<string>();

}

void dataEmitter::emitOneSequenceValue () {
	emitter << YAML::Value << YAML::BeginSeq << getLine<string>() << YAML::EndSeq;

}

void dataEmitter::emitSequenceValues () {
	emitter << YAML::Value << YAML::BeginSeq;
	getLineWhile();
	emitter << YAML::EndSeq;
}

void dataEmitter::setID ( int& ID ) {
	emitter << YAML::Value << ID;
	ID++;

}

void dataEmitter::loopEmit ( int & loopCount, void (*setFunction)() ) {
// 	// use this method every time getLine is used after cin
// 	cinIgnore();

// 	if ( loopCount == 0 ) {
// 		emitter << YAML::Value << "[]";
// 	}

// 	else {
// 		emitter << YAML::BeginSeq;

// 		while ( loopCount != 0 ) {	
// 			(*setFunction)();
// 			loopCount--;
// 		}

// 		emitter << YAML::EndSeq;
// 	}
}

void dataEmitter::searchLine (const string& phrase) {
	// string line;
	// size_t pos;
	// while (getline(outFile, line)) {
	// 	pos = line.find(phrase);


	// }
}

void dataEmitter::printToFile () {	

	emitter << YAML::EndMap;
	outFile << emitter.c_str();

}


void dataEmitter::startArea () {
	// AREA BEGIN
	emitter << YAML::Key << "AREA";
	emitter << YAML::BeginMap;
}

void dataEmitter::setAreaName (string inputName) {
	emitter << YAML::Key << "name";
	//cout << "What is the name of the Area? ";
	emitter << YAML::Value << inputName;
	//emitMapValue();
}

void dataEmitter::endArea () {
	// AREA END
	emitter << YAML::EndMap;
}

void dataEmitter::setNPCDescription () {
	cout << "What is the description of the NPC (-1 to finish)? ";
	emitSequenceValues();
}

void dataEmitter::setNPCKeyWords () {
	cout << "What are the keywords of the NPC (-1 to finish)? ";
	emitSequenceValues();
}

void dataEmitter::setNPCLongDescription() {
	cout << "What is the long description of the NPC? ";
	emitOneSequenceValue();
}

void dataEmitter::setNPCShortDescription() {
	cout << "What is the short description of the NPC? ";
	emitMapValue ();
}

void dataEmitter::startSequence ( const string& s) {
	// NPCS BEGIN
	emitter << YAML::Key << s;
	emitter << YAML::BeginSeq;	
}

void dataEmitter::endSequence () {
	emitter << YAML::EndSeq;
}

void dataEmitter::emitNPC () {
	emitter << YAML::BeginMap;

	// 	NPC description
	emitter << YAML::Key << "description";
	setNPCDescription();

	// 	NPC id
	emitter << YAML::Key << "id";
	setID(npcID);

	// 	NPC keywords
	emitter << YAML::Key << "keywords";
	setNPCKeyWords();

	// 	NPC longDescription
	emitter << YAML::Key << "longdesc";
	setNPCLongDescription();

	// 	NPC shortDescription
	emitter << YAML::Key << "shortdesc";
	setNPCShortDescription();

	emitter << YAML::EndMap;

}

void dataEmitter::setObjectExtraDescription() {

	cout << "What is the description of the object (-1 to finish)? ";
	emitSequenceValues();
}

void dataEmitter::setObjectKeyWords() {

	cout << "What are the keywords of the object (-1 to finish)? ";
	emitSequenceValues();
}

void dataEmitter::setObjectExtra() {
	
	emitter << YAML::BeginMap;


	// 	OBJECTS extra desc
	emitter << YAML::Key << "desc";
	setObjectExtraDescription();
	

	// 	OBJECTS extra keywords
	emitter << YAML::Key << "keywords";
	setObjectKeyWords();

	emitter << YAML::EndMap;
}

void dataEmitter::objectExtraLoop () {
	int extraDescCount;
	cout << "How many extra descriptions for this object? ";
	std::cin >> extraDescCount;

	// use this method every time getLine is used after cin
	cinIgnore();

	if ( extraDescCount == 0 ) {
		emitter << YAML::Value << "[]";
	}

	else {
		emitter << YAML::BeginSeq;

		while ( extraDescCount != 0 ) {	
			setObjectExtra();
			extraDescCount--;
		}

		emitter << YAML::EndSeq;
	}
}

void dataEmitter::setObjectLongDescription () {
	cout << "What is the long description of the object? ";
	emitOneSequenceValue();
}

void dataEmitter::setObjectShortDescription() {
	cout << "What is the short description of the object? ";
	emitMapValue ();
}

void dataEmitter::emitObject () {
	emitter << YAML::BeginMap;
	
	// 	OBJECTS extra
	emitter << YAML::Key << "extra";

	objectExtraLoop();

	// 	OBJECTS id
	emitter << YAML::Key << "id";
	setID(objID);

	// 	OBJECTS keywords
	emitter << YAML::Key << "keywords";
	setObjectKeyWords();

	// 	OBJECTS long description
	emitter << YAML::Key << "longdesc";
	setObjectLongDescription();

	// 	OBJECTS short description
	emitter << YAML::Key << "shortdesc";
	setObjectShortDescription();

	emitter << YAML::EndMap;

}

void dataEmitter::setResetAction () {
	cout << "What is the action of the reset? ";
	emitMapValue ();
}

void dataEmitter::setResetComment () {
	cout << "What is the comment of the reset? ";
	emitMapValue ();
}

void dataEmitter::setResetLimit () {
	cout << "What is the limit of the reset? ";
	emitMapValue ();
}

void dataEmitter::setResetRoom () {
	cout << "What is the room of the reset? ";
	emitMapValue ();
}

void dataEmitter::emitReset () {
	
	// RESETS BEGIN
	emitter << YAML::BeginMap;

	// 	RESETS action
	emitter << YAML::Key << "action";
	setResetAction();

	// 	RESETS comment
	emitter << YAML::Key << "comment";
	setResetComment();

	// 	RESETS id
	emitter << YAML::Key << "id";
	setID (resetID);

	// 	RESETS limit
	emitter << YAML::Key << "limit";
	setResetLimit();

	// 	RESETS room
	emitter << YAML::Key << "room";
	setResetRoom();

	emitter << YAML::EndMap;

	// RESETS END

}


void dataEmitter::setRoomDescription () {
	cout << "What is the description of the room (-1 to finish)? ";
	emitSequenceValues();

}

void dataEmitter::setDoorDescription () {
	cout << "What is the description of the door (-1 to finish)? ";
	emitSequenceValues();

}

void dataEmitter::setDoorDirection () {
	cout << "What is the direction of the door? ";
	emitMapValue ();
}

void dataEmitter::setDoorKeyWords () {
	cout << "What are the keywords of the door (-1 to finish)? ";
	emitSequenceValues();

}

void dataEmitter::setDoorTo() {
	cout << "What is the TO of the door? ";
	emitMapValue ();
}

void dataEmitter::setRoomDoor () {
	emitter << YAML::BeginMap;

	// 	ROOM door description
	emitter << YAML::Key << "desc";
	setDoorDescription();

	// 	ROOM door direction
	emitter << YAML::Key << "dir";
	setDoorDirection();

	// 	ROOM door keywords
	emitter << YAML::Key << "keywords";
	setDoorKeyWords();
	
	// 	ROOM door to	
	emitter << YAML::Key << "to";
	setDoorTo();

	emitter << YAML::EndMap;
}

void dataEmitter::roomDoorLoop () {
	int roomDoorCount;
	cout << "How many doors for this room? ";
	std::cin >> roomDoorCount;

	// use this method every time getLine is used after cin
	cinIgnore();

	if ( roomDoorCount == 0 ) {
		emitter << YAML::Value << "[]";
	}

	else {
		emitter << YAML::BeginSeq;

		while ( roomDoorCount != 0 ) {	
			setRoomDoor();
			roomDoorCount--;
		}

		emitter << YAML::EndSeq;
	}

}

void dataEmitter::setExtendedDescription () {
	cout << "What is the extended description of the room (-1 to finish)? ";
	emitSequenceValues();

}

void dataEmitter::setExtendedKeyWords () {
	cout << "What are the extended keywords of the room (-1 to finish)? ";
	emitSequenceValues();

}

void dataEmitter::setRoomExtended () {
	emitter << YAML::BeginMap;

	// 	ROOM extended description
	emitter << YAML::Key << "desc";
	setExtendedDescription();

	// 	ROOM extended keywords
	emitter << YAML::Key << "keywords";
	setExtendedKeyWords();

	emitter << YAML::EndMap;
}

void dataEmitter::roomExtendedLoop () {
	int roomExtendedCount;
	cout << "How many extended descriptions for this room? ";
	std::cin >> roomExtendedCount;

	// use this method every time getLine is used after cin
	cinIgnore();

	if ( roomExtendedCount == 0 ) {
		emitter << YAML::Value << "[]";
	}

	else {
		emitter << YAML::BeginSeq;

		while ( roomExtendedCount != 0 ) {	
			setRoomExtended();
			roomExtendedCount--;
		}

		emitter << YAML::EndSeq;
	}
}

void dataEmitter::setRoomName () {
	cout << "What is the name of the room? ";
	emitMapValue ();
}

void dataEmitter::emitRoom () {
	// ROOMS BEGIN
	emitter << YAML::BeginMap;

	// 	ROOM description
	emitter << YAML::Key << "desc";
	setRoomDescription();

	// 	ROOM door
	emitter << YAML::Key << "doors";
	roomDoorLoop();

	//  ROOM extended descriptions
	emitter << YAML::Key << "extended_descriptions";
	roomExtendedLoop();

	// 	ROOM ID
	emitter << YAML::Key << "id";
	setID(roomID);

	// 	ROOM name
	emitter << YAML::Key << "name";
	setRoomName();

	// ROOM END
}



void dataEmitter::startEmittingToYamlFile (string inputName) {



	startArea();
	setAreaName(inputName);
	endArea();

	bool creationDone = false;

	while (!creationDone){
		cout << "\nWorld Name: " << inputName << endl;

		cout << "Please select your next creation: " << endl;
		cout << "1.NPC Creation \n2.Object Creation \n3.Room Creation \n4.Exit World Creation\n" << endl;

		string creationChoice;
		cin >> creationChoice;

		bool done = false;

		if (creationChoice == "1"){
			startSequence("NPCS");
			while (!done)  {
				emitNPC();

				cout << "Add another NPC (y/n)? "; 
				if (getLine<string>() == "n" )
					done = true;
				}
			endSequence();		
		}
		else if (creationChoice == "2"){
			startSequence("OBJECTS");
			while (!done)  {
				emitObject();

				cout << "Add another Object (y/n)? "; 
				if (getLine<string>() == "n" ) {
					done = true;
				}		
			}
			endSequence();	
		}
		else if (creationChoice == "3"){
			startSequence("ROOMS");
			while (!done)  {
				emitRoom();
				cout << "Add another Room (y/n)? "; 
				if (getLine<string>() == "n" ) {
					done = true;
				}	
			}
			endSequence();
		}
		else if (creationChoice == "4"){
			creationDone = true;
			printToFile();
		}
	}
	// cout << "\nEmitting NPC \nPress Enter to Start";
	// getLine<string>();
	// startSequence("NPCS");
	// while (!done)  {
	// 	emitNPC();

	// 	cout << "Add another NPC (y/n)? "; 
	// 	if (getLine<string>() == "n" )
	// 		done = true;
	// 	}
	// endSequence();




	// done = false;
	// cout << "\n\nEmitting Objects\n Press Enter to Start";
	// getLine<string>();
	// startSequence("OBJECTS");
	// while (!done)  {
	// 	emitObject();

	// 	cout << "Add another Object (y/n)? "; 
	// 	if (getLine<string>() == "n" ) {
	// 		done = true;
	// 	}		
	// }
	// endSequence();

/*
	done = false;
	cout << "\n\nEmitting Resets\n Press Enter to Start";
	getLine<string>();
	startSequence("RESETS");
	while (!done)  {
		emitReset();

		cout << "Add another Reset (y/n)? "; 
		if (getLine<string>() == "n" ) {
			done = true;
		}	
	}
	endSequence();

*/
	// done = false;
	// cout << "\n\nEmitting Rooms\n Press Enter to Start";
	// getLine<string>();
	// startSequence("ROOMS");
	// while (!done)  {
	// 	emitRoom();
	// 	cout << "Add another Room (y/n)? "; 
	// 	if (getLine<string>() == "n" ) {
	// 		done = true;
	// 	}	
	// }
	// endSequence();

	

}
