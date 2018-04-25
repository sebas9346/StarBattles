#include "Asteroid.h"


using namespace std;
Asteroid::Asteroid()
{
	new GameObject("\assets\Player.png", renderer, 2, 2);

}
void Asteroid::moveLeft(void) {
	xpos = xpos-1;
	cout << "left" << endl;
}
void Asteroid::moveRight(void) {
	xpos = xpos+1;
	cout << "Right" << endl;
}
void Asteroid::update() {
	srcRect.h = 1854;
	srcRect.w = 1473;
	srcRect.x = 0;
	srcRect.y = 0;


	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w / 5;
	destRect.h = srcRect.h / 5;
}


Asteroid::~Asteroid()
{
}
