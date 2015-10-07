//A widget represents all objects in the game
#include <string>
#include <vector>
#include "locationTile.h"

// Will have more subclasses to represent all game objects (i.e. creature, item, foliage, etc.)

using namespace std;

class widget {
	string widget_name; // should be const?
	locationTile currentLocation;

	widget(string name) {
		widget_name = name;
	}

	virtual string use() {} // function to interact with object, returns string to send to server
}
