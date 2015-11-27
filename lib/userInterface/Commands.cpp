#ifndef _COMMANDS_CPP_
#define _COMMANDS_CPP_
#include "userInterfaceHeaders/Commands.h"
#include "gameEngineHeaders/GameEngine.h"

static const string SPACER = "  ";

typedef void (*functionReferenceVoid)(void);
typedef void (*functionReferenceString)(const string&);
typedef void (*functionReferenceStrings)(const vector<string>&);
static map<string, functionReferenceVoid> functionMapVoid;
static map<string, functionReferenceString> functionMapString;
static map<string, functionReferenceString> errorMapString;

static vector<string> options;
static vector<string> dynamicFunctions;
static map<string, string> menuCommands;
static map<string, string> gameCommands;

static GameEngine *gameEngine = NULL;

void Commands_addGameEngine(GameEngine *g) {
	gameEngine = g;
}

static vector<string> getPossibleDirections(void) {
	if (gameEngine == NULL) {
		UserInterface_println("ERROR: No Game Engine");
		UserInterface_exit();
	} else {
		vector<string> derp;
		derp.push_back("up");
		derp.push_back("down");
		return derp;

		vector<string> directions = gameEngine->GameEngine_getPossibleDirections();
		return directions;
	}
}

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

bool Commands_hasDynamicArguements(const string &input) {
	return find(dynamicFunctions.begin(), dynamicFunctions.end(), input) != dynamicFunctions.end();
}


vector<string> Commands_getMatches(const string &input, int n, bool dynamic, int type) {
	if (dynamic) {

		if (type == DYNAMIC_MOVE_COMMAND) {
			return getMatches(getPossibleDirections(), input, n);
		}

		if (type == DYNAMIC_LOOK_COMMAND) {
			UserInterface_println("UNIMPLEMENTED: LOOK LIST");
			
			//need another function to get possible objects to look at
			//return getMatches(UserInterface_getPossibleDirections(), input, n);
		}
	}

	return getMatches(options, input, n);
}


bool Commands_isValidToken(const string &token) {
	return find(options.begin(), options.end(), token) != options.end();
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
	UserInterface_println("move command");
}

static void moveError(const string &str) {
	vector<string> directions = getPossibleDirections();

	UserInterface_println("Invalid direction: " + str);
	UserInterface_println(SPACER + "possible directions are:");

	for(int i = 0; directions.size() > i; ++i) {
		UserInterface_println(SPACER + SPACER + directions.at(i));
	}
}

static void move(void) {
	vector<string> directions = getPossibleDirections();

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
    functionMapVoid["login"] = dummyCommand;
    functionMapVoid["testworld"] = dummyCommand;

	//single arguement functions
    functionMapString["help"] = help;
    functionMapString["move"] = move;

	//dynamic functions
	errorMapString["move"] = moveError;

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

	for(auto itr = errorMapString.begin(); itr != errorMapString.end(); ++itr) {
		dynamicFunctions.push_back(itr->first);
	}



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
void Commands_callError(const string &funcName, const string &funcArgs) {
		errorMapString[funcName](funcArgs);
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


