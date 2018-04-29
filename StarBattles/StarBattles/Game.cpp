#include "Game.h"
#include "Rocketship.h"
#include "Lazer.h"
#include "Asteroid.h"

#include <iterator>
#include <list>


using namespace std;
//Asteroids
list<GameObject*> asteroids;
int numAsteroids = 0;
int maxAsteroids = 10;

//Lazer
Lazer* majorLazer;
Rocketship* rocket;
int lives = 3;

int ammo = 50; //amount of lasers allowed
bool firedLast = false; //keep track of spacebar keystroke
int lazerShift = 29; //to center the firing of lazers

list<GameObject*> allLazers;
list<GameObject*> rocketlives;

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
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			cout << "Renderer created" << endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}


	inputmanager = InputManager::Instance();
	
	rocket = new Rocketship(renderer, 350, 500);
	for (int i = 0; i < lives; i++) {
		int x =550 + (i * 64);
		rocketlives.push_back(new Rocketship(renderer, x, 0));
	}
	

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

	inputmanager->Update();
	
	if (isRunning) {

		if (inputmanager->KeyDown(SDL_SCANCODE_D)) {
			rocket->moveRight();
		}
		else if (inputmanager->KeyDown(SDL_SCANCODE_A)) {
			rocket->moveLeft();
		}

		if (inputmanager->KeyDown(SDL_SCANCODE_SPACE) && !firedLast) {
			firedLast = true;
			if (ammo > 0) {
				majorLazer = new Lazer(renderer, rocket->getX() + lazerShift, 500);
				allLazers.push_back(majorLazer);
				ammo--;
			}
			else
				ammo = 0; //game over..chill this is a place holder...need @Ronald's code!		
		}
		else if (!(inputmanager->KeyDown(SDL_SCANCODE_SPACE)) && firedLast) {
			firedLast = false;
		}
	}

	rocket->update(); // update rocket

	//lazer update

	//Update all the lazers 
	for (list<GameObject*>::iterator la = allLazers.begin(); la != allLazers.end(); ++la) {
		(*la)->update();
	}

	for (list<GameObject*>::iterator it = asteroids.begin(); it != asteroids.end();) {

		(*it)->update();
		if ((*it)->collision(rocket)) {
			rocket->isDead();
			(*it)->reset();
			rocket->reset();
		}
		
		if ((*it)->isOutOfBounds()) {
			(*it)->reset();
		}
		else {
		it++;
		}
	}

		//some code here for @Victor for asteroid collision
	
	//Asteroid control
	while(asteroids.size() < maxAsteroids) {
			asteroids.push_back(new Asteroid(renderer));
			numAsteroids++;
			
	}
	/*for (list<GameObject*>::iterator it = asteroids.begin(); it != asteroids.end();) {
	
		(*it)->update();
		if ((*it)->collision(rocket)) {
			rocket->isDead();
			(*it)->reset();
			rocket->reset();
		}
		
		if ((*it)->isOutOfBounds()) {
			(*it)->reset();
		}
		else {
			it++;
		}
	}*/

	if (rocket->getLife() < lives) {
		cout << "dec lives" << endl;
		lives = rocket->getLife();
		GameObject* tmp = rocketlives.front();
		tmp->setX(1000);
		rocketlives.remove(tmp);
		cout << rocketlives.size()<<endl;
	}
	for (list<GameObject*>::iterator it = rocketlives.begin(); it != rocketlives.end(); ++it) {
		(*it)->update();
	}

}

void Game::render() {
	SDL_RenderClear(renderer);
	//add stuff to render
	rocket->render();

	for (list<GameObject*>::iterator it = asteroids.begin(); it != asteroids.end(); it++) {
		(*it)->render();
	}
	for (list<GameObject*>::iterator it = allLazers.begin(); it != allLazers.end(); ++it) {
		(*it)->render();
	}
	for (list<GameObject*>::iterator it = rocketlives.begin(); it != rocketlives.end(); ++it) {
		(*it)->render();
	}
	//
	SDL_RenderPresent(renderer);

}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleared" << endl;
}
