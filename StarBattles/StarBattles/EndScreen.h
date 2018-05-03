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
#include "Sound.h"
#include <iostream>
#include <string>

class EndScreen
{
private:
	//ronald start screen object no debating 
	bool hitspace = false;
	char const * high_score;
	char const * current_score;
	SDL_Window *window;
	SDL_Renderer *renderer;
	InputManager* inputmanager;

	SDL_Texture* starfield;
	SDL_Texture* gameOverTex;
	SDL_Rect srcS, destS;   //space rectangle
	SDL_Texture* spacew;// CurrentScore
	//high score textures
	SDL_Texture* highScoreTex;
	SDL_Texture* outScoreTex;
	SDL_Rect srcR, destR;
	SDL_Rect destScore;

	//current score textures
	SDL_Texture* currentScoreTex;
	SDL_Texture* yourScoreTex;
	SDL_Rect srcC, destC;
	SDL_Rect destCurrent;  


	SDL_Rect srcCurrentTex, destCurrTex;
	SDL_Rect destCurrentTex;
	

public:
	EndScreen();
	~EndScreen();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, int highScore, int currentScore);

	void handleEvents();
	void updates(); //Individual class update functions will go here!!
	void renders();
	void cleans();

	bool ishitspace() { return hitspace; };

};

#endif
