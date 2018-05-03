#include "EndScreen.h"
#include "InputManager.h"	




using namespace std;
EndScreen::EndScreen()
{
}


EndScreen::~EndScreen()
{
}

void EndScreen::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen == true) {
		flags = SDL_WINDOW_FULLSCREEN;
	}



	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "Subsystems Initialized!" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			cout << "window has been created" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		//Setting the renderer clear color to white
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); //255, 255, 255, 255
			cout << "Renderer created" << endl;
		}
		inputmanager = InputManager::Instance();
	}


	//Creating texture
	SDL_Surface* tmpSurface = IMG_Load("assets/Starfield.png");
	starfield = SDL_CreateTextureFromSurface(renderer, tmpSurface);

	SDL_Surface* tmpSurface1 = IMG_Load("assets/HighScore.png");
	highScoreTex = SDL_CreateTextureFromSurface(renderer, tmpSurface1);

	SDL_Surface* tmpSurface2 = IMG_Load("assets/GameOver.png");
	gameOverTex = SDL_CreateTextureFromSurface(renderer, tmpSurface2);

	//SDL_Surface* tmpSurface3 = IMG_Load("assets/spacewhite.png");
	//spacew = SDL_CreateTextureFromSurface(renderer, tmpSurface3);


	SDL_FreeSurface(tmpSurface);
	SDL_FreeSurface(tmpSurface1);
	SDL_FreeSurface(tmpSurface2);
	//SDL_FreeSurface(tmpSurface3);

	//FONT STUFF
	TTF_Font *times;
	SDL_Color blue = { 0, 0, 255};
	times = TTF_OpenFont("Times.ttf", 72);
	SDL_Surface *outScore = TTF_RenderText_Solid(times, "IT WORKS!!", blue);
	outScoreTex = SDL_CreateTextureFromSurface(renderer, outScore);
}

void EndScreen::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		hitspace = false;
		break;
	default:
		break;
	}
}

//Individual class update functions will go here!!
void EndScreen::updates() {



	inputmanager->Update();
	if (inputmanager->KeyDown(SDL_SCANCODE_SPACE)) {
		hitspace = true;
		cout << "true" << endl;

	}


	//Game Over
	srcS.h = 87;
	srcS.w = 554;
	srcS.x = 0;
	srcS.y = 0;

	destS.x = 150;
	destS.y = 100;
	destS.w = srcR.w;
	destS.h = srcR.h;

	//High Score
	srcR.h = 85;
	srcR.w = 550;
	srcR.x = 0;
	srcR.y = 0;

	destR.x = 50;
	destR.y = 300;
	destR.w = srcR.w / 2;
	destR.h = srcR.h / 2;
	
	//outScoretext

	destScore.x = 50;
	destScore.y = 400;
	destScore.h = 64;
	destScore.w = 128;

}

void EndScreen::renders() {
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, starfield, NULL, NULL);
	SDL_RenderCopy(renderer, highScoreTex, &srcR, &destR);
	SDL_RenderCopy(renderer, gameOverTex, &srcS, &destS);
	SDL_RenderCopy(renderer, outScoreTex, NULL, &destScore);

	SDL_RenderPresent(renderer);
}
void EndScreen::cleans() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleared" << endl;
}
