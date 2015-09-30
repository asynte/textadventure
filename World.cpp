// World class

#include "LocationTile.cpp"
#include <vector>
using namespace std;


class World {
    
	public:
        
        World ();
    
        World (vector <LocationTile> inputLocationTIles){
            locationTileArray = inputLocationTiles;
        }
    
        ~World ();
    
        int getTotalLocationTiles () {
            return locationTileArray.size();   
        }
    
    
    private:
        vector <LocationTile> locationTileArray;
    


};
