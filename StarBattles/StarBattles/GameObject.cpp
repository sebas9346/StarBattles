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
int GameObject::getY() {
	return ypos;
}
int GameObject::getWidth() {
	return destRect.w;
}
int GameObject::getHeight() {
	return destRect.h;
}
void  GameObject::setX(int x) {
	xpos = x;
}
void GameObject::clean() {
	SDL_RenderClear(renderer);
}
bool GameObject::collision(GameObject* other) {
	int x_diff = 3;
	int y_diff = 3;

	int astLeftBound = getX() + x_diff;
	int astRightBound = getX() + getWidth() - x_diff;
	int astTopBound = getY() + y_diff;
	int astBottomBound = getY() + getHeight() - y_diff;
	int rocketleft = other->getX() + x_diff;
	int rocketright = other->getX() + other->getWidth() - x_diff;
	int rocketbottom = other->getY() + other->getHeight() - y_diff;
	int rockettop = other->getY() + y_diff;
	if (astLeftBound <= rocketleft && rocketleft <= astRightBound) {
		if (astTopBound <= rockettop && rockettop <= astBottomBound) {
			return true;
		}
		if (astTopBound >= rockettop && rocketbottom >= astTopBound) {
			return true;
		}
	}
	else if (astLeftBound <= rocketright && rocketright <= astRightBound) {
		if (astTopBound <= rockettop && rockettop <= astBottomBound) {
			return true;
		}
		if (astTopBound >= rocketbottom && rocketbottom >= astBottomBound) {
			return true;
		}
	}
	return false;
}

void GameObject::reset() {

}