#include "Rocketship.h"

//constructor
Rocketship::Rocketship(SDL_Renderer *ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture("assets/Player.png", renderer);

	xpos = x;
	ypos = y;
	std::cout << "Rocket created" << std::endl;
	score = 0;
	lives = 3;
	killed = false;
}

//Determine if game has ended when rocket gets hit by 
//an asteroid or some relevant object
bool Rocketship::isDead() {
	if (lives == 0)
		killed = true;
	else
		lives -= 1;
	return false;
}

//Add 1 point to score when rocket successfully
//destroys a standard asteroid
void Rocketship::isScore() {
	score += 1;
}

//Add 5 points to score when rocket successfully 
//destroys a special object 
void Rocketship::isSpecialScore() {
	score += 5;
}

//Method to move rocket left
void Rocketship::moveLeft(void) {
	if (xpos < 0)
		xpos = 0;
	else
		xpos -= 5;  //changing x pos by 5
}

//Method to move rocket right
void Rocketship::moveRight(void) {
	if (xpos > 750) 
		xpos = 750;
	else
		xpos += 5; //changing x pos by 5
}

//Method to update the rocket
void Rocketship::update(void) {
	srcRect.w = 1473;
	srcRect.h = 1854;
	srcRect.x = 200;
	srcRect.y = 200;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 63;
	destRect.h = 100;
}

Rocketship::~Rocketship() {}


