#include "/public/read.h" // IWYU pragma: keep
//Basic Header Inclusion
#include "Game.h"
//Handling stream
#include <SocketConnection.h>
#include <cstdio>
//??
#include <curl/curl.h>
#include <type_traits>
//Yada Yada
#include <vector> // IWYU pragma: keep
//Non Blocking I/O
#include <NonBlockingGame.h>
//For Framerate
#include <chrono>
//usleep
#include <unistd.h>
//For Bridges & Color
#include "NamedColor.h"

#include "NamedSymbol.h"


using bridges::game::NamedColor;
using bridges::game::NamedSymbol;

//Starts game 
virtual void initialize() override { }

//Keeps game looping per <NonBlockingGame.h>
void Game::GameLoop() { 
FPSdelay();
render();
Physics();
InputControls();
}


void Game::run(){
	start();
}
//Frame Count,clock
long long CurrMillisec(){
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

//Saving Board space for HUD and commands
static const int Board_Rows = 32;
static const int Board_Columns = 30;
static const int Hud_Rows = 3;

//
Game() : NonBlockingGame(1, "myuserid", "myapikey", Board_Rows, Board_Columns), 
		 World(Board_Rows - Hud_Rows, Board_Columns) {}







int main() {
	Game game;
	game.run();
}
