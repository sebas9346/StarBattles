#include "Game.h"
#include "Rocketship.h"
#include "Lazer.h"
#include "Asteroid.h"
#include "LazerCharge.h"
#include "PowerUp.h"
#include <time.h>
#include <fstream>
#include <string>
#include <iterator>
#include <list>


using namespace std;

//Asteroids
list<GameObject*> asteroids;
int numAsteroids = 0;
int maxAsteroids = 10;

//Lazer
Lazer* majorLazer;
list<GameObject*> allLazers;
LazerCharge* lazerChargeGUI;
int lives = 3;

//Rocketship
Rocketship* rocket;
list<GameObject*> rocketlives;

//PowerUp
PowerUp* powerUpGo;

//clock
clock_t startCharge;
bool fullCharge;

bool firedLast = false; //keep track of spacebar keystroke
int lazerShift = 0; //to center the firing of lazers

SDL_Texture* backGround;
Sound *soundEngine = nullptr;

Game::Game(){
}


Game::~Game(){
}

void Game::init(const char* title, int xpos, int ypos, int width, int height,bool fullscreen) {
	
	int flags = 0;
	soundEngine = new Sound();

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
	SDL_Surface* tmpSurface = IMG_Load("assets/Starfield.png");
	backGround = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	inputmanager = InputManager::Instance();
	
	rocket = new Rocketship(renderer, 350, 500);
	for (int i = 0; i < lives; i++) {
		int x =550 + (i * 64);
		rocketlives.push_back(new Rocketship(renderer, x, 0));
	}
	// Play the tunes once everything's set up
	soundEngine->playBGM();

	lazerChargeGUI = new LazerCharge(renderer);
	powerUpGo = new PowerUp(renderer);
	fullCharge = true; // check if ammo is at full

	TTF_Init();
	blue = { 242, 125, 53 };
	font = TTF_OpenFont("ARDESTINE.ttf", 72);
	
	
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
			if (lazerChargeGUI->howManyCharges() > 0) {
				majorLazer = new Lazer(renderer, rocket->getX() + lazerShift, 500);
				soundEngine->playLazer();
				allLazers.push_back(majorLazer);
				lazerChargeGUI->subtractCharge();
				if (fullCharge) {
					fullCharge = false;
					startCharge = clock();
				}
			}
			//else
				//ammo = 0; //game over..chill this is a place holder...need @Ronald's code!		
		}
		else if (!(inputmanager->KeyDown(SDL_SCANCODE_SPACE)) && firedLast) {
			firedLast = false;
		}
	}

	rocket->update(); // update rocket
	lazerChargeGUI->update(); // update lazerChargeGUI
	powerUpGo->update(); //update PowerUp

	if ((clock() - startCharge) / CLOCKS_PER_SEC > 2) {
		lazerChargeGUI->addCharge();
		if (lazerChargeGUI->howManyCharges() == 4) {
			fullCharge = true;
		}
		else {
			startCharge = clock();
		}
	}

	//lazer update

	//Update all the lazers 
	for (list<GameObject*>::iterator la = allLazers.begin(); la != allLazers.end(); ++la) {
		
		bool collisionFlag = false;
		(*la)->update();
		for (list<GameObject*>::iterator it = asteroids.begin(); it != asteroids.end();) {
			if ((*it)->collision(*la)) {
				(*it)->reset();
				collisionFlag = true;
				rocket->isScore(); //update the score by 1 point for every asteroid shot
				//cout << rocket->getScore(); << endl;
				soundEngine->playExplosion();
				break;
			}
			it++;

		}
		if ((*la)->collision(powerUpGo)) {
			powerUpGo->reset();
			collisionFlag = true;
		}

		if (collisionFlag) {
			allLazers.remove(*la);
			(*la)->reset();
		}
	}

	if (powerUpGo->collision(rocket)) {
		rocket->set_power();
		powerUpGo->reset();
	}

	for (list<GameObject*>::iterator it = asteroids.begin(); it != asteroids.end();) {

		(*it)->update();
		if ((*it)->collision(rocket)) {
			if (!rocket->is_powered()) {
				rocket->isDead();
			}
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

	if (powerUpGo->isOutOfBounds()) {
		powerUpGo->reset();
	}

	
	//Asteroid control
	while(asteroids.size() < maxAsteroids) {
			asteroids.push_back(new Asteroid(renderer));
			numAsteroids++;
			
	}

	if (rocket->getLife() < lives) {
		//cout << "Number of lives left: ";
		lives = rocket->getLife();
		GameObject* tmp = rocketlives.front();
		tmp->setX(1000);
		rocketlives.remove(tmp);
		cout << rocketlives.size() << endl;

		if (rocket->getLife() == 0) {
			currentScore = rocket->getScore(); //get the current score
			compareScores(); //compare previous score for high score
			isRunning = false;  //end the game
		}
	}
	for (list<GameObject*>::iterator it = rocketlives.begin(); it != rocketlives.end(); ++it) {
		(*it)->update();
	}

	//Score update on game screen
	currentScore = rocket->getScore();
	string temp = to_string(currentScore); //makes the current score a string value for output to window
	current_score = temp.c_str();
	SDL_Surface *outScore = TTF_RenderText_Solid(font, current_score, blue);
	currScoreTex = SDL_CreateTextureFromSurface(renderer, outScore);
	SDL_QueryTexture(currScoreTex, NULL, NULL, &destCurrScore.w, &destCurrScore.h);
	destCurrScore.x = 10;
	destCurrScore.y = 0;
	destCurrScore.w = destCurrScore.w / 2;
	destCurrScore.h = destCurrScore.h / 2;

}

void Game::render() {
	SDL_RenderClear(renderer);
	//add stuff to render
	SDL_RenderCopy(renderer, backGround, NULL, NULL);
	rocket->render();
	lazerChargeGUI->render();
	powerUpGo->render();
	SDL_RenderCopy(renderer, currScoreTex, NULL, &destCurrScore);
	

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

//Destroy Game window
void Game::clean() {
	SDL_DestroyWindow(window);
	// Free the music data
	soundEngine->cleans();
	SDL_DestroyRenderer(renderer);

	Mix_Quit(); // closes audio engine
	SDL_Quit();
	cout << "Game Cleared" << endl;
}

//Compare the score if the user has played 
//this game more than once --> high score
void Game::compareScores() {
	int temp;
	ifstream readFile("score.txt"); //open the file for reading
	if (readFile.is_open())
	{
		while (readFile >> temp) {}
		if (temp < rocket->getScore()) //for cases when nothing in file
			highScore = rocket->getScore();
		else
			highScore = temp;
	}
	readFile.close();

	ofstream writeFile("score.txt");
	writeFile << highScore << endl;
	writeFile.close();
}

//Get the high score
int Game::getHighScore() {
	return highScore;
}

//Get the current score
int Game::getCurrentScore() {
	return currentScore;
}
