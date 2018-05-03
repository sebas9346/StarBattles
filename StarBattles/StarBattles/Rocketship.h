#pragma once
#pragma once 

/*
@author: Anagha Indic
@date: April 16, 2018
@description: Rocket class
*/

#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

#include "GameObject.h"
#include "time.h"

class Rocketship : public GameObject
{
public:
	Rocketship(SDL_Renderer *, int, int); //constructor
	~Rocketship();  //destructor
	bool isDead();
	void isScore();
	void isSpecialScore();
	int getLife();

	//motion
	void moveRight();
	void moveLeft();
	void update();
	void reset();

	//powerup
	bool is_powered();
	void set_power();

	int getScore();

protected:
	bool killed; //true or false value to determine end of game
	bool poweredUp;
	int lives; //number of lives
	int score;   //score keeper
	int ani = 0;
	int pass = 0;
	int timeoutSoon = 0;
	int powerani = 0;
	clock_t powerStart = NULL;
};
#endif


