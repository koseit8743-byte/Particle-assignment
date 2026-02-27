#include "/public/read.h" // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include "World.h"
#include "Particle.h"
#include "/public/colors.h"
#include <fstream>
using namespace std;

World::World() {
	Boundaries();
}

Particle* World::at(float row, float col) {
	for (auto temp = Parts.begin(); temp != Parts.end(); temp++) { 
		if (temp->getRow() == row and temp->getCol() == col) {
			Particle* location = &*temp;
			return location;
		}
		return nullptr;
	}
}

list <Particle> World::Elements() const {
	return Parts;
}


void World::Boundaries() {	
	const auto [ROWS,COLS] = get_terminal_size();
	rows= ROWS - 1;
	columns = COLS - 1;
}

int World::size() const { 
	return Parts.size();
}

int World::alive_count() {
	int alive = 0;
	auto temp = Parts.begin();
	while (temp != Parts.end()) { //double check if this should be a different loop
	 if (temp->getLifetime() == 0) {
		temp = Parts.erase(temp);
	}
else if (temp->getLifetime() > 0) {
	alive++;
	temp++;
	}
 }
	return alive;
}

void World::isInside() {
	auto temp = Parts.begin();
	while (temp != Parts.end()) {
		if (temp->getRow() < 0 or temp->getCol() < 0 or temp->getRow() >= rows or temp->getCol() >= columns) { 
			temp = Parts.erase(temp);
		}
	}
}

bool World::isEmpty(int r, int col) {
  if(r < 0 ||  r >= rows || col < 0 || col  >= columns) return false;
  return (at(r, col)) == nullptr;
}

char World::get_Map_Location(vector<vector<char>> &World_Map, size_t World_rows, size_t World_columns) { 
	if (World_rows >= World_Map.size() or World_columns >= World_Map[World_rows].size())
		return ' ';
	else 
		return World_Map[World_rows][World_columns];
}

void World::Game_Map() {
	clearscreen();	
	for (size_t i = 0; i < World_Map.size(); i++) { 
		for (size_t j = 0; j < World_Map[i].size(); j++) {
		World_Map[i][j] = ' '; //This will print out spaces in the terminal so we can visually see the particle
	}
	cout << endl;
	}
}



void World::Load(string SaveFile) {
	Parts.clear();
	ifstream file(SaveFile);
		if (file.eof()) {
			return; 
		}
		else { 
			Parts = World_Parts;
		}
	}	


void World::Save() { 
	World_Parts = Parts;
}

void World::add(Particle holder) { 
		Parts.emplace_back(holder);
}
/*void World::Save(string SaveFile) { 
		ofstream upload(SaveFile);
		if (upload.eof())
			return; 
		
		upload << rows << " " << columns;
		for (const auto &temp : Parts) {
			uint8_t Color = temp.getColor(uint8_t red, uint8_t green, uint8_t blue);
			upload << static_cast<int>(temp.getType()) << " " << temp.getRow() << " " << temp.getCol() << " " << temp.getXvel() << " " << temp.getYvel() << " " <<  static_cast<int>(Color) << " " << temp.isStill() << " " << temp.getLifetime();			
		} */
	
 
	


