#pragma once
#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "InputManager.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#include "SDL_image.h"
#include "InputManager.h"
#include <iostream>

class StartScreen 
{
private:
	//ronald start screen object no debating 
	bool hitspace = false;
	bool startGame = false;
	SDL_Window *window;
	SDL_Renderer *renderer;
	InputManager* inputmanager;





public:
	StartScreen();
	~StartScreen();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, bool& );

	void handleEvents();
	void updates(); //Individual class update functions will go here!!
	void renders();
	void cleans();

	bool ishitspace() { return hitspace; };

};

#endif
