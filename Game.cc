#include "Game.h"
#include "World.h"
#include <chrono>
#include "/public/colors.h"
#include <csignal>
#include <cstdlib>
#include <cstdint>
//Non Blocking I/O, #include <NonBlockingGame.h> (Formerly Used)
#include "Particle.h"
//usleep
#include <ostream>
#include <unistd.h>
#include <algorithm>


//prevents sadness and upset when exiting
void cleanupTerminal() {
	set_mouse_mode(false);
	set_raw_mode(false);
	set_cursor_mode(true);
	resetcolor();

//	std::cout << "\033[?1000l\033[?10006l" << std::flush;
	}

static void CtrlC(int) {
	exit(0);
}

bool g_clicked = false;
int g_clickRow = -1;
int g_clickCol = -1;

void onMouseDown(int row, int col){
	g_clicked = true;
	g_clickRow = row;
	g_clickCol = col;

//	movecursor(1,1);
//	resetcolor();
//cout << "Click row=" << row << "Col" << col << "" << flush;

}

Game::Game() : world(1, 1) {
	pause=true;
	frame = 0;
	fps = 5;
	SaveFile = "world.txt";
	hudRows = 5;

	paintType = ParticleType::DUST;
}
long long Game::CurrMill() const{
	using namespace chrono;
	return chrono::duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

void Game::run() {
	
	atexit(cleanupTerminal);
	signal(SIGINT, CtrlC);
	
set_raw_mode(true);
set_cursor_mode(false);
set_mouse_mode(true);
//std::cout << "\033[?1006l\033[?1000h" << std::flush;
//on_mousedown(onMouseDown);

auto terminal = get_terminal_size();
int termRows = terminal.first;
int termCols = terminal.second;

int worldRows = max(1, termRows - hudRows);
int worldCols = max(1, termCols);

world.SetRows(worldRows);
world.SetColumns(worldCols);
for (int i = 0; i < world.getCols(); i++){
	Particle ground(world.getRows() - 1, i, ParticleType::EARTH);
	world.addParticle(ground);
}
//Testing
//Particle test(5, 5, paintType);
//world.addParticle(test);

//clearscreen();
movecursor(1,1);
cout << "Particle Sim" << endl;
cout << "Space = Run/Pause | Q = Quit | L = Load | S = Save | D = BRIDGES | +/- FPS" << endl;
cout << "When Paused: click to add/remove" << endl;
cout << "Press SPACE to start!" << endl;
cout.flush();

	//Input Reading
while (true){
int ch;
while ((ch = quick_read()) != ERR){
if (ch == ' ') goto START;
}
usleep(10000);
}
START:
set_raw_mode(true);
set_mouse_mode(true);
on_mousedown(onMouseDown);
bool currently_running = true;
while(currently_running) {
	long long frameStart = CurrMill();
int ch;
//while((ch = quick_read()) != ERR){
ch = quick_read();

/*Debugging
if(ch != -1){
	cout << "ch="<<ch<< "\n";
	cout.flush();
}
*/
if (ch == 'q' or ch == 'Q'){
	currently_running = 0;
}
	else if (ch == ' '){
	commandPAUSE();
	}
		else if (ch == 's' or ch == 'S'){
		commandSAVE();
		}
			else if (ch == 'l' or ch == 'L'){
			commandLOAD();
			}
				else if (ch == '+') {
				commmandFPSup();	
				}	
					else if (ch == '-') {
					commandFPSdown();
					}	
						else if(ch == 'd' or ch == 'D'){
							commandBRIDGES();
						}
//test print
else if(ch =='p' or ch =='P'){
	Particle test(rand() % termRows, rand() % termCols, paintType);
	test.setLifetime(200);
	world.addParticle(test);

}
if (ch=='2') paintType = ParticleType::DIRT;
if (ch=='4') paintType = ParticleType::WATER;
if (ch=='6') paintType = ParticleType::FIRE;
if (ch=='1') paintType = ParticleType::LIGHTNING;
if (ch=='0') paintType = ParticleType::AIR;
//}
//movecursor(30,30);
//cout << "YUP\n";
//usleep(100000);
//on_mousedown(onMouseDown);
if (g_clicked){
	g_clicked = false;

	int r = g_clickRow;
	int c = g_clickCol;

	if (r > 0) r -= 1; 
	if (c > 0) c -=1;

	if (r>= 0 and r < world.getRows() and c >= 0 and c < world.getCols()) {
		Particle* existing = world.at(r, c);

		if(existing != nullptr){
			existing -> setLifetime(0);
		}
		else{
			Particle p(r, c, paintType);
			p.setLifetime(200);
			world.addParticle(p);
		}
	}

}
 //temp holder
if(!pause){

	world.physics();
	frame++;
//	if(before > 0 and after == 0) {
//		pause = true;
	}
render();
delayFrame(frameStart);
}
}

void Game::render() {

//Testing
//movecursor(5, 5);
//setbgcolor(255, 0, 0);
//cout << " ";
//resetcolor();
//cout.flush();

	clearscreen();
	list<Particle> parts = world.Elements();
	for(auto it = parts.begin(); it != parts.end(); ++it){
		int r = (int)it->getRow();
		int c = (int)it->getCol();

		if(r < 0 or c < 0 or r>= world.getRows() or c >= world.getCols()) continue;
		uint8_t rr = rand() % 255, gg = rand() % 255, bb = rand() % 255;
		it->getColor(rr,gg,bb);
		movecursor((uint32_t)(r + 1), (uint32_t)(c+1));
		setbgcolor(rr,gg,bb);
		cout << " ";
		cout.flush();
		resetcolor();
	}

	int hudTop = world.getRows() + 1;
	movecursor((uint32_t)hudTop, 1);
	resetcolor();
	cout<<"Frame: " <<frame << "| FPS: " << fps << (pause ? " | Paused " : " | Running ") << "| Alive: " << world.alive_count() << " | Type: " << (int)paintType;

	movecursor((uint32_t)(hudTop+1), 1);
	cout << " Space:Run/Pause | Q | L | S | D | +/-";

	movecursor((uint32_t)(hudTop +2), 1);
	cout << "Paused";
	cout.flush();

	movecursor((uint32_t)(hudTop + 3),1);
	resetcolor();
	cout << "click: " << g_clicked << "," << g_clickCol << "clicked=" << g_clickRow << "    ";

cout.flush();
}

void Game::delayFrame(long long StartFrame) {
	if (fps < 1) fps = 1;
	long long GoalMS = 1000LL / (long long)fps;
	long long elapsed = CurrMill() - StartFrame;
	if (elapsed < GoalMS){
		long long remainder = GoalMS - elapsed;
		usleep((useconds_t)(remainder * 1000));
	}


}
void Game::commandPAUSE(){
	pause = !pause;
}
void Game::commandSAVE(){
	world.Save(); 
}
void Game::commandLOAD(){
	pause = true;
	world.Load(SaveFile);
}
void Game::commmandFPSup(){
fps = min(60, fps + 1);
}
void Game::commandFPSdown(){
	fps = max(1, fps - 1);
}
void Game::commandBRIDGES(){
	string user = "placeholder";//BridgesUser ""
	string key = "placeholder";//BridgesKey ""
	int assignmentId = 1;
	
	pause = true;

	int hudTop = world.getRows() + 1;
	movecursor((uint32_t)(hudTop + 2), 1);
	cout << "Bridges Output";
		cout.flush();
}
