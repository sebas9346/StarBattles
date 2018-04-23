#include "Game.h"


using namespace std;
Game::Game(){
}


Game::~Game(){
}

void Game::init(const char* title, int xpos, int ypos, int width, bool fullscreen) {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "Subsystems Initialized!" << endl;
	}
}

void Game::handleEvents() {

}

void Game::update() {

}

void Game::render() {

}
void Game::clean() {

}
