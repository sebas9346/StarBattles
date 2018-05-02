#include "LazerCharge.h"

//Default constructor
LazerCharge::LazerCharge(SDL_Renderer * ren) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture("assets/LazerCharge.png", renderer);
	LazerCount = 4;
}

//Destructor
LazerCharge::~LazerCharge() {}

void LazerCharge::subtractCharge() {
	if (LazerCount > 0) {
		LazerCount--;
	}
}

void LazerCharge::addCharge() {
	if (LazerCount < 4) {
		LazerCount++;
	}
}

int LazerCharge::howManyCharges() {
	return LazerCount;
}

void LazerCharge::reset() {
	LazerCount = 4;
}
//Update the start position
//of the laser
void LazerCharge::update() {
	srcRect.w = 64;
	srcRect.h = 64;
	srcRect.x = -1 * (LazerCount - 4) * 64;
	srcRect.y = 0;

	destRect.x = 0;
	destRect.y = 550;
	destRect.w = 128;
	destRect.h = 64;
}