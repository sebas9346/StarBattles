#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Asteroid.h"

GameObject* player;
Asteroid* asteroid;

using namespace std;
Game::Game(){
}


Game::~Game(){
}

void Game::init(const char* title, int xpos, int ypos, int width, int height,bool fullscreen) {
	
	int flags = 0;
	if (fullscreen == true) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "Subsystems Initialized!" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			cout << "window has been created" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer created" << endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	//Creating texture

	SDL_Surface* tmpSurface = IMG_Load("assets/Player.png");

	SDL_FreeSurface(tmpSurface);

	inputmanager = InputManager::Instance();
	
	//player = new GameObject("assets/Player.png", renderer, 0, 0);
	asteroid = new Asteroid();


}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default: 
			break;
	}
}

//Individual class update functions will go here!!
void Game::update() {
	//input manager updating in game


	//Asteroid::update(int x,int y) {
	//	xpos = x;
	//	ypos = y;
	//
	//	srcRect.h = 1854;// Dimension of image to use(Slab from texture sheet)
	//	srcRect.w = 1473;
	//	srcRect.x = 0;
	//	srcRect.y = 0;
	//
	//	destRect.x = xpos;
	//	destRect.y = ypos;
	//	destRect.w = srcRect.w / 5;
	//	destRect.h = srcRect.h / 5;
	//}
	inputmanager->Update();
	//cnt++;
	if (isRunning) {
		
		if (inputmanager->KeyDown(SDL_SCANCODE_D)) {
			asteroid->moveRight();
		}
		else if (inputmanager->KeyDown(SDL_SCANCODE_A)) {
			asteroid->moveLeft();
		}
	}
	
	
	//player->update();
	asteroid->update();

}

void Game::render() {
	SDL_RenderClear(renderer);
	//add stuff to render
	player->render();
	//
	SDL_RenderPresent(renderer);

}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleared" << endl;
}
