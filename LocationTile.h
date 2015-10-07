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

	private:

		string roomDescription;
		string direction;
		int locationID;
		//obtain the above information from YAML data
		vector<widget> widgetArray;
};