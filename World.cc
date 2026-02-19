#include "/public/read.h" // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include "World.h"
#include "Particle.h"
#include "/public/colors.h"
using namespace std;

World::World(int World_row, int World_Column) {
	row = World_row;
    columns = World_Column;	
}

