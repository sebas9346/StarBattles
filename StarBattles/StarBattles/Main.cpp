#include <iostream>
#include <SDL.h>
using namespace std;
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

int main(int argc, char * argv[])
{
	bool gameON = true;
	while (gameON) {

	}
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000);

	return 0;
}