#include "GameObject.h"
#include "TextureManager.h"


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

void GameObject::update(int x, int y) {
	xpos = x;
	ypos = y;

	srcRect.h = 1854;// Dimension of image to use(Slab from texture sheet)
	srcRect.w = 1473;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w/5 ;
	destRect.h = srcRect.h /5;
}
void GameObject::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

