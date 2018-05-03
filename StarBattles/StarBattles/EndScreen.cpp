#include "EndScreen.h"
#include "InputManager.h"	




using namespace std;
EndScreen::EndScreen()
{
}


EndScreen::~EndScreen()
{
}

void EndScreen::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, int highScore, int currentScore) {
	string temp = to_string(highScore); //makes the high score a string value for output to window
	high_score = temp.c_str();

	string temp2 = to_string(currentScore); //makes the current score a string value for output to window
	current_score = temp2.c_str();

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

	//FONT FOR HIGH SCORE CONFIGURATION
	TTF_Init();
	TTF_Font *times;
	SDL_Color blue = { 242, 125, 53};
	times = TTF_OpenFont("ARDESTINE.ttf", 72);
	SDL_Surface *outScore = TTF_RenderText_Solid(times, high_score, blue);
	outScoreTex = SDL_CreateTextureFromSurface(renderer, outScore);
	SDL_QueryTexture(outScoreTex, NULL, NULL, &destScore.w, &destScore.h);

	//FONT FOR CURRENT SCORE CONFIGURATION
	SDL_Surface *outCurrentScore = TTF_RenderText_Solid(times, current_score, blue);
	yourScoreTex = SDL_CreateTextureFromSurface(renderer, outCurrentScore);
	SDL_QueryTexture(yourScoreTex, NULL, NULL, &destCurrent.w, &destCurrent.h);

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
	destScore.x = 400;
	destScore.y = 280;

	//yourScoreTex
	destCurrent.x = 400;
	destCurrent.y = 380;

}

void EndScreen::renders() {
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, starfield, NULL, NULL);
	SDL_RenderCopy(renderer, highScoreTex, &srcR, &destR);
	SDL_RenderCopy(renderer, gameOverTex, &srcS, &destS);
	SDL_RenderCopy(renderer, outScoreTex, NULL, &destScore);
	SDL_RenderCopy(renderer, yourScoreTex, NULL, &destCurrent);

	SDL_RenderPresent(renderer);
}
void EndScreen::cleans() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
	cout << "Game Cleared" << endl;
}
