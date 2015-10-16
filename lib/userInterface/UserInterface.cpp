#include "userInterfaceHeaders/UserInterface.h"

#ifndef _USER_INTERFACE_CPP_
#define _USER_INTERFACE_CPP_

using namespace std;

/*class InterfaceObserver : public Observer {
	public:
		InterfaceObserver()	{}

		void notify(const string &userInput) {
			//do stuff with the parsed string
			//like call a function...
		}
		void notify(const vector<string> &userInput) {
			//do more stuff with the parsed strings
			//like call a function with arguements...
		}
};
static InterfaceObserver observer;*/



static ObserverList observers;
static bool IS_RUNNING;
static bool IGNORE;
static pthread_t INTERFACE_THREAD;


void UserInterface_addListener(Observer *obs) {
	observers.addObserver(obs);
}

void UserInterface_notifyListeners(const string &str) {
	observers.notifyObservers(str);
}
void UserInterface_notifyListeners(const vector<string> &str) {
	observers.notifyObservers(str);
}

void UserInterface_invalidInput(const string &str) {
	cout << "\"" << str << "\" does not match any commands..." << endl
		 << "use \"list\" to see available commands" << endl
		 << "use \"help <command>\" to see details about a command" << endl;
}


static void displayMatches(const vector<string> &matches, const string &input) {
	cout << "what command did you mean" << endl
		 <<  "\"" << input << "\" refers to multiple commands:"
		 << endl;

	for(auto itr = matches.begin(); itr != matches.end(); ++itr) {
		cout << "  " << *itr << endl;
	}
}



struct parsedResults {
	bool isMatch;
	int matchCount;
	vector<string> matches;
};

static struct parsedResults parseSubToken(const string &token) {
	struct parsedResults result;

	result.matches = Commands_getMatches(token, token.size());
	result.matchCount = result.matches.size();
	result.isMatch = result.matchCount > 0;

	return result;
}


static bool processSubToken(const vector<string> &inputs, vector<string> &tokens, int index) {
	string token = inputs.at(index);
	struct parsedResults results = parseSubToken(token);

	if (results.isMatch) {
		if (results.matchCount == 1) {
			token = results.matches.front();

			int remaining = inputs.size() - 1;

			if (remaining == 0) {
				Commands_callFunction(token);
			} else {
				tokens.push_back(token);

				if (index == remaining) {
					Commands_callFunction(tokens.front(), tokens);
				} else {
					processSubToken(inputs, tokens, index + 1);
				}
			}
		} else {	
			displayMatches(results.matches, token);
		}

		return true;
	}
	
	if (index == tokens.size() && index > 0) {
		UserInterface_invalidInput(token);
	}
	return false;
}

static bool processSubToken(const vector<string> &inputs) {
	vector<string> tokens;
	processSubToken(inputs, tokens, 0);
}

static void parseTokens(const vector<string> &tokens) {

	for(auto itr = tokens.begin(); itr != tokens.end(); ++itr) {
		string token = *itr;

		if (Commands_isValidToken(token)) {
			vector<string> temp = {token};

			if (!processSubToken(tokens, temp, 1)) {
				return;
			}
			++itr;
		} else {
			if (itr == tokens.end() - 1) {
				if ( !processSubToken( {token}) ) {
					return;
				}
			} else {
				if (  !processSubToken( {token, *(itr + 1)} )  ) {
					return;
				}
			}
		}
	}
}

static void parseToken(const string &token) {
	if (Commands_isValidToken(token)) {
		Commands_callFunction(token);
		return;
	}

	processSubToken( {token} );
}


static bool startsWithSpace(const string &str) {
	bool startWithSpace1 = str.substr(0,1).compare(" ") == 0;
	bool startWithSpace2 = str.substr(0,1).compare("\f") == 0;
	bool startWithSpace3 = str.substr(0,1).compare("\n") == 0;	
	bool startWithSpace4 = str.substr(0,1).compare("\r") == 0;
	bool startWithSpace5 = str.substr(0,1).compare("\t") == 0;
	bool startWithSpace6 = str.substr(0,1).compare("\v") == 0;

	return startWithSpace1 || startWithSpace2 || startWithSpace3 
		|| startWithSpace4 || startWithSpace5 || startWithSpace6;
}

static void trimInput(string &input) {
	if(startsWithSpace(input)) {
		input.erase( 0, input.find_first_not_of( " \f\n\r\t\v" ) );
	}
	input.erase( input.find_last_not_of( " \f\n\r\t\v" ) + 1 );

	for (int i = 0;  i < input.length(); ++i) {
		input[i] = tolower(input[i]);
	}
}

static vector<string> parseInput(string &input) {
	int start = -1;
	int tokenCount = 0;
	vector<string> tokens;

	trimInput(input);
	
	for(size_t found = input.find(" "); found != string::npos; found = input.find(" ", found + tokenCount)) {
		++tokenCount;
		
		string token = input.substr(start + 1, found - start - 1);
		start = found;
		tokens.push_back(token);
	}

	string token = input.substr(start + 1, input.size());
	tokens.push_back(token);

	return tokens;
}


static void interfaceLoop() {
	bool hasOverflown = false;

	string input;

	cout << "enter a command" << endl
		 << "  type \"list\" to display possible commands" << endl;

	while(IS_RUNNING) {
		getline(cin, input);

		if (IGNORE) {
			IGNORE = false;
		} else {
			vector<string> tokens = parseInput(input);

			if (tokens.size() == 1) {
				parseToken(tokens.front());
			} else if (tokens.size() > 1) {
				parseTokens(tokens);
			} else {
				assert(false && "invalid token count from user input");
			}
		}
	}
}

static void* threadFunc(void *arg) {
	interfaceLoop();
}


static void startInterfaceThread(void) {
	if ( pthread_create(&INTERFACE_THREAD, NULL, threadFunc, NULL) ) {
		fprintf( stderr, "Error creating thread\n" );
		exit(-1);
	}
}


bool UserInterface_isActive(void) {
	return IS_RUNNING;
}

void UserInterface_ignoreNext(void) {
	IGNORE = true;
}


void UserInterface_quit(void) {
	IS_RUNNING = false;
}

pthread_t& UserInterface_getThreadId(void) {
	return INTERFACE_THREAD;
}

void UserInterface_create(void) {
	Commands_initiate();

	IS_RUNNING = true;
	IGNORE = false;

	startInterfaceThread();
}

#endif



