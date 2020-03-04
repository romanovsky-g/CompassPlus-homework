#include "Player.h"
#include "TextureManager.h"

//inheritance problems!!

Player::Player(int initSpeed) : GameObject(const char* texture, SDL_Renderer* rend, int initX, int initY) {
	speed = initSpeed;
}