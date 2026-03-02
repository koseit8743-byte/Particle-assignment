
#include "NewBridges.h"
#include "World.h"
#include<iostream>
#include "Particle.h"
#include<string>
using namespace std;
using namespace bridges::datastructure;
VisualBridges::VisualBridges(int assign, string username, string APIkey) {
	bridges =  new bridges::Bridges(assign, username, APIkey);
bridges->setTitle("Particle Simlation");
	bridges->setDescription("Particle Class");

}

void VisualBridges::visualize(World& world) {
	int rows = world.getRows();
	int cols = world.getCols();

ColorGrid cg(rows, cols);
 for(int r  = 0; r < rows; r++){
	 for ( int c = 0; c < cols; c++){ Particle* p = world.at(r,c);
		 if( p == nullptr){
			 cg.set(r,c, Color(0,0,0));
		 }
		 else {
			 uint8_t red, green, blue;
			 p->getColor(red, green, blue);
			 cg.set(r,c,Color(red, green, blue));
		 }
	 }
 }
 


		 bridges->setDataStructure(&cg);
	bridges->visualize();
}
