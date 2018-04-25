#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;

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
<<<<<<< HEAD
	SDL_Surface* tmpSurface = IMG_Load("assets/Player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	roninputmanager = InputManager::Instance();
=======
	
	player = new GameObject("assets/Player.png", renderer);

>>>>>>> sebastian
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
<<<<<<< HEAD
	//input manager updating in game
	roninputmanager->Update();
	//cnt++;
	if (roninputmanager->KeyDown(SDL_SCANCODE_D)) {
		cnt++;
		destR.h = 64;
		destR.w = 64;
		destR.x = cnt + 1;
	}
	else if (roninputmanager->KeyDown(SDL_SCANCODE_A)) {
		cnt--;
		destR.h = 64;
		destR.w = 64;
		destR.x = cnt - 1;
	}
	else if (roninputmanager->KeyDown(SDL_SCANCODE_W)) {
		cnt--;
		destR.h = 64;
		destR.w = 64;
		destR.y = cnt - 1;
	}
	else if (roninputmanager->KeyDown(SDL_SCANCODE_S)) {
		cnt--;
		destR.h = 64;
		destR.w = 64;
		destR.y = cnt - 1;
	}
	

	cout << cnt << endl;
	
=======
	player->update();
>>>>>>> sebastian
}

void Game::render() {
	SDL_RenderClear(renderer);
	//add stuff to render
	player->render();
	//
	SDL_RenderPresent(renderer);

}
void Game::clean() {
	InputManager::Release;
	roninputmanager = NULL;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleared" << endl;
}
