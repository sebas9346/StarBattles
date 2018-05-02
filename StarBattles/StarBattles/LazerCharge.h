#pragma once

#ifndef LAZERCHARGE_H
#define LAZERCHARGE_H

#include "GameObject.h"

class LazerCharge : public GameObject {
public:
	LazerCharge(SDL_Renderer *); //constructor
	~LazerCharge();
	void subtractCharge();
	void addCharge();
	int howManyCharges();
	void reset();
	void update();
protected:
	int LazerCount;
};

#endif