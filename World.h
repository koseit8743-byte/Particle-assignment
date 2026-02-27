#pragma once
#include "Particle.h"
#include <list>
#include <vector>
using namespace std;


class World {
	private:
	int rows = 0;
	int columns = 0;
	vector<vector<char>> World_Map;
	list<Particle> Parts;
	list<Particle> Part_World;
 	public: 
//	World(int World_rows, int World_columns) : rows(World_rows), columns(World_columns) {};	
	World();	
	friend class World_Particles;
	void GetRows() const;
	void GetColumns() const;
	void SetRows(int World_rows) {
		rows = World_rows;
	}
	void SetColumns(int World_columns) { 
		columns = World_columns;
	}

	char get_Map_Location(vector<vector<char>> &World_Map, size_t rows, size_t columns);

	int size() const;
	int alive_count();
	void Boundaries();		
	bool isEmpty(int rows, int columns);
	void Game_Map();	

	int getRows() const{ 
		return rows;
	}
	int getCols() const{
		return columns;
	}

	// Particle* at(int row, int col){
		for (auto& k : Part_World){
			if((k.getRow() == row) && (k.getCol() == col))
				return &k;
		}
   return nullptr;
}

};
//If the particle goes out of bounds -> call a destructor on it or something
//std::list<int> particle-> holds all of the particles in the world
//A .at(row,col) method that checks if the particle is in its rightful place in the game world
// .physics() method that runs the physics functions on each one

