#pragma once
#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include <SDL.h>
class InputManager
{

private:

	static InputManager* sInstance;   //pointer for the instance

	const Uint8* mKeyBoardStates; //hold all our key states
public:
	
	static InputManager* Instance(); 
	static void Release();

	bool KeyDown(SDL_Scancode scanCode); //check if key is pressed

	void Update();  //update input manager

private:
	InputManager();
	~InputManager();
};

#endif
