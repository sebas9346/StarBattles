#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "Layout.h"
class Asteroid: public GameObject
{
public:
	Asteroid(SDL_Renderer* ren);
	void moveLeft(void);
	void moveRight(void);
	void reset(void);
	virtual void update(void);

	~Asteroid();

private:
	int speed;
	int ani = 0;
	int spr_update_count = 0;
	int rotationspeed;
	

};

