#pragma once
#include "SDL_mixer.h"
#include "SDL.h"
#include "GameObject.h"

class Sound

{
public:
	
	Sound(); // default will initialize sound engine with default values
	~Sound();

	void playBGM();
	void playMenu();
	void playEnd();

	void playLazer();
	void playExplosion();
	void playSelect();

	void cleans();

};

