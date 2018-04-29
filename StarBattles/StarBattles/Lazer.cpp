#include "Lazer.h"

//Default constructor
Lazer::Lazer(SDL_Renderer * ren, int x, int y) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture("assets/Laser.png", renderer);

	xpos = x; 
	ypos = y;
}

//Destructor
Lazer::~Lazer() {}

void Lazer::reset() {
	ypos = -500;
}
//Update the start position
//of the laser
void Lazer::update() {
	ypos -= 5;
	/*srcRect.h = 74;
	srcRect.w = 12;*/
	srcRect.w = 64;
	srcRect.h = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 18;
	destRect.h = 24;
}
