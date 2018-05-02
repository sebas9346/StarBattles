#include "PowerUp.h"
#include <random>

using namespace std;
PowerUp::PowerUp(SDL_Renderer* ren)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture("assets/PowerUp.png", renderer);
	speed = 3;
	xpos = rand() % 800;
	ypos = 0;
	ani = 0;
	spr_update_count = 0;
}

PowerUp::~PowerUp() {};

void PowerUp::update() {
	if (ani < 64 * 19 && spr_update_count == 7) {
		ani += 64;
		spr_update_count = 0;
	}
	else if (ani >= 64 * 19 && spr_update_count == 7) {
		ani = 0;
		spr_update_count = 0;
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

void PowerUp::reset() {
	spr_update_count = 0;
	xpos = rand() % 800;
	ypos = -2500;
}
