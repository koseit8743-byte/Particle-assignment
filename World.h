#pragma once
#include "Particle.h"
#include <list>
#include <vector>
using namespace std;


class World {
	private:
	float rows = 0;
	float columns = 0;
	vector<vector<char>> World_Map;
	list<Particle> Parts;
 	public: 
//	World(int World_rows, int World_columns) : rows(World_rows), columns(World_columns) {};	
	World();
	  int getRows() const{
       return rows;
     }
     int getCols() const{
   return columns;
     }

	void SetRows(int World_rows) {
		rows = World_rows;
	}
	void SetColumns(int World_columns) { 
		columns = World_columns;
	}

	//char get_Map_Location(vector<vector<char>> &World_Map);
	
	Particle* at(float x, float y);
	list <Particle> Elements() const;
	int size() const;
	int alive_count();
	void Boundaries();		
	bool isEmpty(int rows, int columns);
	void Game_Map();	


 void addParticle(const Particle& P) {
	 Parts.push_back(P);
 }

 void physics() {
	 for( auto& P : Parts){
		 P.Physics (*this);
		 alive_count();
	isInside();
	 }
 }
	char get_Map_Location(vector<vector<char>> &World_Map, size_t World_rows, size_t World_columns); 
	void isInside();
};
//If the particle goes out of bounds -> call a destructor on it or something
//std::list<int> particle-> holds all of the particles in the world
//A .at(row,col) method that checks if the particle is in its rightful place in the game world
// .physics() method that runs the physics functions on each one

