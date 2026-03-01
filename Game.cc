#include "/public/read.h" // IWYU pragma: keep
#include "Game.h"
#include <chrono>
#include <csignal>
#include <cstdlib>
#include <cstdint>
//Non Blocking I/O, #include <NonBlockingGame.h> (Formerly Used)
#include "/public/colors.h"
#include "Particle.h"
//usleep
#include <unistd.h>
#include <algorithm>

//prevents sadness and upset when exiting
void cleanupTerminal() {
	set_mouse_mode(false);
	set_raw_mode(false);
	set_cursor_mode(true);
	resetcolor();
	}
static void CtrlC(int) {
	exit(0);
}

bool g_clicked = false;
int g_clickRow = 0;
int g_clickCol = 0;
void onMouseDown(int row, int col){
	g_clicked = true;
	g_clickRow = row;
	g_clickCol = col;
}

Game::Game():world(1,1){
	pause=true;
	frame = 0;
	fps = 5;
	SavePath = "world.txt";
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
set_mouse_mode(true);
set_cursor_mode(false);
on_mousedown(onMouseDown);

Game::Game() : bridges::game::NonBlockingGame(Assignment, Username, API, Board_Rows, Board_Columns),
 world(Board_Rows - Hud_Rows, Board_Columns)
	}
//Starts game 
virtual void initialize() override {
setTitle("Particle Sim");
setDescription( "// Space = Pause or Run // Q = Quit // W = Load // S = Save // <- Increase Frame Rate // -> Decrease Frame Rate");
=======
auto terminal = get_terminal_size();
int termRows = terminal.first;
int termCols = terminal.second;

int worldRows = max(1, termRows - hudRows);
int worldCols = max(1, termCols);

world = World(worldRows, worldCols);

clearscreen();
movecursor(1,1);
cout << "Particle Sim" << endl;
cout << "Space = Run/Pause | Q = Quit | L = Load | S = Save | D = BRIDGES | +/- FPS" << endl;
cout << "When Paused: click to add/remove" << endl;
cout << "Press SPACE to start!" << endl;
cout.flush();

	//Input Reading
while (true){
int ch = quick_read();
if (ch == ' ') break;
usleep(10'000);
}

bool currently_running = true;
while(currently_running) {
	long long start = CurrMill();
int ch = quick_read();
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
	}

if (pause and g_clicked){
	g_clicked = false;

	int r = g_clickRow;
	int c = g_clickCol;

	if (r > 0) r -= 1; if (c > 0) c -=1;

	if (r>= 0 and r < world.getRows() and c >= 0 and c < world.getCols()) {
		Particle* existing = world.at((float)r, (float)c);

		if(existing != nullptr){
			existing -> setLifetime(0);
		}else{
			Particle p((float)r, (float)c, paintType);
			world.addParticle(p);
		}
	}
}
}
if(!pause){
	world.physics();
	frame++;

	if(world.alive_count() == 0) {
		pause = true;
render();
delayFrame(start);
}
}

void Game::render() {
	clearscreen();
	list<Particle> parts = world.Elements();
	for(auto it = parts.begin(); it != parts.end(); ++it){
		int r = (int)it->getRows();
		int c = (int)it->getCols();

		if(r < 0 or c < 0 or r>= world.getRows() or c >= world.getCols()) continue;
		uint8_t rr = 255, gg = 255, bb = 255;
		it->getColor(rr,gg,bb);
		movecursor((uint32_t)(r + 1), (uint32_t)(c+1));
		setbgcolor(rr,gg,bb);
		cout << " ";
		resetcolor();
	}

	int hudTop = world.getRows() + 1;
	movecursor((uint32_t)hudTop, 1);
	resetcolor();
	cout<<"Frame: " <<frame << " FPS: " << fps << (pause ? "Paused" : "Running") << Alive: << world.alive_count() << "Type:" << (int)paintType;

	movecursor((uint32_t)(hudTop+1), 1);
	cout << "Space Run/Pause   Q   L   S   D   +/-";

	movecursor((uint32_t)(hudTop +2), 1);
	cout << "Paused";
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
	world.Load(SavePath);
}
void Game::commmandFPSup(){
fps = min(60, fps + 1);
}
void Game::commandFPSdown(){
	fps = max(1, fps - 1);
}
void Game::commandBRIDGES(){
	string user = ;//BridgesUser ""
	string key = ;//BridgesKey ""
	int assignmentId = 1;
	
	pause = true;

	int hudTop = world.getRows() + 1;
	movecursor((uint32_t)(hudTop + 2), 1);
	cout << "Bridges Output"
		cout.flush();



