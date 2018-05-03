#pragma once
#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "InputManager.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "InputManager.h"
#include <iostream>

class StartScreen 
{
private:
	//ronald start screen object no debating 
	bool hitspace = false;
	SDL_Window *window;
	SDL_Renderer *renderer;
	InputManager* inputmanager;

	SDL_Texture* starfield;
	SDL_Texture* fontstar;
	SDL_Texture* spacer;
	SDL_Texture* spacew;
	SDL_Rect srcR, destR;
	SDL_Rect srcS, destS;   //space rectangle


public:
	StartScreen();
	~StartScreen();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void updates(); //Individual class update functions will go here!!
	void renders();
	void cleans();

	bool ishitspace() { return hitspace; };

};

#endif
