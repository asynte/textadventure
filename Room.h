// locationTile

#include <vector>
using namespace std;

class Room {

	public:

		Room();

		Room(vector<widget> inputWidgets) {
			widgetArray = inputWidgets;
		}

		int getTotalWidgets() {
			return widgetArray.size();
		}
        int getRoom(){
            return roomID;
        }
        void addDoor();
        void removeDoor();
    

	private:
        vector<Door> doorList;
        string name;
		string description;
    
		string direction;
		int roomID;
		//obtain the above information from YAML data
		vector<widget> widgetArray;
};