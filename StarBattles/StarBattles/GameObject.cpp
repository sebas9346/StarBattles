#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject() {
	xpos = 0;
	ypos = 0;
}

GameObject::~GameObject()
{
	clean();
}

void GameObject::update() {
}
void GameObject::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
bool GameObject::isOutOfBounds() {
	if (ypos > 900) {
		return true;
	}
	return false;
}
int GameObject::getX() {
	return xpos;
}
void GameObject::clean() {
	SDL_RenderClear(renderer);
}

void GameObject::reset() {

}