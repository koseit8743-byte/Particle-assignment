#include "/public/read.h" // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include "World.h"
#include "Particle.h"
#include "/public/colors.h"
using namespace std;

World::World() {
	int World_row = 0;
    int  World_Column = 0;
}

char World::get_Map_Location(vector<vector<char>>& World_Map, size_t rows, size_t columns) {
	if (rows >= World_Map.size() or columns >= World_Map.size())
		return '*';
	else 
		return World_Map[rows][columns];
}

void World::Boundaries() {	
	const auto [Rows,Cols] = get_terminal_size();
	rows = Rows - 1;
	columns = Cols - 1;
}


void World::Game_Map() {
	clearscreen();	
	for (size_t i = 0; i < World_Map.size(); i++) { 
		for (size_t j = 0; j < World_Map[i].size(); j++) {
		World_Map[rows][columns] = ' ';
		}
		cout << endl;	
	}
}

	
//void World::Boundaries(list ) 
//	Parts.emplace_back(ParticleType);
//	auto temp = Parts.begin();	


