#pragma once
#ifndef _ENDSCREEN_H
#define _ENDSCREEN_H
#include "InputManager.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "InputManager.h"
#include "SDL_ttf.h"
#include <iostream>

class EndScreen
{
private:
	//ronald start screen object no debating 
	bool hitspace = false;
	SDL_Window *window;
	SDL_Renderer *renderer;
	InputManager* inputmanager;

	SDL_Texture* starfield;
	SDL_Texture* highScoreTex;
	SDL_Texture* gameOverTex;
	SDL_Texture* spacew;
	SDL_Texture*outScoreTex;
	SDL_Rect srcR, destR;
	SDL_Rect srcS, destS;   //space rectangle
	SDL_Rect destScore;



public:
	EndScreen();
	~EndScreen();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void updates(); //Individual class update functions will go here!!
	void renders();
	void cleans();

	bool ishitspace() { return hitspace; };

};

#endif
