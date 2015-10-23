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
static WINDOW *DISPLAY_WINDOW;
static const int BUFFER_LENGTH = 128;

static int interface_row;
static int interface_col;



void UserInterface_print(const string &value) {
	mvprintw(interface_row, 0, "%s", value.c_str());
	++interface_row;
	refresh();
}

void UserInterface_println(const string &value) {
	UserInterface_print(value + "\n");
}

void UserInterface_printTop(const string &value) {
	mvprintw(0, 0, "%s\n", value.c_str());
	refresh();
}

static void UserInterface_printRow(const string &value, const int row) {
	mvprintw(row, 0, "%s\n", value.c_str());
	refresh();
}

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
	UserInterface_println("\"" + str + "\" does not match any commands...\nuse \"list\" to see available commands\nuse \"help <command>\" to see details about a command");



	/*
	cout << "\"" << str << "\" does not match any commands..." << endl
		 << "use \"list\" to see available commands" << endl
		 << "use \"help <command>\" to see details about a command" << endl;
	*/
}





static void displayMatches(const vector<string> &matches, const string &input) {
	UserInterface_println("what command did you mean");
	UserInterface_println("\"" + input + "\" refers to multiple commands:");

	for(auto itr = matches.begin(); itr != matches.end(); ++itr) {
		UserInterface_println("  " + *itr);
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

	
	//if (index == tokens.size() && index > 0) {
		UserInterface_invalidInput(token);
	//}
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
	UserInterface_println("enter a command");
	UserInterface_println("  type \"list\" to display possible commands");

	while(IS_RUNNING) {
		//char str[BUFFER_LENGTH];
		//getstr(str);
		string input = UserInterface_getUserInput();

		if (IGNORE) {
			IGNORE = false;
		} else if(input > "") {
			vector<string> tokens = parseInput(input);

			if (tokens.size() == 1) {
				parseToken(tokens.front());
			} else if (tokens.size() > 1) {
				parseTokens(tokens);
			} else {
			//	assert(false && "invalid token count from user input");
			}
		}
	}
}

static void* threadFunc(void *arg) {
	interfaceLoop();
}


static void startInterfaceThread(void) {
	IS_RUNNING = true;
	IGNORE = false;

	UserInterface_printTop("making thread\n");


	if ( pthread_create(&INTERFACE_THREAD, NULL, threadFunc, NULL) ) {
		UserInterface_printTop("Error creating thread\n");
		//fprintf( stderr, "Error creating thread\n" );
		exit(-1);
	}
}



static void destroyNCurses(WINDOW *display) {
	delwin(display);
	endwin();
	refresh();
}

static void initNCurses(void) {
	DISPLAY_WINDOW = initscr();

	if (DISPLAY_WINDOW == NULL) {
		cout << "failure initiating NCurse Window" << endl
			 << "exiting program" << endl;
		endwin();
		exit(-1);
	}

	//raw();
	noecho();
}


static string C2S(const char c) {
	stringstream ss;
	string s;
	ss << c;
	ss >> s;
	return s;
}

static string I2S(const int i) {
	stringstream ss;
	string s;
	ss << i;
	ss >> s;
	return s;
}

static bool isDeleteChar(int ch) {
	static const int DELETE = 127;
	return ch == DELETE;
}

static bool isNewlineChar(int ch) {
	static const int NEWLINE = 10;
	return ch == NEWLINE;
}

static bool isValidChar(int ch) {
	static const int CHAR_START = 31;
	static const int CHAR_END = 126;
	return ch > CHAR_START && CHAR_END > ch;
}

static string getUserInput() {
	char ch = getch();
	char first;
	int row = ++interface_row - 1;

	if (isNewlineChar(ch)) {
		return "";
	}
	if (isValidChar(ch)) {
		first = ch;
		UserInterface_printRow(C2S(ch), row);
	}

	string input = "";
	input = input + ch;

	while(1) {
		ch = getch();

		if (isNewlineChar(ch)) {
			input = input;
			return input;
		}
		if (isDeleteChar(ch)) {
			if (input.length() > 0) {
				input = input.substr(0,input.length() - 1);
			}
		} else if (isValidChar(ch)) {
			input = input + ch;
		}

		//UserInterface_printTop(I2S(ch));
		UserInterface_printRow(input, row);
	}

	return "";
}

string UserInterface_getUserInput(void) {

	string input = getUserInput();
	interface_row = 1;
	clear();
	refresh();

	return input;

/*
	//UserInterface_println(getUserInput());
	//sleep(10);

	char str[BUFFER_LENGTH];
	char ch = getch();

	++interface_row;
	getstr(str);

	string input(str);
	input = ch + input;



	return input;
	//return string(ch + str);
*/


}

bool UserInterface_isActive(void) {
	return IS_RUNNING;
}

void UserInterface_ignoreNext(void) {
	IGNORE = true;
}


void UserInterface_quit(void) {
	IS_RUNNING = false;
	destroyNCurses(DISPLAY_WINDOW);
}

pthread_t& UserInterface_getThreadId(void) {
	return INTERFACE_THREAD;
}



/*
struct MyCout {};
extern MyCout myCout;

template <typename T>
MyCout& operator<< (MyCout &s, const T &x) {
  //format x as you please
	//printw("%s", value.c_str());


	cout << "meh " << x;
	return s;
}

MyCout& operator<< (MyCout &s, std::ostream& (*f)(std::ostream &)) {
  f(std::cout);
  return s;
}

MyCout& operator<< (MyCout &s, std::ostream& (*f)(std::ios &)) {
  f(std::cout);
  return s;
}

MyCout& operator<< (MyCout &s, std::ostream& (*f)(std::ios_base &)) {
  f(std::cout);
  return s;
}

 	//MyCout cout;
	//cout << "test" << endl;

*/


void UserInterface_create(void) {
	initNCurses();
	Commands_initiate();
	startInterfaceThread();
}

#endif



