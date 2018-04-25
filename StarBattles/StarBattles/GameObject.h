#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "Game.h"

class GameObject
{
public:
	GameObject();
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void update();
	void render();

protected:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};
#endif // !ASTEROIDOBJECT_H


