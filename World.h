#pragma once
#include "Particle.h"
#include <list>


class World {
	private:
	int rows = 0;
	int columns = 0;
	std::list<Particle> Parts;
 	public: 
	World(int World_rows, int World_columns) : rows(World_rows), columns(World_columns) {};	
	 const std::list<Particle> getParts const {
		return Parts;
	 }  
	
	
	

	
	
};
//If the particle goes out of bounds -> call a destructor on it or something
//std::list<int> particle-> holds all of the particles in the world
//A .at(row,col) method that checks if the particle is in its rightful place in the game world
// .physics() method that runs the physics functions on each one

