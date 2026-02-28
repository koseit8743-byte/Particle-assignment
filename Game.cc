#include "/public/read.h" // IWYU pragma: keep
//Basic Header Inclusion
#include "Game.h"
#include <climits>
#include <cstdio>
#include <type_traits>
#include <vector> // IWYU pragma: keep
//Non Blocking I/O, #include <NonBlockingGame.h> (Formerly Used)
#include "/public/colors.h"
//For Framerate
#include <chrono>
//usleep
#include <unistd.h>


Game::Game{
	fps=5;
	frames=0;
	pause = true;
	SaveFile = //blah blah	
//Terminal launch and size
		auto[ROWS, COLS] = get_terminal_size
		int HUD = 5;
		(ROWS - HUD);

//Mouse Commands
void run(){
	bool clicked = false;
	mouse_r = 0;
	mouse_c = 0;
on_mousedown(int row, int col){
clicked = true;
mouse_r = row;
mouse_c = col;
}




};

//Frame Count,clock
long long CurrMillisec(){
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();

	//prevents sadness and upset when exiting
	 void bailout() {
		set_mouse_mode(false);
		set_raw_mode(false);
		set_cursor_mode(true);
		resetcolor();
	}

int ch = quick_read();
bool currently_running = true;
while(currently_running == 1){
	int start = CurrMillisec;
if (ch == 'q' or ch == 'Q'){
	currently_running = 0;
}
else if (ch == ' '){
	pause = true;
}
else if (ch == 's' or ch == 'S'){
	World.save(SaveFile);
}
else if (ch == 'l' or ch == 'L'){
	pause = 1;
	World.load(SaveFile);
}
else if (ch == '+') {
	fps++;	
}
else if (ch == '-') {
	fps--;
}
