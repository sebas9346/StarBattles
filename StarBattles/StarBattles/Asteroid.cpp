#include "Asteroid.h"
#include <random>
//test
using namespace std;
Asteroid::Asteroid(SDL_Renderer* ren)
{
	
	renderer = ren;
	if (rand() % 10 + 1 <= 5) {
		objTexture = TextureManager::LoadTexture("assets/FAsteroid.png", renderer);
	}
	else {
		objTexture = TextureManager::LoadTexture("assets/HAsteroid.png", renderer);
	}
	rotationspeed = rand() % 25 + 1;
	speed = 1+(rand() % 7);
	xpos = rand()%800;
	ypos = 0;
}
void Asteroid::moveLeft(void) {
	xpos = xpos - 1;
}
void Asteroid::moveRight(void) {
	xpos = xpos+1;
}
void Asteroid::update() {
	if (ani < 64 * 7 && spr_update_count == rotationspeed) {
		ani += 64;
		spr_update_count = 0;
	}
	else if (ani >= 64 * 7) {
		ani = 0;
	}

	ypos = ypos + speed;
	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = ani;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 64;
	destRect.h = 64;

	spr_update_count++;
}
void Asteroid::reset() {
	speed = 1 + (rand() % 10);
	spr_update_count = 0;
	rotationspeed = rand() % 25 + 3;
	SDL_DestroyTexture(objTexture);
	if (rand() % 10 + 1 <= 5) {
		objTexture = TextureManager::LoadTexture("assets/FAsteroid.png", renderer);
	}
	else {
		objTexture = TextureManager::LoadTexture("assets/HAsteroid.png", renderer);
	}
	xpos = rand() % 700;
	ypos = 0;
}


Asteroid::~Asteroid()
{
	
}
