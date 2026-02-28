#pragma once

//World for "World world;" Why? idk
#include "World.h"
#include <string>
//Previous Header included "NonBlockingGame" from bridges. Upadated to use colors.h

class Game {
public:
	Game();
//Runs game
	void run();

private:

	bool pause;
	string SaveFile;
	int frames;
	int fps;

World world;
};
