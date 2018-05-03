#include "Sound.h"


// load up our default sounds

// Music & sound effects resources
Mix_Music *backgroundMusic = NULL;
Mix_Music *menuSong = NULL;
Mix_Music *endSong = NULL;

Mix_Chunk *lazerSound = NULL;
Mix_Chunk *explosionSound = NULL;
Mix_Chunk *selectSound = NULL;


// constructor will init with default vals
Sound::Sound() {

	// init audio mixer
	if ((SDL_Init(SDL_INIT_AUDIO)) < 0) {

		printf("Could not initialize audio properly. SDL Error: %s\n", SDL_GetError());
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}


	// init audio pointers
	backgroundMusic = Mix_LoadMUS("levelSong.wav");
	menuSong = Mix_LoadMUS("menuSong.wav");
	endSong = Mix_LoadMUS("gameOver.wav");


	lazerSound = Mix_LoadWAV("lazer.wav");
	explosionSound = Mix_LoadWAV("explosion.wav");
	selectSound = Mix_LoadWAV("menuSelect.wav");


	if (backgroundMusic == NULL) {
		printf("Failed to load dope music! SDL_mixer Error: %s\n", Mix_GetError());
	}

}

Sound::~Sound() {

}


void Sound::playBGM() {

	// first pause anything that's playing
	Mix_HaltChannel(-1);

	// Play the tunes once everything's set up
	Mix_PlayMusic(backgroundMusic, -1);

}

void Sound::playMenu() {

	// first pause anything that's playing
	Mix_HaltChannel(-1);

	// Play the tunes once everything's set up
	Mix_PlayMusic(menuSong, -1);

}

void Sound::playEnd() {

	// first pause anything that's playing
	Mix_HaltChannel(-1);

	// Play the tunes once everything's set up
	Mix_PlayMusic(endSong, -1);

}


void Sound::playLazer() {
	// Play the chunk once everything's set up
	Mix_PlayChannel(-1, lazerSound, 0);

}

void Sound::playExplosion() {
	// Play the chunk once everything's set up
	Mix_PlayChannel(-1, explosionSound, 0);

}

void Sound::playSelect() {
	// Play the chunk once everything's set up
	Mix_PlayChannel(-1, selectSound, 0);

}



void Sound::cleans() {

	Mix_CloseAudio();
	Mix_FreeMusic(backgroundMusic);
	Mix_FreeChunk(lazerSound);
	Mix_FreeChunk(explosionSound);
	Mix_Quit();

}


