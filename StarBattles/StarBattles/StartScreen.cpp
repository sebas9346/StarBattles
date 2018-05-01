#include "StartScreen.h"
#include "Asteroid.h"
#include "InputManager.h"	


SDL_Texture* starfield;
SDL_Texture* fontstar;
SDL_Texture* spacer;
SDL_Texture* spacew;
SDL_Rect srcR, destR;
SDL_Rect srcS, destS;   //space rectangle



using namespace std;
StartScreen::StartScreen()
{
}


StartScreen::~StartScreen()
{
}

void StartScreen::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

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
	//SDL_FreeSurface(tmpSurface);

	SDL_Surface* tmpSurface1 = IMG_Load("assets/fontstar.png");
	fontstar = SDL_CreateTextureFromSurface(renderer, tmpSurface1);

	SDL_Surface* tmpSurface2 = IMG_Load("assets/space.png");
	spacer = SDL_CreateTextureFromSurface(renderer, tmpSurface2);

	SDL_Surface* tmpSurface3 = IMG_Load("assets/spacewhite.png");
	spacew = SDL_CreateTextureFromSurface(renderer, tmpSurface3);


	SDL_FreeSurface(tmpSurface);
	SDL_FreeSurface(tmpSurface1);
	SDL_FreeSurface(tmpSurface2);
	SDL_FreeSurface(tmpSurface3);
 

}

void StartScreen::handleEvents() {
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
void StartScreen::updates() {
	


	inputmanager->Update();
	if (inputmanager->KeyDown(SDL_SCANCODE_SPACE)) {
		hitspace = true;
		cout << "true" << endl;

	}
	//cnt++;
	//if (hitspace) {

		
	//}
	//
	srcR.h = 65;
	srcR.w = 636;
	srcR.x = 0;
	srcR.y = 0;

	destR.x = 100;
	destR.y = 100;
	destR.w = srcR.w ;
	destR.h = srcR.h;
	//
	srcS.h = 66;
	srcS.w = 1078;
	srcS.x = 0;
	srcS.y = 0;

	destS.x = 100;
	destS.y = 400;
	destS.w = srcR.w;
	destS.h = srcR.h;

}

void StartScreen::renders() {
	SDL_RenderClear(renderer);
	//add stuff to render
	SDL_RenderCopy(renderer, starfield, NULL, NULL);
	SDL_RenderCopy(renderer, fontstar, &srcR, &destR);
	SDL_RenderPresent(renderer);



	
		inputmanager->Update();
		int mstime = SDL_GetTicks();
		int mstime1 = SDL_GetTicks();
		if ((mstime % 2) == 0) {
			SDL_RenderCopy(renderer, spacer, &srcS, &destS);
			SDL_RenderPresent(renderer);
		}
		//SDL_Delay(500);
		else {
			SDL_RenderCopy(renderer, spacew, &srcS, &destS);
			SDL_RenderPresent(renderer);
		}
		//SDL_Delay(500);
	SDL_RenderPresent(renderer);

	

}
void StartScreen::cleans() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleared" << endl;
}
