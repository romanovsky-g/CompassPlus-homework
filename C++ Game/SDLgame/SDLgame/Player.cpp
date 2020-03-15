#include "Player.h"

Player::Player(const char* texture, SDL_Renderer* rend, int initX, int initY, int initSpeed) : GameObject(texture, rend, initX, initY) {
	speed = initSpeed;
    x = initX;
    y = initY;
}

Player::~Player()
{}

void Player::handle_event(SDL_Event* evt)
{
}

void Player::update()
{

    SDL_GetMouseState(&x, &y);

    x = y;

    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 0;
    srcRect.y = 0;

    GameObject::update();
}

void Player::render()
{
    GameObject::render();
}