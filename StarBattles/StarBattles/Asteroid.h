#pragma once
#include "GameObject.h"
class Asteroid: public GameObject
{
public:
	Asteroid();
	void moveLeft(void);
	void moveRight(void);
	void update(void);
	~Asteroid();

};

