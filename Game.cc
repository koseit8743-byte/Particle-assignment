#include "/public/read.h" // IWYU pragma: keep
//Basic Header Inclusion
#include "Game.h"
#include <cstdio>
#include <type_traits>
#include <vector> // IWYU pragma: keep
//Non Blocking I/O, #include <NonBlockingGame.h> (Formerly Used)
#include "/public/colors.h"
#include "World.h"
//For Framerate
#include <chrono>
//usleep
#include <unistd.h>

//Initalizing
Game::Game():world(1, 1) {
	frames = 0;
	pause = true;
	fps = 5;
	//Somethin
}
//Frame Count,clock
long long CurrMillisec(){
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

//Set screen size
	auto [ROWS, COLS] = get_terminal_size();
	const int HUD = 3;
	world = World(ROWS - HUD, COLS);

//prevents sadness and upset when exiting
void bailout() {
	set_mouse_mode(false);
	set_raw_mode(false);
	set_cursor_mode(true);
	resetcolor();
	}

void Game::run() {

	//Input Reading
int ch = quick_read();
bool currently_running = true;

while(currently_running == 1){	
if (ch == 'q' or ch == 'Q'){
	currently_running = 0;
}
	else if (ch == ' '){
	pause = !pause;
	}
		else if (ch == 's' or ch == 'S'){
		world.save(SaveFile);
		}
			else if (ch == 'l' or ch == 'L'){
			pause = 1;
			world.load(SaveFile);
			}
				else if (ch == '+') {
				fps++;	
				}	
					else if (ch == '-') {
					fps--;
					}	
		}
	}
}
