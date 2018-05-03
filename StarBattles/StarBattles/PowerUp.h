#pragma once
#include "GameObject.h"

class PowerUp : public GameObject
{
public:
	PowerUp(SDL_Renderer* ren, int type);
	~PowerUp();
	void reset(void);
	void update(void);
	int type_id(void);

private:
	int speed;
	int ani;
	int spr_update_count;
	int id;
};
