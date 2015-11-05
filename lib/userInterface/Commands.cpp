#ifndef _COMMANDS_CPP_
#define _COMMANDS_CPP_
#include "userInterfaceHeaders/Commands.h"

static const string SPACER = "  ";

typedef void (*functionReferenceVoid)(void);
typedef void (*functionReferenceString)(const string&);
typedef void (*functionReferenceStrings)(const vector<string>&);
static map<string, functionReferenceVoid> functionMapVoid;
static map<string, functionReferenceString> functionMapString;
static map<string, functionReferenceStrings> functionMapStrings;

static vector<string> options;
static map<string, string> menuCommands;
static map<string, string> gameCommands;

static bool isRuntimeMatch = false;

static vector<string> getMatches(const vector<string> &options, const string &input, int n) {
	vector<string> matches;

	for(auto itr = options.begin(); itr != options.end(); ++itr) {
		string str = itr->substr(0,n);

		if (input == str) {
			matches.push_back(*itr);
		}
	}

	return matches;
}


vector<string> Commands_getMatches(const string &input, int n) {
	vector<string> matches = getMatches(options, input, n);

	/*if (matches.size() == 0) {
		isRuntimeMatch = true;
		return getMatches(UserInterface_getPossibleDirections(), input, n);
	}*/

	isRuntimeMatch = false;
	return matches;
}


bool Commands_isValidToken(const string &token) {
	auto searchResult = find(options.begin(), options.end(), token);
	return (searchResult == options.end()) == 0;
}

bool isVoidFunction(const string &str) {
	return functionMapVoid.find(str) != functionMapVoid.end();
}

bool isStringFunction(const string &str) {
	return functionMapString.find(str) != functionMapString.end();
}

bool isGameCommand(const string &str) {
	return gameCommands.find(str) != gameCommands.end();
}

bool isMenuCommand(const string &str) {
	return menuCommands.find(str) != menuCommands.end();
}

static void move(const string &str) {
	UserInterface_println("move");

	vector<string> directions = UserInterface_getPossibleDirections();

	if ( find(directions.begin(), directions.end(), str) != directions.end() ) {
		UserInterface_println("invalid direction: " + str);
	}
}

static void move(void) {
	vector<string> directions = UserInterface_getPossibleDirections();

	UserInterface_println("requires a direction to move to!");
	UserInterface_println(SPACER + "\"move <direction>\"");
	UserInterface_println(SPACER + "use \"help move\" to see more details");
	UserInterface_println(SPACER + "possible directions are:");

	for(int i = 0; directions.size() > i; ++i) {
		UserInterface_println(SPACER + SPACER + directions.at(i));
	}
}

static void quit(void){
	string result;

	UserInterface_println("quit game?");
	UserInterface_println(SPACER +"y/n");

	result = UserInterface_getUserInput();

	if ((result.substr(0,1) == "y") == true) {
		UserInterface_println("quitting");
		UserInterface_quit();
	}
}

static void help(void){ 
	UserInterface_println("use \"help <command>\" to see details about a command");
}

static void dummyCommand(void){ 
	UserInterface_println("null command");
}

static void help(const string &str){
	if (Commands_isValidToken(str)) {
		UserInterface_println(str + ":");
		if (isMenuCommand(str)) {
			UserInterface_println(SPACER + menuCommands.at(str));
		} else if (isGameCommand(str)) {
			UserInterface_println(SPACER + gameCommands.at(str));
		} else {

		}
	} else {
		UserInterface_invalidInput(str);
	}
}

static void listCommand(void){ 
	UserInterface_println("Menu Commands:");
	for(auto itr = menuCommands.begin(); itr != menuCommands.end(); ++itr) {
		UserInterface_println(SPACER + itr->first);// endl;
	}

	UserInterface_println("");
	UserInterface_println("Possible Game Commands:");
	for(auto itr = gameCommands.begin(); itr != gameCommands.end(); ++itr) {
		UserInterface_println(SPACER + itr->first);
	}
}





void Commands_initiate() {
	//no arguement functions
    functionMapVoid["quit"] = quit;
    functionMapVoid["list"] = listCommand;
    functionMapVoid["help"] = help;
    functionMapVoid["move"] = move;
    functionMapVoid["login"] = move;
    functionMapVoid["testworld"] = dummyCommand;

	//single arguement functions
    functionMapString["help"] = help;
    functionMapString["move"] = move;

	//menu command helper descriptions
	menuCommands["quit"] = "prompts to exits the game";
	menuCommands["list"] = "displays all menuCommands that are currently available";
	menuCommands["help"] = "displays additional info about a command\n"
		 + SPACER +"help <command>";
	menuCommands["login"] = "displays additional info about a command\n"
		 + SPACER +"help <command>";

	//game command helper descriptions
	gameCommands["move"] = "move to a different region in the game\n"
		 + SPACER +"move <direction>\n";

	for(auto itr = functionMapVoid.begin(); itr != functionMapVoid.end(); ++itr) {
		options.push_back(itr->first);
	}

	/*for(auto itr = menuCommands.begin(); itr != menuCommands.end(); ++itr) {
		options.push_back(itr->first);
	}
	for(auto itr = gameCommands.begin(); itr != gameCommands.end(); ++itr) {
		options.push_back(itr->first);
	}*/


	sort(options.begin(), options.end());
}

void Commands_callFunction(const string &funcName) {
	if (isRuntimeMatch) {
		return;
	}

	UserInterface_notifyListeners(funcName);

	functionMapVoid[funcName]();
}

void Commands_callFunction(const string &funcName, const string &funcArgs) {
		vector<string> tokens = {funcName, funcArgs};
		UserInterface_notifyListeners(tokens);

		functionMapString[funcName](funcArgs);
}

void Commands_callFunction(const string &funcName, const vector<string> &funcArgs) {
	int arguCount = funcArgs.size();

	if (isRuntimeMatch) {
		return;
	}

	if (isVoidFunction(funcName) && !isStringFunction(funcName)) {
		Commands_callFunction(funcName);
	} else if (isStringFunction(funcName) && arguCount == 2) {
		Commands_callFunction(funcName,funcArgs.back());
	} else {
		string str;

		for(auto itr = funcArgs.begin(); itr != funcArgs.end(); ++itr) {
			str = str + (*itr);
			str = str + " ";
		}

		UserInterface_invalidInput(str);
	}
}

#endif


