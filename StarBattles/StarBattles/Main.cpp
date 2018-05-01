#include <iostream>
#include <SDL.h>
#include <ctime>
#include "StartScreen.h"
#include "Game.h"

using namespace std;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;


Game *game = nullptr;
StartScreen *startScreen = nullptr;

bool start = false;

int starposx = 0;
int starposy = 0;
int main(int argc, char * argv[])
{
	srand(time(0));
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	
	//Ronald's code
	startScreen = new StartScreen();
	startScreen->init("StarBattles", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

	while (!startScreen->ishitspace()) {

		frameStart = SDL_GetTicks();

		startScreen->handleEvents();
		startScreen->updates();
		startScreen->renders();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	startScreen->cleans();
	game = new Game();
	game->init("StarBattles", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

	while (game->running()) {

		frameStart = SDL_GetTicks();	
			game->handleEvents();
			game->update();
			game->render();




		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	return 0;
}