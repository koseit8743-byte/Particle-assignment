  #ifndef BRIDGES_H
  #define BRIDGESH

   #include <Bridges.h>
  
  #include <ColorGrid.h>
  using namespace std;
 
  class World;
  class VisualBridges {
     private:
    bridges::Bridges bridges;

	 public:

	VisualBridges( int asign, string username, string APIkey);

	void visualize(World& world);

  };
#endif


