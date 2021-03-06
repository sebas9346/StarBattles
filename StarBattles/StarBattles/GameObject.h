#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "TextureManager.h"
#include "GameObject.h"
class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void update();
	virtual void reset();
	bool isOutOfBounds();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	void setX(int X);
	void clean();
	void render();
	bool collision(GameObject*);

protected:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Surface* tmpSurface;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};
#endif // !ASTEROIDOBJECT_H


