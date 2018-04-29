#include "Asteroid.h"
#include <random>
//test
using namespace std;
Asteroid::Asteroid(SDL_Renderer* ren)
{
	
	renderer = ren;
	objTexture = TextureManager::LoadTexture("assets/AsteroidBrown.png", renderer);
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
	ypos = ypos + speed;
	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 64;
	destRect.h = 64;
}
void Asteroid::reset() {
	speed = 1 + (rand() % 10);
	xpos = rand() % 700;
	ypos = 0;
}


Asteroid::~Asteroid()
{
	
}
