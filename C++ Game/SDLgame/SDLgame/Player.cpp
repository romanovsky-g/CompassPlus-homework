#include "Player.h"

Player::Player(const char* texture, SDL_Renderer* rend, int initX, int initY, int initSpeed, GameState* gameState) : GameObject(texture, rend, initX, initY) {
    speed = initSpeed;
    x = initX;
    y = initY;
    this->gameState = gameState;

    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 0;
    srcRect.y = 0;
}

Player::~Player()
{}

void Player::handle_event(SDL_Event* evt)
{
}

void Player::update()
{
    for (auto elem : gameState->arrows)
    {
        if (elem->x == destRect.x && elem->y == destRect.y) {
            printf("player is on an arrow!\n");
        }
    }

    GameObject::update();
}

void Player::render()
{
    GameObject::render();
}