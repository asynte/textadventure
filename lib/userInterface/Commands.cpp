#include "userInterfaceHeaders/Commands.h"

#ifndef _COMMANDS_CPP_
#define _COMMANDS_CPP_

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


vector<string> Commands_getMatches(const string &input, int n) {
	vector<string> matches;

	for(auto itr = options.begin(); itr != options.end(); ++itr) {
		string str = itr->substr(0,n);

		if (input == str) {
			matches.push_back(*itr);
		}
	}

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
}

static void move(void) {
	UserInterface_println("requires a direction to move to!");
	UserInterface_println(SPACER + "\"move <direction>\"");
	UserInterface_println(SPACER + "use \"help move\" to see more details");
}

static void quit(void){
	string result;

	UserInterface_println("quit game?");
	UserInterface_println(SPACER +"y/n");

	//UserInterface_ignoreNext();
	//cin >> result;
	result = UserInterface_getUserInput();

	if ((result == "y") == true) {
		UserInterface_println("quitting");
		UserInterface_quit();
	}
}

static void help(void){ 
	UserInterface_println("use \"help <command>\" to see details about a command");
}

static void dummyCommand(void){ 
	//UserInterface_println("null command");
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

static void list(void){ 
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
    functionMapVoid["list"] = list;
    functionMapVoid["help"] = help;
    functionMapVoid["move"] = move;
    functionMapVoid["login"] = dummyCommand;
    functionMapVoid["register"] = dummyCommand;

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
		 + SPACER +"move <direction>\n"
		 + SPACER +"possible directions are:\n"
		 + SPACER + SPACER + "\"north\"\n"
		 + SPACER + SPACER + "\"south\"\n"
		 + SPACER + SPACER + "\"east\"\n"
		 + SPACER + SPACER + "\"west\"\n"
		 + SPACER + SPACER + "\"up\"\n"
		 + SPACER + SPACER + "\"down\"";

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


