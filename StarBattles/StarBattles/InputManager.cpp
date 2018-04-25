#include "InputManager.h"


InputManager* InputManager::sInstance = NULL;  //initialize sInstance 

InputManager* InputManager::Instance() {

	if (sInstance == NULL)
		sInstance = new InputManager();
	return sInstance;
}

void InputManager::Release() {
	delete sInstance;
	sInstance = NULL;
}


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

bool InputManager::KeyDown(SDL_Scancode scancode) {
	return mKeyBoardStates[scancode];
}

void InputManager::Update(){
	mKeyBoardStates = SDL_GetKeyboardState(NULL);  //fill array with all SDL keyboard states from SDL frameworkss
}
