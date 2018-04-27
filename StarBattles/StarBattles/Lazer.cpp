#include "Lazer.h"

//Default constructor
Lazer::Lazer(SDL_Renderer * ren, int x, int y) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture("assets/Player.png", renderer);

	xpos = x; //create laser off screen
	ypos = y;
}

//Destructor
Lazer::~Lazer() {}


//Update the start position
//of the laser
void Lazer::update() {
	ypos -= 5;
	/*srcRect.h = 74;
	srcRect.w = 12;*/
	srcRect.w = 1473;
	srcRect.h = 1854;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 6;
	destRect.h = 12;
}
