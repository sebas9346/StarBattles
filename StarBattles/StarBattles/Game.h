#pragma once
#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "InputManager.h"
#include "SDL_ttf.h"
#include "Sound.h"
#include <iostream>

class Game{
	public:
		Game();
		~Game();
		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

		void handleEvents();
		void update(); //Individual class update functions will go here!!
		void render();
		void clean();
		void compareScores();
		bool running() { return isRunning; };
		int getHighScore();
		int getCurrentScore();

	private:
		SDL_Surface * currScore;
		char const* current_score;
		SDL_Color blue;
		int highScore;
		int currentScore;
		bool isRunning;
		TTF_Font *font;
		SDL_Texture *currScoreTex;
		SDL_Rect destCurrScore;
		SDL_Window *window;
		SDL_Renderer *renderer;
		InputManager* inputmanager;


		int cnt=0;
};
#endif