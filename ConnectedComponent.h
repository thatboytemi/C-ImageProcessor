#include <vector>
#include <utility>
#include <limits.h>
namespace ANXTEM001{
    class ConnectedComponent{
        private:
            int numPixels;
            int identifier;
            std::vector <std::pair<int, int>> coordinates;
        public:
            //contstructors
            ConnectedComponent(int identifier);
            ConnectedComponent();
            ConnectedComponent(const ConnectedComponent & other);
            ConnectedComponent(ConnectedComponent && other);
            ConnectedComponent& operator=(const ConnectedComponent & other);
            ConnectedComponent& operator=(ConnectedComponent && other);
            ~ConnectedComponent();
            static int COUNTER;
            int getNumPixels() const;
            int getIdentifier() const;
            void addToCoordinates(std::pair<int, int> && coordinate);
            //functions that return iterators (allowing me to traverse through vector of coordinates within PGMimageProcessor class)
            std::vector<std::pair<int, int>>::const_iterator begin();
            std::vector<std::pair<int, int>>::const_iterator end();
            int xMin=INT_MAX;
            int xMax=0;
            int yMin=INT_MAX;
            int yMax=0;
    };
}
