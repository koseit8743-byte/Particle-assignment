#pragma once

//World for "World world;" Why? idk
#include "World.h"

#include "Particle.h"
#include <string>
#include "/public/colors.h"
using namespace std;
//Previous Header included "NonBlockingGame" from bridges. Upadated to use colors.h

class Game {
public:
	Game();
	void run();

private:
	World world;
	bool pause;
	string SaveFile;
	int frame;
	int fps;
	int hudRows;
	ParticleType paintType;

	void Input();
	void PhysicsUpdate();
	void render();
	void delayFrame(long long StartFrame);

	void commandSAVE();
	void commandLOAD();
	void commandPAUSE();
	void commmandFPSup();
	void commandFPSdown();
	void commandBRIDGES();

	long long CurrMill() const;


};
