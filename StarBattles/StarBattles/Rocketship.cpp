#include "Rocketship.h"

//constructor
Rocketship::Rocketship(SDL_Renderer *ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture("assets/Rocket.png", renderer);

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
int Rocketship::getLife(void) {
	return lives;
}
void Rocketship::reset() {
	/*xpos = -5;
	ypos = -5;
	xpos = 350;
	ypos = 500;*/
}

//Method to update the rocket
void Rocketship::update(void) {
	
	if (ani < 64 * 5 && pass == 6) {
		ani += 64;
		pass = 0;
	}
	else if(ani >= 64*5) {
		ani = 0;
	}
	pass += 1;
	srcRect.w = 64;
	srcRect.h = 64;
	srcRect.x = ani;
	srcRect.y = 0;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 64;
	destRect.h = 64;
}

Rocketship::~Rocketship() {}


