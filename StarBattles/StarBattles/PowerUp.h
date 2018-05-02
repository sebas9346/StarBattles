#pragma once
#include "GameObject.h"

class PowerUp : public GameObject
{
public:
	PowerUp(SDL_Renderer* ren);
	~PowerUp();
	void reset(void);
	void update(void);

private:
	int speed;
	int ani;
	int spr_update_count;
};
