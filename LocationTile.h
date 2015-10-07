// locationTile

#include <vector>
using namespace std;

class locationTile {

	public:

		locationTile();

		locationTile(vector<widget> inputWidgets) {
			widgetArray = inputWidgets;
		}

		int getTotalWidgets() {
			return widgetArray.size();
		}
        int getLocation(){
            return locationID;
        }

	private:

		string locationDescription;
        
		string direction;
		int locationID;
		//obtain the above information from YAML data
		vector<widget> widgetArray;
};