
#include "SDL.h"

#include "Game.h"
using namespace std;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

Game *game = nullptr;
int main(int argc, char * argv[])
{
	game = new Game();
	game->init("StarBattles", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
	while (game ->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
	return 0;
}