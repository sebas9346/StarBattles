#pragma once

#ifndef LAZER_H
#define LAZER_H

#include "GameObject.h"

class Lazer : public GameObject{
public:
	Lazer(SDL_Renderer *, int, int); //constructor
	~Lazer();
	void update();
};

#endif

