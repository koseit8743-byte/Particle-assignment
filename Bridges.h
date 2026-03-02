  #ifndef BRIDGES_H
  #define BRIDGES_H
 #include <Bridges.h>
#include<DataStructure.h>
#include <string>  
  #include <ColorGrid.h>
  using namespace std;
 
  class World;
  class VisualBridges {
     private:
    bridges::Bridges* bridges;

	 public:

	VisualBridges( int asign, string username, string APIkey);

	void visualize(World& world);

  };
#endif


