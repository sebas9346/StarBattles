#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject() {}
GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren,int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	xpos = x;
	ypos = y;
}


GameObject::~GameObject()
{
}

void GameObject::update() {
	srcRect.h = 1854;
	srcRect.w = 1473;
	srcRect.x = 0;
	srcRect.y = 0;


	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w / 5;
	destRect.h = srcRect.h / 5;
}
void GameObject::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

