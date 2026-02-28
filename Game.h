#pragma once

//World for "World world;" Why? idk
#include "World.h"
//In BRIDGES library for NonBlocking I/O
#include <NonBlockingGame.h>
//Bridges Color Names
#include "NamedColor.h"
//Not sure yet but will need *shrug* 
//I think "NamedSymbol.h" is included in <NonBlockingGame.h>
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
//Sanity
private:
void FPSdelay(int frame_start);
void render();
static void Physics();
void InputControls();

static const int Board_Rows = 32;
static const int Board_Columns = 32;
static const int Hud_Space = 3;
int Mouse_X = 0;
int Mouse_Y = 0;

static bool Pause = true;
string SaveFile = "Game.txt";
int frames = 0;
int fps = 5;



World world;


};
