#pragma once

//World for "World world;" Why? idk
#include "World.h"
//In BRIDGES library for NonBlocking I/O
#include <NonBlockingGame.h>
//Bridges Color Names
#include "NamedColor.h"
//Not sure yet but will need *shrug*
#include "NamedSymbol.h"

#include <string>

class Game : public bridges::game::NonBlockingGame {
public:
	Game();
//Runs game
	void run();
//Does doohickeys on launch
	void initialize() override;
//Keeps game looping per <NonBlockingGame.h> & performs checks
	void GameLoop() override;

private:
void FPSdelay();
void render();
static void Physics();
void InputControls();

World world;


};
